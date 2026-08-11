/*
 * tcp.c — TCP 协议栈 (多连接版本)
 * ====================================
 * 功能：完整的 TCP/IP 协议栈实现，包含：
 *   1. 网络字节序转换（大端）
 *   2. TCP 校验和计算（含伪首部）
 *   3. 底层 TCP 段发送（带 CRC 补齐）
 *   4. 多连接管理（最多 4 个并发连接）
 *   5. TCP 状态机（三次握手 + 数据传输 + 四次挥手）
 *   6. HTTP 请求解析（GET/POST + JSON + form-urlencoded）
 *   7. 寄存器读写控制（LED 等外设）
 *   8. 保洁定时器（SYN 重传 / 空闲超时 / TIME_WAIT 回收）
 *
 * 硬件平台：XC7A35T + PicoRV32 @ 50MHz
 * 数据通路：RX FIFO 直接读取 → TX FIFO 直接写入（零拷贝）
 */

#include "inc/lcpu_general.h"
#include "inc/tcp.h"
#include "inc/ip.h"
#include "inc/http.h"

/* ================================================================
 * 第 1 部分：连接表 — 并行数组管理多连接
 * 每个连接独立维护：状态 / 序列号 / 确认号 / 端口 / IP / 定时器
 * ================================================================ */
uint8_t  conn_state     [MAX_CONNECTIONS];  // TCP 状态 (0=CLOSED ~ 7=TIME_WAIT)
uint32_t conn_snd_seq   [MAX_CONNECTIONS];  // 本端发送序列号 (ISN + 已发字节)
uint32_t conn_rcv_ack   [MAX_CONNECTIONS];  // 期望收到的下一字节序号
uint16_t conn_src_port  [MAX_CONNECTIONS];  // 对方端口 (PC 的临时端口)
uint16_t conn_dst_port  [MAX_CONNECTIONS];  // 本端监听端口 (80 = HTTP)
uint32_t conn_src_ip    [MAX_CONNECTIONS];  // 对方 IP 地址
uint32_t conn_dst_ip    [MAX_CONNECTIONS];  // 本端 IP 地址 (Local_IP_ADDR)
uint32_t conn_timewait  [MAX_CONNECTIONS];  // TIME_WAIT 开始时间戳
uint32_t conn_activity  [MAX_CONNECTIONS];  // 上次活动时间 (空闲超时用)
uint32_t conn_tx_time   [MAX_CONNECTIONS];  // 上次发送时间 (SYN 重传用)
uint8_t  conn_syn_retry [MAX_CONNECTIONS];  // SYN+ACK 重传计数

/* 全局标志: TCP 写 LED 寄存器时置 1, 暂停主循环流水灯 */
uint8_t tcp_led_override = 0;

/* ================================================================
 * 第 2 部分：网络字节序转换（大端 / Big-Endian）
 * 网络协议统一使用大端序，x86/RISC-V 为小端序，需要转换
 * ================================================================ */

// 把 16 位数字拆成高 8 位和低 8 位，存入 buf[0] 和 buf[1]
static void tcp_write_u16_be(uint8 *buf, uint16 val) {
    buf[0] = (val >> 8) & 0xFF;   // 高字节在前（大端）
    buf[1] = val & 0xFF;           // 低字节在后
}

// 把 32 位数字拆成 4 个字节，存入 buf[0] 到 buf[3]
static void tcp_write_u32_be(uint8 *buf, uint32 val) {
    buf[0] = (val >> 24) & 0xFF;  // 最高字节
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] =  val & 0xFF;          // 最低字节
}

/* ================================================================
 * 第 3 部分：TCP 校验和计算
 * TCP 校验和 = 伪首部(12B) + TCP头(20B) + 数据载荷
 * 伪首部包含: 源IP(4B) + 目的IP(4B) + 保留(1B=0) + 协议号(1B=6) + TCP长度(2B)
 * 算法: 16位反码求和 → 进位回卷 → 取反
 * ================================================================ */

// 字节流按 16 位为单位累加求和
// 奇数个字节时，最后一个字节当高字节处理（低字节补 0）
// 例如：[0x12, 0x34, 0x56] → 加 0x1234，最后剩 0x56 当 0x5600 加
static uint32 tcp_checksum_add_bytes(uint32 sum, const uint8 *bytes, uint16 len) {
    uint16 i;
    for (i = 0; i + 1 < len; i += 2)
        sum += ((uint16)bytes[i] << 8) | bytes[i + 1];
    if (i < len) sum += (uint16)bytes[i] << 8;  // 最后一个奇数字节
    return sum;
}

// 纯 TCP 头的校验和（无数据载荷）
static uint16 tcp_checksum_build(const uint8 header[20], uint32 src_ip, uint32 dst_ip) {
    uint32 sum = 0;

    // 1. 伪首部 (12 字节)
    sum += (src_ip >> 16) & 0xFFFF;  // 源 IP 高 16 位
    sum += src_ip & 0xFFFF;           // 源 IP 低 16 位
    sum += (dst_ip >> 16) & 0xFFFF;  // 目的 IP 高 16 位
    sum += dst_ip & 0xFFFF;           // 目的 IP 低 16 位
    sum += (uint16)IP_PROTOCOL_TCP;   // 协议号 0x06
    sum += (uint16)20;                // TCP 段长度 (仅头部)

    // 2. TCP 头部 (20 字节)
    sum = tcp_checksum_add_bytes(sum, header, 20);

    // 3. 进位回卷（"1的补码"加法 — 把进位加到低 16 位）
    while (sum >> 16) sum = (sum & 0xFFFF) + (sum >> 16);

    // 4. 取反 = 接收端验算结果为 0xFFFF 即正确
    return (uint16)(~sum);
}

// 带数据载荷的 TCP 校验和 (伪首部 + TCP 头 + 数据)
static uint16 tcp_checksum_with_payload(
    const uint8 header[20], const uint8 *payload, uint16 payload_len,
    uint32 src_ip, uint32 dst_ip)
{
    uint32 sum = 0;

    // 1. 伪首部 (12 字节)
    sum += (src_ip >> 16) & 0xFFFF;
    sum += src_ip & 0xFFFF;
    sum += (dst_ip >> 16) & 0xFFFF;
    sum += dst_ip & 0xFFFF;
    sum += (uint16)IP_PROTOCOL_TCP;
    sum += (uint16)(20 + payload_len);  // TCP 段长度 (头 + 数据)

    // 2. TCP 头部
    sum = tcp_checksum_add_bytes(sum, header, 20);

    // 3. 数据载荷（如果有）
    if (payload && payload_len > 0)
        sum = tcp_checksum_add_bytes(sum, payload, payload_len);

    // 4. 进位回卷 + 取反
    while (sum >> 16) sum = (sum & 0xFFFF) + (sum >> 16);
    return (uint16)(~sum);
}

/* ================================================================
 * 第 4 部分：底层发送函数
 * 把 TCP 头和数据载荷写入 LCPU 的 TX FIFO，补齐最小帧长，触发发送
 * 注意：以太网最小帧长 64 字节 (含 4 字节 CRC)
 * ================================================================ */

// 发送纯 TCP 头（20 字节，无数据）
static void send_tcp_segment(const uint8 header[20]) {
    uint16 i, tcp_start = eth_header_len + ip_header_len;  // =34 (14+20)

    // 把 20 字节 TCP 头逐一写入 TX FIFO（地址 34~53）
    for (i = 0; i < 20; i++) LCPU_WR_BYTE(tcp_start + i, header[i]);

    // 计算总包长：MAC(14) + IP(20) + TCP(20) + CRC(4) = 58 → 补齐到 64
    uint16 pkt_len = eth_header_len + ip_header_len + 20 + 4;
    if (pkt_len < 64) pkt_len = 64;
    LCPU_WR_PUSH_PACKET(pkt_len);    // 推送发送
    _WR(6) = 1u;                      // 强制 TX 刷新，确保立即发出
}

// 发送 TCP 头 + 数据载荷
static void send_tcp_segment_with_payload(
    const uint8 header[20], const uint8 *payload, uint16 payload_len)
{
    uint16 i, tcp_start = eth_header_len + ip_header_len;

    // 1. 写入 TCP 头 (20 字节)
    for (i = 0; i < 20; i++) LCPU_WR_BYTE(tcp_start + i, header[i]);

    // 2. 写入数据载荷 (紧接 TCP 头之后)
    if (payload && payload_len > 0)
        for (i = 0; i < payload_len; i++)
            LCPU_WR_BYTE(tcp_start + 20 + i, payload[i]);

    // 3. 补齐并发送
    uint16 pkt_len = eth_header_len + ip_header_len + 20 + payload_len + 4;
    if (pkt_len < 64) pkt_len = 64;
    LCPU_WR_PUSH_PACKET(pkt_len);
    _WR(6) = 1u;  // 强制 TX 刷新
}

/* ================================================================
 * 第 5 部分：连接表管理
 * 查找空闲槽位 / 查找已有连接 / 关闭连接
 * ================================================================ */

// 在连接表中找一个空闲位置（state == CLOSED）
static int find_free_connection(void) {
    uint8 i;
    for (i = 0; i < MAX_CONNECTIONS; i++)
        if (conn_state[i] == TCP_STATE_CLOSED) return i;
    return -1;  // 连接表已满
}

// 根据四元组 (源端口, 目的端口, 源IP) 查找已有连接
static int find_connection(uint16 src_port, uint16 dst_port, uint32 src_ip) {
    uint8 i;
    for (i = 0; i < MAX_CONNECTIONS; i++)
        if (conn_state[i] != TCP_STATE_CLOSED &&
            conn_src_port[i] == src_port &&
            conn_dst_port[i] == dst_port &&
            conn_src_ip[i]   == src_ip)
            return i;
    return -1;  // 未找到
}

// 关闭连接：重置该槽位的所有字段
static void close_connection(int idx) {
    if (idx < 0 || idx >= MAX_CONNECTIONS) return;
    conn_state    [idx] = TCP_STATE_CLOSED;
    conn_snd_seq  [idx] = 0;
    conn_rcv_ack  [idx] = 0;
    conn_src_port [idx] = 0;
    conn_dst_port [idx] = 0;
    conn_src_ip   [idx] = 0;
    conn_dst_ip   [idx] = 0;
    conn_timewait [idx] = 0;
    conn_activity [idx] = 0;
    conn_tx_time  [idx] = 0;
    conn_syn_retry[idx] = 0;
}

/* ---- 全局初始化：上电时调用，清空所有连接槽位 ---- */
void tcp_init(void) {
    uint8 i;
    for (i = 0; i < MAX_CONNECTIONS; i++) close_connection(i);
}

/* ================================================================
 * 第 6 部分：TCP 头解析器
 * 从 RX FIFO 中读出源端口、目的端口、序列号、确认号、标志位
 * TCP 头位于：以太网头(14) + IP 头(20) = 第 34 字节开始
 * 所有字段均为大端序
 * ================================================================ */
static void tcp_parse_header(
    uint16 *src_port,   // 返回：对方端口
    uint16 *dst_port,   // 返回：本端端口
    uint32 *seq_num,    // 返回：对方序列号
    uint32 *ack_num,    // 返回：对方确认号
    uint8  *flags)      // 返回：标志位 (SYN/ACK/FIN/RST/PSH/URG)
{
    uint32 tcp_off = eth_header_len + ip_header_len;  // =34

    // 读源端口 (大端，2字节)
    LCPU_RD_SET_ADDR(tcp_off + 0);
    *src_port  = ((uint16)LCPU_RD_DATA8() << 8); LCPU_RD_INC_ADDR();
    *src_port |= LCPU_RD_DATA8();

    // 读目的端口
    LCPU_RD_SET_ADDR(tcp_off + 2);
    *dst_port  = ((uint16)LCPU_RD_DATA8() << 8); LCPU_RD_INC_ADDR();
    *dst_port |= LCPU_RD_DATA8();

    // 读序列号 (大端，4字节)
    LCPU_RD_SET_ADDR(tcp_off + 4);
    *seq_num  = ((uint32)LCPU_RD_DATA8() << 24); LCPU_RD_INC_ADDR();
    *seq_num |= ((uint32)LCPU_RD_DATA8() << 16); LCPU_RD_INC_ADDR();
    *seq_num |= ((uint32)LCPU_RD_DATA8() << 8);  LCPU_RD_INC_ADDR();
    *seq_num |= LCPU_RD_DATA8();

    // 读确认号 (大端，4字节)
    LCPU_RD_SET_ADDR(tcp_off + 8);
    *ack_num  = ((uint32)LCPU_RD_DATA8() << 24); LCPU_RD_INC_ADDR();
    *ack_num |= ((uint32)LCPU_RD_DATA8() << 16); LCPU_RD_INC_ADDR();
    *ack_num |= ((uint32)LCPU_RD_DATA8() << 8);  LCPU_RD_INC_ADDR();
    *ack_num |= LCPU_RD_DATA8();

    // 读标志位 (1字节，位于 TCP 头偏移 13)
    LCPU_RD_SET_ADDR(tcp_off + 13);
    *flags = LCPU_RD_DATA8();
}

/* ================================================================
 * 第 7 部分：TCP 包发送函数
 * send_syn_ack — 第二次握手：SYN+ACK
 * send_ack     — 纯确认包 (ACK)
 * send_fin     — 连接关闭：FIN+ACK
 * send_rst     — 连接复位：RST+ACK
 * ================================================================ */

// 发送 SYN+ACK（第二次握手）
// idx: 连接表索引
static void send_syn_ack(int idx) {
    uint8 h[20] = {0};

    // 填充 TCP 头
    tcp_write_u16_be(&h[0], conn_dst_port[idx]);   // 源端口 = 本端监听端口 (80)
    tcp_write_u16_be(&h[2], conn_src_port[idx]);   // 目的端口 = 对方端口
    tcp_write_u32_be(&h[4], conn_snd_seq[idx]);    // 本端序列号 (ISN)
    tcp_write_u32_be(&h[8], conn_rcv_ack[idx]);    // 确认号 = 对方 ISN + 1
    h[12] = 0x50;                                   // 数据偏移 = 5 (20 字节头)
    h[13] = TCP_FLAG_SYN | TCP_FLAG_ACK;            // SYN + ACK
    h[14] = 0xFF; h[15] = 0xFF;                     // 窗口大小 = 65535

    // 计算校验和并填入
    uint16 cs = tcp_checksum_build(h, conn_dst_ip[idx], conn_src_ip[idx]);
    h[16] = (cs >> 8) & 0xFF; h[17] = cs & 0xFF;

    // 修改 IP 头（目的 IP → 对方 IP）
    ip_header_update(conn_src_ip[idx], ip_header_len + 20);

    // 发送 TCP 段
    send_tcp_segment(h);

    // 记录发送时间 (用于超时重传)
    conn_tx_time[idx] = LCPU_LOCAL_TIME_L();
}

// 发送纯 ACK（确认包，无数据）
static void send_ack(int idx) {
    uint8 h[20] = {0};

    tcp_write_u16_be(&h[0], conn_dst_port[idx]);   // 源端口
    tcp_write_u16_be(&h[2], conn_src_port[idx]);   // 目的端口
    tcp_write_u32_be(&h[4], conn_snd_seq[idx]);    // 序列号 (不变，ACK 不消耗序号)
    tcp_write_u32_be(&h[8], conn_rcv_ack[idx]);    // 确认号
    h[12] = 0x50;
    h[13] = TCP_FLAG_ACK;                           // 纯 ACK
    h[14] = 0xFF; h[15] = 0xFF;

    uint16 cs = tcp_checksum_build(h, conn_dst_ip[idx], conn_src_ip[idx]);
    h[16] = (cs >> 8) & 0xFF; h[17] = cs & 0xFF;

    ip_header_update(conn_src_ip[idx], ip_header_len + 20);
    send_tcp_segment(h);
}

// 发送 FIN+ACK（主动关闭连接）
// FIN 消耗一个序列号，所以发送后 conn_snd_seq++
static void send_fin(int idx) {
    uint8 h[20] = {0};

    tcp_write_u16_be(&h[0], conn_dst_port[idx]);   // 源端口
    tcp_write_u16_be(&h[2], conn_src_port[idx]);   // 目的端口
    tcp_write_u32_be(&h[4], conn_snd_seq[idx]);    // 序列号
    tcp_write_u32_be(&h[8], conn_rcv_ack[idx]);    // 确认号
    h[12] = 0x50;
    h[13] = TCP_FLAG_FIN | TCP_FLAG_ACK;            // FIN + ACK
    h[14] = 0xFF; h[15] = 0xFF;

    uint16 cs = tcp_checksum_build(h, conn_dst_ip[idx], conn_src_ip[idx]);
    h[16] = (cs >> 8) & 0xFF; h[17] = cs & 0xFF;

    ip_header_update(conn_src_ip[idx], ip_header_len + 20);
    send_tcp_segment(h);

    conn_snd_seq[idx]++;  // FIN 消耗一个序列号
}

// 发送 RST+ACK（连接复位，通知对端立即关闭）
static void send_rst(int idx) {
    uint8 h[20] = {0};

    tcp_write_u16_be(&h[0], conn_dst_port[idx]);
    tcp_write_u16_be(&h[2], conn_src_port[idx]);
    tcp_write_u32_be(&h[4], conn_snd_seq[idx]);
    tcp_write_u32_be(&h[8], conn_rcv_ack[idx]);
    h[12] = 0x50;
    h[13] = TCP_FLAG_RST | TCP_FLAG_ACK;            // RST + ACK
    h[14] = 0x00; h[15] = 0x00;                     // 窗口 = 0

    uint16 cs = tcp_checksum_build(h, conn_dst_ip[idx], conn_src_ip[idx]);
    h[16] = (cs >> 8) & 0xFF; h[17] = cs & 0xFF;

    ip_header_update(conn_src_ip[idx], ip_header_len + 20);
    send_tcp_segment(h);
}

/* ================================================================
 * 第 8 部分：HTTP 辅助函数
 *   - JSON 字段解析 (tcp_find_json_field)
 *   - Form-urlencoded 字段解析 (tcp_find_form_field)
 *   - ASCII 十六进制字符串转数值 (read_ascii_hex_field)
 *   - 数值转十六进制字符串 (to_hex_string)
 *   - POST 响应页面填充 (build_post_response)
 *   - HTTP 响应数据发送 (send_http_data)
 * ================================================================ */

#define TCP_POST_FIELD_WIDTH  8      // JSON/form 字段最大提取字符数
#define TCP_POST_RESP_BUF_SIZE  640  // POST 响应缓冲区大小
#define TCP_MSS  1460                // TCP 最大分段大小 (Maximum Segment Size)

// 单个 ASCII 十六进制字符转数值, 非法返回 0xFF
static uint8 tcp_hex_char_to_val(char ch) {
    if (ch >= '0' && ch <= '9') return (uint8)(ch - '0');
    if (ch >= 'A' && ch <= 'F') return (uint8)(ch - 'A' + 10);
    if (ch >= 'a' && ch <= 'f') return (uint8)(ch - 'a' + 10);
    return 0xFF;  // 非法字符
}

/*
 * tcp_find_form_field — 在 TCP payload 中扫描 form-urlencoded 的 key=value
 * 用于解析 URL 查询参数 (GET /set?addr=...&data=...) 和 HTML form 提交
 * key: 要匹配的键名 (如 "addr", "data", "mode")
 * 返回: 1=找到, 0=未找到
 */
static uint8 tcp_find_form_field(
    uint16 data_len, const char *key, char field_out[], uint8 field_width)
{
    uint32 base = OFF_TCP_PAYLOAD;  // TCP 数据载荷起始地址 (54)
    uint8 key_len = 0, i;
    uint16 pos = 0;

    // 初始化输出为空格
    for (i = 0; i < field_width; i++) field_out[i] = ' ';
    field_out[field_width] = '\0';

    // 计算 key 长度
    while (key[key_len]) key_len++;

    // 线性扫描 payload，寻找 "key=value" 模式
    while (pos + key_len + 1 <= data_len) {
        LCPU_RD_SET_ADDR(base + pos);

        // key 必须位于行首、'&'、'?'、或 '\r'、'\n' 之后
        if (pos > 0) {
            LCPU_RD_SET_ADDR(base + pos - 1);
            uint8 prev = LCPU_RD_DATA8();
            if (prev != '&' && prev != '?' && prev != '\n' && prev != '\r')
                { pos++; continue; }
        }

        // 逐字符匹配 key
        LCPU_RD_SET_ADDR(base + pos);
        uint8 matched = 1;
        for (i = 0; i < key_len; i++) {
            LCPU_RD_SET_ADDR(base + pos + i);
            if (LCPU_RD_DATA8() != (uint8)key[i]) { matched = 0; break; }
        }
        if (!matched) { pos++; continue; }

        // 检查 key 后面是否跟着 '='
        LCPU_RD_SET_ADDR(base + pos + key_len);
        if (LCPU_RD_DATA8() != '=') { pos++; continue; }

        // 提取 value：从 '=' 之后到 '&' 或行尾
        uint16 vs = pos + key_len + 1;
        uint8 cnt = 0;
        for (i = 0; i < field_width && (vs + i) < data_len; i++) {
            LCPU_RD_SET_ADDR(base + vs + i);
            uint8 ch = LCPU_RD_DATA8();
            if (ch == '&' || ch == '\r' || ch == '\n') break;
            field_out[cnt++] = (char)ch;
        }
        field_out[cnt] = '\0';
        return 1;  // 找到
    }
    return 0;  // 未找到
}

/*
 * tcp_find_json_field — 在 TCP payload 中扫描 JSON 的 "key":"value" 模式
 * 用于解析 curl POST 请求的 JSON body
 * key: 要匹配的键名 (如 "addr", "data", "mode")
 * 返回: 1=找到, 0=未找到
 */
static uint8 tcp_find_json_field(
    uint16 data_len, const char *key, char field_out[], uint8 field_width)
{
    uint32 base = OFF_TCP_PAYLOAD;
    uint8 key_len = 0, i;
    uint16 pos = 0;

    // 初始化输出为空格
    for (i = 0; i < field_width; i++) field_out[i] = ' ';
    field_out[field_width] = '\0';

    // 计算 key 长度
    while (key[key_len] != '\0') key_len++;

    // 线性扫描 payload，寻找 "key":"value" 模式
    while (pos + key_len + 2 <= data_len) {
        LCPU_RD_SET_ADDR(base + pos);

        // 找前导引号 "
        if (LCPU_RD_DATA8() != 0x22) { pos++; continue; }

        // 逐字符匹配 key (在引号内)
        uint8 matched = 1;
        for (i = 0; i < key_len; i++) {
            LCPU_RD_SET_ADDR(base + pos + 1 + i);
            if (LCPU_RD_DATA8() != (uint8)key[i]) { matched = 0; break; }
        }
        if (!matched) { pos++; continue; }

        // 检查 key 后面的 ": 即 "key":
        LCPU_RD_SET_ADDR(base + pos + 1 + key_len);
        if (LCPU_RD_DATA8() != 0x22) { pos++; continue; }
        LCPU_RD_SET_ADDR(base + pos + 1 + key_len + 1);
        if (LCPU_RD_DATA8() != 0x3A) { pos++; continue; }  // ':'

        // 提取 value：跳过 ": 之后的第一个引号，读内容到下一个引号
        uint16 vs = pos + key_len + 3;
        if (vs >= data_len) return 0;
        LCPU_RD_SET_ADDR(base + vs);
        if (LCPU_RD_DATA8() != 0x22) { pos++; continue; }
        vs++;  // 跳过 value 前的引号
        uint8 cnt = 0;
        for (i = 0; i < field_width && (vs + i) < data_len; i++) {
            LCPU_RD_SET_ADDR(base + vs + i);
            uint8 ch = LCPU_RD_DATA8();
            if (ch == 0x22) break;  // value 后的引号 → 结束
            field_out[cnt++] = (char)ch;
        }
        field_out[cnt] = '\0';
        return 1;  // 找到
    }
    return 0;  // 未找到
}

// 将 8 字符的 ASCII 十六进制字符串转为 32 位数值
// 遇到空格或 '\0' 提前终止
static uint32 read_ascii_hex_field(const char field[], uint8 fw) {
    uint32 v = 0; uint8 i;
    for (i = 0; i < fw; i++) {
        if (field[i] == ' ' || field[i] == '\0') break;
        uint8 n = tcp_hex_char_to_val(field[i]);
        if (n == 0xFF) break;  // 非法字符 → 停止
        v = (v << 4) | n;       // 左移 4 位拼接
    }
    return v;
}

// 32 位数值 → 8 字符 ASCII 十六进制字符串 (大写)
static void to_hex_string(uint32 data, char hex_str[8]) {
    const char d[] = "0123456789ABCDEF"; uint8 i;
    for (i = 0; i < 8; i++) {
        hex_str[7 - i] = d[data & 0xF];  // 从低位到高位逐字节填充
        data >>= 4;
    }
}

/*
 * build_post_response — 填充 POST 响应页面的模板占位符
 * 模板字符串 (来自 http.c) 中的占位符:
 *   XXX          → "读" 或 "写" (UTF-8 中文，各 3 字节)
 *   0x00000000   → 寄存器地址 (8 字符十六进制)
 *   0x88888888   → 数据值 (8 字符十六进制)
 * 采用等长替换，不改变字符串长度
 */
static void build_post_response(char response[], uint16 buf_size,
                                uint32 address, uint32 data, const char *mode)
{
    uint16 rlen = 0, i;

    // 复制 post_response 模板到本地缓冲区
    while (post_response[rlen] && rlen < buf_size - 1) rlen++;
    for (i = 0; i <= rlen; i++) response[i] = post_response[i];

    // 替换 "XXX" → "读" 或 "写"
    const char *mt = (mode[0] == 'w' || mode[0] == 'W') ? "写" : "读";
    char *p = response;
    while ((p = strstr(p, "XXX")) != NULL) {
        p[0]=mt[0]; p[1]=mt[1]; p[2]=mt[2]; p+=3;
    }

    char hex[8];

    // 替换 "0x00000000" → 实际寄存器地址
    p = response;
    while ((p = strstr(p, "0x00000000")) != NULL) {
        to_hex_string(address, hex);
        p[2]=hex[0];p[3]=hex[1];p[4]=hex[2];p[5]=hex[3];
        p[6]=hex[4];p[7]=hex[5];p[8]=hex[6];p[9]=hex[7]; p+=10;
    }

    // 替换 "0x88888888" → 实际数据值
    p = response;
    while ((p = strstr(p, "0x88888888")) != NULL) {
        to_hex_string(data, hex);
        p[2]=hex[0];p[3]=hex[1];p[4]=hex[2];p[5]=hex[3];
        p[6]=hex[4];p[7]=hex[5];p[8]=hex[6];p[9]=hex[7]; p+=10;
    }
}

/*
 * send_http_data — 发送 HTTP 响应，支持 MSS 分段
 * 对标参考代码的 send_http_response()
 * 将大数据按 MSS (1460 字节) 拆成多个 TCP 段
 * 最后一个段带 FIN 标志，通知客户端服务器已关闭连接
 */
static void send_http_data(int idx, const uint8 *data, uint16 len) {
    uint16 offset = 0;

    while (offset < len) {
        uint16 seg = len - offset;
        if (seg > TCP_MSS) seg = TCP_MSS;  // 限制每段不超过 MSS

        // 最后一个段：附加 FIN 标志，通知客户端服务器已关闭
        uint8 fl = TCP_FLAG_ACK;
        if (offset + seg >= len) fl |= TCP_FLAG_FIN;

        // 构造 TCP 头
        uint8 h[20] = {0};
        tcp_write_u16_be(&h[0], conn_dst_port[idx]);   // 源端口
        tcp_write_u16_be(&h[2], conn_src_port[idx]);   // 目的端口
        tcp_write_u32_be(&h[4], conn_snd_seq[idx]);    // 序列号
        tcp_write_u32_be(&h[8], conn_rcv_ack[idx]);    // 确认号
        h[12] = 0x50;
        h[13] = fl;                                     // 标志位 (ACK 或 ACK+FIN)
        h[14] = 0xFF; h[15] = 0xFF;

        // 计算校验和 (含数据载荷)
        uint16 cs = tcp_checksum_with_payload(h, data + offset, seg,
                                              conn_dst_ip[idx], conn_src_ip[idx]);
        h[16] = (cs >> 8) & 0xFF; h[17] = cs & 0xFF;

        // 更新 IP 头，发送 TCP 段
        ip_header_update(conn_src_ip[idx], ip_header_len + 20 + seg);
        send_tcp_segment_with_payload(h, data + offset, seg);

        // 推进序列号
        conn_snd_seq[idx] += seg;
        if (fl & TCP_FLAG_FIN) conn_snd_seq[idx]++;  // FIN 额外消耗一个序号
        offset += seg;
    }
}

/* ================================================================
 * 第 9 部分：TCP 状态机主处理器 tcp_handler()
 *
 * TCP 状态转移图:
 *
 *                       +---------+
 *                       | CLOSED  |  初始状态
 *                       +---------+
 *                            | 收到纯 SYN
 *                            v
 *                     +---------------+
 *                     | SYN_RECEIVED  |  等待第三次握手 ACK
 *                     +---------------+
 *                            | 收到正确 ACK
 *                            v
 *                     +---------------+
 *                     | ESTABLISHED   |  连接建立，可传输数据
 *                     +---------------+
 *                       |          |
 *          收到 FIN     |          |  主动发 FIN
 *                       v          v
 *               +----------+   +------------+   +------------+
 *               |CLOSE_WAIT|   |FIN_WAIT_1  |-->|FIN_WAIT_2  |
 *               +----------+   +------------+   +------------+
 *                    | 发 FIN        |                  | 收到 FIN
 *                    v              v                  v
 *               +----------+   +------------+   +------------+
 *               |LAST_ACK  |   | TIME_WAIT  |<--| TIME_WAIT  |
 *               +----------+   +------------+   +------------+
 *                    | 收到 ACK      | 2s 超时
 *                    v              v
 *                  CLOSED        CLOSED
 * ================================================================ */
void tcp_handler(void) {
    uint16 src_port, dst_port;
    uint32 seq_num, ack_num;
    uint8  flags;

    // 第 1 步：解析 TCP 头，读出端口/序列号/确认号/标志位
    tcp_parse_header(&src_port, &dst_port, &seq_num, &ack_num, &flags);

    // 第 2 步：端口过滤 — 只处理发往 80 端口的包
    if (dst_port != 80) return;

    // 第 3 步：查找已有连接
    int idx = find_connection(src_port, dst_port, src_ip);

    // 第 4 步：RST 处理 — 收到 RST 直接关闭连接
    if (flags & TCP_FLAG_RST) {
        if (idx >= 0) close_connection(idx);
        return;
    }

    // 第 5 步：新连接建立 — 仅接受纯 SYN (SYN=1, ACK=0)
    if (idx < 0) {
        if ((flags & TCP_FLAG_SYN) && !(flags & TCP_FLAG_ACK)) {
            idx = find_free_connection();
            if (idx < 0) return;  // 连接表已满，丢弃

            // 初始化连接信息
            conn_state   [idx] = TCP_STATE_SYN_RECEIVED;
            conn_src_port[idx] = src_port;
            conn_dst_port[idx] = dst_port;
            conn_src_ip  [idx] = src_ip;
            conn_dst_ip  [idx] = Local_IP_ADDR;
            conn_rcv_ack [idx] = seq_num + 1;             // 期望对方下一个字节
            conn_snd_seq [idx] = LCPU_LOCAL_TIME_L();     // 本端随机初始序列号
            conn_activity[idx] = LCPU_LOCAL_TIME_L();
            conn_syn_retry[idx] = 0;

            send_syn_ack(idx);         // 发送第二次握手
            conn_snd_seq[idx]++;       // SYN 消耗一个序列号
        }
        return;
    }

    // 第 6 步：已有连接 — 更新活动时间戳，进入状态机
    conn_activity[idx] = LCPU_LOCAL_TIME_L();

    switch (conn_state[idx]) {

    /* ------------------------------------------------------------
     * SYN_RECEIVED — 等待第三次握手 ACK
     * 收到正确 ACK → ESTABLISHED
     * ------------------------------------------------------------ */
    case TCP_STATE_SYN_RECEIVED:
        if ((flags & TCP_FLAG_ACK) && (ack_num == conn_snd_seq[idx])) {
            conn_state[idx] = TCP_STATE_ESTABLISHED;
            conn_syn_retry[idx] = 0;   // 握手完成，清除重传计数
        }
        break;

    /* ------------------------------------------------------------
     * ESTABLISHED — 数据传输中
     *   收到 FIN  → 被动关闭 → LAST_ACK
     *   收到数据  → HTTP 请求处理 (GET/POST)
     * ------------------------------------------------------------ */
    case TCP_STATE_ESTABLISHED: {
        // 优先检查 FIN (被动关闭)
        // 必须放在最前面，否则先读 ip_total 的 RX 操作会延迟 send_fin
        if (flags & TCP_FLAG_FIN) {
            conn_rcv_ack[idx] = seq_num + 1;   // FIN 消耗一个序号
            send_fin(idx);                      // 回复 FIN+ACK
            conn_state[idx] = TCP_STATE_LAST_ACK;
            break;
        }

        // 计算 TCP 数据载荷长度 = IP总长 - IP头 - TCP头
        LCPU_RD_SET_ADDR(eth_header_len + 2);
        uint16 ip_total = ((uint16)LCPU_RD_DATA8() << 8);
        LCPU_RD_INC_ADDR();
        ip_total |= LCPU_RD_DATA8();
        LCPU_RD_SET_ADDR(eth_header_len);
        uint8 ip_hdr_len = ((LCPU_RD_DATA8() & 0x0F) * 4);
        uint16 data_len = ip_total - ip_hdr_len - 20;

        // 收到数据 → HTTP 请求处理
        if (data_len > 0 && (flags & TCP_FLAG_ACK)) {
            conn_rcv_ack[idx] = seq_num + data_len;  // 更新期望序号

            // 读第一个字节判断 HTTP 方法
            LCPU_RD_SET_ADDR(OFF_TCP_PAYLOAD);
            char fc = (char)LCPU_RD_DATA8();
            uint8 handled = 0;

            // ---- GET 请求 ----
            if (fc == 'G') {
                LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == 'E') { LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == 'T') { LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == ' ') {
                    // 检查 URL 是否包含 addr= → 寄存器访问请求
                    char ga[TCP_POST_FIELD_WIDTH+1];
                    if (tcp_find_form_field(data_len, "addr", ga, TCP_POST_FIELD_WIDTH)) {
                        // GET /set?addr=... → 寄存器读写
                        char gd[TCP_POST_FIELD_WIDTH+1], gm[TCP_POST_FIELD_WIDTH+1];
                        tcp_find_form_field(data_len, "data", gd, TCP_POST_FIELD_WIDTH);
                        tcp_find_form_field(data_len, "mode", gm, TCP_POST_FIELD_WIDTH);
                        uint32 ra = read_ascii_hex_field(ga, TCP_POST_FIELD_WIDTH);
                        uint32 rd = read_ascii_hex_field(gd, TCP_POST_FIELD_WIDTH);
                        uint32 result = 0;
                        if (gm[0] == 'r' || gm[0] == 'R') {
                            // 读寄存器
                            result = LCPU_REG32_READ(ra);
                        } else {
                            // 写寄存器 (默认)
                            LCPU_REG32_WRITE(ra, rd);
                            tcp_led_override = 1;  // 写操作暂停流水灯
                            result = rd;
                            gm[0] = 'w';            // 确保响应显示"写操作成功"
                        }
                        char resp[TCP_POST_RESP_BUF_SIZE];
                        build_post_response(resp, TCP_POST_RESP_BUF_SIZE, ra, result, gm);
                        uint16 rl = 0; while (resp[rl]) rl++;
                        send_http_data(idx, (const uint8 *)resp, rl);
                    } else {
                        // GET / → 返回主页面
                        uint16 pl = 0; while (main_page[pl]) pl++;
                        send_http_data(idx, (const uint8 *)main_page, pl);
                    }
                    handled = 1;
                }}}
            }

            // ---- POST 请求 ----
            else if (fc == 'P') {
                LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == 'O') { LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == 'S') { LCPU_RD_INC_ADDR();
                if (LCPU_RD_DATA8() == 'T') {
                    char fa[TCP_POST_FIELD_WIDTH+1], fd[TCP_POST_FIELD_WIDTH+1],
                         fm[TCP_POST_FIELD_WIDTH+1];

                    // 先尝试 JSON 格式，失败则回退到 form-urlencoded
                    if (!tcp_find_json_field(data_len, "addr", fa, TCP_POST_FIELD_WIDTH))
                        tcp_find_form_field(data_len, "addr", fa, TCP_POST_FIELD_WIDTH);
                    if (!tcp_find_json_field(data_len, "data", fd, TCP_POST_FIELD_WIDTH))
                        tcp_find_form_field(data_len, "data", fd, TCP_POST_FIELD_WIDTH);
                    if (!tcp_find_json_field(data_len, "mode", fm, TCP_POST_FIELD_WIDTH))
                        tcp_find_form_field(data_len, "mode", fm, TCP_POST_FIELD_WIDTH);

                    uint32 ra = read_ascii_hex_field(fa, TCP_POST_FIELD_WIDTH);
                    uint32 rd = read_ascii_hex_field(fd, TCP_POST_FIELD_WIDTH);
                    uint32 result = 0;

                    if (fm[0] == 'r' || fm[0] == 'R') {
                        // 读寄存器
                        result = LCPU_REG32_READ(ra);
                    } else {
                        // 写寄存器 (默认)
                        LCPU_REG32_WRITE(ra, rd);
                        tcp_led_override = 1;  // 暂停流水灯
                        result = rd;
                        fm[0] = 'w';
                    }

                    char resp[TCP_POST_RESP_BUF_SIZE];
                    build_post_response(resp, TCP_POST_RESP_BUF_SIZE, ra, result, fm);
                    uint16 rl = 0; while (resp[rl]) rl++;
                    send_http_data(idx, (const uint8 *)resp, rl);
                    handled = 1;
                }}}
            }

            // 无法识别的请求 → 发空 ACK 防止对端重传
            if (!handled) send_ack(idx);

            // HTTP 短连接：响应完成后直接关闭
            close_connection(idx);
        }
        break;
    }

    /* ------------------------------------------------------------
     * FIN_WAIT_1 — 本端已发 FIN，等待对方 ACK
     *   收到 ACK       → FIN_WAIT_2
     *   收到 FIN       → TIME_WAIT (同时关闭)
     * ------------------------------------------------------------ */
    case TCP_STATE_FIN_WAIT_1:
        if (flags & TCP_FLAG_FIN) {
            // 对方也发了 FIN (同时关闭)
            conn_rcv_ack[idx] = seq_num + 1;
            send_ack(idx);
            conn_timewait[idx] = LCPU_LOCAL_TIME_L();
            conn_state[idx] = TCP_STATE_TIME_WAIT;
        } else if (flags & TCP_FLAG_ACK) {
            conn_state[idx] = TCP_STATE_FIN_WAIT_2;
        }
        break;

    /* ------------------------------------------------------------
     * FIN_WAIT_2 — 已收到对方对本端 FIN 的 ACK，等待对方 FIN
     *   收到 FIN → TIME_WAIT
     * ------------------------------------------------------------ */
    case TCP_STATE_FIN_WAIT_2:
        if (flags & TCP_FLAG_FIN) {
            conn_rcv_ack[idx] = seq_num + 1;
            send_ack(idx);
            conn_timewait[idx] = LCPU_LOCAL_TIME_L();
            conn_state[idx] = TCP_STATE_TIME_WAIT;
        }
        break;

    /* ------------------------------------------------------------
     * CLOSE_WAIT — 收到对方 FIN，等待应用层关闭
     *   立即发 FIN → LAST_ACK
     * ------------------------------------------------------------ */
    case TCP_STATE_CLOSE_WAIT:
        send_fin(idx);
        conn_state[idx] = TCP_STATE_LAST_ACK;
        break;

    /* ------------------------------------------------------------
     * LAST_ACK — 已发最后 FIN，等待对方 ACK
     *   收到 ACK → CLOSED
     * ------------------------------------------------------------ */
    case TCP_STATE_LAST_ACK:
        if (flags & TCP_FLAG_ACK) close_connection(idx);
        break;

    /* ------------------------------------------------------------
     * TIME_WAIT — 主动关闭后等待 2MSL
     *   收到重复 FIN → 重发 ACK
     * ------------------------------------------------------------ */
    case TCP_STATE_TIME_WAIT:
        if (flags & TCP_FLAG_FIN) {
            conn_rcv_ack[idx] = seq_num + 1;
            send_ack(idx);
        }
        break;
    }
}

/* ================================================================
 * 第 10 部分：TCP 保洁定时器 tcp_periodic_check()
 *
 * 主循环每次迭代调用，负责：
 *   1. SYN+ACK 超时重传 (SYN_RECEIVED 状态，最多 3 次，间隔约 3 秒)
 *   2. TIME_WAIT 超时回收 (2MSL ≈ 2 秒后自动关闭)
 *   3. 空闲超时踢连接 (约 6 秒无活动 → 发 RST 关闭)
 *
 * 时间基准：LCPU_LOCAL_TIME_L() = rdcycle @ 50MHz
 * ================================================================ */
void tcp_periodic_check(void) {
    uint32 now = LCPU_LOCAL_TIME_L();
    uint8 i;

    // 遍历所有连接槽位
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        uint8 st = conn_state[i];
        if (st == TCP_STATE_CLOSED) continue;  // 跳过空闲槽位

        // 保洁 1：TIME_WAIT 超时回收
        if (st == TCP_STATE_TIME_WAIT) {
            if ((now - conn_timewait[i]) >= TCP_TIMEWAIT_TICKS) {
                close_connection(i);
            }
            continue;  // TIME_WAIT 不检查空闲超时
        }

        // 保洁 2：SYN+ACK 超时重传
        if (st == TCP_STATE_SYN_RECEIVED) {
            if (conn_syn_retry[i] < TCP_SYN_MAX_RETRIES &&
                (now - conn_tx_time[i]) >= TCP_SYN_RETRY_TICKS) {
                // 未超过最大重传次数 → 重发 SYN+ACK
                conn_syn_retry[i]++;
                conn_snd_seq[i]--;     // 回退到 ISN (重传需用原始序列号)
                send_syn_ack(i);
                conn_snd_seq[i]++;     // 恢复到 ISN+1 (ACK 校验用)
                conn_tx_time[i] = now;
            } else if (conn_syn_retry[i] >= TCP_SYN_MAX_RETRIES &&
                       (now - conn_tx_time[i]) >= TCP_SYN_RETRY_TICKS) {
                // 超过最大重传次数 → 放弃连接
                close_connection(i);
            }
            continue;
        }

        // 保洁 3：空闲超时踢连接
        if (st != TCP_STATE_TIME_WAIT) {
            if ((now - conn_activity[i]) >= TCP_IDLE_TIMEOUT_TICKS) {
                // 发 RST 通知对方连接已死亡
                send_rst(i);
                close_connection(i);
            }
        }
    }
}

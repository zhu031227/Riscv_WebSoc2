/*
 * tcp.c — TCP 发送发动机（第 1 步）
 * 功能：实现大端转换、校验和计算、发送原语
 */

#include "inc/lcpu_general.h"
#include "inc/tcp.h"
#include "inc/ip.h"

//1.网络字节转换（大端）

//把16位数字拆成高8位和低8位，存入buf[0]和buf[1]
static void tcp_write_u16_be(uint8 *buf, uint16 val) {
    buf[0] = (val >> 8) & 0xFF;
    buf[1] = val & 0xFF;
}

//把32位数字拆成4个字节，存入buf[0]到buf[3]（高8位，次高8位，次低8位，低8位）
static void tcp_write_u32_be(uint8 *buf, uint32 val) {
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] =  val & 0xFF;
}


//2.计算TCP校验和
//把字节流按16位为单位累加求和，返回累加和（奇数个字节时，最后一个字节补0）
static uint32 tcp_checksum_add_bytes(uint32 sum, const uint8 *bytes, uint16 len) {
    uint16 i;
    for (i = 0; i + 1 < len; i += 2) {
        sum +=((uint16)bytes[i] << 8) | bytes[i + 1];
    }
    if (i <len) {
        sum += (uint16)bytes[i] << 8;
    }
    return sum;
}
//例如：[0x12, 0x34, 0x56] → 加 0x1234，最后剩 0x56 当 0x5600 加


//完整 TCP 校验和（含 12 字节伪首部）

static uint16 tcp_checksum_build(
    const uint8 header[20], uint32 src_ip, uint32 dst_ip) {
    uint32 sum = 0;
    uint16 tcp_len = 20;// 没有数据载荷，只有 TCP 头


    //1. 伪首部(12个字节）
    // 包含源 IP 地址（4 字节）、目的 IP 地址（4 字节）、保留字节（1 字节，值为 0）、协议号（1 字节，TCP 为 6）、TCP 长度（2 字节，包含 TCP 头和数据长度）
    sum += (src_ip >>16) & 0xFFFF;  // 源 IP 地址高 16 位
    sum += (src_ip & 0xFFFF);       // 源 IP 地址低 16 位
    sum += (dst_ip >>16) & 0xFFFF;  // 目的 IP 地址高 16 位
    sum += (dst_ip & 0xFFFF);       // 目的 IP 地址低 16 位
    sum += (uint16)IP_PROTOCOL_TCP; // 协议号（TCP 为 6）0x06
    sum += tcp_len;                 // TCP 长度（20 字节）
    
    //2. TCP 头部（20个字节）
    sum = tcp_checksum_add_bytes(sum, header, 20);


    //3.进位回卷（直到剩16位）,“1 的补码”加法
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (uint16)(~sum);//最后取反 = 让接收端的验算逻辑变得极致简单（算出来是 0xFFFF 就绝对没问题）
}


//带数据载荷的 TCP 校验和（包含 12 字节伪首部 + TCP 头 + 数据）


static uint16 tcp_checksum_with_payload(
    const uint8 header[20], const uint8 *payload, uint16 payload_len,
    uint32 src_ip, uint32 dst_ip) {
    uint32 sum = 0;
    uint16 tcp_len = 20 + payload_len; // TCP 头 + 数据长度

    //1. 伪首部(12个字节）
    sum += (src_ip >>16) & 0xFFFF;  // 源 IP 地址高 16 位
    sum += (src_ip & 0xFFFF);       // 源 IP 地址低 16 位
    sum += (dst_ip >>16) & 0xFFFF;  // 目的 IP 地址高 16 位
    sum += (dst_ip & 0xFFFF);       // 目的 IP 地址低 16 位
    sum += (uint16)IP_PROTOCOL_TCP; // 协议号（TCP 为 6）0x06
    sum += tcp_len;                 // TCP 长度（20 字节 + 数据长度）

    //2. TCP 头部（20个字节）
    sum = tcp_checksum_add_bytes(sum, header, 20);

    //3. 数据载荷
    if(payload != NULL && payload_len > 0){
        sum = tcp_checksum_add_bytes(sum, payload, payload_len);
    }
    //4.进位回卷（直到剩16位）,“1 的补码”加法
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (uint16)(~sum);//最后取反 = 让接收端的验算逻辑变得极致简单（算出来是 0xFFFF 就绝对没问题）
}



//3.底层发送函数（把 TCP 头和数据载荷写入 LCPU 的发送缓冲区，并触发发送）
static void send_tcp_segment(const uint8 header[20]){
    uint16 i;
    uint16 tcp_start = eth_header_len + ip_header_len;  //=34

    //把 TCP 头(20 字节)写入 LCPU 的发送缓冲区fifo
    for (i = 0; i <20; i++) {
        LCPU_WR_BYTE(tcp_start + i,header[i]);
    
    
    }
    //补齐到64字节的最小帧长（以太网帧最小长度要求）并推送
    uint16 pkt_len = eth_header_len+ ip_header_len + 20 + 4; // 以太网帧最小长度要求
    if (pkt_len < 64)pkt_len = 64;
    LCPU_WR_PUSH_PACKET(pkt_len);
}



//底层发送函数2（把 TCP 头和数据载荷写入 LCPU 的发送缓冲区，并触发发送）
static void send_tcp_segment_with_payload(
    const uint8 header[20], 
    const uint8 *payload, 
    uint16 payload_len)
{
    uint16 i;
    uint16 tcp_start = eth_header_len + ip_header_len;  // =34

    // 1. 写入 TCP 头（20 字节）
    for (i = 0; i < 20; i++) {
        LCPU_WR_BYTE(tcp_start + i, header[i]);
    }

    // 2. 写入数据（如果有）
    if (payload != NULL && payload_len > 0) {
        for (i = 0; i < payload_len; i++) {
            LCPU_WR_BYTE(tcp_start + 20 + i, payload[i]);
        }
    }

    // 3. 计算总包长并补齐，触发发送
    uint16 pkt_len = eth_header_len + ip_header_len + 20 + payload_len;
    if (pkt_len < 60) pkt_len = 60;  // 以太网最小帧长（不含 CRC）
    LCPU_WR_PUSH_PACKET(pkt_len);
}


//4.连接管理（TCP 状态机、连接表、端口号、序列号、确认号等）和数据处理（HTTP 请求解析、寄存器读写等）在其他函数中实现.

/*
 * TCP 状态机常量 — 完整 7 状态版本
 *
 *                             +---------+
 *     被动打开                 |  CLOSED |  初始状态
 *        |                     +---------+
 *        | 收到 SYN                | 主动发送 SYN
 *        v                        v
 *   +-----------+          +--------------+
 *   |SYN_RECEIVED|         | SYN_SENT     | (未实现, 仅被动打开)
 *   +-----------+          +--------------+
 *        | 收到 ACK
 *        v
 *   +---------------+
 *   |  ESTABLISHED   |  数据传输
 *   +---------------+
 *        | 收到 FIN (被动关闭)
 *        v
 *   +---------------+
 *   |  CLOSE_WAIT    |  等待应用层关闭
 *   +---------------+
 *        | 发送 FIN
 *        v
 *   +---------------+
 *   |   LAST_ACK     |  等待最后 ACK
 *   +---------------+
 *        | 收到 ACK
 *        v
 *   +---------------+       +---------------+
 *   |   CLOSED       |       |  TIME_WAIT    | (主动关闭, 2s后回收)
 *   +---------------+       +---------------+
 */
#define TCP_STATE_CLOSED       0   // 初始/已关闭
#define TCP_STATE_SYN_RECEIVED 1   // 收到 SYN, 等待 ACK
#define TCP_STATE_ESTABLISHED  2   // 三次握手完成, 可传数据
#define TCP_STATE_FIN_WAIT_1   3   // 主动发 FIN, 等对方 ACK
#define TCP_STATE_FIN_WAIT_2   4   // 收到 ACK for FIN, 等对方 FIN
#define TCP_STATE_CLOSE_WAIT   5   // 收到对方 FIN, 等应用层关
#define TCP_STATE_LAST_ACK     6   // 发最后 ACK, 等对方 ACK
#define TCP_STATE_TIME_WAIT    7   // 主动关闭后等 2s 回收

/* ---- 超时常量 (rdcycle ticks @ 50MHz) ---- */
#define TCP_SYN_RETRY_TICKS     150000000UL  // SYN+ACK 重传间隔 (~3s)
#define TCP_SYN_MAX_RETRIES     3            // 最多重传 3 次
#define TCP_IDLE_TIMEOUT_TICKS  300000000UL  // 空闲超时 (~6s)
#define TCP_TIMEWAIT_TICKS      100000000UL  // TIME_WAIT 持续时间 (~2s)

/*
 * 连接变量 (单连接, static 本文件可见)
 * 连接表 = 对方 IP + 对方端口 + 我方端口 + 序列号 + 确认号 + 状态
 */
static uint8_t  tcp_state;       // 当前 TCP 状态 (0~7)
static uint32_t tcp_snd_seq;     // 我发送的序列号 (ISN + 已发字节)
static uint32_t tcp_rcv_ack;     // 期望收到的下一个序列号 (对方seq+已收)
static uint16_t tcp_src_port;    // 对方端口
static uint16_t tcp_dst_port;    // 我方监听端口
static uint32_t tcp_src_ip;      // 对方 IP

/* 全局标志: TCP 控灯时置 1, 暂停流水灯 */
uint8_t tcp_led_override = 0;

/* ---- 保洁/重传变量 ---- */
static uint32_t tcp_last_activity;   // 上次活动时间 (rdcycle)
static uint32_t tcp_last_tx_time;    // 上次发送时间
static uint8_t  tcp_syn_retries;     // SYN+ACK 重传次数
static uint32_t tcp_timewait_start;  // TIME_WAIT 开始时间



//初始化函数

void tcp_init(void) {
    tcp_state        = TCP_STATE_CLOSED;
    tcp_snd_seq      = 0;
    tcp_rcv_ack      = 0;
    tcp_src_port     = 0;
    tcp_dst_port     = 7; // 监听 7 号端口
    tcp_src_ip       = 0;
    // 保洁变量归零
    tcp_last_activity = 0;
    tcp_last_tx_time  = 0;
    tcp_syn_retries   = 0;
    tcp_timewait_start = 0;
}

// 前置声明 (步骤 1~6 全部函数)
static void send_syn_ack(void);
static void send_ack(void);
static void send_fin(void);
static void send_rst(void);
static void send_echo_packet(const uint8 *data, uint16 len);

//写接收解析器


static void tcp_parse_header(
    uint16 *src_port,// 返回：对方端口
    uint16 *dst_port,// 返回：我方端口
    uint32 *seq_num,// 返回：对方发来的序列号
    uint32 *ack_num,// 返回：对方发来的确认号
    uint8 *flags// 返回：标志位（SYN/ACK/FIN/RST）
) {
    //tcp头从以太网帧的第34字节开始（14 字节以太网头 + 20 字节 IP 头）
    uint32 tcp_off = eth_header_len + ip_header_len;

    //读源端口
    //是大端，所以先读高字节（左移 8 位），再读低字节（拼上去）
    LCPU_RD_SET_ADDR(tcp_off + 0);
    *src_port = ((uint16)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    *src_port |= LCPU_RD_DATA8();

    //读目的端口
    LCPU_RD_SET_ADDR(tcp_off + 2);
    *dst_port = ((uint16)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    *dst_port |= LCPU_RD_DATA8();

    //读序列号
    LCPU_RD_SET_ADDR(tcp_off + 4);
    *seq_num = ((uint32)LCPU_RD_DATA8() << 24);
    LCPU_RD_INC_ADDR();
    *seq_num |= ((uint32)LCPU_RD_DATA8() << 16);
    LCPU_RD_INC_ADDR();
    *seq_num |= ((uint32)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    *seq_num |= LCPU_RD_DATA8();


    //读确认号
    LCPU_RD_SET_ADDR(tcp_off + 8);
    *ack_num = ((uint32)LCPU_RD_DATA8() << 24);
    LCPU_RD_INC_ADDR();
    *ack_num |= ((uint32)LCPU_RD_DATA8() << 16);
    LCPU_RD_INC_ADDR();
    *ack_num |= ((uint32)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    *ack_num |= LCPU_RD_DATA8();
    

    //读标志位（SYN/ACK/FI
    LCPU_RD_SET_ADDR(tcp_off + 13);
    *flags = LCPU_RD_DATA8();
}

//三次握手

/*
 * TCP 三次握手状态机
 *
 *   +-----------+
 *   |  CLOSED   |  初始状态，监听 7 号端口
 *   +-----------+
 *         |
 *   收到 SYN (且无 ACK)
 *         |  记录对方 IP/端口/seq
 *         |  生成自己的初始 seq
 *         |  发送 SYN+ACK
 *         v
 *   +-------------------+
 *   |  SYN_RECEIVED     |  等待第三次握手
 *   +-------------------+
 *         |
 *   收到 ACK (且 ack == 自己的 snd_seq)
 *         |  发送纯 ACK (可选)
 *         v
 *   +-------------------+
 *   |  ESTABLISHED      |  连接建立，可以传输数据
 *   +-------------------+
 */



//TCP 处理器 状态机

void tcp_handler(void) {
    uint16 src_port, dst_port;
    uint32 seq_num, ack_num;
    uint8 flags;

    /* ---- 第 1 步：解析 TCP 头 ---- */
    tcp_parse_header(&src_port, &dst_port, &seq_num, &ack_num, &flags);

    /*
     * Step 6: RST 处理 — 收到 RST 直接重置连接
     * RST 表示对方异常终止, 无需回复, 直接关
     */
    if (flags & TCP_FLAG_RST) {
        tcp_state = TCP_STATE_CLOSED;
        tcp_init();
        return;
    }

    /* 诊断 LED: 只要进了 handler 就亮 */
    LCPU_SET_LED(0x04);

    /* ---- 端口过滤 ---- */
    if (dst_port != 7) return;

    /* 更新活动时间戳 (用于保洁定时器) */
    tcp_last_activity = LCPU_LOCAL_TIME_L();

    /* ---- 第 3 步：状态机 ---- */
    switch (tcp_state) {

    /* ================================================
     * CLOSED — 收到 SYN → 记录信息 → SYN+ACK
     * ================================================ */
    case TCP_STATE_CLOSED:
        if ((flags & TCP_FLAG_SYN) && !(flags & TCP_FLAG_ACK)) {
            tcp_src_port = src_port;
            tcp_dst_port = dst_port;
            tcp_src_ip   = src_ip;
            tcp_rcv_ack  = seq_num + 1;
            tcp_snd_seq  = LCPU_LOCAL_TIME_L();
            tcp_state    = TCP_STATE_SYN_RECEIVED;
            LCPU_SET_LED(0x01);        // LED=0x01: SYN 已收
            send_syn_ack();
        }
        break;

    /* ================================================
     * SYN_RECEIVED — 收到正确 ACK → ESTABLISHED
     * ================================================ */
    case TCP_STATE_SYN_RECEIVED:
        if ((flags & TCP_FLAG_ACK) && (ack_num == tcp_snd_seq)) {
            tcp_state = TCP_STATE_ESTABLISHED;
            tcp_syn_retries = 0;       // 复位重传计数
            LCPU_SET_LED(0x0F);        // LED=0x0F: 握手成功
            send_ack();
        }
        break;

    /* ================================================
     * ESTABLISHED — 收数据 Echo / 对方 FIN 被动关闭
     * ================================================ */
    case TCP_STATE_ESTABLISHED: {
        /* 读取 TCP 数据长度 */
        LCPU_RD_SET_ADDR(eth_header_len + 2);
        uint16 ip_total = ((uint16)LCPU_RD_DATA8() << 8);
        LCPU_RD_INC_ADDR();
        ip_total |= LCPU_RD_DATA8();

        LCPU_RD_SET_ADDR(eth_header_len);
        uint8 ver_ihl   = LCPU_RD_DATA8();
        uint8 ip_hdr_len = (ver_ihl & 0x0F) * 4;
        uint16 data_len  = ip_total - ip_hdr_len - 20;

        /* ---- 分支 1: 收到 FIN (被动关闭) ---- */
        if (flags & TCP_FLAG_FIN) {
            tcp_rcv_ack = seq_num + 1;   // FIN 消耗一个序号
            send_ack();                  // 先确认对方的 FIN
            send_fin();                  // 再发我们的 FIN
            tcp_snd_seq++;              // FIN 消耗一个序号
            tcp_state = TCP_STATE_LAST_ACK;
            LCPU_SET_LED(0x08);         // LED=0x08: 被动关闭中
        }
        /* ---- 分支 2: 收到数据 → Echo + 主动关闭 ---- */
        else if (data_len > 0 && (flags & TCP_FLAG_ACK)) {
            uint8 buf[data_len];
            uint32 data_off = eth_header_len + ip_hdr_len + 20;
            for (uint16 i = 0; i < data_len; i++) {
                LCPU_RD_SET_ADDR(data_off + i);
                buf[i] = LCPU_RD_DATA8();
            }
            /* ---- LED 控制命令 ---- */
            // 单字节命令: 0x00~0x0F 直接设 LED, 回显设置值
            // 设 tcp_led_override 标志位, 暂停流水灯
            if (data_len >= 1) {
                uint8 cmd = buf[0] & 0x0F;    // 取低 4 位
                LCPU_SET_LED(cmd);             // 设置 LED
                tcp_led_override = 1;          // 暂停流水灯
                buf[0] = cmd | 0x80;           // 回显时 bit7=1 表示已执行
            }

            tcp_rcv_ack = seq_num + data_len;
            send_echo_packet(buf, data_len);
            tcp_snd_seq += data_len;
            send_fin();                  // 命令执行后主动关
            tcp_state = TCP_STATE_FIN_WAIT_1;
        }
        break;
    }

    /* ================================================
     * FIN_WAIT_1 — 收到 ACK for FIN → FIN_WAIT_2
     *             — 收到 FIN (同时关闭) → CLOSING → TIME_WAIT
     * ================================================ */
    case TCP_STATE_FIN_WAIT_1:
        if (flags & TCP_FLAG_FIN) {
            /* 对方也发了 FIN (同时关闭) */
            tcp_rcv_ack = seq_num + 1;
            send_ack();
            tcp_timewait_start = LCPU_LOCAL_TIME_L();
            tcp_state = TCP_STATE_TIME_WAIT;
            LCPU_SET_LED(0x06);         // LED=0x06: TIME_WAIT
        } else if (flags & TCP_FLAG_ACK) {
            tcp_state = TCP_STATE_FIN_WAIT_2;
        }
        break;

    /* ================================================
     * FIN_WAIT_2 — 收到对方 FIN → TIME_WAIT
     * ================================================ */
    case TCP_STATE_FIN_WAIT_2:
        if (flags & TCP_FLAG_FIN) {
            tcp_rcv_ack = seq_num + 1;
            send_ack();
            tcp_timewait_start = LCPU_LOCAL_TIME_L();
            tcp_state = TCP_STATE_TIME_WAIT;
            LCPU_SET_LED(0x06);
        }
        break;

    /* ================================================
     * CLOSE_WAIT — 等应用层关 (本实现直接发 FIN)
     * ================================================ */
    case TCP_STATE_CLOSE_WAIT:
        send_fin();
        tcp_state = TCP_STATE_LAST_ACK;
        break;

    /* ================================================
     * LAST_ACK — 收到最后 ACK → CLOSED
     * ================================================ */
    case TCP_STATE_LAST_ACK:
        if (flags & TCP_FLAG_ACK) {
            tcp_state = TCP_STATE_CLOSED;
            tcp_init();
        }
        break;

    /* ================================================
     * TIME_WAIT — 重复 FIN 重发 ACK
     * ================================================ */
    case TCP_STATE_TIME_WAIT:
        if (flags & TCP_FLAG_FIN) {
            tcp_rcv_ack = seq_num + 1;
            send_ack();
        }
        break;

    default:
        break;
    }
}
// 发送 SYN+ACK（第二次握手）

static void send_syn_ack(void) {
    uint8 tcp_header[20] = {0};
    uint16 checksum;

    // 填充 TCP 头
    tcp_write_u16_be(&tcp_header[0], tcp_dst_port);   // 源端口（我的监听端口）
    tcp_write_u16_be(&tcp_header[2], tcp_src_port);   // 目的端口（对方端口）
    tcp_write_u32_be(&tcp_header[4], tcp_snd_seq);    // 我的序列号
    tcp_write_u32_be(&tcp_header[8], tcp_rcv_ack);    // 确认号
    tcp_header[12] = 0x50;                            // 数据偏移=5 (20字节)
    tcp_header[13] = TCP_FLAG_SYN | TCP_FLAG_ACK;     // SYN+ACK
    tcp_header[14] = 0xFF;                            // 窗口高字节
    tcp_header[15] = 0xFF;                            // 窗口低字节 (65535)

    // 计算校验和
    checksum = tcp_checksum_build(tcp_header, Local_IP_ADDR, tcp_src_ip);
    tcp_header[16] = (checksum >> 8) & 0xFF;
    tcp_header[17] = checksum & 0xFF;

    // 修改 IP 头（目的 IP → 对方 IP）
    ip_header_update(tcp_src_ip, ip_header_len + 20);

    // 发送 TCP 头
    send_tcp_segment(tcp_header);

    // ★ SYN 消耗一个序列号
    tcp_snd_seq++;
}


// 发送 ACK（确认包）

static void send_ack(void) {
    uint8 tcp_header[20] = {0};
    uint16 checksum;

    tcp_write_u16_be(&tcp_header[0], tcp_dst_port);// 源端口
    tcp_write_u16_be(&tcp_header[2], tcp_src_port);// 目的端口
    tcp_write_u32_be(&tcp_header[4], tcp_snd_seq); // 序列号
    tcp_write_u32_be(&tcp_header[8], tcp_rcv_ack);// 确认号
    tcp_header[12] = 0x50;
    tcp_header[13] = TCP_FLAG_ACK;                    // 纯 ACK
    tcp_header[14] = 0xFF;
    tcp_header[15] = 0xFF;

    checksum = tcp_checksum_build(tcp_header, Local_IP_ADDR, tcp_src_ip);
    tcp_header[16] = (checksum >> 8) & 0xFF;
    tcp_header[17] = checksum & 0xFF;

    ip_header_update(tcp_src_ip, ip_header_len + 20);
    send_tcp_segment(tcp_header);
}

//发送一个带数据的 TCP 包，用于实现 Echo 服务器（收到什么数据就原样返回）
static void send_echo_packet(const uint8 *data, uint16 len) {
    uint8 header[20] = {0};

    // 源端口 = 本地端口 (tcp_dst_port)
    tcp_write_u16_be(&header[0], tcp_dst_port);
    // 目的端口 = 对方端口 (tcp_src_port)
    tcp_write_u16_be(&header[2], tcp_src_port);
    // 序号 = 本端发送序号
    tcp_write_u32_be(&header[4], tcp_snd_seq);
    // 确认号 = 期望的下一个接收序号（已更新）
    tcp_write_u32_be(&header[8], tcp_rcv_ack);
    // 数据偏移 5，标志 ACK
    header[12] = 0x50;
    header[13] = TCP_FLAG_ACK;
    header[14] = 0xFF;
    header[15] = 0xFF;

    // 校验和：注意参数顺序为你定义的 (header, payload, payload_len, src_ip, dst_ip)
    uint16 checksum = tcp_checksum_with_payload(
        header, data, len, Local_IP_ADDR, tcp_src_ip);
    header[16] = (checksum >> 8) & 0xFF;
    header[17] = checksum & 0xFF;

    // 更新 IP 头
    ip_header_update(tcp_src_ip, ip_header_len + 20 + len);

    // 发送
    send_tcp_segment_with_payload(header, data, len);
}


//构造一个发送 FIN+ACK 报文的函数，用于主动关闭连接。
static void send_fin(void) {
    uint8 header[20] = {0};

    // 源端口 = 本地端口
    tcp_write_u16_be(&header[0], tcp_dst_port);
    // 目的端口 = 对方端口
    tcp_write_u16_be(&header[2], tcp_src_port);
    // 序号 = 本端发送序号
    tcp_write_u32_be(&header[4], tcp_snd_seq);
    // 确认号 = 期望的下一个接收序号
    tcp_write_u32_be(&header[8], tcp_rcv_ack);
    header[12] = 0x50;
    // 标志位：FIN + ACK
    header[13] = TCP_FLAG_FIN | TCP_FLAG_ACK;
    header[14] = 0xFF;
    header[15] = 0xFF;

    // 校验和（无数据）
    uint16 checksum = tcp_checksum_build(header, Local_IP_ADDR, tcp_src_ip);
    header[16] = (checksum >> 8) & 0xFF;
    header[17] = checksum & 0xFF;

    // 更新 IP 头，总长度 = IP头 + TCP头
    ip_header_update(tcp_src_ip, ip_header_len + 20);

    // 发送
    send_tcp_segment(header);

    // FIN 消耗一个序号
    tcp_snd_seq++;
}

/*
 * tcp_periodic_check — TCP 保洁定时器 (主循环每次迭代调用)
 * ==============================================================
 * 职责:
 *   1. SYN+ACK 超时重传 (SYN_RECEIVED 状态, 最多 3 次)
 *   2. 空闲超时踢连接 (所有非 CLOSED 状态, ~6s 无活动)
 *   3. TIME_WAIT 超时回收 (2s 后自动关闭)
 *
 * 调用频率: 主循环每轮调用一次 (~数 μs 间隔)
 * 时间基准: LCPU_LOCAL_TIME_L() = rdcycle @ 50MHz
 */
void tcp_periodic_check(void) {
    uint32 now = LCPU_LOCAL_TIME_L();

    /* CLOSED 状态下无需保洁 */
    if (tcp_state == TCP_STATE_CLOSED)
        return;

    /*
     * 保洁 1: TIME_WAIT 超时回收
     * 主动关闭后等 2s, 时间到 → CLOSED
     */
    if (tcp_state == TCP_STATE_TIME_WAIT) {
        if ((now - tcp_timewait_start) >= TCP_TIMEWAIT_TICKS) {
            tcp_state = TCP_STATE_CLOSED;
            tcp_init();
        }
        return;  // TIME_WAIT 不检查空闲超时
    }

    /*
     * 保洁 2: SYN+ACK 重传
     * 在 SYN_RECEIVED 状态, 每隔 ~3s 重发一次, 最多 3 次
     * 超过 3 次仍无 ACK → 放弃, 回到 CLOSED
     */
    if (tcp_state == TCP_STATE_SYN_RECEIVED) {
        if (tcp_syn_retries < TCP_SYN_MAX_RETRIES &&
            (now - tcp_last_tx_time) >= TCP_SYN_RETRY_TICKS) {
            tcp_syn_retries++;
            tcp_last_tx_time = now;
            send_syn_ack();              // 重传 SYN+ACK
            LCPU_SET_LED(0x02);         // LED=0x02: 正在重传
        }
        else if (tcp_syn_retries >= TCP_SYN_MAX_RETRIES &&
                 (now - tcp_last_tx_time) >= TCP_SYN_RETRY_TICKS) {
            /* 超过最大重传次数, 放弃连接 */
            tcp_state = TCP_STATE_CLOSED;
            tcp_init();
        }
    }

    /*
     * 保洁 3: 空闲超时踢连接
     * 除 SYN_RECEIVED 和 TIME_WAIT 外, 6s 无活动 → 发 RST 踢掉
     * 防止死连接永久占用连接槽
     */
    if (tcp_state != TCP_STATE_SYN_RECEIVED &&
        tcp_state != TCP_STATE_TIME_WAIT) {
        if ((now - tcp_last_activity) >= TCP_IDLE_TIMEOUT_TICKS) {
            /* 发 RST 让对方立刻知道连接已死 */
            send_rst();
            tcp_state = TCP_STATE_CLOSED;
            tcp_init();
        }
    }
}

/*
 * send_rst — 发送 RST+ACK 复位报文
 * 用于空闲超时踢连接时通知对方
 */
static void send_rst(void) {
    uint8 header[20] = {0};

    tcp_write_u16_be(&header[0], tcp_dst_port);
    tcp_write_u16_be(&header[2], tcp_src_port);
    tcp_write_u32_be(&header[4], tcp_snd_seq);
    tcp_write_u32_be(&header[8], tcp_rcv_ack);
    header[12] = 0x50;
    header[13] = TCP_FLAG_RST | TCP_FLAG_ACK;   // RST+ACK
    header[14] = 0x00;
    header[15] = 0x00;

    uint16 cs = tcp_checksum_build(header, Local_IP_ADDR, tcp_src_ip);
    header[16] = (cs >> 8) & 0xFF;
    header[17] = cs & 0xFF;

    ip_header_update(tcp_src_ip, ip_header_len + 20);
    send_tcp_segment(header);
}
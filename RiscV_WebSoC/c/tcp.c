/*
 * tcp_handshake.c — TCP 三次握手验证版（纯握手，无 HTTP）
 * ========================================================
 * 功能：
 *   1. 监听 7 号端口
 *   2. 收到 SYN → 记录对方信息 → 回复 SYN+ACK
 *   3. 收到 ACK → LED 全亮，三次握手完成！
 * 
 * 验证：nc -vz 169.254.1.1 7
 *        LED 0x0F 全亮 且 nc 显示 Connected
 */

#include "inc/lcpu_general.h"
#include "inc/ip.h"
#include "tcp.h"

// ==================== 配置 ====================
#define PC_IP_ADDR  0xA9FE5C15   // 改成你电脑的 IP（169.254.92.21）

// ==================== 连接表（只支持 1 个连接） ====================
static uint8_t  tcp_state;          // 0=CLOSED, 1=SYN_RCVD, 2=ESTABLISHED
static uint32_t tcp_snd_seq;        // 我的序列号
static uint32_t tcp_rcv_ack;        // 期望收到的序列号
static uint16_t tcp_src_port;       // 对方端口
static uint16_t tcp_dst_port;       // 我方监听端口
static uint32_t tcp_src_ip;         // 对方 IP

// ==================== 状态常量 ====================
#define TCP_STATE_CLOSED       0
#define TCP_STATE_SYN_RECEIVED 1
#define TCP_STATE_ESTABLISHED  2

// ==================== 1. 大端转换工具 ====================
static void tcp_write_u16_be(uint8 *buf, uint16 val) {
    buf[0] = (val >> 8) & 0xFF;
    buf[1] = val & 0xFF;
}

static void tcp_write_u32_be(uint8 *buf, uint32 val) {
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] = val & 0xFF;
}

// ==================== 2. 校验和 ====================
static uint32 tcp_checksum_add_bytes(uint32 sum, const uint8 *bytes, uint16 len) {
    uint16 i;
    for (i = 0; i + 1 < len; i += 2) {
        sum += ((uint16)bytes[i] << 8) | bytes[i + 1];
    }
    if (i < len) {
        sum += (uint16)bytes[i] << 8;
    }
    return sum;
}

static uint16 tcp_checksum_build(const uint8 header[20], uint32 src_ip, uint32 dst_ip) {
    uint32 sum = 0;
    uint16 tcp_len = 20;

    // ★ 伪首部（12 字节）
    sum += (src_ip >> 16) & 0xFFFF;
    sum += src_ip & 0xFFFF;
    sum += (dst_ip >> 16) & 0xFFFF;
    sum += dst_ip & 0xFFFF;
    sum += (uint16)IP_PROTOCOL_TCP;
    sum += tcp_len;

    // ★ TCP 头
    sum = tcp_checksum_add_bytes(sum, header, 20);

    // ★ 进位回卷 + 取反
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (uint16)(~sum);
}

// ==================== 3. 发送函数 ====================

// 发送 SYN+ACK
static void send_syn_ack(void) {
    uint8 tcp_header[20] = {0};
    uint16 checksum;

    // 填充 TCP 头
    tcp_write_u16_be(&tcp_header[0], tcp_dst_port);   // 源端口（我的监听端口）
    tcp_write_u16_be(&tcp_header[2], tcp_src_port);   // 目的端口（对方端口）
    tcp_write_u32_be(&tcp_header[4], tcp_snd_seq);    // 我的序列号
    tcp_write_u32_be(&tcp_header[8], tcp_rcv_ack);    // 确认号 = 收到的 Seq + 1
    tcp_header[12] = 0x50;                            // 数据偏移=5 (20字节)
    tcp_header[13] = TCP_FLAG_SYN | TCP_FLAG_ACK;     // ★ SYN+ACK
    tcp_header[14] = 0xFF;                            // 窗口 65535
    tcp_header[15] = 0xFF;

    // 计算校验和
    checksum = tcp_checksum_build(tcp_header, Local_IP_ADDR, tcp_src_ip);
    tcp_header[16] = (checksum >> 8) & 0xFF;
    tcp_header[17] = checksum & 0xFF;

    // ★ 调用 IP 层修改 IP 头（目的 IP = 对方 IP）
    ip_header_update(tcp_src_ip, ip_header_len + 20);

    // ★ 写 TCP 头到 TX FIFO（偏移 34）
    uint16 tcp_start = eth_header_len + ip_header_len;
    for (int i = 0; i < 20; i++) {
        LCPU_WR_BYTE(tcp_start + i, tcp_header[i]);
    }

    // ★ 补齐 64 字节并发送
    uint16 pkt_len = eth_header_len + ip_header_len + 20 + 4;
    if (pkt_len < 64) pkt_len = 64;
    LCPU_WR_PUSH_PACKET(pkt_len);

    // ★ SYN 消耗一个序列号
    tcp_snd_seq++;
}

// 发送 ACK
static void send_ack(void) {
    uint8 tcp_header[20] = {0};
    uint16 checksum;

    tcp_write_u16_be(&tcp_header[0], tcp_dst_port);
    tcp_write_u16_be(&tcp_header[2], tcp_src_port);
    tcp_write_u32_be(&tcp_header[4], tcp_snd_seq);
    tcp_write_u32_be(&tcp_header[8], tcp_rcv_ack);
    tcp_header[12] = 0x50;
    tcp_header[13] = TCP_FLAG_ACK;                    // ★ 纯 ACK
    tcp_header[14] = 0xFF;
    tcp_header[15] = 0xFF;

    checksum = tcp_checksum_build(tcp_header, Local_IP_ADDR, tcp_src_ip);
    tcp_header[16] = (checksum >> 8) & 0xFF;
    tcp_header[17] = checksum & 0xFF;

    ip_header_update(tcp_src_ip, ip_header_len + 20);

    uint16 tcp_start = eth_header_len + ip_header_len;
    for (int i = 0; i < 20; i++) {
        LCPU_WR_BYTE(tcp_start + i, tcp_header[i]);
    }

    uint16 pkt_len = eth_header_len + ip_header_len + 20 + 4;
    if (pkt_len < 64) pkt_len = 64;
    LCPU_WR_PUSH_PACKET(pkt_len);
}

// ==================== 4. TCP 包处理器 ====================
void tcp_handshake_handler(void) {
    uint16 src_port, dst_port;
    uint32 seq_num, ack_num;
    uint8 flags;

    uint32 tcp_off = eth_header_len + ip_header_len;

    // --- 读取 TCP 头 ---
    LCPU_RD_SET_ADDR(tcp_off + 0);
    src_port  = ((uint16)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    src_port |= LCPU_RD_DATA8();

    LCPU_RD_SET_ADDR(tcp_off + 2);
    dst_port  = ((uint16)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    dst_port |= LCPU_RD_DATA8();

    LCPU_RD_SET_ADDR(tcp_off + 4);
    seq_num  = ((uint32)LCPU_RD_DATA8() << 24);
    LCPU_RD_INC_ADDR();
    seq_num |= ((uint32)LCPU_RD_DATA8() << 16);
    LCPU_RD_INC_ADDR();
    seq_num |= ((uint32)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    seq_num |= LCPU_RD_DATA8();

    LCPU_RD_SET_ADDR(tcp_off + 8);
    ack_num  = ((uint32)LCPU_RD_DATA8() << 24);
    LCPU_RD_INC_ADDR();
    ack_num |= ((uint32)LCPU_RD_DATA8() << 16);
    LCPU_RD_INC_ADDR();
    ack_num |= ((uint32)LCPU_RD_DATA8() << 8);
    LCPU_RD_INC_ADDR();
    ack_num |= LCPU_RD_DATA8();

    LCPU_RD_SET_ADDR(tcp_off + 13);
    flags = LCPU_RD_DATA8();

    // ★ 只监听 7 号端口
    if (dst_port != 7) return;

    // --- 状态机 ---
    if (tcp_state == TCP_STATE_CLOSED) {
        // ★ 第一次握手：收到 SYN
        if ((flags & TCP_FLAG_SYN) && !(flags & TCP_FLAG_ACK)) {
            tcp_src_port = src_port;
            tcp_dst_port = dst_port;
            tcp_src_ip   = src_ip;          // src_ip 由 ip_proc 解析好了
            tcp_rcv_ack  = seq_num + 1;     // 期望对方下次发 seq+1
            tcp_snd_seq  = LCPU_LOCAL_TIME_L(); // 随机 ISN

            tcp_state = TCP_STATE_SYN_RECEIVED;
            LCPU_SET_LED(0x01);  // ★ 收到 SYN，亮 LED0

            send_syn_ack();      // ★ 第二次握手：回复 SYN+ACK
        }
    }
    else if (tcp_state == TCP_STATE_SYN_RECEIVED) {
        // ★ 第三次握手：收到 ACK
        if (flags & TCP_FLAG_ACK) {
            // 校验确认号是否正确
            if (ack_num == tcp_snd_seq) {
                tcp_state = TCP_STATE_ESTABLISHED;
                LCPU_SET_LED(0x0F);  // ★ 全亮！三次握手成功！
            }
        }
    }
    else if (tcp_state == TCP_STATE_ESTABLISHED) {
        // 已建立，保持连接（收到任何包都回复 ACK）
        if (flags & TCP_FLAG_ACK) {
            tcp_rcv_ack = seq_num + 1;
            send_ack();
        }
    }
}

// ==================== 5. 初始化函数 ====================
void tcp_handshake_init(void) {
    tcp_state = TCP_STATE_CLOSED;
    tcp_snd_seq = 0;
    tcp_rcv_ack = 0;
    tcp_src_port = 0;
    tcp_dst_port = 7;  // 默认监听 7 号端口
    tcp_src_ip = 0;
}
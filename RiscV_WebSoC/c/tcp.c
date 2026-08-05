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


//4.连接管理（TCP 状态机、连接表、端口号、序列号、确认号等）和数据处理（HTTP 请求解析、寄存器读写等）在其他函数中实现.

//状态常量
#define TCP_STATE_CLOSED       0//还没握手
#define TCP_STATE_SYN_RECEIVED 1//收到 SYN，等待 ACK
#define TCP_STATE_ESTABLISHED  2//连接已建立 ，三次握手完成

//连接变量 （只支持1个连接，用static表示本文件可见

static uint8_t  tcp_state;  //当前状态012
static uint32_t tcp_snd_seq; //我发送出去的序列号
static uint32_t tcp_rcv_ack; //我期望收到的下一个序列号（对方发送过来的序列号+1）

//对方的SEQ + 1

static uint16_t tcp_src_port; //对方的pc的端口
static uint16_t tcp_dst_port; //我方监听的端口
static uint32_t tcp_src_ip;   //对方的pc的ip



//初始化函数

void tcp_init(void) {
    tcp_state = TCP_STATE_CLOSED;
    tcp_snd_seq = 0;
    tcp_rcv_ack = 0;
    tcp_src_port = 0;
    tcp_dst_port = 7;//监听7号端口
    tcp_src_ip = 0;
}

// 前置声明
static void send_syn_ack(void);
static void send_ack(void);

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

    // 第 1 步：调用接收解析器，读出 TCP 头
    tcp_parse_header(&src_port, &dst_port, &seq_num, &ack_num, &flags);

    // ★ 诊断：只要进 TCP handler 就亮 LED2，确认 TCP 包能进来
    LCPU_SET_LED(0x04);

    // 第 2 步：只处理发往 7 号端口的包
    // 这样 `nc -vz 169.254.1.1 7` 才能触发我们的代码
    if (dst_port != 7) return;

    // 第 3 步：状态机
    if (tcp_state == TCP_STATE_CLOSED) {
        // 收到 SYN（第一次握手）
        if ((flags & TCP_FLAG_SYN) && !(flags & TCP_FLAG_ACK)) {
            //  记录对方信息到连接表
            tcp_src_port = src_port;
            tcp_dst_port = dst_port;
            tcp_src_ip = src_ip;            // src_ip 由 ip_proc 提前解析好了
            tcp_rcv_ack = seq_num + 1;      // 期望下次发 seq+1
            tcp_snd_seq = LCPU_LOCAL_TIME_L(); // 随机初始序列号

            tcp_state = TCP_STATE_SYN_RECEIVED;

            // 亮 LED0，表示“收到 SYN，已记录”
            LCPU_SET_LED(0x01);

            // ★ 新增：回复 SYN+ACK（第二次握手）
            send_syn_ack();
        }
    }
    else if (tcp_state == TCP_STATE_SYN_RECEIVED) {
        // 收到 ACK（第三次握手）
        if (flags & TCP_FLAG_ACK) {
            // 检查确认号是否正确
            if (ack_num == tcp_snd_seq) {
                tcp_state = TCP_STATE_ESTABLISHED;
                LCPU_SET_LED(0x0F);  // ★ 全亮！三次握手成功！

                // ★ 新增：回复 ACK（确认三次握手完成）
                send_ack();
            }
        }
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
    tcp_write_u32_be(&tcp_header[4], tcp_snd_seq);// 序列号
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
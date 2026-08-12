/*
 * mock_lcpu.h — x86 单元测试 mock 层
 * 替换 lcpu_general.h 中的 RISC-V 硬件依赖
 * 编译时 -include 此文件, 再 include lcpu_general.h 时跳过硬编码定义
 */
#ifndef MOCK_LCPU_H
#define MOCK_LCPU_H

#include <stdint.h>
#include <stdio.h>

/* ---- 基本类型 (匹配固件) ---- */
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef char           int8;
typedef short          int16;
typedef int            int32;

/* ---- Mock 硬件寄存器访问 ---- */
uint32_t mock_reg[256];
#define LCPU_BASE  0  /* x86 上不关心地址 */
#define LCPU_REG32_WRITE(wa, d)  do { mock_reg[(wa)&0xFF] = (d); } while(0)
#define LCPU_REG32_READ(wa)      (mock_reg[(wa)&0xFF])

/* ---- Mock LED ---- */
#define LCPU_SET_LED(v)  do { printf("  [LED]=0x%x\n", (v)&0xF); } while(0)

/* ---- Mock 定时器 (替换 rdcycle) ---- */
static inline uint32 LCPU_LOCAL_TIME_L(void) {
    static uint32 t = 0; return t++;
}

/* ---- SIM_FAST: RX/TX FIFO 走内存 buffer ---- */
extern uint8   sim_tx_buf[2048];
extern uint16  sim_tx_addr;
extern uint16  sim_tx_pkt_len;
extern uint8  *sim_rx_buf_ptr;
extern uint16  sim_rx_buf_len;
extern uint16  sim_rx_addr;

/* ---- 网络配置 ---- */
#define Local_MAC_HIGH   0x00000102
#define Local_MAC_LOW    0x0405
#define Local_IP_ADDR    0xA9FE0101  /* 169.254.1.1 */

/* ---- 协议常量 ---- */
#define eth_header_len   14
#define ip_header_len    20
#define tcp_header_len   20

#define OFF_ETH_DST_MAC   0
#define OFF_ETH_SRC_MAC   6
#define OFF_ETH_TYPE      12
#define OFF_IP_VER_IHL    (eth_header_len+0)
#define OFF_IP_TOTAL_LEN  (eth_header_len+2)
#define OFF_IP_TTL        (eth_header_len+8)
#define OFF_IP_PROTO      (eth_header_len+9)
#define OFF_IP_CHECKSUM   (eth_header_len+10)
#define OFF_IP_SRC_IP     (eth_header_len+12)
#define OFF_IP_DST_IP     (eth_header_len+16)
#define OFF_TCP_SRC_PORT  (eth_header_len+ip_header_len+0)
#define OFF_TCP_DST_PORT  (eth_header_len+ip_header_len+2)
#define OFF_TCP_SEQ_NUM   (eth_header_len+ip_header_len+4)
#define OFF_TCP_ACK_NUM   (eth_header_len+ip_header_len+8)
#define OFF_TCP_DATA_OFS  (eth_header_len+ip_header_len+12)
#define OFF_TCP_FLAGS     (eth_header_len+ip_header_len+13)
#define OFF_TCP_WINDOW    (eth_header_len+ip_header_len+14)
#define OFF_TCP_CHECKSUM  (eth_header_len+ip_header_len+16)
#define OFF_TCP_PAYLOAD   (eth_header_len+ip_header_len+tcp_header_len)

#define IP_OFS_TOTAL_LEN  2
#define IP_OFS_PROTO      9
#define IP_OFS_CHECKSUM   10
#define IP_OFS_SRC_IP     12
#define IP_OFS_DST_IP     16

#define OFF_ARP_HTYPE      14
#define OFF_ARP_PTYPE      16
#define OFF_ARP_HLEN       18
#define OFF_ARP_PLEN       19
#define OFF_ARP_OPCODE     20
#define OFF_ARP_SENDER_MAC 22
#define OFF_ARP_SENDER_IP  28
#define OFF_ARP_TARGET_MAC 32
#define OFF_ARP_TARGET_IP  38

#define ETH_TYPE_IP   0x0800
#define ETH_TYPE_ARP  0x0806
#define IP_PROTOCOL_ICMP  0x01
#define IP_PROTOCOL_UDP   0x11
#define IP_PROTOCOL_TCP   0x06
#define ARP_REQUEST     0x0001
#define ICMP_REQUEST    0x08
#define HTTP_PORT  80

#define NO_PROC     0x0000
#define ARP_PROC    0x0001
#define IP_PROC     0x1000
#define ICMP_PROC   0x1100
#define TCP_PROC    0x1200
#define HTTP_PROC   0x1201
#define UDP_PROC    0x1300

#define TCP_TIMEWAIT_TICKS      100000000u
#define TCP_IDLE_TIMEOUT_TICKS  2000000000u
#define TCP_SYN_RETRY_TICKS     150000000u
#define TCP_SYN_MAX_RETRIES     3

/* ---- SIM_FAST: RX/TX FIFO 宏替换 ---- */
#define LCPU_RD_EMPTY()         0
#define LCPU_RD_START_PACKET()  do {} while (0)
#define LCPU_RD_PKT_LEN()       sim_rx_buf_len
#define LCPU_RD_SET_ADDR(addr)  do { sim_rx_addr = (uint16)(addr); } while (0)
#define LCPU_RD_INC_ADDR()      do { sim_rx_addr++; } while (0)
#define LCPU_RD_DATA8()         (sim_rx_buf_ptr[sim_rx_addr])

#define LCPU_WR_SET_ADDR(addr)  do { sim_tx_addr = (uint16)(addr); } while (0)
#define LCPU_WR_SET_DATA(data)  do { sim_tx_buf[sim_tx_addr] = (uint8)(data); } while (0)
#define LCPU_WR_PULSE_WEN()     do {} while (0)
#define LCPU_WR_BYTE(addr, data) do { sim_tx_buf[(uint16)(addr)] = (uint8)(data); } while (0)
#define LCPU_WR_PUSH_PACKET(pkt_len) do { sim_tx_pkt_len = (uint16)(pkt_len); } while (0)
#define LCPU_WR_TEST_ENABLE()   (0)

/* 给 arp.c 用的 _RD(1)=1 简化 */
#define _RD(n) (mock_reg[n])  /* 不用于 RX, 只是消编译错误 */

#endif

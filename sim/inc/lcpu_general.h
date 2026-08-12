/* mock_lcpu.h — 抢先定义 _LCPU_GEN_H_ 阻止真实 lcpu_general.h */
#ifndef _LCPU_GEN_H_
#define _LCPU_GEN_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef char           int8;
typedef short          int16;
typedef int            int32;

extern uint32_t mock_reg[256];
#define LCPU_BASE  0

static inline uint32 LCPU_LOCAL_TIME_L(void) { static uint32 t=0; return t++; }
#define LCPU_REG32_WRITE(wa,d) do{mock_reg[(wa)&0xFF]=(d);}while(0)
#define LCPU_REG32_READ(wa)    (mock_reg[(wa)&0xFF])
#define LCPU_SET_LED(v)        do{printf("  [LED]=0x%x\n",(v)&0xF);}while(0)

extern uint8  sim_tx_buf[2048];
extern uint16 sim_tx_addr;
extern uint16 sim_tx_pkt_len;
extern uint8 *sim_rx_buf_ptr;
extern uint16 sim_rx_buf_len;
extern uint16 sim_rx_addr;

#define Local_MAC_HIGH 0x00000102
#define Local_MAC_LOW  0x0405
#define Local_IP_ADDR  0xA9FE0101
#define eth_header_len 14
#define ip_header_len  20
#define tcp_header_len 20
#define OFF_ETH_DST_MAC 0
#define OFF_ETH_SRC_MAC 6
#define OFF_ETH_TYPE    12
#define OFF_IP_VER_IHL  14
#define OFF_IP_TOTAL_LEN 16
#define OFF_IP_PROTO    23
#define OFF_IP_CHECKSUM 24
#define OFF_IP_SRC_IP   26
#define OFF_IP_DST_IP   30
#define OFF_TCP_PAYLOAD 54
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
#define IP_PROTOCOL_ICMP 0x01
#define IP_PROTOCOL_UDP  0x11
#define IP_PROTOCOL_TCP  0x06
#define ARP_REQUEST    0x0001
#define ICMP_REQUEST   0x08
#define HTTP_PORT      80
#define NO_PROC   0x0000
#define ARP_PROC  0x0001
#define IP_PROC   0x1000
#define ICMP_PROC 0x1100
#define TCP_PROC  0x1200
#define UDP_PROC  0x1300
#define TCP_TIMEWAIT_TICKS      100000000u
#define TCP_IDLE_TIMEOUT_TICKS  2000000000u
#define TCP_SYN_RETRY_TICKS     150000000u
#define TCP_SYN_MAX_RETRIES     3

#define LCPU_RD_EMPTY()          0
#define LCPU_RD_START_PACKET()   do{}while(0)
#define LCPU_RD_PKT_LEN()        sim_rx_buf_len
#define LCPU_RD_SET_ADDR(a)      do{sim_rx_addr=(uint16)(a);}while(0)
#define LCPU_RD_INC_ADDR()       do{sim_rx_addr++;}while(0)
#define LCPU_RD_DATA8()          (sim_rx_buf_ptr[sim_rx_addr])
#define LCPU_WR_BYTE(a,d)        do{sim_tx_buf[(uint16)(a)]=(uint8)(d);}while(0)
#define LCPU_WR_PUSH_PACKET(l)   do{sim_tx_pkt_len=(uint16)(l);}while(0)
#define _RD(n)                   (mock_reg[n])
#define _WR(n)                   (mock_reg[n])
#define LCPU_WR_SET_ADDR(a)      do{sim_tx_addr=(uint16)(a);}while(0)
#define LCPU_WR_SET_DATA(d)      do{sim_tx_buf[sim_tx_addr]=(uint8)(d);}while(0)
#define LCPU_WR_PULSE_WEN()      do{}while(0)
extern uint32 src_ip;
extern uint16 ip_total_len;

#endif

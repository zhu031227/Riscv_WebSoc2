/*
 * test_arp.c — ARP 协议 x86 原生单元测试
 * 编译: cd sim && gcc -DSIM_FAST -include inc/lcpu_general.h -I. -I../c/inc -I../c \
 *   -o test_arp test_arp.c ../c/eth.c ../c/arp.c && ./test_arp
 *
 * 覆盖 ARP 协议知识点的逐字节断言:
 *   Case 1  正常 ARP 请求(广播, 问 169.254.1.1) → 应答帧 14 个字段逐一核对
 *   Case 2  问的是别人的 IP → 不应答
 *   Case 3  收到 ARP Reply → 不应答 (防循环)
 *   Case 4  目的 MAC 非本机非广播 → 不应答
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Mock 寄存器 + SIM_FAST 全局 (与 test_http.c 一致的注入方式) */
uint32_t mock_reg[256];
uint8_t  sim_tx_buf[2048];
uint16_t sim_tx_addr;
uint16_t sim_tx_pkt_len;
uint8_t *sim_rx_buf_ptr;
uint16_t sim_rx_buf_len;
uint16_t sim_rx_addr;

/* 固件 extern */
uint16_t eth_proc(void);
void arp_reply(void);

static int pass, fail;
#define CHECK(n,c) do{ if(c){printf("  PASS: %s\n",n);pass++;}\
    else{printf("  FAIL: %s\n",n);fail++;}}while(0)

/* ── 模拟请求方 PC ── */
static const uint8_t PC_MAC_B[6] = {0x9c,0x2d,0xcd,0xac,0x8f,0xa4};
#define PC_IP 0xA9FE5C15u          /* 169.254.92.21 */

/* ── 本机 (与 lcpu_general.h 一致) ── */
static const uint8_t LOCAL_MAC_B[6] = {0x00,0x00,0x01,0x02,0x04,0x05};
#define LOCAL_IP 0xA9FE0101u        /* 169.254.1.1 */

/* 构造 ARP 帧 (广播或非本机单播目的, 补零到 64) */
static void build_arp(uint8_t *pkt, uint32_t target_ip, uint16_t opcode, int unicast_dst) {
    int i;
    for (i = 0; i < 256; i++) pkt[i] = 0;
    if (unicast_dst) { /* 非本机单播 */
        pkt[0]=0x00;pkt[1]=0x11;pkt[2]=0x22;pkt[3]=0x33;pkt[4]=0x44;pkt[5]=0x55;
    } else {           /* 广播 */
        pkt[0]=0xFF;pkt[1]=0xFF;pkt[2]=0xFF;pkt[3]=0xFF;pkt[4]=0xFF;pkt[5]=0xFF;
    }
    for (i = 0; i < 6; i++) pkt[6+i] = PC_MAC_B[i];
    pkt[12]=0x08;pkt[13]=0x06;                    /* 以太类型 ARP */
    pkt[14]=0x00;pkt[15]=0x01;                    /* 硬件类型 Ethernet */
    pkt[16]=0x08;pkt[17]=0x00;                    /* 协议类型 IPv4 */
    pkt[18]=0x06;                                 /* HLEN */
    pkt[19]=0x04;                                 /* PLEN */
    pkt[20]=(opcode>>8)&0xFF;pkt[21]=opcode&0xFF; /* 操作码 */
    for (i = 0; i < 6; i++) pkt[22+i] = PC_MAC_B[i];      /* 发送方 MAC */
    pkt[28]=(PC_IP>>24)&0xFF;pkt[29]=(PC_IP>>16)&0xFF;    /* 发送方 IP */
    pkt[30]=(PC_IP>>8)&0xFF; pkt[31]=PC_IP&0xFF;
    /* 目标 MAC = 0 (请求方不知道) */
    pkt[38]=(target_ip>>24)&0xFF;pkt[39]=(target_ip>>16)&0xFF;  /* 目标 IP */
    pkt[40]=(target_ip>>8)&0xFF; pkt[41]=target_ip&0xFF;
}

/* 注入一帧并跑 eth→arp 链, 返回 eth_proc 结果 */
static uint16_t inject(uint8_t *pkt, uint16_t len) {
    sim_rx_buf_ptr = pkt; sim_rx_buf_len = len; sim_rx_addr = 0; sim_tx_pkt_len = 0;
    uint16_t pt = eth_proc();
    if (pt == ARP_PROC) arp_reply();
    return pt;
}

/* 字节序: 从 uint32 取大端字节 i (0=最高位) */
static uint8_t be32(uint32_t v, int i) { return (uint8_t)((v >> (24 - i*8)) & 0xFF); }

int main(void) {
    printf("=== ARP x86 Unit Test ===\n\n");
    uint8_t pkt[256];
    uint16_t pt;
    int i, ok;

    /* ══ Case 1: 正常 ARP 请求 (广播, 问 169.254.1.1) → 应答, 逐字节核对 ══ */
    printf("--- Case 1: ARP Request for our IP → Reply ---\n");
    build_arp(pkt, LOCAL_IP, 0x0001, 0);
    pt = inject(pkt, 64);
    CHECK("eth_proc() 返回 ARP_PROC", pt == ARP_PROC);
    CHECK("应答帧长度 = 64 (补零到最小帧)", sim_tx_pkt_len == 64);

    ok=1; for (i=0;i<6;i++) if(sim_tx_buf[i]!=PC_MAC_B[i]) ok=0;
    CHECK("TX[0..5]  目的MAC = 请求方MAC", ok);
    ok=1; for (i=0;i<6;i++) if(sim_tx_buf[6+i]!=LOCAL_MAC_B[i]) ok=0;
    CHECK("TX[6..11] 源MAC   = 本机MAC", ok);
    CHECK("TX[12..13] 以太类型 = 0x0806", sim_tx_buf[12]==0x08 && sim_tx_buf[13]==0x06);
    CHECK("TX[14..15] 硬件类型 = 0x0001", sim_tx_buf[14]==0x00 && sim_tx_buf[15]==0x01);
    CHECK("TX[16..17] 协议类型 = 0x0800", sim_tx_buf[16]==0x08 && sim_tx_buf[17]==0x00);
    CHECK("TX[18] HLEN = 6", sim_tx_buf[18]==0x06);
    CHECK("TX[19] PLEN = 4", sim_tx_buf[19]==0x04);
    CHECK("TX[20..21] 操作码 = 0x0002 (Reply)", sim_tx_buf[20]==0x00 && sim_tx_buf[21]==0x02);
    ok=1; for (i=0;i<6;i++) if(sim_tx_buf[22+i]!=LOCAL_MAC_B[i]) ok=0;
    CHECK("TX[22..27] 发送方MAC = 本机MAC", ok);
    ok=1; for (i=0;i<4;i++) if(sim_tx_buf[28+i]!=be32(LOCAL_IP,i)) ok=0;
    CHECK("TX[28..31] 发送方IP  = 本机IP 169.254.1.1", ok);
    ok=1; for (i=0;i<6;i++) if(sim_tx_buf[32+i]!=PC_MAC_B[i]) ok=0;
    CHECK("TX[32..37] 目标MAC = 请求方MAC", ok);
    ok=1; for (i=0;i<4;i++) if(sim_tx_buf[38+i]!=be32(PC_IP,i)) ok=0;
    CHECK("TX[38..41] 目标IP  = 请求方IP", ok);
    ok=1; for (i=42;i<64;i++) if(sim_tx_buf[i]!=0) ok=0;
    CHECK("TX[42..63] 补零", ok);

    /* ══ Case 2: 问的是别人的 IP → 不应答 ══ */
    printf("--- Case 2: ARP Request for other IP → no reply ---\n");
    build_arp(pkt, 0xC0A80101u, 0x0001, 0);   /* 192.168.1.1 */
    inject(pkt, 64);
    CHECK("无应答 (TX 长度=0)", sim_tx_pkt_len == 0);

    /* ══ Case 3: 收到 ARP Reply → 不应答 (防回环) ══ */
    printf("--- Case 3: ARP Reply received → no reply ---\n");
    build_arp(pkt, LOCAL_IP, 0x0002, 0);      /* 操作码 = Reply */
    inject(pkt, 64);
    CHECK("无应答 (TX 长度=0)", sim_tx_pkt_len == 0);

    /* ══ Case 4: 目的 MAC 非本机非广播 → 不应答 ══ */
    printf("--- Case 4: unicast dst not ours → no reply ---\n");
    build_arp(pkt, LOCAL_IP, 0x0001, 1);      /* 单播非本机 */
    inject(pkt, 64);
    CHECK("无应答 (TX 长度=0)", sim_tx_pkt_len == 0);

    printf("\n=== %d PASS, %d FAIL ===\n", pass, fail);
    return fail ? 1 : 0;
}

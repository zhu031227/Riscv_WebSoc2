/*
 * main.c — RISC-V Ping 应答主程序
 * ====================================
 * 功能：系统入口 + LED 心跳 + 主循环（ARP/ICMP 协议分发）
 *
 * 数据流：
 *   PC ping → 以太网帧 → RX FIFO → eth_proc(解析以太类型)
 *   → ARP? → arp_reply(ARP应答)
 *   → IP?  → ip_proc(解析IP头) → ICMP? → icmp_reply(Ping应答)
 *                               → TCP?  → tcp_packet_handler(TCP处理)
 *   → TX FIFO → 以太网帧 → PC
 *
 * FIFO 访问规则（与原项目一致）：
 *   1. 永远不关 REN（读使能保持为 1）
 *   2. 每帧 POP 两次：头部 POP 取出包数据，尾部 POP 推进到下一包
 *   3. 直接从 RX FIFO 读写，不使用内存缓冲区
 */

#include "inc/lcpu_general.h"
#include "inc/system.h"
#include "inc/eth.h"
#include "inc/arp.h"
#include "inc/ip.h"
#include "inc/icmp.h"
#include "inc/tcp.h"

/* ---- CPU 复位入口：上电后 PC=0，跳转至 program_main ---- */
__attribute__((naked, used, section(".text.bootloader")))
void reset_entry() {
    asm volatile("j program_main\n");
}

int main() {
    program_main();
    return 0;
}

void program_main() {
    /* ---- LED 上电自检 ---- */
#ifdef SIM_FAST
    LCPU_SET_LED(0x0F);
    LCPU_SET_LED(0x00);
#else
    LCPU_SET_LED(0x0F);
#ifndef SIM_SKIP_DELAY
    volatile uint32 dly = 5000000;
    while (dly--) { asm volatile("nop"); }
#endif
    LCPU_SET_LED(0x00);
#endif

    /* ---- TCP 初始化 ---- */
    tcp_init();

#ifdef SIM_FAST
    /* ====== SIM_FAST HTTP 自测 (跳过硬件, 直接验证协议栈) ====== */
    {
        extern uint8  *sim_rx_buf_ptr;
        extern uint16  sim_rx_buf_len;
        extern uint16  sim_rx_addr;
        extern uint8   sim_tx_buf[128];
        extern uint16  sim_tx_pkt_len;

        uint8 pkt[128]; uint8 i;

        // ---- Phase 1: TCP SYN (54 bytes) ----
        for(i=0;i<128;i++) pkt[i]=0;
        pkt[0]=0x00;pkt[1]=0x00;pkt[2]=0x01;pkt[3]=0x02;pkt[4]=0x04;pkt[5]=0x05;
        pkt[6]=0x9c;pkt[7]=0x2d;pkt[8]=0xcd;pkt[9]=0xac;pkt[10]=0x8f;pkt[11]=0xa4;
        pkt[12]=0x08;pkt[13]=0x00; // EtherType=IPv4
        pkt[14]=0x45;pkt[15]=0x00;pkt[16]=0x00;pkt[17]=0x28;
        pkt[18]=0x00;pkt[19]=0x01;pkt[20]=0x40;pkt[21]=0x00;
        pkt[22]=0x40;pkt[23]=0x06;pkt[24]=0x00;pkt[25]=0x00;
        pkt[26]=0xa9;pkt[27]=0xfe;pkt[28]=0x5c;pkt[29]=0x15;
        pkt[30]=0xa9;pkt[31]=0xfe;pkt[32]=0x01;pkt[33]=0x01;
        pkt[34]=0x30;pkt[35]=0x39;pkt[36]=0x00;pkt[37]=0x50; // port 12345→80
        pkt[38]=0x05;pkt[39]=0x85;pkt[40]=0x2e;pkt[41]=0xa5;
        pkt[46]=0x50;pkt[47]=0x02; // SYN
        pkt[48]=0xfa;pkt[49]=0xf0;

        sim_rx_buf_ptr = pkt; sim_rx_buf_len = 54; sim_rx_addr = 0;
        sim_tx_pkt_len = 0;
        uint16 pt = eth_proc();
        if (pt == IP_PROC) { uint16 it = ip_proc(); if (it == TCP_PROC) tcp_handler(); }
        if (sim_tx_pkt_len == 0) LCPU_SET_LED(0x0E); // FAIL: no SYN+ACK

        // Phase 2: ACK → ESTABLISHED
        uint32 isn = (sim_tx_buf[38]<<24)|(sim_tx_buf[39]<<16)|(sim_tx_buf[40]<<8)|sim_tx_buf[41];
        pkt[38]=0x05;pkt[39]=0x85;pkt[40]=0x2e;pkt[41]=0xa6; // PC seq=ISN+1
        pkt[42]=((isn+1)>>24)&0xFF;pkt[43]=((isn+1)>>16)&0xFF;
        pkt[44]=((isn+1)>>8)&0xFF; pkt[45]=(isn+1)&0xFF;
        pkt[47]=0x10; // ACK only
        sim_rx_buf_ptr = pkt; sim_rx_buf_len = 54; sim_rx_addr = 0;
        pt = eth_proc(); if (pt == IP_PROC) { uint16 it = ip_proc(); if (it == TCP_PROC) tcp_handler(); }

        // Phase 3: HTTP GET
        for(i=54;i<128;i++) pkt[i]=0;
        pkt[16]=0x00;pkt[17]=0x62; // total_len=98
        pkt[47]=0x18; // PSH|ACK
        const char *http = "GET / HTTP/1.1\r\nHost: 169.254.1.1\r\n\r\n";
        for(i=0; http[i]; i++) pkt[54+i] = http[i];
        sim_rx_buf_ptr = pkt; sim_rx_buf_len = 54+i; sim_rx_addr = 0;
        sim_tx_pkt_len = 0;
        pt = eth_proc(); if (pt == IP_PROC) { uint16 it = ip_proc(); if (it == TCP_PROC) tcp_handler(); }

        // Phase 4: Check TX for "HTTP"
        int ok = 0;
        for(i=0; i<sim_tx_pkt_len && i<120; i++) {
            if (sim_tx_buf[i]=='H' && sim_tx_buf[i+1]=='T' &&
                sim_tx_buf[i+2]=='T' && sim_tx_buf[i+3]=='P') { ok = 1; break; }
        }
        LCPU_SET_LED(ok ? 0x0F : 0x0E); // 0x0F=PASS, 0x0E=FAIL
    }
    while (1) { asm volatile("wfi"); }
#endif

    uint32 led_val = 0x01;   // 流水灯初始位置：LED0

    while (1) {
        /* ---- TCP 保洁定时器 ---- */
        tcp_periodic_check();

        /* ---- LED 流水灯 ---- */
#ifndef SIM_SKIP_DELAY
        if (!tcp_led_override) {
            static uint32 last_toggle = 0;
            uint32 now = LCPU_LOCAL_TIME_L();
            if ((now - last_toggle) >= 50000000UL) {
                last_toggle = now;
                LCPU_SET_LED(led_val);
                // 0x01 → 0x02 → 0x04 → 0x08 → 0x01 循环
                led_val = (led_val == 0x08) ? 0x01 : (led_val << 1);
            }
        }
#endif

        /* ---- 收包处理 ---- */
        if (LCPU_RD_EMPTY())   // RX FIFO 为空，继续等待
            continue;

        // 第一步：弹出当前包 + 使能读
        LCPU_RD_START_PACKET();
        uint32 len = LCPU_RD_PKT_LEN();

        if (len == 0 || len > 2048) {
            // 无效包：再弹一次丢弃，跳过处理
            LCPU_RD_START_PACKET();
            continue;
        }

        // 第二步：解析以太类型，同时预写 MAC 头到 TX FIFO
        //   eth_proc() 返回 ARP_PROC / IP_PROC / NO_PROC
        uint16 ptype = eth_proc();

        // 第三步：协议分发
        if (ptype == ARP_PROC) {
            // ARP 请求 → 构造 ARP 应答（内部自动 PUSH）
            arp_reply();
        } else if (ptype == IP_PROC) {
            // IP 包 → 检查协议类型
            uint16 iptype = ip_proc();
            if (iptype == ICMP_PROC) {
                // ICMP Echo Request → 构造 Echo Reply（内部自动 PUSH）
                icmp_reply();
            } else if (iptype == TCP_PROC) {
                // TCP 包 → 状态机
                tcp_handler();
            }
        }

        // 第四步：弹出当前包，推进到下一个包
        _RD(1) = 1;
    }
}

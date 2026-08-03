/*
 * main.c — RISC-V Ping 应答主程序
 * ====================================
 * 功能：系统入口 + LED 心跳 + 主循环（ARP/ICMP 协议分发）
 *
 * 数据流：
 *   PC ping → 以太网帧 → RX FIFO → eth_proc(解析以太类型)
 *   → ARP? → arp_reply(ARP应答)
 *   → IP?  → ip_proc(解析IP头) → ICMP? → icmp_reply(Ping应答)
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
    /* ---- LED 上电自检：全亮 ~200ms → 全灭 ---- */
    LCPU_SET_LED(0x0F);
    volatile uint32 dly = 5000000;
    while (dly--) { asm volatile("nop"); }
    LCPU_SET_LED(0x00);

    uint32 led_val = 0x01;   // 流水灯初始位置：LED0

    while (1) {
        /* ---- LED 流水灯：每 ~1s 移一位（rdcycle 硬件定时）---- */
        {
            static uint32 last_toggle = 0;
            uint32 now = LCPU_LOCAL_TIME_L();
            if ((now - last_toggle) >= 50000000UL) {   // 50M 周期 ≈ 1s
                last_toggle = now;
                LCPU_SET_LED(led_val);
                // 0x01 → 0x02 → 0x04 → 0x08 → 0x01 循环
                led_val = (led_val == 0x08) ? 0x01 : (led_val << 1);
            }
        }

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
            }
        }

        // 第四步：弹出当前包，推进到下一个包
        _RD(1) = 1;
    }
}

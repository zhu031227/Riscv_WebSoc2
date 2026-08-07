/*
 * eth.c — 以太网帧解析（FIFO 直接读写）
 * ========================================
 * 功能：从 RX FIFO 读取以太类型和 MAC 地址，验证后预写应答帧的 MAC 头到 TX FIFO
 *
 * eth_proc() 返回值：
 *   ARP_PROC — ARP 包（直接返回，不写 TX 头）
 *   IP_PROC  — IP 包，且目的 MAC 匹配（已写 MAC 头到 TX FIFO）
 *   NO_PROC  — 非本机包或未知以太类型
 *
 * 写入 TX FIFO 的内容（仅 IP_PROC 时）：
 *   TX[0..5]  = 请求方 MAC（RX[6..11] 拷贝）
 *   TX[6..11] = 本机 MAC
 *   TX[12..13] = 以太类型
 */

#include "inc/lcpu_general.h"

uint16 eth_proc()
{
    uint32 fifo_data = 0;
    uint16 eth_type = 0;

    /* ---- 读取以太类型（字节 12-13），大端 ---- */
    LCPU_RD_SET_ADDR(OFF_ETH_TYPE);
    fifo_data = LCPU_RD_DATA8();
    eth_type = (uint16)fifo_data << 8;
    LCPU_RD_SET_ADDR(OFF_ETH_TYPE + 1);
    fifo_data = LCPU_RD_DATA8();
    eth_type = eth_type | fifo_data;

    if (eth_type == ETH_TYPE_ARP) {
        // ARP 包：直接返回，MAC 处理留给 arp_reply()
        return ARP_PROC;
    }
    else if (eth_type == ETH_TYPE_IP) {
        /* ---- 读取目的 MAC 高 4 字节（RX[0..3]）---- */
        uint32 dst_mac_high = 0;
        LCPU_RD_SET_ADDR(OFF_ETH_DST_MAC);
        dst_mac_high  = (uint32)LCPU_RD_DATA8() << 24;
        LCPU_RD_INC_ADDR();
        dst_mac_high |= (uint32)LCPU_RD_DATA8() << 16;
        LCPU_RD_INC_ADDR();
        dst_mac_high |= (uint32)LCPU_RD_DATA8() << 8;
        LCPU_RD_INC_ADDR();
        dst_mac_high |= (uint32)LCPU_RD_DATA8();
        LCPU_RD_INC_ADDR();  // raddr 现在 = 4

        /* ---- 读取目的 MAC 低 2 字节（RX[4..5]）---- */
        uint32 dst_mac_low = 0;
        dst_mac_low  = (uint32)LCPU_RD_DATA8() << 8;
        LCPU_RD_INC_ADDR();
        dst_mac_low |= (uint32)LCPU_RD_DATA8();

        // 只接受发往本机 MAC 的包（不处理广播 IP 包，交给 ARP 层处理）
        if (dst_mac_high != Local_MAC_HIGH || dst_mac_low != (uint32)Local_MAC_LOW) {
            return NO_PROC;
        }

        /* ---- 写入源 MAC = 本机 MAC（TX[6..11]）---- */
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 0, (Local_MAC_HIGH >> 24) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 1, (Local_MAC_HIGH >> 16) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 2, (Local_MAC_HIGH >> 8) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 3, (Local_MAC_HIGH >> 0) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 4, (Local_MAC_LOW >> 8) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 5, (Local_MAC_LOW >> 0) & 0xFF);

        /* ---- 拷贝请求方 MAC → 目的 MAC（RX[6..11] → TX[0..5]）---- */
        uint32 i;
        for (i = 0; i < 6; i++) {
            LCPU_RD_SET_ADDR(OFF_ETH_SRC_MAC + i);
            fifo_data = LCPU_RD_DATA8();
            LCPU_WR_BYTE(OFF_ETH_DST_MAC + i, fifo_data);
        }

        /* ---- 拷贝以太类型（TX[12..13]）---- */
        LCPU_WR_BYTE(OFF_ETH_TYPE,     (eth_type >> 8) & 0xFF);
        LCPU_WR_BYTE(OFF_ETH_TYPE + 1, (eth_type >> 0) & 0xFF);

        return IP_PROC;
    }
    else {
        return NO_PROC;
    }
}

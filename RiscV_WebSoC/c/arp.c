/*
 * arp.c — ARP 协议处理（FIFO 直接读写）
 * ======================================
 * 功能：从 RX FIFO 解析 ARP 请求，构造 ARP 应答直接写入 TX FIFO
 *
 * arp_reply() 处理流程：
 *   1. 校验目的 MAC（本机单播或广播）
 *   2. 校验目标 IP 是否为本机
 *   3. 校验操作码为 ARP Request (0x0001)
 *   4. 逐段构造 42 字节 ARP 应答帧 → 补零到 64 字节
 *   5. LCPU_WR_PUSH_PACKET(64) 推送发送
 */

#include "inc/lcpu_general.h"
#include "inc/arp.h"

void arp_reply() {
    uint16 i;
    uint16 arp_type = 0;
    uint32 dst_mac_high = 0;
    uint16 dst_mac_low = 0;
    uint32 target_ip = 0;

    /* ---- 校验 1：目的 MAC（RX[0..5]）为本机 MAC 或广播 ---- */
    for (i = 0; i < 4; i++) {
        LCPU_RD_SET_ADDR(i);
        dst_mac_high = (dst_mac_high << 8) | (LCPU_RD_DATA8() & 0xFFu);
    }
    for (i = 4; i < 6; i++) {
        LCPU_RD_SET_ADDR(i);
        dst_mac_low = (uint16)((dst_mac_low << 8) | (LCPU_RD_DATA8() & 0xFFu));
    }

    if (!((dst_mac_high == Local_MAC_HIGH && dst_mac_low == Local_MAC_LOW) ||
          (dst_mac_high == 0xFFFFFFFFu && dst_mac_low == 0xFFFFu))) {
        return;
    }

    /* ---- 校验 2：目标 IP（RX[38..41]）是否为本机 IP ---- */
    target_ip = 0;
    for (i = OFF_ARP_TARGET_IP; i < OFF_ARP_TARGET_IP + 4; i++) {
        LCPU_RD_SET_ADDR(i);
        target_ip = (target_ip << 8) | (LCPU_RD_DATA8() & 0xFFu);
    }
    if (target_ip != Local_IP_ADDR) return;

    /* ---- 校验 3：操作码（RX[20..21]）为 ARP Request ---- */
    LCPU_RD_SET_ADDR(OFF_ARP_OPCODE);
    arp_type = (uint16)LCPU_RD_DATA8() << 8;
    LCPU_RD_SET_ADDR(OFF_ARP_OPCODE + 1);
    arp_type |= LCPU_RD_DATA8();
    if (arp_type != ARP_REQUEST) return;

    /*
     * ---- 构造 ARP 应答帧（逐段写入 TX FIFO）----
     * 帧结构（共 42 字节，补齐到 64）：
     *   [0..5]   目的 MAC  ← 请求方 MAC (RX[6..11])
     *   [6..11]  源 MAC    ← 本机 MAC
     *   [12..13] 以太类型 ← 0x0806 (ARP)
     *   [14..15] 硬件类型 ← 0x0001 (Ethernet)
     *   [16..17] 协议类型 ← 0x0800 (IPv4)
     *   [18]     HLEN     ← 6 (MAC 地址长度)
     *   [19]     PLEN     ← 4 (IP 地址长度)
     *   [20..21] 操作码   ← 0x0002 (ARP Reply)
     *   [22..27] 发送方 MAC ← 本机 MAC
     *   [28..31] 发送方 IP  ← 本机 IP
     *   [32..37] 目标 MAC  ← 请求方 MAC (RX[22..27])
     *   [38..41] 目标 IP   ← 请求方 IP (RX[28..31])
     */

    // 段1: 目的 MAC ← 请求方 MAC (RX[6..11] → TX[0..5])
    for (i = 0; i < 6; i++) {
        LCPU_RD_SET_ADDR(OFF_ETH_SRC_MAC + i);
        LCPU_WR_BYTE(i, LCPU_RD_DATA8());
    }

    // 段2: 源 MAC ← 本机 MAC (TX[6..11])
    for (i = 0; i < 4; i++) {
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + i, (Local_MAC_HIGH >> (24 - i * 8)) & 0xFF);
    }
    for (i = 0; i < 2; i++) {
        LCPU_WR_BYTE(OFF_ETH_SRC_MAC + 4 + i, (Local_MAC_LOW >> (8 - i * 8)) & 0xFF);
    }

    // 段3: 以太类型 (RX[12..13] → TX[12..13]，保持不变)
    for (i = OFF_ETH_TYPE; i < OFF_ETH_TYPE + 2; i++) {
        LCPU_RD_SET_ADDR(i);
        LCPU_WR_BYTE(i, LCPU_RD_DATA8());
    }

    // 段4: 硬件类型+协议类型+HLEN+PLEN (RX[14..19] → TX[14..19]，保持不变)
    for (i = OFF_ARP_HTYPE; i < OFF_ARP_OPCODE; i++) {
        LCPU_RD_SET_ADDR(i);
        LCPU_WR_BYTE(i, LCPU_RD_DATA8());
    }

    // 段5: 操作码 = ARP Reply (TX[20..21] = 0x0002)
    LCPU_WR_BYTE(OFF_ARP_OPCODE,     (ARP_ECHO_REPLY >> 8) & 0xFF);
    LCPU_WR_BYTE(OFF_ARP_OPCODE + 1, (ARP_ECHO_REPLY >> 0) & 0xFF);

    // 段6: 发送方 MAC ← 本机 MAC (TX[22..27])
    for (i = 0; i < 4; i++) {
        LCPU_WR_BYTE(OFF_ARP_SENDER_MAC + i, (Local_MAC_HIGH >> (24 - i * 8)) & 0xFF);
    }
    for (i = 0; i < 2; i++) {
        LCPU_WR_BYTE(OFF_ARP_SENDER_MAC + 4 + i, (Local_MAC_LOW >> (8 - i * 8)) & 0xFF);
    }

    // 段7: 发送方 IP ← 本机 IP (TX[28..31])
    for (i = 0; i < 4; i++) {
        LCPU_WR_BYTE(OFF_ARP_SENDER_IP + i, (Local_IP_ADDR >> (24 - i * 8)) & 0xFF);
    }

    // 段8: 目标 MAC ← 请求方 MAC (RX[22..27] → TX[32..37])
    for (i = 0; i < 6; i++) {
        LCPU_RD_SET_ADDR(OFF_ARP_SENDER_MAC + i);
        LCPU_WR_BYTE(OFF_ARP_TARGET_MAC + i, LCPU_RD_DATA8());
    }

    // 段9: 目标 IP ← 请求方 IP (RX[28..31] → TX[38..41])
    for (i = 0; i < 4; i++) {
        LCPU_RD_SET_ADDR(OFF_ARP_SENDER_IP + i);
        LCPU_WR_BYTE(OFF_ARP_TARGET_IP + i, LCPU_RD_DATA8());
    }

    // 填充到以太网最小帧长 64 字节（TX[42..63] = 0）
    for (i = 42; i < 64; i++) {
        LCPU_WR_BYTE(i, 0);
    }

    LCPU_WR_PUSH_PACKET(64);
}

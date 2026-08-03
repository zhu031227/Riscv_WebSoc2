/*
 * ip.c — IPv4 协议处理（FIFO 直接读写）
 * ======================================
 * 功能：
 *   ip_proc()            — 从 RX FIFO 解析 IP 头，校验后返回协议类型
 *   ip_header_checksum() — 计算 IP 头校验和
 *   ip_header_update()   — 将修改后的 IP 头（交换源/目的 IP + 新校验和）写入 TX FIFO
 *
 * 全局变量（供 icmp.c 使用）：
 *   src_ip       — 请求方 IP 地址
 *   ip_total_len — IP 数据报总长度
 *
 * 设计要点：
 *   - IP 校验和覆盖整个 IP 头（20 字节），不含数据
 *   - 网络字节序为大端，所有 16/32 位字段需转换
 *   - 直接操作 RX/TX FIFO，不使用内存缓冲区
 */

#include "inc/lcpu_general.h"
#include "inc/comlib.h"
#include "inc/ip.h"

uint32 src_ip;          // 请求方 IP（用于构造应答时交换地址）
uint16 ip_total_len;   // IP 总长度（IP 头 + 数据）

/*
 * ip_proc — 解析 IP 头，返回上层协议类型
 * 返回：ICMP_PROC / UDP_PROC / TCP_PROC / NO_PROC
 */
uint16 ip_proc() {
    uint32 fifo_data = 0;
    uint32 ip_protocol_type = 0;
    src_ip = 0;

    /* ---- 校验 IP 版本和头长度 ---- */
    LCPU_RD_SET_ADDR(OFF_IP_VER_IHL);
    uint8 ver_ihl = LCPU_RD_DATA8();
    if ((ver_ihl & 0xF0) != 0x40) {   // 版本必须为 4 (IPv4)
        return NO_PROC;
    }
    if ((ver_ihl & 0x0F) < 5) {       // IHL >= 5 (最小 20 字节，无选项)
        return NO_PROC;
    }

    /* ---- 校验目的 IP 是否为本机 ---- */
    uint32 i = 0;
    for (i = 0; i < 4; i++) {
        LCPU_RD_SET_ADDR(OFF_IP_DST_IP + i);
        fifo_data = LCPU_RD_DATA8();
        if (fifo_data != ((Local_IP_ADDR >> (24 - i * 8)) & 0xFF)) {
            return NO_PROC;
        }
    }

    /* ---- 读取源 IP（字节序转换：大端 → uint32）---- */
    for (i = 0; i < 4; i++) {
        LCPU_RD_SET_ADDR(OFF_IP_SRC_IP + i);
        fifo_data = LCPU_RD_DATA8();
        src_ip |= (uint32)(fifo_data << (24 - i * 8));
    }

    /* ---- 读取协议类型 ---- */
    LCPU_RD_SET_ADDR(OFF_IP_PROTO);
    ip_protocol_type = LCPU_RD_DATA8();

    /* ---- 读取 IP 总长度（供 ICMP 应答使用）---- */
    LCPU_RD_SET_ADDR(OFF_IP_TOTAL_LEN);
    fifo_data = LCPU_RD_DATA8();
    ip_total_len = fifo_data * 256;
    LCPU_RD_SET_ADDR(OFF_IP_TOTAL_LEN + 1);
    fifo_data = LCPU_RD_DATA8();
    ip_total_len = ip_total_len + fifo_data;

    /* ---- 协议分发 ---- */
    if (ip_protocol_type == IP_PROTOCOL_ICMP) return ICMP_PROC;
    if (ip_protocol_type == IP_PROTOCOL_UDP)  return UDP_PROC;
    if (ip_protocol_type == IP_PROTOCOL_TCP)  return TCP_PROC;

    return NO_PROC;
}

/*
 * ip_header_checksum — 计算 IP 头校验和
 * 从 RX FIFO 读取原始 IP 头，替换 total_len，跳过校验和字段，累加计算
 */
uint16 ip_header_checksum(uint16 total_len, uint16 checksum_ini) {
    uint16 ip_checksum = checksum_ini;
    uint32 hi_byte = 0;
    uint32 fifo_data = 0;

    uint32 i = 0;
    for (i = eth_header_len; i < eth_header_len + ip_header_len; i++) {
        LCPU_RD_SET_ADDR(i);
        fifo_data = LCPU_RD_DATA8();

        // 跳过原校验和字段（清零参与计算）
        if (i == OFF_IP_CHECKSUM || i == OFF_IP_CHECKSUM + 1) fifo_data = 0;
        // 替换 total_len（应答包的总长度）
        if (i == OFF_IP_TOTAL_LEN)     fifo_data = (total_len >> 8) & 0xFF;
        if (i == OFF_IP_TOTAL_LEN + 1) fifo_data = (total_len >> 0) & 0xFF;

        // 16 位累加（大端：高字节在前）
        if (i % 2 == 0) {
            hi_byte = fifo_data;
        } else {
            ip_checksum = cks_sum_cal(hi_byte, fifo_data, ip_checksum);
        }
    }
    return ~ip_checksum;
}

/*
 * ip_header_update — 将修改后的 IP 头写入 TX FIFO
 * 修改内容：交换源/目的 IP、更新校验和、保持其他字段不变
 */
void ip_header_update(uint32 src_ip, uint16 total_len) {
    uint16 ip_checksum = ip_header_checksum(total_len, 0);
    uint32 i = 0;
    for (i = eth_header_len; i < eth_header_len + ip_header_len; i++) {
        LCPU_WR_SET_ADDR(i);

        if (i >= OFF_IP_TOTAL_LEN && i < OFF_IP_TOTAL_LEN + 2) {
            // 更新总长度
            LCPU_WR_SET_DATA((total_len >> (8 - (i - OFF_IP_TOTAL_LEN) * 8)) & 0xFF);
            LCPU_WR_PULSE_WEN();
        }
        else if (i >= OFF_IP_SRC_IP && i < OFF_IP_SRC_IP + 4) {
            // 源 IP ← 本机 IP
            LCPU_WR_SET_DATA((Local_IP_ADDR >> (24 - (i - OFF_IP_SRC_IP) * 8)) & 0xFF);
            LCPU_WR_PULSE_WEN();
        }
        else if (i >= OFF_IP_DST_IP && i < OFF_IP_DST_IP + 4) {
            // 目的 IP ← 请求方 IP（交换源和目的）
            LCPU_WR_SET_DATA((src_ip >> (24 - (i - OFF_IP_DST_IP) * 8)) & 0xFF);
            LCPU_WR_PULSE_WEN();
        }
        else if (i >= OFF_IP_CHECKSUM && i < OFF_IP_CHECKSUM + 2) {
            // 写入重新计算的校验和
            LCPU_WR_SET_DATA((ip_checksum >> (8 - (i - OFF_IP_CHECKSUM) * 8)) & 0xFF);
            LCPU_WR_PULSE_WEN();
        }
        else {
            // 其他字段：从 RX FIFO 原样拷贝
            LCPU_RD_SET_ADDR(i);
            LCPU_WR_SET_DATA(LCPU_RD_DATA8());
            LCPU_WR_PULSE_WEN();
        }
    }
}

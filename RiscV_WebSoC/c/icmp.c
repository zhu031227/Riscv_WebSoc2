/*
 * icmp.c — ICMP 协议处理（FIFO 直接读写）
 * ========================================
 * 功能：处理 ICMP Echo Request（Ping），构造 Echo Reply
 *
 * 调用链：
 *   main() → ip_proc() → ICMP_PROC → icmp_reply()
 *
 * icmp_reply() 处理流程：
 *   1. 调用 ip_header_update() 将 IP 头写入 TX FIFO（交换地址 + 新校验和）
 *   2. 写入 ICMP 头（type=0, code=0）
 *   3. 从 RX FIFO 拷贝 ID/Seq/数据载荷到 TX FIFO
 *   4. 计算 ICMP 校验和并写入
 *   5. 补零到最小帧长 → LCPU_WR_PUSH_PACKET()
 *
 * ICMP 校验和覆盖范围：ICMP 头 + 数据（不含 IP 伪首部）
 */

#include "inc/lcpu_general.h"
#include "inc/comlib.h"
#include "inc/ip.h"
#include "inc/icmp.h"

// ICMP 头字段偏移（相对于 icmp_start）
#define ICMP_OFS_TYPE       0
#define ICMP_OFS_CODE       1
#define ICMP_OFS_CHECKSUM   2
#define ICMP_OFS_IDENTIFIER 4
#define ICMP_OFS_SEQUENCE   6
#define ICMP_HEADER_LEN     8

/*
 * icmp_body_checksum — 计算 ICMP 校验和
 * 从 RX FIFO 读取 ID/Seq/数据，以 type=ECHO_REPLY 为起点累加
 */
uint16 icmp_body_checksum(uint16 icmp_req_len, uint16 checksum_ini) {
    uint16 icmp_start = eth_header_len + ip_header_len;
    uint16 icmp_checksum = checksum_ini;
    uint16 processed_len = 0;
    uint32 hi_byte = 0;
    uint32 fifo_data = 0;

    // 处理奇数字节长度
    bool is_odd = false;
    if (icmp_req_len % 2) {
        is_odd = true;
        processed_len = icmp_req_len - 1;
    } else {
        is_odd = false;
        processed_len = icmp_req_len;
    }

    // 起始累加：type=0 (Echo Reply), code=0
    icmp_checksum = cks_sum_cal(ICMP_ECHO_REPLY, 0, icmp_checksum);

    // 从 ID 字段开始累加（跳过 type/code/checksum，从 offset 4 开始）
    uint32 i = 0;
    for (i = icmp_start + ICMP_OFS_IDENTIFIER; i < icmp_start + processed_len; i++) {
        LCPU_RD_SET_ADDR(i);
        fifo_data = LCPU_RD_DATA8();
        if (i % 2 == 0) {
            hi_byte = fifo_data;
        } else {
            icmp_checksum = cks_sum_cal(hi_byte, fifo_data, icmp_checksum);
        }
    }
    // 奇数长度：最后一个字节当高字节处理
    if (is_odd) {
        LCPU_RD_SET_ADDR(icmp_start + processed_len);
        fifo_data = LCPU_RD_DATA8();
        icmp_checksum = cks_sum_cal(fifo_data, 0, icmp_checksum);
    }
    return ~icmp_checksum;
}

/*
 * icmp_reply — 构造并发送 ICMP Echo Reply
 */
void icmp_reply() {
    uint16 icmp_start = eth_header_len + ip_header_len;  // ICMP 起始偏移 = 14 + 20 = 34
    uint16 icmp_req_len = 0;
    uint16 tx_pkt_len = 0;
    uint16 i = 0;

    // ICMP 数据长度 = IP 总长度 - IP 头长度
    icmp_req_len = ip_total_len - ip_header_len;
    // 发送总长度：以太头 + IP 头 + ICMP 数据 + FCS(4字节)
    tx_pkt_len = eth_header_len + ip_total_len + 4;
    if (tx_pkt_len < 64) tx_pkt_len = 64;  // 补齐到以太网最小帧长

    /* ---- 第1步：写入 IP 头（交换源/目的地址 + 新校验和）---- */
    ip_header_update(src_ip, ip_total_len);

    /* ---- 第2步：写入 ICMP 类型 = Echo Reply (0)，代码 = 0 ---- */
    LCPU_WR_BYTE(icmp_start + ICMP_OFS_TYPE, ICMP_ECHO_REPLY);
    LCPU_WR_BYTE(icmp_start + ICMP_OFS_CODE, 0);

    /* ---- 第3步：拷贝 ICMP ID 和序列号（RX → TX，保持不变）---- */
    for (i = 0; i < 4; i++) {
        LCPU_RD_SET_ADDR(icmp_start + ICMP_OFS_IDENTIFIER + i);
        LCPU_WR_BYTE(icmp_start + ICMP_OFS_IDENTIFIER + i, LCPU_RD_DATA8());
    }

    /* ---- 第4步：拷贝 ICMP 数据载荷（跳过 8 字节 ICMP 头）---- */
    for (i = icmp_start + ICMP_HEADER_LEN; i < icmp_start + icmp_req_len; i++) {
        LCPU_RD_SET_ADDR(i);
        LCPU_WR_BYTE(i, LCPU_RD_DATA8());
    }

    /* ---- 第5步：计算并写入 ICMP 校验和 ---- */
    uint16 icmp_checksum = icmp_body_checksum(icmp_req_len, 0);

    for (i = 0; i < 2; i++) {
        LCPU_WR_BYTE(icmp_start + ICMP_OFS_CHECKSUM + i,
                     (icmp_checksum >> (8 - i * 8)) & 0xFF);
    }

    /* ---- 第6步：补零到最小帧长 ---- */
    for (i = eth_header_len + ip_total_len; i < tx_pkt_len - 4; i++) {
        LCPU_WR_BYTE(i, 0);
    }

    /* ---- 推送发送 ---- */
    LCPU_WR_PUSH_PACKET(tx_pkt_len);
}

/*
 * comlib.c — 通用工具函数
 * ========================
 * 功能：提供 IP/ICMP 校验和计算所需的基础函数
 *
 * cks_sum_cal(a, b, c) — 16 位校验和累加
 *   将两个字节 (a, b) 组成大端 16 位字，加上累加值 c，
 *   执行进位回卷后返回新的累加值。
 *   用于 IP 头校验和和 ICMP 校验和的逐步计算。
 */

#include "inc/lcpu_general.h"
#include "inc/comlib.h"

uint16 cks_sum_cal(uint32 a, uint32 b, uint16 c) {
    // a 为高字节，b 为低字节，组成大端 16 位字
    uint32 sum = (a << 8 | b) + c;

    // 进位回卷：将高 16 位的进位加回低 16 位
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return sum & 0xFFFF;
}

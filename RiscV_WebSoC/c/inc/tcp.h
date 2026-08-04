/*
 * tcp.h — TCP 协议头文件
 * ========================
 * 第 1 步：只定义验证所需的常量和测试函数
 */

#ifndef TCP_H_
#define TCP_H_

#include <stdint.h>

/* TCP 标志位（RFC 793）*/
#define TCP_FLAG_FIN  0x01u
#define TCP_FLAG_SYN  0x02u
#define TCP_FLAG_RST  0x04u
#define TCP_FLAG_PSH  0x08u
#define TCP_FLAG_ACK  0x10u
#define TCP_FLAG_URG  0x20u

/* 第 1 步验证函数：发送一个硬编码 SYN+ACK 包 */
void tcp_test_send_syn_ack(void);

#endif

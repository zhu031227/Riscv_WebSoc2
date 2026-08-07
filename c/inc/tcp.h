/*
 * tcp.h — TCP 协议头文件
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

/* 初始化 + 主处理 + 保洁定时器 */
void tcp_init(void);
void tcp_handler(void);
void tcp_periodic_check(void);

#endif

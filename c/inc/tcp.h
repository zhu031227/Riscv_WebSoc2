/*
 * tcp.h — TCP 协议头文件 (多连接版本, 对标参考代码)
 */

#ifndef TCP_H_
#define TCP_H_

#include <stdint.h>

#define MAX_CONNECTIONS  4   /* 最大并发连接数 */

/* TCP 状态 */
#define TCP_STATE_CLOSED       0
#define TCP_STATE_SYN_RECEIVED 1
#define TCP_STATE_ESTABLISHED  2
#define TCP_STATE_FIN_WAIT_1   3
#define TCP_STATE_FIN_WAIT_2   4
#define TCP_STATE_CLOSE_WAIT   5
#define TCP_STATE_LAST_ACK     6
#define TCP_STATE_TIME_WAIT    7

/* TCP 标志位（RFC 793）*/
#define TCP_FLAG_FIN  0x01u
#define TCP_FLAG_SYN  0x02u
#define TCP_FLAG_RST  0x04u
#define TCP_FLAG_PSH  0x08u
#define TCP_FLAG_ACK  0x10u
#define TCP_FLAG_URG  0x20u

/* 连接表 (并行数组, 对标参考代码) */
extern uint8_t  conn_state     [MAX_CONNECTIONS];
extern uint32_t conn_snd_seq   [MAX_CONNECTIONS];
extern uint32_t conn_rcv_ack   [MAX_CONNECTIONS];
extern uint16_t conn_src_port  [MAX_CONNECTIONS];
extern uint16_t conn_dst_port  [MAX_CONNECTIONS];
extern uint32_t conn_src_ip    [MAX_CONNECTIONS];
extern uint32_t conn_dst_ip    [MAX_CONNECTIONS];
extern uint32_t conn_timewait  [MAX_CONNECTIONS];
extern uint32_t conn_activity  [MAX_CONNECTIONS];
extern uint32_t conn_tx_time   [MAX_CONNECTIONS];
extern uint8_t  conn_syn_retry [MAX_CONNECTIONS];

/* LED 控灯标志: TCP 接管时置 1, 暂停流水灯 */
extern uint8_t tcp_led_override;

/* 初始化 + 主处理 + 保洁定时器 */
void tcp_init(void);
void tcp_handler(void);
void tcp_periodic_check(void);

#endif

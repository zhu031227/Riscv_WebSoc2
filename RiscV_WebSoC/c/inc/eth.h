#ifndef _ETH_H_
#define _ETH_H_

#include <stdint.h>

/* 最大以太网帧长（可被外部定义覆盖） */
#ifndef ETH_MAX_FRAME_LEN
#define ETH_MAX_FRAME_LEN   1518
#endif

/* 收包：返回0成功，-1无包，-2超长包丢弃 */
int eth_rx_frame(uint8_t *buf, uint16_t *len);

/* 发包：将整帧写入TX FIFO并推送发送 */
void eth_tx_frame(const uint8_t *buf, uint16_t len);

/* 获取本机MAC地址（6字节） */
void eth_get_mac(uint8_t *mac);

#endif /* _ETH_H_ */
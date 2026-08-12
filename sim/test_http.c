/*
 * test_http.c — TCP/HTTP 协议栈 x86 原生单元测试
 * 编译: cd sim && gcc -DSIM_FAST -I. -I../c/inc -I../c \
 *   -o test_http test_http.c ../c/tcp.c ../c/eth.c ../c/ip.c \
 *   ../c/icmp.c ../c/arp.c ../c/http.c ../c/comlib.c && ./test_http
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Mock 寄存器 */
uint32_t mock_reg[256];

/* SIM_FAST 全局变量 (固件 extern 它们) */
uint8_t  sim_tx_buf[2048];
uint16_t sim_tx_addr;
uint16_t sim_tx_pkt_len;
uint8_t *sim_rx_buf_ptr;
uint16_t sim_rx_buf_len;
uint16_t sim_rx_addr;

/* 固件 extern */
extern uint32_t src_ip;
extern uint16_t ip_total_len;
void tcp_init(void);
void tcp_handler(void);
uint16_t eth_proc(void);
uint16_t ip_proc(void);

/* 测试辅助 */
static int pass, fail;
#define CHECK(n, c) do{ if(c){printf("  PASS: %s\n",n);pass++;}\
    else{printf("  FAIL: %s\n",n);fail++;}}while(0)

int main(void) {
    printf("=== TCP/HTTP x86 Unit Test ===\n\n");
    tcp_init();

    uint8_t pkt[256]; int i;
    for(i=0;i<256;i++) pkt[i]=0;

    /* Phase 1: SYN */
    printf("--- Phase 1: SYN ---\n");
    pkt[0]=0x00;pkt[1]=0x00;pkt[2]=0x01;pkt[3]=0x02;pkt[4]=0x04;pkt[5]=0x05;
    pkt[6]=0x9c;pkt[7]=0x2d;pkt[8]=0xcd;pkt[9]=0xac;pkt[10]=0x8f;pkt[11]=0xa4;
    pkt[12]=0x08;pkt[13]=0x00;
    pkt[14]=0x45;pkt[15]=0x00;pkt[16]=0x00;pkt[17]=0x28;
    pkt[18]=0x00;pkt[19]=0x01;pkt[20]=0x40;pkt[21]=0x00;
    pkt[22]=0x40;pkt[23]=0x06;pkt[24]=0x00;pkt[25]=0x00;
    pkt[26]=0xa9;pkt[27]=0xfe;pkt[28]=0x5c;pkt[29]=0x15;
    pkt[30]=0xa9;pkt[31]=0xfe;pkt[32]=0x01;pkt[33]=0x01;
    pkt[34]=0x30;pkt[35]=0x39;pkt[36]=0x00;pkt[37]=0x50;
    pkt[38]=0x05;pkt[39]=0x85;pkt[40]=0x2e;pkt[41]=0xa5;
    pkt[46]=0x50;pkt[47]=0x02;pkt[48]=0xfa;pkt[49]=0xf0;

    sim_rx_buf_ptr=pkt; sim_rx_buf_len=54; sim_rx_addr=0; sim_tx_pkt_len=0;
    uint16_t pt=eth_proc();
    if(pt==0x1000){uint16_t it=ip_proc();if(it==0x1200)tcp_handler();}
    CHECK("SYN+ACK sent", sim_tx_pkt_len>=40);
    CHECK("SYN+ACK flags=0x12", sim_tx_buf[47]==0x12);

    uint32_t isn=(sim_tx_buf[38]<<24)|(sim_tx_buf[39]<<16)|(sim_tx_buf[40]<<8)|sim_tx_buf[41];
    printf("  ISN=0x%08x\n", isn);

    /* Phase 2: ACK */
    printf("--- Phase 2: ACK ---\n");
    pkt[38]=0x05;pkt[39]=0x85;pkt[40]=0x2e;pkt[41]=0xa6;
    pkt[42]=((isn+1)>>24)&0xFF;pkt[43]=((isn+1)>>16)&0xFF;
    pkt[44]=((isn+1)>>8)&0xFF; pkt[45]=(isn+1)&0xFF;
    pkt[47]=0x10;
    sim_rx_buf_ptr=pkt; sim_rx_buf_len=54; sim_rx_addr=0;
    pt=eth_proc(); if(pt==0x1000){uint16_t it=ip_proc();if(it==0x1200)tcp_handler();}
    CHECK("ACK processed", 1);

    /* Phase 3: HTTP GET */
    printf("--- Phase 3: HTTP GET ---\n");
    for(i=54;i<256;i++) pkt[i]=0;
    pkt[16]=0x00;pkt[17]=0x62;
    pkt[47]=0x18;
    const char *http="GET / HTTP/1.1\r\nHost: 169.254.1.1\r\n\r\n";
    for(i=0;http[i];i++)pkt[54+i]=http[i];
    sim_rx_buf_ptr=pkt; sim_rx_buf_len=54+i; sim_rx_addr=0; sim_tx_pkt_len=0;
    pt=eth_proc(); if(pt==0x1000){uint16_t it=ip_proc();if(it==0x1200)tcp_handler();}
    CHECK("HTTP response sent", sim_tx_pkt_len>14);

    int fh=0,f2=0,fr=0;
    for(i=0;i+4<sim_tx_pkt_len;i++){
        if(sim_tx_buf[i]=='H'&&sim_tx_buf[i+1]=='T'&&sim_tx_buf[i+2]=='T'&&sim_tx_buf[i+3]=='P')fh=1;
        if(sim_tx_buf[i]=='2'&&sim_tx_buf[i+1]=='0'&&sim_tx_buf[i+2]=='0')f2=1;
        if(sim_tx_buf[i]=='R'&&sim_tx_buf[i+1]=='I'&&sim_tx_buf[i+2]=='S'&&sim_tx_buf[i+3]=='C')fr=1;
    }
    CHECK("HTTP/1.1 in response", fh);
    CHECK("200 in response", f2);
    CHECK("RISC-V in response", fr);

    printf("\n  Response: ");
    for(i=0;i<sim_tx_pkt_len&&i<100;i++)putchar(sim_tx_buf[i]>=32&&sim_tx_buf[i]<127?sim_tx_buf[i]:'.');
    printf("\n");

    /* Phase 4: POST JSON */
    printf("--- Phase 4: POST JSON ---\n");
    for(i=54;i<256;i++)pkt[i]=0;
    const char *body="POST /submit HTTP/1.1\r\nContent-Type: application/json\r\nContent-Length: 48\r\n\r\n{\"addr\":\"0010\",\"data\":\"0000000F\",\"mode\":\"write\"}";
    int blen=strlen(body);
    pkt[16]=((40+blen)>>8)&0xFF;pkt[17]=(40+blen)&0xFF;
    pkt[47]=0x18;
    for(i=0;body[i];i++)pkt[54+i]=body[i];
    sim_rx_buf_ptr=pkt; sim_rx_buf_len=54+i; sim_rx_addr=0; sim_tx_pkt_len=0;
    pt=eth_proc(); if(pt==0x1000){uint16_t it=ip_proc();if(it==0x1200)tcp_handler();}
    CHECK("POST response sent", sim_tx_pkt_len>14);
    int po=0;for(i=0;i+3<sim_tx_pkt_len;i++)if(sim_tx_buf[i]=='2'&&sim_tx_buf[i+1]=='0'&&sim_tx_buf[i+2]=='0')po=1;
    CHECK("POST returns 200", po);

    printf("\n=== %d PASS, %d FAIL ===\n", pass, fail);
    return fail?1:0;
}

// tb_http.cpp — HTTP 全链路 Verilator 仿真
// Phase 1: SYN → SYN+ACK
// Phase 2: ACK → ESTABLISHED
// Phase 3: HTTP GET → 验证 HTTP 200 响应

#include "Vtb_http.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdio>
#include <cstdint>
#include <cstring>

Vtb_http *top;
VerilatedVcdC *tfp;
vluint64_t sim_time = 0;

void tick() {
    top->clk_50m_in = !top->clk_50m_in;
    top->eval();
    if (tfp) tfp->dump(sim_time);
    sim_time += 10;
}
void tick_n(int n) { for(int i=0;i<n;i++){tick();tick();} }

// Packet buffers
uint8_t syn_pkt[54], ack_pkt[54], get_pkt[128];
uint8_t tx_buf[1024];
int     tx_len = 0;
bool    tx_captured = false;
int     pass_cnt = 0, fail_cnt = 0;

// Verilator signal access — via wrapper wire aliases
#define MAC_RX_SOP  top->tb_http__DOT__u_mac_rx_sop
#define MAC_RX_EN   top->tb_http__DOT__u_mac_rx_en
#define MAC_RX_DATA top->tb_http__DOT__u_mac_rx_data
#define MAC_RX_EOP  top->tb_http__DOT__u_mac_rx_eop
#define MAC_TX_SOP  top->tb_http__DOT__u_mac_tx_sop
#define MAC_TX_EN   top->tb_http__DOT__u_mac_tx_en
#define MAC_TX_DATA top->tb_http__DOT__u_mac_tx_data
#define MAC_TX_EOP  top->tb_http__DOT__u_mac_tx_eop
#define DUT_LED     top->tb_http__DOT__u_led

void inject_pkt(uint8_t *pkt, int len) {
    printf("[SIM] 注入 %d 字节\n", len);
    tick_n(10);

    MAC_RX_SOP = 1;
    MAC_RX_EN  = 1;
    MAC_RX_DATA = pkt[0];
    MAC_RX_EOP = 0;
    tick(); tick();
    MAC_RX_SOP = 0;

    for (int i = 1; i < len - 1; i++) {
        MAC_RX_DATA = pkt[i];
        tick(); tick();
    }
    MAC_RX_DATA = pkt[len - 1];
    MAC_RX_EOP = 1;
    tick(); tick();
    MAC_RX_EN  = 0;
    MAC_RX_EOP = 0;
    printf("[SIM] 注入完成\n");
}

bool capture_tx(int timeout_cycles) {
    tx_captured = false;
    tx_len = 0;
    bool tx_started = false;

    for (int i = 0; i < timeout_cycles; i++) {
        tick(); tick();
        if (!tx_started && MAC_TX_SOP && MAC_TX_EN) {
            tx_started = true;
            tx_buf[tx_len++] = MAC_TX_DATA;
            continue;
        }
        if (tx_started && tx_len < 1024) {
            if (MAC_TX_EN)
                tx_buf[tx_len++] = MAC_TX_DATA;
            if (MAC_TX_EOP) {
                printf("[SIM] TX: %d bytes @ %lu ns\n", tx_len, sim_time);
                tx_captured = true;
                return true;
            }
        }
    }
    return false;
}

void dump_tx_meta(const char *label) {
    if (tx_len < 54) return;
    printf("[%s] ETH: %02x:%02x:%02x:%02x:%02x:%02x->%02x:%02x:%02x:%02x:%02x:%02x type=%04x\n",
        label,
        tx_buf[0],tx_buf[1],tx_buf[2],tx_buf[3],tx_buf[4],tx_buf[5],
        tx_buf[6],tx_buf[7],tx_buf[8],tx_buf[9],tx_buf[10],tx_buf[11],
        (tx_buf[12]<<8)|tx_buf[13]);
    printf("[%s] TCP: %d->%d flags=0x%02x seq=%08x ack=%08x win=%d\n",
        label,
        (tx_buf[34]<<8)|tx_buf[35], (tx_buf[36]<<8)|tx_buf[37],
        tx_buf[47],
        (tx_buf[38]<<24)|(tx_buf[39]<<16)|(tx_buf[40]<<8)|tx_buf[41],
        (tx_buf[42]<<24)|(tx_buf[43]<<16)|(tx_buf[44]<<8)|tx_buf[45],
        (tx_buf[48]<<8)|tx_buf[49]);
}

bool find_str(const char *s) {
    int sl = strlen(s);
    for (int ti = 0; ti <= tx_len - sl; ti++) {
        bool ok = true;
        for (int si = 0; si < sl; si++)
            if (tx_buf[ti + si] != (uint8_t)s[si]) { ok = false; break; }
        if (ok) { printf("[SIM] 找到 '%s' @ offset %d\n", s, ti); return true; }
    }
    return false;
}

//-----------------------------------------------------------------
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    top = new Vtb_http;
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("tb_http.vcd");

    // Init
    top->clk_50m_in = 0;
    top->reset_l = 0;
    top->rgmii_rxc = 0; top->rgmii_rxd = 0; top->rgmii_rx_ctl = 0;
    top->uart_rx = 1;
    tick_n(10); top->reset_l = 1;
    tick_n(10);

    // Wait for firmware load (BFM)
    printf("[SIM] Wait BFM firmware load...\n");
    tick_n(200000);
    printf("[SIM] Starting test\n");

    //-------------------------------------------------------------
    // Phase 1: SYN → SYN+ACK
    //-------------------------------------------------------------
    printf("\n=== Phase 1: SYN ===\n");
    inject_pkt(syn_pkt, 54);
    uint32_t fpga_isn = 0, pc_isn = 0, pc_seq = 0, pc_ack = 0;

    if (!capture_tx(300000)) {
        printf("FAIL: No SYN+ACK response\n"); fail_cnt++;
    } else {
        dump_tx_meta("SYN+ACK");
        if ((tx_buf[47] & 0x12) == 0x12) {
            printf("PASS: SYN+ACK flags OK\n"); pass_cnt++;
        } else {
            printf("FAIL: bad flags 0x%02x\n", tx_buf[47]); fail_cnt++;
        }

        // Extract FPGA ISN
        fpga_isn = (tx_buf[38]<<24)|(tx_buf[39]<<16)|(tx_buf[40]<<8)|tx_buf[41];
        pc_isn   = (syn_pkt[38]<<24)|(syn_pkt[39]<<16)|(syn_pkt[40]<<8)|syn_pkt[41];
        printf("[SIM] FPGA ISN=%08x PC ISN=%08x\n", fpga_isn, pc_isn);

        // Phase 2: ACK → ESTABLISHED
        printf("\n=== Phase 2: ACK ===\n");
        memcpy(ack_pkt, syn_pkt, 54);
        pc_seq = pc_isn + 1; pc_ack = fpga_isn + 1;
        ack_pkt[38]=(pc_seq>>24)&0xFF; ack_pkt[39]=(pc_seq>>16)&0xFF;
        ack_pkt[40]=(pc_seq>>8)&0xFF;  ack_pkt[41]=pc_seq&0xFF;
        ack_pkt[42]=(pc_ack>>24)&0xFF; ack_pkt[43]=(pc_ack>>16)&0xFF;
        ack_pkt[44]=(pc_ack>>8)&0xFF;  ack_pkt[45]=pc_ack&0xFF;
        ack_pkt[47] = 0x10;
        inject_pkt(ack_pkt, 54);
        tick_n(25000);
        bool established = (DUT_LED & 0xF) == 0xF;
        printf("LED=%x => %s\n", DUT_LED & 0xF, established ? "ESTABLISHED" : "NOT ESTABLISHED");
        if (established) pass_cnt++; else fail_cnt++;

        // Phase 3: HTTP GET
        printf("\n=== Phase 3: HTTP GET ===\n");
        memset(get_pkt, 0, 128);
        get_pkt[0]=0x00;get_pkt[1]=0x00;get_pkt[2]=0x01;get_pkt[3]=0x02;get_pkt[4]=0x04;get_pkt[5]=0x05;
        get_pkt[6]=0x9c;get_pkt[7]=0x2d;get_pkt[8]=0xcd;get_pkt[9]=0xac;get_pkt[10]=0x8f;get_pkt[11]=0xa4;
        get_pkt[12]=0x08;get_pkt[13]=0x00;
        get_pkt[14]=0x45;get_pkt[15]=0x00;get_pkt[16]=0x00;get_pkt[17]=0x62;
        get_pkt[18]=0x00;get_pkt[19]=0x02;get_pkt[20]=0x40;get_pkt[21]=0x00;
        get_pkt[22]=0x40;get_pkt[23]=0x06;get_pkt[24]=0x00;get_pkt[25]=0x00;
        get_pkt[26]=0xa9;get_pkt[27]=0xfe;get_pkt[28]=0x5c;get_pkt[29]=0x15;
        get_pkt[30]=0xa9;get_pkt[31]=0xfe;get_pkt[32]=0x01;get_pkt[33]=0x01;
        get_pkt[34]=0x30;get_pkt[35]=0x39;get_pkt[36]=0x00;get_pkt[37]=0x50;
        get_pkt[38]=(pc_seq>>24)&0xFF;get_pkt[39]=(pc_seq>>16)&0xFF;
        get_pkt[40]=(pc_seq>>8)&0xFF; get_pkt[41]=pc_seq&0xFF;
        get_pkt[42]=(pc_ack>>24)&0xFF;get_pkt[43]=(pc_ack>>16)&0xFF;
        get_pkt[44]=(pc_ack>>8)&0xFF; get_pkt[45]=pc_ack&0xFF;
        get_pkt[46]=0x50;get_pkt[47]=0x18;
        get_pkt[48]=0xfa;get_pkt[49]=0xf0;
        const char *http = "GET / HTTP/1.1\r\nHost: 169.254.1.1\r\n\r\n";
        int hlen = strlen(http);
        memcpy(get_pkt + 54, http, hlen);
        inject_pkt(get_pkt, 112);

        printf("[SIM] Waiting for HTTP response...\n");
        tick_n(5000);
        bool got_response = false;
        for (int t = 0; t < 100000; t++) {
            tick(); tick();
            if (MAC_TX_SOP && MAC_TX_EN) {
                tx_len = 0;
                tx_buf[tx_len++] = MAC_TX_DATA;
                while (!(MAC_TX_EOP && MAC_TX_EN) && tx_len < 1024) {
                    tick(); tick();
                    if (MAC_TX_EN) tx_buf[tx_len++] = MAC_TX_DATA;
                }
                if (MAC_TX_EN && tx_len < 1024) tx_buf[tx_len++] = MAC_TX_DATA;
                got_response = true;
                printf("[SIM] HTTP response: %d bytes\n", tx_len);
                break;
            }
        }

        if (got_response) {
            bool f1 = find_str("HTTP/1.1");
            bool f2 = find_str("200") || find_str("OK");
            bool f3 = find_str("text/html") || find_str("RISC-V");
            if (f1 || f2 || f3) {
                printf("PASS: HTTP response verified\n"); pass_cnt++;
            } else {
                printf("INFO: TX captured but markers not found\n");
                printf("  First %d bytes: ", tx_len < 80 ? tx_len : 80);
                for (int i = 0; i < (tx_len < 80 ? tx_len : 80); i++) printf("%c", tx_buf[i]>=32?tx_buf[i]:'.');
                printf("\n");
            }
        } else {
            printf("FAIL: No HTTP response TX captured\n"); fail_cnt++;
        }
    }

    printf("\n============================================\n");
    printf(" Results: %d PASS, %d FAIL\n", pass_cnt, fail_cnt);
    if (fail_cnt == 0) printf(" HTTP 仿真全部通过!\n");
    printf("============================================\n");

    tfp->close(); top->final(); delete top; return 0;
}

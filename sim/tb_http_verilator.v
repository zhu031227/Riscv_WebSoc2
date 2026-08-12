//-----------------------------------------------------------------
// tb_http_verilator.v — HTTP 仿真顶层 (Verilator 兼容)
//-----------------------------------------------------------------
`timescale 1ns / 1ps

module tb_http;

  reg clk_50m_in, reset_l;
  wire [3:0] rgmii_txd, led_o;
  wire rgmii_txc, rgmii_tx_ctl, Eth0_MDC, Eth0_MDIO, rgmii_reset_l, uart_tx;
  reg rgmii_rxc, rgmii_rx_ctl, uart_rx;
  reg [3:0] rgmii_rxd;

  webserver_cpu_top #(.sim_mod(1)) u_dut (
      .clk_50m_in(clk_50m_in), .reset_l(reset_l),
      .rgmii_txc(rgmii_txc), .rgmii_txd(rgmii_txd), .rgmii_tx_ctl(rgmii_tx_ctl),
      .rgmii_rxc(rgmii_rxc), .rgmii_rxd(rgmii_rxd), .rgmii_rx_ctl(rgmii_rx_ctl),
      .Eth0_MDC(Eth0_MDC), .Eth0_MDIO(Eth0_MDIO), .rgmii_reset_l(rgmii_reset_l),
      .uart_rx(uart_rx), .uart_tx(uart_tx), .led_o(led_o)
  );

  // Wire aliases for C++ access of internal signals (for C++ access)
  wire u_mac_rx_sop  = u_dut.mac_rx_sop;
  wire u_mac_rx_en   = u_dut.mac_rx_en;
  wire [7:0] u_mac_rx_data = u_dut.mac_rx_data;
  wire u_mac_rx_eop  = u_dut.mac_rx_eop;

  wire u_mac_tx_sop  = u_dut.mac_tx_sop;
  wire u_mac_tx_en   = u_dut.mac_tx_en;
  wire [7:0] u_mac_tx_data = u_dut.mac_tx_data;
  wire u_mac_tx_eop  = u_dut.mac_tx_eop;

  wire u_bus_req     = u_dut.bus_req;
  wire [31:0] u_bus_address = u_dut.bus_address;
  wire [31:0] u_bus_wdata  = u_dut.bus_wdata;
  wire [3:0] u_led   = led_o;

endmodule

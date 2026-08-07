#===== 输入时钟 50MHz =====
create_clock -period 20.000 -name clk_50m_in [get_ports clk_50m_in]

#===== RGMII RXC (来自 PHY, 125MHz, 异步) =====
create_clock -period 8.000 -name rgmii_rxc [get_ports rgmii_rxc]
set_false_path -from [get_clocks rgmii_rxc] -to [all_clocks]
set_false_path -to   [get_clocks rgmii_rxc] -from [all_clocks]

#===== MMCM 相移时钟组 (同源, ODDR/IDDR内部处理时序) =====
set_clock_groups -asynchronous \
    -group [get_clocks -include_generated clk_125m_unbuf] \
    -group [get_clocks -include_generated clk_125m_tx_unbuf]

#===================================================================
# ILA 探针 false path (调试信号, 不要求建立保持时间)
#===================================================================
set_false_path -to [get_pins u_ila_core0/probe*]

# ILA 所有相关路径 false path (调试逻辑, 不影响主功能)
set_false_path -from [get_clocks clk_50m_cpu_unbuf] -to [get_clocks clk_125m_unbuf]
set_false_path -from [get_clocks clk_125m_unbuf] -to [get_clocks clk_50m_cpu_unbuf]

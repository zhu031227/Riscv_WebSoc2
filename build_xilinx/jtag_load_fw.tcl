# jtag_load_fw.tcl — JTAG-AXI 外灌固件到指令 RAM
# 流程: 按住 CPU 复位 → 逐字写 0x10000+i → 释放复位 → 写 LED 验证
# 用法: cd build_xilinx && vivado -mode batch -nojournal -nolog -source jtag_load_fw.tcl
# 前置: 已 source settings64.sh; 已跑 bin_to_jtag_tcl.py 生成 fw_axi_body.tcl

set script_dir [file dirname [file normalize [info script]]]

open_hw_manager
connect_hw_server
current_hw_target [lindex [get_hw_targets] 0]
open_hw_target
refresh_hw_device [current_hw_device]

set hw_axis [get_hw_axis -quiet]
if {[llength $hw_axis] == 0} {
    puts "ERROR: 未找到 JTAG-AXI 实例, 请确认纯硬件 bit 已烧录"
    close_hw_manager
    exit 1
}
set hw_axi [lindex $hw_axis 0]
puts "Found HW AXI: $hw_axi"
source [file join $script_dir jtag_lcpu_xilinx]

# ① 按住 CPU 复位 (写 0x100=0; 改 RTL 后 cpu_channel 复位 = sys_rst_n & riscv_reset_l,
#    所以这里同时把网络 RX FIFO 按住复位、保持清空, 不会被 PHY 广播包写满)
jwrite 0x100 0x0
puts "[1/4] CPU+net reset held (0x100=0)"

# ② 逐字写固件 (CPU 复位中, 不取指; 双口 RAM 口1空闲/口2写, 无冲突)
set body [file join $script_dir fw_axi_body.tcl]
if {![file exists $body]} {
    puts "ERROR: 找不到 $body, 请先运行 bin_to_jtag_tcl.py"
    close_hw_manager
    exit 1
}
source $body
puts "[2/4] firmware words written"

# ③ 释放复位 (写 0x100=1, 软核从 PC=0 跑, 网络 FIFO 从干净状态开始收包)
jwrite 0x100 0x1
puts "[3/4] CPU+net reset released (0x100=1)"

# ④ 验证: 写 LED=0x05 (LED0+LED2 亮, 与复位默认 0xF 区分, 证明 JTAG 写通)
jwrite 0x10 0x5
puts "[4/4] LED write OK (0x05)"

puts "=== FIRMWARE LOADED ==="
close_hw_manager

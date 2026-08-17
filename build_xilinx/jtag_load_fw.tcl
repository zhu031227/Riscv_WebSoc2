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

# ① 逐字写固件 (不复位 CPU: 纯硬件 bit 的 BRAM 全 0, CPU 跑 trap 循环, 不发总线请求;
#    双口 RAM 口1取指/口2写互不冲突, 避免长时间复位把 RX FIFO 写满破坏)
set body [file join $script_dir fw_axi_body.tcl]
if {![file exists $body]} {
    puts "ERROR: 找不到 $body, 请先运行 bin_to_jtag_tcl.py"
    close_hw_manager
    exit 1
}
source $body
puts "[1/3] firmware words written (no reset during write)"

# ② 短复位 + 释放 (写 0x100=0 再 0x100=1, 软核从 PC=0 重新启动)
create_hw_axi_txn hold $hw_axi -type write -address 0x00000100 -data 0x00000000 -len 1
run_hw_axi hold
create_hw_axi_txn rel $hw_axi -type write -address 0x00000100 -data 0x00000001 -len 1
run_hw_axi rel
puts "[2/3] CPU reset (short) + released"

# ③ 验证: 写 LED=0x05 (LED0+LED2 亮, 与复位默认 0xF 区分, 证明 JTAG 写通)
create_hw_axi_txn led $hw_axi -type write -address 0x00000010 -data 0x00000005 -len 1
run_hw_axi led
puts "[3/3] LED write OK (0x05)"

puts "=== FIRMWARE LOADED ==="
close_hw_manager

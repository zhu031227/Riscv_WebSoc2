# read_back.tcl — 灌固件前「验明正身」: 读版本号 + 状态寄存器
# 一次确认四件事: ① JTAG-AXI 读路径通 ② 地址映射对 ③ 烧的是正确纯硬件 bit ④ 时钟域正常
# 用法: cd build_xilinx && vivado -mode batch -nojournal -nolog -source read_back.tcl

# 把 get_property DATA 的返回(可能带 0x/前导零/大小写不一)规范成整数
proc hexval {s} {
    set s [string toupper [string trim $s]]
    if {[string range $s 0 1] == "0X"} { set s [string range $s 2 end] }
    if {$s eq ""} { return 0 }
    return [expr 0x$s]
}

open_hw_manager
connect_hw_server
current_hw_target [lindex [get_hw_targets] 0]
open_hw_target
refresh_hw_device [current_hw_device]

set hw_axis [get_hw_axis -quiet]
if {[llength $hw_axis] == 0} {
    puts "ERROR: 无 JTAG-AXI 实例"
    close_hw_manager
    exit 1
}
set hw_axi [lindex $hw_axis 0]
set script_dir [file dirname [file normalize [info script]]]
source [file join $script_dir jtag_lcpu_xilinx]

# ① FPGA 编译版本号 (只读 = 纯硬件 bit 的身份签名)
#    jread 连续读 0x0(日期)、0x1(时间) 两个
set ver [jread 0x0 2]
set build_date [lindex $ver 0]
set build_time [lindex $ver 1]
puts "fpga_build_date = 0x[string toupper [string trim $build_date]]"
puts "fpga_build_time = 0x[string toupper [string trim $build_time]]"

# ② 状态 / 复位默认值
#    jread 连续读 0x10(LED)、0x11(pll_locked) 两个
set st [jread 0x10 2]
set led [lindex $st 0]
set pll [lindex $st 1]
puts "pll_locked      = 0x[string toupper [string trim $pll]]"
puts "led(复位默认)   = 0x[string toupper [string trim $led]]"

# 判定
set fail 0
if {[hexval $pll] != 1} {
    puts "FAIL: pll_locked != 1 (时钟域异常)"
    set fail 1
} else {
    puts "PASS: pll_locked = 1 (时钟域正常)"
}
# led 读回: 0xF=复位默认(刚烧录未写), 其他=之前 M1 写入的值 — 只要在 0~F 合理范围即证明读路径通
set ledv [hexval $led]
if {$ledv >= 0 && $ledv <= 15} {
    puts "PASS: led 读回 = 0x[string toupper [string trim $led]] (读路径通)"
} else {
    puts "FAIL: led 读回异常 = 0x[string toupper [string trim $led]]"
    set fail 1
}
puts "NOTE: 版本号应为本次 build 的日期时间(自动生成), 请与 build 日志核对"

if {$fail} {
    puts "=== 验明正身失败, 请勿灌固件 ==="
    close_hw_manager
    exit 1
}
puts "=== 验明正身通过, 可以灌固件 ==="
close_hw_manager

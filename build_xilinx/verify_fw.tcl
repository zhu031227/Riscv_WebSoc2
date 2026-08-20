# verify_fw.tcl — 灌固件后回读指令 RAM, 与 firmware.bin 逐字比对
# 前置: 已跑 bin_to_jtag_tcl.py 生成 fw_expected_words.txt
# 用法: cd build_xilinx && vivado -mode batch -nojournal -nolog -source verify_fw.tcl

set script_dir [file dirname [file normalize [info script]]]

# 规范 hex (去 0x 前缀/前导零/大小写), 用于数值比对
proc normhex {s} {
    set s [string toupper [string trim $s]]
    if {[string range $s 0 1] == "0X"} { set s [string range $s 2 end] }
    set s [string trimleft $s "0"]
    if {$s eq ""} { return "0" }
    return $s
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
source [file join $script_dir jtag_lcpu_xilinx]

# 读期望值
set expect_file [file join $script_dir fw_expected_words.txt]
if {![file exists $expect_file]} {
    puts "ERROR: 找不到 $expect_file, 请先运行 bin_to_jtag_tcl.py"
    close_hw_manager
    exit 1
}
set fh [open $expect_file r]
set expect_words [split [string trim [read $fh]] "\n"]
close $fh

set n [llength $expect_words]
set mismatch 0
puts "Verifying $n words ..."

# 用 jread 一次回读全部 (与 jwrite 对称), 再逐字比对
puts "  reading back $n words ..."
set got_list [jread 0x10000 $n]
puts "  read done, comparing ..."

for {set i 0} {$i < $n} {incr i} {
    set got [normhex [lindex $got_list $i]]
    set exp [normhex [lindex $expect_words $i]]
    if {$got != $exp} {
        puts "MISMATCH word\[$i\]: expect 0x$exp got 0x$got"
        incr mismatch
        if {$mismatch >= 20} {
            puts "... 差异过多, 中止"
            break
        }
    }
    if {$i > 0 && ($i % 500) == 0} {
        puts "  verified $i/$n"
    }
}

if {$mismatch == 0} {
    puts "FW VERIFY OK: $n words all match"
    close_hw_manager
} else {
    puts "FW VERIFY FAIL: $mismatch words mismatched"
    close_hw_manager
    exit 1
}

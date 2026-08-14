set script_dir [file dirname [file normalize [info script]]]
set proj_name "RiscV_WebSoC"
set proj_dir  $script_dir
set rtl_dir   [file normalize [file join $script_dir ../rtl]]
set ila_home  /home/haitaoz/work/FPGA_Prj/fpga_ila-snapshot-20260812133532
set ila_rtl   [file join $ila_home rtl]

create_project -force $proj_name $proj_dir -part xc7a35tfgg484-2
puts "\[OK\] Project created"

foreach f [lsort [glob -nocomplain ${rtl_dir}/*.v ${rtl_dir}/*.sv]] {
    add_files -norecurse $f
}
puts "\[OK\] Added [llength [glob -nocomplain ${rtl_dir}/*.v ${rtl_dir}/*.sv]] RTL files"

# ILA RTL files (参考 RiscV_WebSoC_3 方式: glob 所有 .v + .vh)
foreach f [lsort [glob -nocomplain ${ila_rtl}/*.v]] { add_files -norecurse $f }
foreach f [lsort [glob -nocomplain ${ila_rtl}/*.vh]] { add_files -norecurse $f }
set_property INCLUDE_DIRS [list ${rtl_dir} ${ila_rtl}] [current_fileset]
puts "\[OK\] Added ILA RTL files"

set_property FILE_TYPE SYSTEMVERILOG [get_files -filter {FILE_TYPE == Verilog}]
set_property top webserver_cpu_top [current_fileset]
update_compile_order -fileset sources_1

add_files -fileset constrs_1 -norecurse [file join $script_dir pins.xdc]
add_files -fileset constrs_1 -norecurse [file join $script_dir timing.xdc]

puts "Running Synthesis..."
launch_runs synth_1 -jobs 8
wait_on_run synth_1

puts "Running Implementation..."
launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1

set bit_src "$proj_dir/${proj_name}.runs/impl_1/webserver_cpu_top.bit"
set bit_dst "$proj_dir/${proj_name}.bit"
if {[file exists $bit_src]} { file copy -force $bit_src $bit_dst; puts "Bitstream: $bit_dst" }

open_run impl_1
report_timing_summary -file "$proj_dir/timing_summary.rpt"
report_utilization    -file "$proj_dir/utilization.rpt"
# 生成 BRAM 内存映射文件 (updatemem 合并固件用, 必须每次 build 重新生成)
write_mem_info -force "$proj_dir/${proj_name}.mmi"
close_design
puts "BUILD COMPLETE"

#!/bin/bash
# upload_fw_jtag.sh — 一键外灌固件 (先 make 出 firmware.bin, 再经 JTAG 灌进指令 RAM)
# 用法: ./upload_fw_jtag.sh   (前提: 纯硬件 bit 已烧录, 见 build.tcl + program.tcl)
set -e

ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT"

# ① 编译固件
echo "=== [1/2] make firmware ==="
cd c_build && make -s && cd ..

# ② 生成 AXI 写事务 Tcl
echo "=== [2/2] bin -> JTAG-AXI txn ==="
python3 c_build/bin_to_jtag_tcl.py c_build/out/firmware.bin build_xilinx/fw_axi_body.tcl

# ③ 灌固件
echo "=== [3/3] JTAG load firmware ==="
cd build_xilinx
source ~/Xilinx/2024.1/Vivado/2024.1/settings64.sh
vivado -mode batch -nojournal -nolog -source jtag_load_fw.tcl

echo "=== done: 建议再跑 verify_fw.tcl 回读比对 ==="

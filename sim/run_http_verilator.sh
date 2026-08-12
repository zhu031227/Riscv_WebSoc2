#!/bin/bash
# HTTP 全链路 Verilator 仿真
# 用法: bash run_http_verilator.sh
set -e
cd "$(dirname "$0")"

echo "=== Verilator 编译 ==="

# 清理旧 build
rm -rf obj_dir

# Verilator: 编译 RTL → C++ → 可执行文件
verilator --cc --exe --build \
  -I../rtl \
  --top-module tb_http \
  --timing \
  --trace \
  --public-flat-rw \
  -Wno-fatal \
  -Wno-lint \
  -Wno-width \
  -Wno-COMBDLY \
  -Wno-INITIALDLY \
  -CFLAGS "-O2" \
  ../rtl/*.v \
  vendor_stubs.v xpm_memory_tdpram_sim.v lcpu_bfm.sv \
  tb_http_verilator.v \
  --exe tb_http.cpp 2>&1 | tail -15

echo ""
echo "=== 运行仿真 ==="
./obj_dir/Vtb_http

echo ""
echo "=== 仿真完成 ==="
echo "波形文件: tb_http.vcd"
echo "用 gtkwave tb_http.vcd 查看"

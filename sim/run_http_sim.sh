#!/bin/bash
# HTTP 全链路仿真脚本
# Phase 1: TCP 三次握手 (SYN→SYN+ACK→ACK→ESTABLISHED)
# Phase 2: HTTP GET 请求 → 验证 HTTP 200 响应
set -e
cd "$(dirname "$0")"

echo "=== 编译 HTTP 仿真 ==="

iverilog -g2012 -I ../rtl -s tb_http \
  -o tb_http.vvp \
  ../rtl/*.v \
  vendor_stubs.v xpm_memory_tdpram_sim.v lcpu_bfm.sv \
  tb_http.v

echo "编译成功！运行仿真..."
echo ""

vvp tb_http.vvp

echo ""
echo "=== 仿真完成 ==="
echo "波形文件: tb_http.vcd"
echo "用 gtkwave tb_http.vcd 查看波形"

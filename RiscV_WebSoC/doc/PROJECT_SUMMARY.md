# RiscV WebSoC 项目总结

**文档日期**: 2026-07-28 | **FPGA**: XC7A35T-FGG484-2 | **PHY**: RTL8211F

---

## 1. 项目概述

在 Xilinx Artix-7 FPGA 上实现 RISC-V 软核 + 千兆以太网 Web 服务器 SoC。

```
PC ←──网线──→ [FPGA板子]
                │
           RTL8211F PHY (RGMII)
                │
           gmii2mac (MAC层, CDC, CRC)
                │
           cpu_channel (包FIFO, 125M↔50M跨时钟域)
                │
           ┌─ RISC-V (PicoRV32 RV32IC) ─┐
           │  固件: TCP/IP + HTTP + LED  │
           │  浏览器访问控制LED           │
           └─────────────────────────────┘
```

---

## 2. 技术架构

### 模块树

```
webserver_cpu_top
├── mmcm_50_125       (时钟: 50/125/200/125_90)
├── rgmii_gmii_bridge (RGMII ↔ GMII + IDELAY)
├── gmii2mac          (MAC层 + CDC + CRC)
├── cpu_channel       (包FIFO: RX/TX, 125M↔50M CDC)
├── lcpu_riscv_wrapper (PicoRV32 + UART LCPU + 总线仲裁)
└── lcpu_fpga_test     (寄存器: LED, CPU_FIFO, 指令RAM)
```

### 时钟域

| 时钟 | 频率 | 用途 |
|------|------|------|
| clk_50m | 50 MHz | RISC-V, LCPU, 寄存器 |
| clk_125m | 125 MHz | gmii2mac, cpu_channel |
| clk_200m | 200 MHz | IDELAYCTRL |
| clk_125m_tx | 125MHz 90° | RGMII TX |

### CPU FIFO 寄存器

| 地址 | 寄存器 | 说明 |
|------|--------|------|
| **RX (CPU读包)** | | |
| 0x6000 | cpu_rd_empty | 1=空 |
| 0x6001 | cpu_rd_rpkt_pop | 写1释放包 |
| 0x6002 | cpu_rd_rpkt_len | 包长度 |
| 0x6004 | cpu_rd_ren | 读使能 |
| 0x6005 | cpu_rd_raddr | 字节偏移 |
| 0x6006 | cpu_rd_rdata | 读数据[7:0] |
| **TX (CPU发包)** | | |
| 0x6100 | cpu_wr_full | 1=满 |
| 0x6102 | cpu_wr_waddr | 字节偏移 |
| 0x6103 | cpu_wr_wdata | 数据[7:0] |
| 0x6104 | cpu_wr_wpkt_len | 包长度 |
| 0x6106 | cpu_wr_wpkt_push | 写1发送 |

---

## 3. C 固件架构

```
reset_entry(0x00)
  └─ program_main()
       ├─ designInit()           ← LED=0, 初始化
       └─ designApp() 主循环
            ├─ tcp_connection_init()
            ├─ tcp_periodic_check()
            └─ 收包 → eth_proc() → ARP/IP/TCP/HTTP
```

### 读包协议

```c
if (!LCPU_RD_EMPTY()) {      // empty=0 有包
    LCPU_RD_START_PACKET();   // pop + ren=1
    len = LCPU_RD_PKT_LEN();  // 读长度
    for (i=0; i<len; i++) {
        LCPU_RD_SET_ADDR(i);  // 设字节偏移
        byte = LCPU_RD_DATA8(); // 读数据
    }
}
```

### 发包协议

```c
while (LCPU_WR_FULL());       // 等TX就绪
for (i=0; i<len; i++)
    LCPU_WR_BYTE(i, data[i]); // 逐字节写
LCPU_WR_PUSH_PACKET(len);     // 推送发送
```

---

## 4. 验证状态

### ✅ 已完成

| 验证项 | 工具 | 结果 |
|--------|------|------|
| RTL 编译 | iverilog 12.0 | 0 errors, 43 文件 |
| BFM 固件加载 | lcpu_bfm | 2505 commands |
| RISC-V 执行 | 仿真 | LED 1111→0000 |
| Vivado 综合 | 2024.1 | 0 errors |
| 布局布线 | 2024.1 | WNS=+1.39ns |
| 资源 | XC7A35T | LUT 21%, FF 17%, BRAM 25% |
| 板级烧录 | JTAG | ✅ |
| UART 固件 | 115200 bps | ✅ |
| RISC-V 运行 | 板级 | LED 可控 |
| 以太网收包 | 板级 | rd_empty=0, LED 计数 |
| 寄存器读写 | 板级 | ren, raddr 写读正常 |
| 网页界面 | HTTP GET | HTML 页面完成 |

### 🟡 调试中

| 项目 | 状态 |
|------|------|
| cpu_rd_rdata 数据 | 返回错误值 (预期0xFF, 实际0x?3等) |

---

## 5. 已知问题

**cpu_rd_rdata 数据错误**: RISC-V 能从 CPU FIFO 收到包(rd_empty=0, LED计数正确), 但逐字节读包时 `cpu_rd_rdata` 返回错误值。ren + raddr 寄存器写读正常(确认 RTL 写逻辑正确), 问题在 `package_fifo_v2` 读数据路径或 `cpu_channel` 信号连接。需 ILA 抓信号排查。

---

## 6. 文件清单

```
RiscV_WebSoC/
├── rtl/           43 RTL 文件 (完全自包含)
├── sim/           仿真环境 (run_sim.sh 一键运行)
├── c/             C 固件 (协议栈 + HTTP + LED)
├── c_build/       Makefile + 编译脚本
├── build_xilinx/  Vivado 构建 (build.tcl + XDC)
├── doc/           设计文档 + 项目总结
└── tcl/           固件 TCL 脚本
```

---

## 7. 快速命令

```bash
# 仿真
cd sim && bash run_sim.sh

# 编译固件
cd c_build && make clean && make riscv_reset_addr=0x100 TCL_BASE=0x10000

# Vivado 构建
cd build_xilinx && rm -rf RiscV_WebSoC.* && vivado -mode batch -source build.tcl

# 烧录 + 加载固件
# (需手动操作)
```

---

## 8. 修复记录

| Bug | 原因 | 修复 |
|-----|------|------|
| BFM 不工作 | delay_time=10 太小 | 改回 1000 |
| lcpu_fpga_test 复位不同步 | sys_rst_n 等 PLL, BFM 先跑了 | 用直接 reset_l |
| 固件 LED 不亮 | CATCH_MISALIGN=1 非对齐 trap | 改为 0 |
| CPU FIFO 信号方向 | 5 个 assign 方向接反 | fpga_cpu_rd_* 修正 |
| 固件地址不匹配 | 0x2000 vs 0x6000 | 对齐 xls 地址 |
| 指令 RAM 太小 | 2048→9616B 固件 | 扩至 5120 words |

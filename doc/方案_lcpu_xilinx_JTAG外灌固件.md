# 方案：RISC-V 固件加载改造 —— JTAG 烧纯硬件 + JTAG 外灌固件

> **一句话**：让 C 固件从「每次改一行都要重编译整个 bitstream」变成「纯硬件 bit 只烧一次，之后改 C 固件 = 终端发一条命令几十秒灌进去」。

---

## 一、目的是什么（为什么做这件事）

### 1.1 现状痛点

当前固件的上板方式是 **updatemem 编译期焊固件**：

```
改 C 代码 → make 编译 → updatemem 把 firmware.bin 合进 bitstream → 烧 RiscV_WebSoC_fw.bit
                                    ↑ 每次都要跑完整 Vivado 综合/实现（~15 分钟）
```

问题：调试协议栈时改一行 C，就要重烧整颗 bit，迭代一次十几分钟，太慢。

### 1.2 三个目标

| # | 目标 | 说明 |
|---|------|------|
| 1 | **UART 继续给 ILA 调试** | 板载串口（L21/M21）保持固定接 ILA，不动 |
| 2 | **JTAG 烧纯硬件 bit** | 产出 `RiscV_WebSoC.bit`：含 JTAG 桥、不含固件，只烧这一次 |
| 3 | **JTAG 外灌固件** | 烧完纯硬件后，终端命令把 `firmware.bin` 逐字灌进指令 RAM，软核立刻跑 |

### 1.3 达成后的工作流对比

```
改造前（慢）:
  改 C → make → updatemem 合 bit → 重烧整颗 bit（Vivado 十几分钟）

改造后（快）:
  ① 纯硬件 bit 烧一次（含 JTAG 桥）
  ② 之后每次改 C:  make → 终端敲一条命令 → 固件经 JTAG 灌进 RAM（几十秒）→ 软核直接跑
```

**核心价值**：C 固件与 RTL 彻底解耦——RTL 不动，改多少 C 都只是「外部输入指令」，不用碰 Vivado。

---

## 二、实现是什么（原理与架构）

### 2.1 RISC-V 软核怎么「跑起来」

- 软核 = `riscv32_top`（PicoRV32 变体），程序存在 **BRAM 指令 RAM**（16KB = 4096 字）。
- 「跑起来」= **指令 RAM 里有有效代码 + 复位释放**。没有操作系统、没有启动过程。
- 指令 RAM 是**双口**：口 1 给 CPU 取指/读写，口 2（`program_wr`）给外部加载用。
- 所以「外灌固件」的本质 = 通过口 2 把指令逐字写进 RAM，然后释放复位。

### 2.2 LCPU 总线架构（谁在谁下面）

```
webserver_cpu_top                        ← 顶层（含 ILA，UART 传输）
 └─ lcpu_riscv_wrapper                   ← 参数 lcpu_type 决定加载通道
     ├─ lcpu_top                          ← 加载器容器（按 lcpu_type 三选一）
     │     ├─ "uart"   → uart_lcpu_top     （ASCII 串口协议）
     │     ├─ "xilinx" → jtag_cpu_xilinx   （JTAG→AXI 桥，内含 jtag_axi_0 IP）
     │     └─ "intel"  → jtag_lcpu_intel   （Intel 专用，不用）
     ├─ riscv32_top                       ← RISC-V CPU + 指令 RAM（自带总线 master）
     └─ lcpu_merge                        ← 双 master 仲裁：加载器优先，RISC-V 次之
          └─ lcpu_fpga_test               ← 地址译码（LCPU 总线 → 各外设）
              ├─ 0x10         → LED 寄存器
              ├─ 0x100        → 复位控制寄存器（写 0 按住 / 写 1 释放）
              ├─ 0x6000~6007  → RX FIFO 寄存器
              ├─ 0x6100~6106  → TX FIFO 寄存器
              └─ 0x10000..0x1FFFF → 指令 RAM（字地址）
```

**关键点**：`lcpu_merge` 把「加载器」和「RISC-V」两条总线 master 合并成一条。加载时**先把 RISC-V 复位按住**（写 `0x100`=0），RISC-V 不抢总线，加载器独占——这是外灌固件能成功的前提。

### 2.3 三种加载通道对比

| lcpu_type | 通道 | 传输速率 | 现状 |
|-----------|------|---------|------|
| `"uart"` | 板载串口 ASCII `sw...` 协议 | 115200bps | 当前配置，但 `cpu_uart_rx=1'b1` 已掐断（UART 给了 ILA） |
| `"xilinx"` | JTAG → AXI（Vivado HW manager） | JTAG 时钟，事务级 | **本方案切过去** |
| `"intel"` | Intel JTAG | — | 不适用 |

### 2.4 JTAG→AXI 桥（`jtag_axi_0`）原理

- `jtag_axi_0` 是 **Xilinx 官方 IP「JTAG to AXI Master」v1.2**，内部用 **BSCANE2** 原语，挂在 JTAG 的 USER1/USER2 用户指令链上。
- 桥在 fabric 里扮演一个 **AXI master**，由 PC 端 Vivado **Hardware Manager** 驱动。
- 数据链：

```
PC 终端 (vivado -mode batch)
   ↓  create_hw_axi_txn / run_hw_axi
JTAG 扫描链 (USB-JTAG 下载器)
   ↓  BSCANE2 (USER1/USER2)
jtag_axi_0  (AXI Master, 32bit 地址/数据)
   ↓  axi2lcpu.v  (AXI → LCPU 总线, 一次一拍)
lcpu_merge → lcpu_fpga_test 地址译码
   ↓
指令 RAM / 复位寄存器 / LED 寄存器
```

- **现状盘点（已核实）**：`build_xilinx/jtag_axi_0.xci` 存在，PART = `xc7a35tfgg484-2`（与工程一致）；`JtagCPU_Amd.gen/` 里有生成好的 IP 产物；`build_xilinx/led_ctrl.tcl` 是当年用 JTAG-AXI 写 LED 的验证脚本——**证明这条桥当年搭起来过**。

### 2.5 地址映射（整个方案唯一要记的东西）

**约定：AXI 地址 = LCPU 字地址，直接对应，不乘 4。**（`led_ctrl.tcl` 用地址 `0x10` 直写 LED 寄存器成功，就是这个约定的证据）

| AXI 地址 | 含义 | 写什么 |
|----------|------|--------|
| `0x100` | 复位控制寄存器 | 写 `0x00000000` 按住 CPU / `0x00000001` 释放 |
| `0x10000 + i` | 指令 RAM 第 i 个字 | 固件第 i 个 32 位字（**小端** unpack） |
| `0x10` | LED 寄存器 | 写低 4 位控制 LED（验证用） |

### 2.6 外灌固件的数据流

```
【灌前·验明正身】read_back.tcl：读 0x0/0x1 版本号 + 0x11/0x10 状态
   ↓ 全部符合预期 → 桥通/映射对/bit正确 → 才允许灌
firmware.bin（objcopy 产出，RISC-V 小端指令字节流）
   ↓ bin_to_jtag_tcl.py：每 4 字节按 <I 小端解成 32 位字
Tcl 事务脚本（逐字 create_hw_axi_txn + run_hw_axi）
   ↓ vivado -mode batch -source jtag_load_fw.tcl
JTAG → BSCANE2 → jtag_axi_0 → AXI → axi2lcpu → LCPU 总线 → 指令 RAM
   ↓
① 写 0x100=0 按住复位
② 逐字写 0x10000+i
③ 写 0x100=1 释放复位 → 软核从 PC=0 开始跑
④ 写 0x10 验证 LED
【灌后·验内容】verify_fw.tcl：回读 0x10000+i 与 firmware.bin 逐字比对
   ↓ 全等 + LED流水灯 + ping 通 → 固件正确
```

---

## 三、怎么去做（分步实施，每步可回退）

> 完整命令见各步。全程**不烧坏板子**：任何一步失败，把 `lcpu_type` 改回 `"uart"` 重编即可恢复现状。

### Step 0 前置确认

- [ ] USB-JTAG 下载器已连接、`vivado` 在 PATH（或 source settings64.sh）
- [ ] `jtag_axi_0.xci` PART 已核实 = `xc7a35tfgg484-2` ✅
- [ ] 备份现有 `build_xilinx/RiscV_WebSoC_fw.bit`（作为回退基线）

### Step 1 改 RTL（1 行）

文件 `rtl/webserver_cpu_top.v:41`：

```verilog
localparam lcpu_type = "xilinx";   // 原为 "uart"
```

**影响分析**：
- `lcpu_top` 走 `gen_xilinx` 分支（例化 `jtag_cpu_xilinx`），`uart_rx/uart_tx` 变成无用输入——**不影响 ILA**，因为 ILA 的 UART 是顶层直连（`ila_uart_rx = uart_rx`），不经过 `lcpu_top`。
- `riscv_reset_l` 仍由寄存器 `0x100` 控制，不用改。
- 警告：`lcpu_top` 的 `uart_rx` 输入悬空，Vivado 报 unused input 警告，忽略即可。

### Step 2 改 build.tcl（+1 行）

文件 `build_xilinx/build.tcl`，在 `create_project` 之后、`launch_runs synth_1` 之前加：

```tcl
read_ip $script_dir/jtag_axi_0.xci
```

**为什么必须加**：`rtl/jtag_cpu_xilinx.v` 例化了 `jtag_axi_0` 模块，而它不在 `rtl/` 里；不加 IP，综合会报 `unknown module jtag_axi_0`。`read_ip` 会让 Vivado 为当前工程重新生成 IP（原 `.xci` 已在 build_xilinx/）。

### Step 3 重编译纯硬件 bit

```bash
cd build_xilinx
source ~/Xilinx/2024.1/Vivado/2024.1/settings64.sh
vivado -mode batch -source build.tcl          # 产出 RiscV_WebSoC.bit（含 JTAG 桥，无固件）
```

验证：`ls -la RiscV_WebSoC.bit`，看综合/实现报告里 **BSCANE2 被例化**、时序收敛。

### Step 3.5 版本号自动更新（推荐，让「验明正身」有意义）

`fpga_build_date/time` 目前是 `rtl/fpga_build_time.v` 里**硬编码**的（`0x20260727` / `0x00000001`），不随日期变。想让**当天烧录的 bit 读到当天的版本号**，在 `build.tcl` 里每次综合前自动重新生成这个文件：

```tcl
# build.tcl — 加在 create_project 之后、add_files 之前
set now [clock seconds]
set bd  [clock format $now -format "%Y%m%d"]   ;# 如 20260816
set bt  [clock format $now -format "%H%M%S"]   ;# 如 093000
set f   [open "../rtl/fpga_build_time.v" w]
puts $f "// Auto-generated by build.tcl — 每次综合自动更新版本戳"
puts $f "module fpga_build_time ("
puts $f "    output wire [31:0] build_date,"
puts $f "    output wire [31:0] build_time"
puts $f ");"
puts $f "    assign build_date = 32'h$bd;"
puts $f "    assign build_time = 32'h$bt;"
puts $f "endmodule"
close $f
```

**为什么这么设计**：FPGA **没有实时时钟（RTC），启动时也不知道今天是几号**，所以版本号必须「编译期烤进去」。每次 build 前用系统时钟现生成一个 `fpga_build_time.v`，综合进 bit——烧进去的版本号天然就是**当天的日期**。

**读回来的样子**：`build_date = 0x20260816`（十六进制逐位读就是 2026-08-16）、`build_time = 0x00093000`（09:30:00）——一眼可读，正好对应当天烧录。

**注意**：该文件每次 build 都会变，建议把 `rtl/fpga_build_time.v` 加进 `.gitignore`（它是生成物，不该进版本库）。

### Step 4 烧录纯硬件 bit

把 `build_xilinx/program.tcl` 的 `PROGRAM.FILE` 指向 `RiscV_WebSoC.bit`，然后：

```bash
cd build_xilinx && vivado -mode batch -source program.tcl
```

**预期**：烧成功，但 **CPU 不跑**（BRAM 空 → 取到非法指令 0x00000000 卡住）——这是对的，下一步才灌固件。

### Step 5 验证 JTAG-AXI 桥通（最小写，里程碑 M1）

复用现成的 `build_xilinx/led_ctrl.tcl`（已适配好地址 `0x10`）：

```bash
cd build_xilinx && vivado -mode batch -source led_ctrl.tcl
```

**预期**：板载 LED 亮 `0x05`（LED0+LED2）→ **证明 JTAG→AXI→LCPU→寄存器整条链通了**。

> 失败排查：① `get_hw_axis` 为空 → bit 里没有桥，回 Step 3 检查 BSCANE2 是否例化；② 事务失败 → 检查 JTAG 连接与 Vivado HW server。

### Step 6 灌固件前「验明正身」：读版本号 + 状态（里程碑 M2）

写读回脚本 `build_xilinx/read_back.tcl`，在**灌固件之前**先读回版本号/状态寄存器，一次确认四件事：① JTAG-AXI **读路径**通；② AXI 地址 = 字地址的**映射**成立；③ 烧的是**正确的纯硬件 bit**；④ 时钟域正常。

```tcl
open_hw_manager
connect_hw_server
current_hw_target [lindex [get_hw_targets] 0]
open_hw_target
set hw_axi [lindex [get_hw_axis -quiet] 0]
if {$hw_axi == ""} { puts "ERROR: 无 JTAG-AXI 实例"; exit 1 }

# ① FPGA 编译版本号（只读 = 纯硬件 bit 的身份签名）
create_hw_axi_txn d0 [get_hw_axis] -type read -address 0x00000000 -len 1
run_hw_axi d0
puts "fpga_build_date = 0x[get_property DATA [get_hw_axi_txn d0]]"
create_hw_axi_txn t0 [get_hw_axis] -type read -address 0x00000001 -len 1
run_hw_axi t0
puts "fpga_build_time = 0x[get_property DATA [get_hw_axi_txn t0]]"

# ② 状态 / 复位默认值
create_hw_axi_txn pll [get_hw_axis] -type read -address 0x00000011 -len 1
run_hw_axi pll
puts "pll_locked = 0x[get_property DATA [get_hw_axi_txn pll]]"
create_hw_axi_txn led [get_hw_axis] -type read -address 0x00000010 -len 1
run_hw_axi led
puts "led(复位默认) = 0x[get_property DATA [get_hw_axi_txn led]]"

close_hw_manager
```

**预期值表**（来源：`lcpu_fpga_test.v` 地址译码 + `fpga_build_time.v`）：

| 地址 | 寄存器 | 预期值 | 确认什么 |
|------|--------|--------|---------|
| `0x0` | fpga_build_date | `0x20260727` | 烧的是正确的纯硬件 bit（身份签名） |
| `0x1` | fpga_build_time | `0x00000001` | 同上 |
| `0x11` | pll_locked | `0x1` | PLL 锁定，时钟域正常 |
| `0x10` | led | `0xF` | 复位默认全亮（`lcpu_fpga_test` 复位值 `4'hf`） |

**判定**：4 个值全部符合预期 → 桥通、映射对、bit 正确，**可以放心灌固件**。任一不符 → 停下排查（查 JTAG 连接 / 检查 bit 是否含桥 / 核对版本号），**别灌**。

> 注：`fpga_build_date/time` 是**编译期**烤进 bit 的——默认 `fpga_build_time.v` 硬编码；按 **Step 3.5** 自动更新后 = **当天 build 日期**。它是「硬件身份」，与固件无关，灌完固件后读回仍是原值，正好区分「硬件层」和「固件层」。**自动更新后预期值不再是固定值，以本次 build 日志 / bit 生成时间为准**（如当天 16:00 烧的，应读到 `0x20260816`）。

### Step 7 外灌固件 + 灌后回读验证（里程碑 M3，核心交付物）

新增两个脚本（规格见第四节）：

```bash
# ① 把 firmware.bin 转成 AXI 事务 Tcl
python3 c_build/bin_to_jtag_tcl.py c_build/out/firmware.bin build_xilinx/fw_axi_body.tcl
# ② 灌固件（按住复位 → 逐字写 → 释放复位）
cd build_xilinx && vivado -mode batch -source jtag_load_fw.tcl
```

**灌后立即回读，确认固件正确落位**（新增 `verify_fw.tcl`，规格见 4.4）：

- **逐字比对**：读回指令 RAM 字 0..N（地址 `0x10000`..），与 `firmware.bin` 按 `<I` 小端解出的值**逐一比对**，全等才算固件写对。例：`0x10000` 应等于 firmware.bin 前 4 字节解出的字（`reset_entry` 的跳转指令）。
- **功能验证**：LED 走 `0x0F` 自检 → 全灭 → **流水灯**；`ping 169.254.1.1` 通。

> **为什么灌后要回读、而不是只靠版本号？** 固件目前**不写** SW 版本号寄存器（`0x2/0x3` 无固件写入），所以：
> - 灌前确认 = 读 `fpga_build_date/time`（验**硬件**身份）
> - 灌后确认 = 回读指令 RAM 比对（验**固件内容**）
>
> **可选增强**（后续改固件时做）：在 `main.c` 启动时把一个固件版本常量写进 Scratch 寄存器（`0x4..0xF`），灌后读回 `0x4` 即可直接确认固件版本，比逐字比对更省事。

### Step 8 全链路回归验证（里程碑 M4）

| 项 | 方法 | 预期 |
|----|------|------|
| ILA 未破坏 | ILA（UART 通道）抓 CPU 总线启动波形 | 波形正常 |
| 与 updatemem 等价 | 同一固件 `updatemem` 烧 `_fw.bit` 对比 | 行为一致 |
| TCP/HTTP 全栈 | 浏览器访问 `169.254.1.1` 控制 LED | 正常 |

### Step 9 固化工作流

写一个快捷脚本 `build_xilinx/upload_fw_jtag.sh`：

```bash
#!/bin/bash
# 用法: ./upload_fw_jtag.sh   （先 cd c_build && make 出 firmware.bin）
python3 c_build/bin_to_jtag_tcl.py c_build/out/firmware.bin build_xilinx/fw_axi_body.tcl
cd build_xilinx && source ~/Xilinx/2024.1/Vivado/2024.1/settings64.sh
vivado -mode batch -nojournal -nolog -source jtag_load_fw.tcl
```

之后每次改 C：`cd c_build && make && cd ../build_xilinx && ./upload_fw_jtag.sh`

---

## 四、新脚本规格

### 4.1 `c_build/bin_to_jtag_tcl.py`

| 项 | 说明 |
|----|------|
| 输入 | `c_build/out/firmware.bin` |
| 输出 | `build_xilinx/fw_axi_body.tcl`（纯 AXI 事务段，供 `jtag_load_fw.tcl` source） |
| 逻辑 | 复用 `bin_to_tcl.py` 的「字节→小端字 + 跳过尾部全零」逻辑；每字生成一对 `create_hw_axi_txn w$i -address 0x10000+i -data <8位hex> -len 1 -type write` + `run_hw_axi w$i` |
| 字节序 | `struct.unpack('<I', chunk)[0]`（与 `upload_fw.py` 一致，RISC-V 小端） |
| 地址 | 字基址 `0x10000`；固件 ~2688 字（尾部全零跳过） |

### 4.2 `build_xilinx/jtag_load_fw.tcl`

```tcl
open_hw_manager
connect_hw_server
current_hw_target [lindex [get_hw_targets] 0]
open_hw_target
set hw_axi [lindex [get_hw_axis -quiet] 0]
if {$hw_axi == ""} { puts "ERROR: 无 JTAG-AXI 实例"; exit 1 }

# ① 按住 CPU 复位
create_hw_axi_txn hold [get_hw_axis] -type write -address 0x00000100 -data 0x00000000 -len 1
run_hw_axi hold

# ② 逐字写固件（source 生成的 fw_axi_body.tcl）
source fw_axi_body.tcl

# ③ 释放复位
create_hw_axi_txn rel [get_hw_axis] -type write -address 0x00000100 -data 0x00000001 -len 1
run_hw_axi rel

# ④ 验证：写 LED 全亮
create_hw_axi_txn led [get_hw_axis] -type write -address 0x00000010 -data 0x0000000F -len 1
run_hw_axi led

close_hw_manager
```

### 4.3 `build_xilinx/read_back.tcl`（灌前验证，见 Step 6）

读回 `0x0`/`0x1`（fpga 编译版本号）+ `0x11`/`0x10`（状态/复位默认），比对预期值表，确认桥通、映射对、bit 正确后才灌固件。完整 Tcl 见 Step 6。

### 4.4 `build_xilinx/verify_fw.tcl`（灌后验证，见 Step 7）

| 项 | 说明 |
|----|------|
| 输入 | `c_build/out/firmware.bin`（由 `bin_to_jtag_tcl.py` 顺带输出每个字的值，或脚本内直接读 bin 解析） |
| 逻辑 | 对指令 RAM 地址 `0x10000+i` 逐字 `-type read`，与 firmware.bin 第 i 个 `<I` 小端字比对；不一致打印 i / 期望 / 实际 |
| 输出 | 全对 → `FW VERIFY OK`；有差异 → 打印差异行并 `exit 1` |

性能参考（写入侧）：逐字 2688 事务 ≈ **几十秒**，可接受。优化项（二期）：只写有效字已内置；尝试 `-len N` 突发（⚠️ `axi2lcpu` 是简单 FSM，一次一拍，突发需实测，默认 `-len 1`）。

---

## 五、风险与回退

| # | 风险 | 说明 | 应对 |
|---|------|------|------|
| 1 | **xilinx 分支从未上板** | `jtag_cpu_xilinx`/`axi2lcpu` 只仿真过 | Step 5 先做最小写测试，通了再往下 |
| 2 | **AXI 地址映射** | `led_ctrl.tcl` 证明 `0x10` 直写成立，但高位地址未验证 | Step 6 读回验证后才灌固件 |
| 3 | **`read_ip` 生成问题** | `.xci` 从 `JtagCPU_Amd` 工程带来 | PART 已核实一致；生成失败就 `add_files` 用 `JtagCPU_Amd.gen/.../synth/jtag_axi_0.v` |
| 4 | **突发写不支持** | `axi2lcpu` 简单 FSM 不流水 | 默认 `-len 1` 逐字写 |
| 5 | **JTAG/ILA 干扰** | ILA 是 UART 传输，理论不占 JTAG 链 | Step 8 抓波形确认 |
| 6 | **加载时总线冲突** | 未按住复位就写 RAM，RISC-V 会抢总线 | 严格按「复位→写→释放」顺序 |

**回退保底**：任何一步失败，`lcpu_type` 改回 `"uart"`、build.tcl 去掉 `read_ip`，重编即 100% 恢复现状（当前已验证的 ILA + updatemem 工作流）。

---

## 六、文件清单

| 文件 | 动作 | 说明 |
|------|------|------|
| `rtl/webserver_cpu_top.v:41` | 改 | `lcpu_type = "xilinx"` |
| `build_xilinx/build.tcl` | 改 | +`read_ip jtag_axi_0.xci` |
| `build_xilinx/program.tcl` | 改 | `PROGRAM.FILE` 指向纯硬件 `RiscV_WebSoC.bit` |
| `build_xilinx/jtag_axi_0.xci` | 复用 | JTAG→AXI 桥 IP（PART 已核实） |
| `build_xilinx/led_ctrl.tcl` | 复用 | 桥通验证模板 |
| `build_xilinx/read_back.tcl` | 新 | 灌前版本号 + 状态读回验证（Step 6） |
| `build_xilinx/verify_fw.tcl` | 新 | 灌后指令 RAM 回读比对固件（Step 7） |
| `c_build/bin_to_jtag_tcl.py` | 新 | firmware.bin → AXI 事务 Tcl |
| `build_xilinx/jtag_load_fw.tcl` | 新 | 外灌固件执行脚本 |
| `build_xilinx/upload_fw_jtag.sh` | 新 | 固化「make + 灌固件」一键脚本 |

---

## 七、常见问题

**Q1：为什么不用 UART 灌，非要走 JTAG？**
A：板载 UART 已经固定给 ILA 调试用。方案前提是「UART 留 ILA」，所以固件加载走 JTAG 这条独立通道，两不耽误。

**Q2：AXI 地址为什么不是字节地址（×4）？**
A：`axi2lcpu` 把 AXI 地址直通给 LCPU 总线，LCPU 总线本身按字地址译码（`lcpu_fpga_test` 里 `address==0x100`、`0x10000..` 都是字）。`led_ctrl.tcl` 用 `0x10` 写 LED 成功，证明约定就是「AXI 地址 = 字地址」。

**Q3：会不会把板子烧坏 / 变砖？**
A：不会。所有改动都在 bitstream 层面，烧失败重烧即可；回退只需把 `lcpu_type` 改回 `"uart"` 重编一次。

**Q4：每次灌固件多久？**
A：~2688 字 ≈ 几十秒（逐字事务）。比重编 bit 的十几分钟快一个数量级。

**Q5：灌固件时 CPU 在干嘛？**
A：写 `0x100=0` 后 CPU 全程处于复位（不发总线请求），固件写完后写 `0x100=1` 才从 PC=0 开始执行——所以没有冲突窗口。

**Q6：读到的版本号怎么变成当天的？**
A：FPGA 没有 RTC，启动时不知道日期，版本号必须编译期烤进 bit。按 **Step 3.5** 在 `build.tcl` 里每次综合前用系统时间重新生成 `rtl/fpga_build_time.v`，当天烧的 bit 读回来就是当天日期（`0x20260816` = 2026-08-16）。

---

## 八、上板踩坑记录（2026-08-17 实测）

> 三个坑都是方案文档没预料、实际 JTAG 灌固件调试中踩出来的。

### 坑 1：烧录后必须 `refresh_hw_device`

纯硬件 bit 烧录后，Vivado HW Manager **缓存了烧录前的 JTAG 链**（旧 bit 没有 BSCANE2），`get_hw_axis` 返回空。

**解决**：所有 JTAG-AXI 脚本在 `open_hw_target` 之后、`get_hw_axis` 之前，必须加：

```tcl
refresh_hw_device [current_hw_device]
```

加了之后才看到 `INFO: [Labtools 27-2302] ... has 1 JTAG AXI core(s)`，`get_hw_axis` 返回 `hw_axi_1`。

### 坑 2：`create_hw_axi_txn` 必须写 `<name> <hw_axi>` 位置参数

`led_ctrl.tcl` 老脚本的写法缺事务 name（把 `-quiet` 放最前、`hw_axi` 放最后），导致创建事务返回空、写 LED 失败。

**正确写法**：

```tcl
create_hw_axi_txn led_txn $hw_axi -type write -address 0x10 -data 0x05 -len 1
run_hw_axi led_txn
```

### 坑 3（最关键）：写固件期间**不能长时间复位 CPU**

原始流程「写 0x100=0 按住复位 → 逐字写 2619 字（~50 秒）→ 写 0x100=1 释放」会导致 **ping 不通**。

**根因**：复位期间 CPU 不读 RX FIFO，但 PHY 持续收广播包，RX FIFO 写满（8 个包）并长时间满，破坏异步 FIFO 的 CDC 状态。实测 `cpu_rd_empty=0`（复位期间 FIFO 持续有数据）。

**验证对照**：复位 1 秒 → ping 通；复位 50 秒 → ping 不通。和写指令 RAM 无关（写 1 字也不破坏网络）。

**最终解决**（改 RTL，根治）：让网络 FIFO 的复位也跟随 CPU 复位，这样写固件期间复位 CPU 时，RX FIFO 也保持清空、不会被 PHY 广播包写满。

`rtl/webserver_cpu_top.v` 里 cpu_channel 的复位改一行：

```verilog
.reset_l(sys_rst_n & riscv_reset_l[0]),   // 原为 sys_rst_n
```

然后 `jtag_load_fw.tcl` 恢复用**「复位写固件」**（复位期间 CPU 不取指、网络 FIFO 保持清空，无双口冲突）：

```tcl
# ① 按住复位 (0x100=0, 同时复位网络 FIFO)
create_hw_axi_txn hold $hw_axi -type write -address 0x100 -data 0x0 -len 1
run_hw_axi hold
# ② 逐字写固件
source fw_axi_body.tcl
# ③ 释放复位 (0x100=1)
create_hw_axi_txn rel $hw_axi -type write -address 0x100 -data 0x1 -len 1
run_hw_axi rel
```

实测：`FW VERIFY OK: 2619 words all match`，ping 稳定 0% 丢包（首包丢、后续通）。

> 备注：早期试过「写固件期间不复位 CPU（跑 trap）」方案，它**不可靠**——写固件 ~50 秒期间 CPU 不读 FIFO、FIFO 仍会被广播包写满，只是碰运气（网络广播包少时能通）。真正可靠的是上面「改 RTL + 复位写固件」。

# FPGA RISC-V 轻量级网络协议栈 — Ping 验证

## 一、项目结构

```
RiscV_webSoC2/RiscV_WebSoC/
├── c/
│   ├── main.c              # 主循环 (ARP + ICMP 分发)
│   ├── eth.c               # 以太网帧收发 (FIFO 直接读写)
│   ├── arp.c               # ARP 请求应答
│   ├── ip.c                # IP 头处理 + 校验和
│   ├── icmp.c              # ICMP Ping 应答
│   ├── comlib.c             # 校验和工具函数
│   └── inc/                # 头文件
│       ├── lcpu_general.h   # 寄存器映射 + 网络常量
│       ├── eth.h / arp.h / ip.h / icmp.h
│       └── comlib.h
├── c_build/
│   ├── Makefile             # RISC-V 交叉编译
│   ├── linker.ld            # 链接脚本 (32KB ROM)
│   ├── bin_to_tcl.py        # bin → TCL 转换
│   └── upload_fw.py         # UART 固件上传工具
├── rtl/                     # RTL 源码 (原项目移植)
├── build_xilinx/
│   ├── RiscV_WebSoC.bit     # 纯硬件 bit 流
│   ├── RiscV_WebSoC_fw.bit  # 硬件 + 固件合并 bit 流
│   ├── update_and_program.sh # 一键: 合入固件 + 烧录
│   ├── build.tcl            # Vivado 工程脚本
│   └── program.tcl          # JTAG 烧录脚本
└── tcl/
    └── InstructRAM.tcl      # 生成的 JTAG 固件写入脚本
```

## 二、配置

本机网络参数在 `c/inc/lcpu_general.h` 中定义：

```c
// MAC: 00:00:01:02:04:05
#define Local_MAC_HIGH   0x00000102
#define Local_MAC_LOW    0x0405

// IP: 169.254.1.1
#define Local_IP_ADDR    0xA9FE0101
```

PC 端需在同一网段（例：`169.254.92.21/16`）。

## 三、编译

```bash
cd RiscV_webSoC2/RiscV_WebSoC/c_build
make clean && make
```

编译产物：
- `out/firmware.elf` — ELF 文件
- `out/firmware.bin` — 纯二进制
- `out/firmware_pads.bin` — 补齐到指令 RAM 深度
- `../tcl/InstructRAM.tcl` — JTAG 下载用 TCL

## 四、烧录到 FPGA

### 一键烧录

```bash
cd RiscV_webSoC2/RiscV_WebSoC/build_xilinx
source ~/Xilinx/2024.1/Vivado/2024.1/settings64.sh
./update_and_program.sh
```

脚本自动完成三步：
1. `firmware.bin` → 16 个 `bank*.mem` 文件
2. `updatemem` 将固件合入 `RiscV_WebSoC.bit` → `RiscV_WebSoC_fw.bit`
3. Vivado Hardware Manager 通过 JTAG 烧录

## 五、验证步骤

### 5.1 确认固件在跑

烧录后观察 FPGA 板 LED：
- 上电瞬间全亮 → 全灭（~200ms 自检）
- 之后心跳灯以 ~1s 间隔依次亮起（单灯循环）

LED 不亮 = 固件没跑起来，检查烧录和复位。

### 5.2 抓包确认通信

```bash
# 终端 1: 抓 ARP + ICMP 包
sudo tcpdump -i eno1 -n -e arp or icmp

# 终端 2: ping FPGA
ping 169.254.1.1
```

正常现象：
```
# tcpdump 输出应看到:
ARP, Request who-has 169.254.1.1 tell 169.254.92.21, length 28
ARP, Reply 169.254.1.1 is-at 00:00:01:02:04:05, length 46
ICMP echo request ... 169.254.92.21 > 169.254.1.1
ICMP echo reply ... 169.254.1.1 > 169.254.92.21
```

### 5.3 常见故障排查

| 现象 | 可能原因 | 排查方法 |
|------|----------|----------|
| LED 不亮 | 固件未运行 | 检查烧录是否成功、检查 PLL 锁定 |
| LED 亮但 ping 不通 | FIFO 时序或协议处理有误 | 见下方"ARP 请求发出无应答" |
| ARP 请求发出无应答 | RX FIFO 卡住 | 确认代码不关 REN、每帧二次 POP |
| ARP 有应答但 ICMP 无 | IP/ICMP 校验和错误 | Wireshark 看 Reply 包校验和字段 |
| 时通时不通 | 时序竞争 | 检查 WEN 脉冲和读写时序 |

### 5.4 Wireshark 抓包要点

如果用 Wireshark（GUI）替代 tcpdump：

1. 选择 FPGA 直连的网卡（如 `eno1`）
2. 过滤器输入 `arp or icmp`
3. 观察 ARP 请求和应答的 MAC/IP 是否匹配
4. 双击 ICMP 包查看 Ethernet / IP / ICMP 各层字段
5. 重点检查：IP 头校验和、ICMP 校验和是否正确

## 六、关键踩坑记录

### 6.1 RX FIFO 访问模式

**错误做法**（初版）：
- 将帧拷贝到内存缓冲区再处理
- 读完调用 `LCPU_RD_STOP()` 关闭读使能
- 只 POP 一次

**正确做法**（参考原项目）：
- 直接从 RX FIFO 随机读写，不拷贝缓冲区
- **永远不关 REN**（读使能保持为 1）
- **每帧 POP 两次**：头部 POP 取出包，尾部 POP 推进到下一包

### 6.2 定时器

**错误做法**：软件 tick 计数器（`static uint32_t tick = 0; return tick++;`），主循环调用一次才 +1，误差极大。

**正确做法**：使用 RISC-V `rdcycle` CSR 指令读取硬件周期计数器（50MHz 下每 20ns +1）。

### 6.3 寄存器定义

必须与 RTL 严格对应。本项目寄存器映射：
```
FIFO_BASE = 0x80000000
RX: _RD(n) = *(0x80000000 + (0x6000+n)*4)
TX: _WR(n) = *(0x80000000 + (0x6100+n)*4)
LED: *(0x80000000 + 0x40)
```

## 七、协议栈数据流

```
PC (169.254.92.21)                          FPGA (169.254.1.1)
     │                                              │
     ├─ ARP Request ──────────────────────────────→ │
     │  "169.254.1.1 的 MAC 是?"                      │
     │                                              ├─ eth_proc() → ARP_PROC
     │                                              ├─ arp_reply() 构造应答
     │ ← ARP Reply ────────────────────────────────┤
     │  "MAC = 00:00:01:02:04:05"                   │
     │                                              │
     ├─ ICMP Echo Request ────────────────────────→ │
     │                                              ├─ eth_proc() → IP_PROC
     │                                              ├─ ip_proc() → ICMP_PROC
     │                                              ├─ icmp_reply() 构造应答
     │ ← ICMP Echo Reply ──────────────────────────┤
     │                                              │
  ping 通 ✓
```

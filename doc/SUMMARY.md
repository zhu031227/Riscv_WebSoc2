# RISC-V 轻量级 TCP/IP 协议栈 — 项目总结

> 项目: RiscV_WebSoC2 | 平台: XC7A35T + PicoRV32  
> 日期: 2026-08-04 ~ 08-07 | 状态: TCP 全协议栈完成 + LED 远程控制

---

## 一、项目成果

从零构建了一个运行在 FPGA RISC-V 软核上的**裸机 TCP/IP 协议栈**，不含任何操作系统或第三方网络库。全部 C 代码手工编写，通过 FIFO 直写架构与硬件交互。

### 协议栈层次

```
应用层:  LED 控制 (TCP短连接) / HTTP (待实现)
传输层:  TCP 状态机 (7状态, 三次握手+数据收发+四次挥手+保洁超时)
网络层:  IP (校验和 + 地址交换)
链路层:  ARP (地址解析) + 以太网帧
驱动层:  RX/TX FIFO 直接读写
```

### 完成的协议与验证

| 协议 | 验证方式 | 状态 |
|------|----------|------|
| ARP | `ping 169.254.1.1` — Wireshark 确认 Request/Reply | ✅ |
| IP | Ping Reply 正常, 校验和正确 | ✅ |
| ICMP | Ping RTT < 1ms, 0% 丢包 | ✅ |
| TCP 三次握手 | `nc -vz 169.254.1.1 7` + Wireshark 抓 SYN/SYN+ACK/ACK | ✅ |
| TCP Echo | `nc 169.254.1.1 7` 输入数据回显 | ✅ |
| TCP LED 控制 | `python3 tcp_led_client.py 0x05` | ✅ |
| TCP 四次挥手 | Wireshark 抓 FIN/ACK 四个包 | ✅ |
| TCP 被动关闭 | 对方先发 FIN → ACK → FIN → LAST_ACK | ✅ |
| TCP RST 处理 | 异常/超时发 RST, 收到 RST 重置 | ✅ |
| TCP 超时重传 | SYN+ACK 每 3s 重发, 最多 3 次 | ✅ |
| TCP 空闲保活 | 6s 无活动发 RST 踢连接 | ✅ |
| TCP TIME_WAIT | 2s 自动回收连接 | ✅ |

---

## 二、关键技术点

### 1. FIFO 访问规则（最关键踩坑）

LCPU 的 RX FIFO 有严格的访问时序要求：
- **REN 永远不关**：读使能保持为 1，关闭会导致后续包卡死
- **每帧 POP 两次**：头部 POP 取出包数据，尾部 POP 推进到下一包
- **直接读写 FIFO**：不能拷贝到内存 buffer 再处理，必须在 FIFO 上原地操作

初版代码用了内存缓冲区 + `LCPU_RD_STOP()` 关 REN，FPGA 以太网完全静默。

### 2. TCP 发送流水线

TCP 发包必须严格在收包流程内完成：
```
eth_proc() → 写 MAC 头到 TX FIFO
ip_header_update() → 从 RX FIFO 拷贝其他字段 + 交换 IP 写 TX
send_tcp_segment() → 写 TCP 头到 TX
LCPU_WR_PUSH_PACKET() → 推送
```
独立发送（不在收包上下文）会导致 `ip_header_update()` 从空 RX FIFO 读到随机值。

### 3. 序列号管理

- SYN 和 FIN 即使不带数据也消耗一个序号 (`tcp_snd_seq++`)
- 忘记递增会导致对方 ACK 号不匹配，连接卡死

### 4. 保洁定时器设计

`tcp_periodic_check()` 需要两个独立时间戳：
- `tcp_last_activity`：任何收包刷新（活动检测）
- `tcp_last_tx_time`：仅发包刷新（重传计时）

用同一个时间戳会导致收包重置重传计时，SYN+ACK 永远不发。

---

## 三、仿真验证

### 仿真环境

- **工具**: Icarus Verilog (iverilog) + GTKWave
- **BFM**: `lcpu_bfm.sv` 读取 `InstructRAM.tcl`，模拟 JTAG 写固件到指令 RAM
- **加速**: `SIM_FAST` 宏跳过延时，RX/TX 宏重定向到内存 buffer

### 仿真 vs 硬件分工

| 验证项 | 仿真 | 硬件 |
|--------|------|------|
| 状态机逻辑 | ✅ LED=0x0F | ✅ |
| TCP 校验和 | 未测 | ✅ Wireshark |
| TX 包格式 | 未测 | ✅ tcpdump |
| 全调用链 | ✅ 编译通过 | ✅ nc 测试 |

> 仿真验证逻辑，硬件验证数据。两项互补。

### Icarus 限制

- `force` 动态包注入不可靠（RHS 只求值一次）
- 全 SoC 仿真极慢（1ms 硬件时间 ≈ 数分钟）

---

## 四、ILA 探针尝试

在 RTL 中集成了 fpga_ila 调试系统（1 核 27 探针，151bit），Vivado 综合实现通过但遭遇时序问题：

- XC7A35T-2 在 125MHz 下无法满足 ILA 核 + 27 探针的时序（139 条违例，WNS=-3.488ns）
- `false_path` 约束仅消除跨时钟域违例，intra-clock 违例无法解决
- 降频到 50MHz 后 ILA 内部违例消除，但 MAC/RGMII 125MHz 域仍有违例
- 最终回退到无 ILA 纯净版本，留待后续解决

---

## 五、项目结构

```
RiscV_webSoC2/
├── c/                  # C 源码 (8 个文件)
│   ├── main.c          # 主循环调度
│   ├── eth.c           # 以太帧 + MAC 头
│   ├── arp.c           # ARP 应答
│   ├── ip.c            # IP 层 + 校验和
│   ├── icmp.c          # Ping 应答
│   ├── tcp.c           # TCP 协议栈 (707行, 7状态)
│   └── comlib.c        # 校验和累加
├── c_build/            # 编译 (Makefile + linker.ld)
├── rtl/                # Verilog RTL (46个文件)
├── sim/                # Icarus 仿真
├── build_xilinx/       # Vivado 工程 + bitstream
├── doc/                # 日报 + 项目文档
└── tcp_led_client.py   # PC 端 LED 控制工具
```

---

## 六、快速验证命令

```bash
# 编译 + 烧录
cd c_build && make clean && make
cd ../build_xilinx && ./update_and_program.sh

# Ping
ping 169.254.1.1

# TCP 握手
nc -vz 169.254.1.1 7

# TCP Echo
echo "hello" | nc 169.254.1.1 7

# LED 控制
python3 tcp_led_client.py 0x05

# 抓包
sudo tcpdump -i eno1 -n tcp port 7
```

---

## 七、后续计划

- [ ] HTTP Web 服务器：浏览器访问 `http://169.254.1.1` 控制 LED
- [ ] ILA 时序修复：降 probe / 升 speed grade / 异步采样
- [ ] 多连接支持
- [ ] UDP 协议

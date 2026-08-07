# RISC-V 轻量级 TCP/IP 协议栈 — 项目全貌与验证指南

## 一、项目概述

基于 XC7A35T FPGA + PicoRV32 RISC-V 软核 + 自定义 FIFO 总线的轻量级 TCP/IP 协议栈，裸机 C 语言实现。

| 组件 | 描述 |
|------|------|
| FPGA | Xilinx XC7A35T-FGG484-2 |
| RISC-V 软核 | PicoRV32 (rv32ic, 50MHz) |
| 网络接口 | RGMII → GMII → MAC (100Mbps) |
| 硬件 FIFO | RX FIFO 映射 `0x80006000`, TX FIFO 映射 `0x80006100` |
| LED | 4 个, 映射 `0x80000040` |
| FPGA IP | 169.254.1.1 |
| FPGA MAC | 00:00:01:02:04:05 |

## 二、软件架构

```
main.c (主循环)
  ├── tcp_periodic_check()  — 保洁定时器
  ├── eth_proc()            — 以太层: 验MAC + 预写应答MAC头到TX FIFO
  ├── ip_proc()             — IP层: 验目的IP + 缓存src_ip
  │     └── ICMP_PROC → icmp_reply()   — Ping应答
  │     └── TCP_PROC  → tcp_handler()  — TCP状态机
  └── _RD(1) = 1            — 推下一个包
```

**关键设计原则**：
- RX/TX FIFO 直接读写，不使用内存缓冲区
- RX 读使能 (REN) 永远不关
- 每帧 POP 两次（头部取出 + 尾部推进）

## 三、文件清单

| 文件 | 说明 | 状态 |
|------|------|------|
| `c/inc/lcpu_general.h` | 寄存器映射 + 网络常量 + 定时器宏 | ✅ |
| `c/comlib.c` | 校验和累加 (cks_sum_cal) | ✅ |
| `c/eth.c` | `eth_proc()` 以太帧解析 | ✅ |
| `c/arp.c` | `arp_reply()` ARP 应答 | ✅ |
| `c/ip.c` | `ip_proc()` + `ip_header_update()` | ✅ |
| `c/icmp.c` | `icmp_reply()` Ping 应答 | ✅ |
| `c/tcp.c` | TCP 状态机 (7状态) + 发送/接收/保洁 | ✅ |
| `c/main.c` | 主循环调度 + LED 流水灯 | ✅ |
| `tcp_led_client.py` | PC 端 TCP LED 控制客户端 | ✅ |
| HTTP 服务器 | 待实现 | ⏳ |

## 四、协议栈完成状态

| 协议/功能 | 状态 | 验证命令 |
|-----------|------|----------|
| ARP + IP + ICMP (Ping) | ✅ | `ping 169.254.1.1` |
| TCP 三次握手 | ✅ | `nc -vz 169.254.1.1 7` |
| TCP 数据收发 (Echo) | ✅ | `nc 169.254.1.1 7` 输入回显 |
| TCP LED 控制 | ✅ | `python3 tcp_led_client.py 0x05` |
| TCP 四次挥手 (主动) | ✅ | `nc` 退出后 Wireshark 抓 FIN/ACK |
| TCP 被动关闭 | ✅ | 对方先发 FIN |
| TCP RST 处理 | ✅ | 收到 RST 直接重置 |
| TCP 超时重传 | ✅ | SYN_RECEIVED 下每 3s 重发 SYN+ACK (最多3次) |
| TCP 空闲保活 | ✅ | 6s 无活动发 RST 踢连接 |
| TCP TIME_WAIT 回收 | ✅ | 主动关闭后 2s 自动释放 |
| HTTP 服务器 | ⏳ | 浏览器访问 `http://169.254.1.1` |

## 五、分阶段验证方法

### 阶段 1: 编译 + 烧录

```bash
# 编译固件
cd ~/work/FPGA_Prj/RiscV_webSoC2/c_build
make clean && make

# 烧录
cd ../build_xilinx
./update_and_program.sh
```

### 阶段 2: Ping 验证 (ARP + IP + ICMP)

```bash
ping 169.254.1.1
```

**预期**: `64 bytes from 169.254.1.1: icmp_seq=1 ttl=64`

**LED 状态**: 流水灯 (0x01 → 0x02 → 0x04 → 0x08 循环)

**Wireshark 过滤**:
```
arp or icmp
```

**检查点**:
- ARP Request → ARP Reply (MAC 00:00:01:02:04:05)
- ICMP Echo Request → ICMP Echo Reply

### 阶段 3: TCP 三次握手

```bash
nc -vz 169.254.1.1 7
```

**预期**: `Connected to 169.254.1.1 7`

**LED 状态**: 收到 SYN 时 LED2 闪, 握手完成 LED 全亮 (0x0F)

**Wireshark 过滤**:
```
tcp.port == 7
```

**检查点**:
- `[S]` SYN → `[S.]` SYN+ACK → `[.]` ACK
- SYN+ACK 的 flags = 0x12 (SYN|ACK)
- 源端口 = FPGA端口(7), 目的端口 = PC随机端口

### 阶段 4: TCP Echo 数据收发

```bash
echo "hello" | nc 169.254.1.1 7
```

**预期**: 收到 echo 回显 "hello"

### 阶段 5: TCP LED 控制

```bash
python3 ~/work/FPGA_Prj/RiscV_webSoC2/tcp_led_client.py 0x05
```

**检查点**:
- 0x00 = 全灭
- 0x0F = 全亮
- 0x05 = LED0 + LED2
- TCP 控灯后流水灯自动暂停

### 阶段 6: TCP 四次挥手

**主动关闭**: `nc` 发完数据退出 → Wireshark 看到 `[F.]` FIN+ACK 四个挥手包

**被动关闭**: 对方先发 FIN → FPGA 回 ACK → 发 FIN → 进入 LAST_ACK

**Wireshark 过滤**:
```
tcp.port == 7 and (tcp.flags.fin == 1 or tcp.flags.reset == 1)
```

### 阶段 7: TCP 超时与保活

**SYN 重传**: CLOSED 收到 SYN 后断开网线 → Wireshark 看每 3s 重发 SYN+ACK (最多 3 次)

**空闲踢**: ESTABLISHED 后不发数据, 等 6s → FPGA 发 RST, 状态回 CLOSED

**TIME_WAIT 回收**: 主动关闭后等 2s → 连接自动释放

## 六、调试工具速查

| 工具 | 用途 |
|------|------|
| `ping 169.254.1.1` | 验证 ARP+IP+ICMP 全链路 |
| `nc -vz 169.254.1.1 7` | 验证 TCP 三次握手 |
| `nc 169.254.1.1 7` | 交互式 TCP Echo 测试 |
| `tcpdump -i eno1 -n tcp port 7` | 抓 TCP 包 |
| `tcpdump -i eno1 -n arp or icmp` | 抓 ARP/ICMP 包 |
| `python3 tcp_led_client.py 0x05` | TCP 控制 LED |
| `gtkwave tb_webserver_cpu_top.vcd` | 仿真波形 |

## 七、向 Claude 提问模板

```
【项目背景】
FPGA XC7A35T + PicoRV32 软核, 裸机 C 协议栈,
FIFO 直写架构, IP=169.254.1.1, 监听端口=7

【当前问题】
[描述具体问题和现象]

【期望结果】
[预期行为]

【实际现象】
[LED状态 / 抓包结果 / 错误信息]

【相关代码】
[粘贴关键代码段]
```

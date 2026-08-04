# RISC-V WebSoC 项目概要设计

**平台**：XC7A35T-FGG484-2 + RTL8211F PHY (RGMII)
**CPU**：PicoRV32 (RV32IC) @ 50MHz
**开发流程**：时许设计 → 代码(RTL+C) → 仿真(iverilog) → 上板(ILA)

---

## 一、项目目标

分三步递进实现 RISC-V 网络 SoC：

| 步骤 | 目标 | 验证方式 |
|------|------|----------|
| **第一步** | Ping 通网络（ARP + ICMP） | PC `ping 169.254.1.1` 有回复 |
| **第二步** | TCP 三次握手 | 网络助手连接 169.254.1.1:80 成功 |
| **第三步** | HTTP 请求响应 | 浏览器访问网页，控制 LED |

---

## 二、硬件架构

```
PC ←──网线──→ [RTL8211F PHY] ←──RGMII──→ [FPGA XC7A35T]
                                              │
                    ┌─────────────────────────┘
                    ▼
            ┌──────────────┐
            │ RGMII ↔ GMII │  Bridge (IDELAY/IDDR/ODDR)
            └──────┬───────┘
                   ▼
            ┌──────────────┐
            │   gmii2mac   │  MAC层 (CDC FIFO + CRC + 前导码)
            └──────┬───────┘
                   ▼
            ┌──────────────┐
            │ cpu_channel  │  包FIFO + 125M↔50M 跨时钟域
            └──────┬───────┘
                   ▼
            ┌──────────────┐
            │lcpu_fpga_test│  寄存器文件 (LED + RX/TX FIFO 接口)
            └──────┬───────┘
                   │ LCPU 总线
                   ▼
            ┌──────────────┐
            │  PicoRV32    │  RISC-V 软核 @ 50MHz
            │  RV32IC      │
            └──────────────┘
```

**时钟域**：CPU 50MHz | MAC 125MHz | RGMII 125MHz(来自 PHY) | 通过异步 FIFO 跨时钟域

---

## 三、软件架构

```
┌─────────────────────────┐
│  web_app.c (应用层)      │  网页内容、LED 控制、业务逻辑
├─────────────────────────┤
│  http.c (HTTP 引擎)      │  GET/POST 解析、响应构建
├─────────────────────────┤
│  tls.c (加密层) [预留]   │  将来升级 HTTPS 的接口位置
├─────────────────────────┤
│  tcp.c (TCP 协议栈)      │  状态机、三次握手、连接管理
├─────────────────────────┤
│  ip.c / icmp.c / arp.c  │  IP 路由、Ping 回复、ARP 回复
├─────────────────────────┤
│  eth.c (以太网层)        │  帧类型解析、MAC 过滤、协议分发
├─────────────────────────┤
│  硬件寄存器接口 (MMIO)   │  读包/发包/定时器/LED
└─────────────────────────┘
```

**设计原则**：协议栈与网页内容分离。改页面只改 `web_app.c`，协议栈不动。

---

## 四、第一步：Ping 通网络

### 数据流

```
收包: PHY → RGMII → MAC → 包FIFO → RISC-V(逐字节读)
发包: RISC-V(逐字节写) → 包FIFO → MAC → RGMII → PHY
```

### 协议流程

```
主循环 designApp():
  等待收包 → eth_proc() 解析帧类型:
    EtherType = 0x0806(ARP) → arp_reply() → 构建ARP应答 → 发送
    EtherType = 0x0800(IP)  → ip_proc():
      Protocol = 0x01(ICMP)  → icmp_reply() → 构建Echo Reply → 发送
```

### 架构决策

- MAC 地址 `00:00:01:02:04:05`，IP `169.254.1.1`，硬编码在 C 代码
- 非本机的 ARP/ICMP 请求直接丢弃
- 超大包（超过可配置阈值）丢弃，防止 FIFO 溢出

---

## 五、第二步：TCP 三次握手

### 连接建立

```
PC                              FPGA
 │                                │
 │── SYN ──────────────────────►  │  CLOSED → SYN_RECEIVED
 │                                │  记录对方 SEQ，分配连接槽
 │                                │
 │◄─ SYN+ACK ───────────────────  │  发送自己的 SEQ + ACK
 │                                │
 │── ACK ──────────────────────►  │  验证 ACK 正确
 │                                │  SYN_RECEIVED → ESTABLISHED
 │                                │
 │~~~~~ 连接建立，可传数据 ~~~~~│
```

### 连接管理

- 最大 16 个同时连接，满时缓存 1 个待处理 SYN
- 监听端口 80（HTTP 标准端口）
- 收到非 SYN 且无匹配连接的包 → 回复 RST（方便调试）
- 空闲超时或 TIME_WAIT 超时后发 RST 关闭连接

### 状态机覆盖

CLOSED → SYN_RECEIVED → ESTABLISHED → (FIN_WAIT_1 → FIN_WAIT_2 / CLOSE_WAIT → LAST_ACK) → TIME_WAIT → CLOSED

支持 SYN+ACK 重传（最多 3 次）、空闲超时、RST 快速关闭。

---

## 六、第三步：HTTP 请求响应

### GET 流程

```
浏览器 → TCP连接 → GET / HTTP/1.1 → FPGA 解析
                                      │
                                      ├─ 匹配 "GET " → 识别为 GET 请求
                                      ├─ 构建响应头 + HTML 体
                                      ├─ 分段发送（每段 ≤ MSS 1460 字节）
                                      └─ 发送 FIN 关闭连接
                                      
浏览器收到 → 渲染 LED 控制网页 → 用户点击按钮 → POST 请求
```

### POST 流程

```
浏览器 → POST /submit → JSON {"addr":"0010","data":"0F","mode":"write"}
                              │
FPGA 解析 → 提取 addr/data/mode → 执行寄存器读写 → 返回操作结果页面
```

### 网页功能

LED 独立开关 + 全亮/全灭按钮，点击后通过 POST JSON 控制硬件 LED 寄存器。

### 错误处理

不支持的 HTTP 方法 → 返回 400 Bad Request + 错误提示页面。

---

## 七、CPU 与硬件的数据接口

RISC-V 通过 **MMIO 寄存器** 读写网络包：

| 操作 | 寄存器 | 说明 |
|------|--------|------|
| 检测有包 | `cpu_rd_empty` | 0=有包待读 |
| 锁定包 | `cpu_rd_rpkt_pop` | 写 1 锁定当前包 |
| 读包长 | `cpu_rd_rpkt_len` | 返回字节数 |
| 逐字节读 | `cpu_rd_raddr` + `cpu_rd_rdata` | 写偏移地址，读数据 |
| 逐字节写 | `cpu_wr_waddr` + `cpu_wr_wdata` + `cpu_wr_wen` | 写偏移+数据+使能 |
| 推出发送 | `cpu_wr_wpkt_len` + `cpu_wr_wpkt_push` | 写长度+推出发送 |

CPU 通过 `rdcycle` 指令读周期计数器作为软件定时器。

---

## 八、系统资源

| 资源 | 使用量 | 可用量 |
|------|--------|--------|
| LUT | ~21% | XC7A35T |
| FF | ~17% | |
| BRAM | ~25% | |
| 连接数 | 16 | 可扩展 |
| 固件大小 | ~10KB | 指令 RAM 32KB |
| CPU 频率 | 50MHz | 时许收敛 |

---

## 九、扩展方向

| 方向 | 说明 |
|------|------|
| **HTTPS** | tls.c 预留接口，需要 AES + SHA-256，建议加硬件加速 |
| **DHCP** | 动态获取 IP，替换硬编码 |
| **WebSocket** | 实时双向通信，网页无需刷新 |
| **硬件加速** | TCP 校验和/IP 校验和/CRC 用硬件并行计算 |
| **外扩 RAM** | 加 DDR 控制器，支持更大网页和更多连接 |

---

*概要设计文档*

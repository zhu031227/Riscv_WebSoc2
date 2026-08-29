# RISC-V WebSoC — 面试深度补充(配合演讲材料使用)

> 与《演讲材料_RiscV_WebSoC项目介绍与答辩QA.md》的关系:演讲版管「讲得漂亮」,本文管「问到第三层不倒」。
> 面试官的钻探模式是:**是什么 → 为什么这么设计 → 换个方案呢 → 具体怎么实现的 → 出问题怎么办**。每一节都按这个层次备到第四层。
> 所有数字标注了出处文件,上场前可自行复核。

---

## 一、硬件线必背(FPGA / 数字 IC 前端岗重点)

### 1.1 镇场数字卡(实测,synth 阶段)

| 指标 | 数值 | 占比 | 出处 |
|---|---|---|---|
| Slice LUTs | **6760** | **32.5%**(20800) | synth_1/webserver_cpu_top_utilization_synth.rpt |
| Slice Registers | 8871 | 21.3%(41600) | 同上 |
| Block RAM Tile | **31** | **62%**(50) | 同上 |
| DSP | 0 | — | 同上 |
| F7/F8 Muxes | 459/128 | — | 同上(LUT as Memory 仅 16 个,大 RAM 几乎全 BRAM) |

讲法示范:「整个 SoC 连协议栈带 MAC 吃掉三分之一 LUT、六成 BRAM,DSP 一个没用——因为校验和、CRC 都是查表+异或逻辑实现,CPU 里没有乘法器需求(见 1.2)。」

⚠️ **诚实边界**:上面是综合后数据。会前强烈建议跑一次 implementation 拿 WNS/TNS——被问「时序收敛了吗」时说「综合通过,布局布线 WNS 是 X」远比「应该没问题」有说服力。跑不了就如实说:「以综合收敛为准,后端数据待补」,并主动补一句你知道 timing 大头在哪儿(CPU 取指路径和 CDC 收敛域)。

### 1.2 PicoRV32 微架构专题(必考中的必考)

本项目实例化参数(`rtl/riscv32_localbus.v:29` 起,**全文背诵级**):

```text
COMPRESSED_ISA      = 1    ← 支持 C 压缩指令,代码密度↑,IRAM 省一半
ENABLE_COUNTERS     = 1    (64 位 rdcycle/rdinstret 可用,C 层做时戳)
ENABLE_REGS_DUALPORT= 1    ← 寄存器堆双端口,部分时钟周期可同时读写
TWO_STAGE_SHIFT     = 1    (移位分两拍,单周期移位换频率)
BARREL_SHIFTER      = 0    ← 没有桶形移位!
ENABLE_MUL/DIV/FAST_MUL = 0 ← 硬件乘除全关,编译器降级为 __mulsi3 等软件循环
ENABLE_PCPI         = 0    (协处理器接口关闭)
PROGADDR_RESET      = 32'h0000_0000  ← 复位取指向量 = IRAM[0]
```

由此推出的三个高频问答:

**Q:每条指令几个周期?**
PicoRV32 是**多周期有限状态机核,不是流水线核**。基础 ALU 运算约 3~4 周期,LW/SW 更多,平均 ~4-7 CPI。Barrel shifter 关闭时长移位更慢。「所以我用 50MHz 主频,不是不想高,是内存访问级状态机设计在给面积让路——这正是它 LUT 省的原因。」

**Q:为什么敢关掉乘除?**
整条业务路径(TCP 序号运算、IP 校验和、指针搬移)只涉及加法和移位;头构造全是字节拼接。编译器对常量乘会转加法移位,真除法只有十进制格式化输出这类冷路径。DSP 占用 0% 就是佐证。

**Q:压缩指令带来什么?**
RVC 下常用指令编码减半,同 16KB IRAM 可放约两倍指令,还减轻取指带宽压力。代价:译码器稍复杂。「对本项目这样页面字符串很长的固件,.rodata 压不到,但 .text 受益明显。」

**Q:为什么选多周期核不用流水线核(VexRiscv/E203)?**
面积预算 XC7A35T 要装下 CPU+MAC+FIFO+ILA;无缓存无 MMU 的确定性访存反而利于裸机调试;我们的性能瓶颈在协议栈软件逻辑而非核吞吐(I/O 型负载,大部分时间在等网包)。

### 1.3 时钟树与 CDC —— 三种手段逐一报出

| 跨域场景 | 手段 | 本工程落点 |
|---|---|---|
| 包数据流 125→50 | 双时钟异步 FIFO,**格雷码指针** | dual_clock_fifo.v / cpu_channel |
| 单拍脉冲事件 | pulse_clock_region_pass(打两拍+边沿还原) | 控制握手 |
| 多位慢速标量(计数器/配置) | 源域稳定采样 + 目的域多级同步 | webserver_wrapper 的统计计数回传 |

答题金句:「多 bit 总线绝不用单纯两级同步器——要么进异步 FIFO,要么格雷码化,要么握手。这是硬纪律。」
追问预备:格雷码为什么能安全跨域?(相邻只有一个 bit 变化,异步采样最多采到前一态);空满判断怎么处理同步延迟保守性(空判据在目的侧实时准、满判据留冗余余量)。

### 1.4 RGMII 物理层

- RGMII = DDR,4bit 数据双沿采样,引脚比 GMII 少一半;
- **TX 侧**:ODDR 原语把 GMII 单沿转双沿输出;**RX 侧**:IDELAY 对 RXC/RXD 加延迟补偿 PCB skew,参考时钟 200MHz(`rgmii_gmii_bridge.v` idelay_refclk);
- IDELAY 分辨率:tAP ≈ 78ps(7 系列 tap),延迟 taps 由静态参数给出;
- 追问「为什么需要 IDELAY」:源同步接口,数据和时钟由 PHY 同时发出,采样窗口要校准到眼图中央;板级走线差让每个 lane 延迟不同。
- 动态校准(eIODELAY/训练)未做,固定 tap 值实测可用——如实说明即可。

### 1.5 MAC 与 CRC

- CRC32 在 **gmii2mac 内部**完成:发送侧逐字节计算并对整帧(含以太头)生成 FCS 追加(`gmii2mac.v` crc32_eth function,~crc 反相输出,多项式 802.3 标准 0x04C11DB7 行为);接收侧 MAC 对帧做 CRC 校验并出 mac_rx_err/crc_err 计数;
- 答「CRC 和 TCP 校验和是不是重复?」——不是:CRC 是物理帧完整性(HW 层,防链路误码),TCP checksum 是端到端完整性(SW 层,防中间设备篡改/伪首部绑五元组),且 TCP checksum 用反码和不受 IP 分片位置影响的设计原因可以延伸。

### 1.6 存储地图与「程序怎么进来」

```
IRAM 4096×32bit @0x00010000(webserver_cpu_top.v init_addr_depth=1024*4)
  ├─ 口 A:CPU 取指(riscv_reset_l 释放后 PC=0 顺序执行)
  ├─ 口 B:寄存器总线写(Loading 模式)/ JTAG-AXI 写(jtag_load_fw.tcl)
bank*.mem build_xilinx 共 16 个 bank 文件 ← 初始化 mem 内容切分产物
linker.ld:ENTRY(reset_entry),唯一 ROM 区 ORIGIN=0x0 LENGTH=32K
           .text.bootloader KEEP 置顶 → 入口前 4 字节就是跳转指令
```
若被问「链接脚本写 32K,IRAM 才 16K?」:如实回答——ld 声明的是地址空间上限,真实加载尺寸以 bin 实际大小为准,这是个已知的参数不同源问题,答辩口径见第六节话术。

### 1.7 复位体系(收口在一句话)

「异步复位、同步撤离 + PLL locked 门控;额外把 CPU 复位做成总线可写寄存器(word 0x100),于是**软件、JTAG 都能热复位 CPU** —— 这是外灌固件能工作的地基。」复位期间网络 FIFO 同时被按住,防止 PHY 广播包把 FIFO 写满(jtag_load_fw.tcl 注释原文)。

---

## 二、软件线必背(嵌入式 / 固件岗重点)

### 2.1 TCP 白板八题精答

**① 三次握手为什么不能两次?**
两个理由都要答:a) 防止历史重复 SYN 建立脏连接(RFC793 delayed duplicate 场景);b) 让双方都确认「自己和对方的收发能力」成立。本项目落地:`tcp.c` 只认纯 SYN(flags=SYN&&!ACK),find_free_connection() 占槽 → SYN_RECEIVED → send_syn_ack 回包且**本地 seq+1(SYN 占一个序号)**(日报 08-04 复盘原话)。

**② 最后一次 ACK 丢了怎么办?**
服务器停在 LAST_ACK 重发 FIN;客户端留在 TIME_WAIT 可以重发 ACK。⇒ 这正是 TIME_WAIT 存在理由之一。若客户端已经关socket,服务器重试耗尽后放弃——所以标准建议让**主动关闭方**承担 TIME_WAIT。

**③ TIME_WAIT 为什么要存在(两理由)?**
a) 保证最后的 ACK 若丢失能重发;b) 让旧连接的迷路报文在网络中自然消亡,避免污染相同四元组的新连接。(顺带可答本项目把它压成 2s 的换算依据:LAN 上 RTT μs 级,2s 已数百倍冗余)

**④ MSS 1460 怎么来的?为什么不靠 IP 分片?**
以太 MTU 1500 − IP 头 20 − TCP 头 20。靠 IP 分片则任一分片丢失整个包作废且中间路由器可能再分,TCP 自己按 MSS 分段丢哪段重哪段。本项目 send_http_data() 按 1460 分段推送 TX FIFO(实际逐字节写,页面前缀 + JSON 响应)。

**⑤ 校验和手算怎么做?**
16 位反码和:按 16bit 求和(含伪首部:src_ip/dst_ip/零字节/协议号/TCP长度),溢出高位折返回低位(fold),最后取反码。现场白板演算例子准备一个:0x4500+0x003c+0x1c46… 记住口诀「先累加、再折叠、末取反」。IP 头的 checksum 只覆盖 IP 头本身且每次 TTL 变化要重算——本项目 ip_header_update() 直接重写头部顺便刷它。

**⑥ ARP 表在哪?**
精彩加分点:**这个项目没有 ARP 缓存表,也不需要**——它是纯应答式(request 来才 reply),请求帧里自带对方 MAC/IP,eth_proc 解析时就顺手预写了应答头。只有「主动发起方」才需要 ARP 查询缓存。(如果延伸:接 DNS/NTP 客户端那一刻就必须补 ARP 表项老化和哈希查找——正好衔接日报里学过布谷鸟哈希。)

**⑦ RST 什么情况下发?**
收到不属于任何连接槽的四元组且端口非监听端口;以及本项目空闲 6s 保活踢人(资源回收优先于优雅告别,服务端常见取舍)。

**⑧ keepalive 和你的 6 秒踢有什么区别?**
标准 keepalive 默认 2 小时空闲探活(应用无关保底),我是**应用语义级的会话回收**(控制面板短交互场景,占着不发活就尽快释放 4 个并发槽)。参数动机完全不同。

### 2.2 协议头默写表(字段 + 本项目实填值)

**以太帧**:DST MAC(6)·SRC MAC(6)·EtherType(2,ARP=0x0806/IP=0x0800)·payload·FCS(4)
本项目 MAC = 00:00:01:02:04:05。
**IPv4 头** 20B:版本/IHL(0x45)·TOS·Total Length·ID·Flags/Frag·TTL(直连场景够用故常量)·Protocol(ICMP=1,TCP=6)·Header Checksum·SRC IP·DST IP。
**TCP 头** 20B(本项目 h[20] 数组逐字段填,send_syn_ack 可直接背):Sport·Dport·Seq·Ack·DataOffset(0x50)·Flags·Window(**恒 65535**)·Checksum(伪首部法)·UrgentPtr(0)。无 options(没有 SYN option 协商,MSS 不通告——连同无窗口协商一起构成 B1 的「简化但有界」故事)。

### 2.3 启动链路逐行(30 秒讲完不卡壳)

```text
上电 → PROGADDR_RESET=0(取指 IRAM[0])
     → linker.ld ENTRY(reset_entry) 且 .text.bootloader KEEP 放最前
     → reset_entry() 带 naked/no_bootstrap 属性(无 prologue,直接一条 j program_main)
     → program_main():LED 自检 → tcp_init() 清 4 槽 → while(1){保洁;LED;读FIFO;分发}
```
亮点句:「裸机入口是我自己写的 12 行,没有 crt0 依赖——bss 是 NOLOAD 段、data 直接编进 ROM,启动零搬运,这也是 page flash 式加载能做到秒级的原因。」
栈初始化:复位后 sp 需第一条指令外手动处理(naked 特性),链接脚本 STACKADDR 由 wrapper 传入 picorv32 参数,排障故事 S1 里正有它的戏份。

### 2.4 并行数组 & 线性查找辩护词(日报 Q&A 已成文,直接引用)

- 并行数组而非结构体数组:嵌入式下规避对齐填充,独立清槽内存写放大最小;
- O(n) 线性查找:n≤4 时常数小于任何智能结构的开销,「先用对的简单,再换成复杂的正确」;
- 若扩容路线:n 到几百先址排序/池化,n 上万再上哈希(已自学布谷鸟哈希,日报 08-25)。

### 2.5 无硬件乘除的软件代价

`__mulsi3` 移位加循环(~10-20 cycle)、十进制打印用除 10 循环较昂贵 ⇒ 固件里所有时间戳都是十六进制展示、日志走 LED 信号灯而不是 sprintf——「这是我 4KB 级脚本的约束自觉」。若被问优化方向:开 ENABLE_FAST_MUL 约增数百 LUT,或者协议内容搬到外部 SRAM 后用查表乘法。

---

## 三、三个 STAR 故事(行为面/开放题直接调用)

### S1 · 「软核死活不跑,最后凶手是一行 build.tcl」(真实 08-04 日报)

- **S**:烧完 bit CPU 无任何动作(sp/初始化怀疑点众多),仿真却是好的;
- **T**:定位是构建链问题还是 RTL 问题;
- **A**:逐一排除 sp 初始化、UART 连接、BRAM 深度、复位源、探针 fanout、timing clock group —— 全排除后,对比一个「能 ILA 抓到波形」的姊妹工程 `RiscV_WebSoC_3`,发现它 build.tcl 多一句 `write_mem_info -force`,即多了 `.mmi`(BRAM 初始化地址映射文件);
- **R**:补齐后一切正常。沉淀两条方法论:**“差异对比法”优于“盲猜穷举”**;bitstream 的 BRAM 初始化不是单个文件的事,是 .mem/.mmi/updatеmem 一整条证据链,缺一环就静默失败。
- 面试官后续大概率问「ILU 怎么用的」→ 接 1.3 CDC 与 ILA 夹逼定位(soft_ila×2 + hub,2048 深)。

### S2 · 「JTAG 外灌固件:从一个重复劳动痛点到四步 Tcl」

- **S**:每次改一行 C 都要等 Vivado 全流程(~小时级),迭代节奏被打断;
- **T/A**:分析启动本质(PC 取指 + 复位释放),意识到 IRAM 是真双口 RAM,第二口本来就是空闲的 ⇒ 设计四步流程:hold 复位(连带按住 net FIFO 防广播包灌满)→ 逐字写入(bin_to_jtag_tcl.py 自动生成写序列)→ 释放复位 → 写 LED 验证存活;配套 verify_fw.tcl/read_back.tcl 回读校验;
- **R**:固件迭代小时级→秒级,74 次提交里绝大部分后期调优都靠它撑起节奏。「改工具链的人,改变了自己所有的开发节奏」——用于回答「项目中你最有主见的决定」。

### S3 · 「被旧快照 BFM 冤枉的字节序假错」(复盘框架,细节请按记忆补齐 1-2 个真实波形现象)

- **S**:RTL 明明正确,仿真却持续报字节序错误;
- **T**:不确定是设计错还是环境错;
- **A**:建立「先验证指控者,再信结论」流程,追查到共用库 `ip_common` 是陈年旧快照,BFM 行为与新 RTL 不一致;
- **R**:fix 不是改一行代码,而是建立了 fpga_golden 作为唯一可信运行手册基准。方法论沉淀:**任何环境性失败先核对依赖新鲜度**;(此事故发生在共用库层面,属于 FPGA_Prj 工程族的公共教训。)

---

## 四、简历项目描述模板(直接可抄,按方向二选一或合并)

**FPGA 方向版**:
> 基于 Artix-7(XC7A35T)+ 开源 PicoRV32 核实现轻量 WebSoC:自研 RGMII↔GMII 桥(IDELAY/ODDR 时序校准)、GMII MAC(硬件 CRC32)、跨时钟域包 FIFO 数据通路(格雷码指针/握手同步);全工程 LUT 占用 32%、BRAM 62%、零 DSP;配 ILA 双探针夹逼定位链路异常;独立完成综合后时序分析与资源评估。

**嵌入式方向版**:
> 从零实现裸机 C TCP/IP 协议栈(ARP/IP/ICMP/TCP/HTTP):7 状态 TCP 连接管理、SYN 重传/空闲回收/TIME_WAIT 保洁定时器、零拷贝 FIFO 直读直写架构、GET/POST+JSON/form 解析控制面板;自定义裸机启动链路(naked entry + linker script + RISC-V 嵌入式工具链);固件支持 JTAG 秒级在线更新;Wireshark/七阶段实机清单验证三次握手至挥手全程。

两版共同的隐藏钩子:「52.5MB 器件上做到 XX」这种量化句会把面试官引向你最强的阵地(数字卡),**先亮数字再等提问 = 你出的牌你定节奏**。

---

## 五、高频开放题速答模板

| 问题 | 30 秒答案骨架 |
|---|---|
| 项目最大的难点? | 不在某行代码,而在「静默失败」类问题——S1 的 .mmi 事件为代表 |
| 最有成就感的时刻? | 第一次 `ping 169.254.1.1` 通的那一刻——五层协议第一次合龙 |
| 如果重做一遍改什么? | ① 写代码前先把地址映射文档化(当时 reg 表靠口口相传);② 数据段重传一开始就留 hook;③ CI 化单元仿真 |
| 如何证明它是好的? | 三层验证金字塔:TB×5(Verilator/Icarus)→ Wireshark 对照 RFC 报文 → ILA 物理/接口层双探针 |
| 团队还是独立? | 独立为主,但大量借鉴开源核(PicoRV32 社区)与同事参考工程的对比学习——「站在巨人的肩膀上但每级台阶自己爬」 |

---

## 六、会前 Checklist

- [ ] 跑一次 implementation,拿真实 WNS/TNS(当前只有 synth 数据,别被当场抓住「你后端没看吧」)
- [ ] 数字卡打印(第一节 1.1 + 演讲版第三节)
- [ ] Demo 录屏备份(浏览器面板 + nc + JTAG 换固件各一段),S2 故事必备
- [ ] 简历上的项目描述按第四节定稿后**,打印一份贴在自己工位预演三天**
- [ ] 时间紧版自测:能否 60 秒内画出系统框图?90 秒内默写 send_syn_ack 流程?
- [ ] 补齐 S3 星型故事里的具体细节(日期/现象/抓波截图)

---

*生成于 2026-08-27。所有参数均可溯源:riscv32_localbus.v:29-58 / gmii2mac.v / tcp.c / linker.ld / jtag_load_fw.tcl / synth utilization rpt / 步骤00_日报_20260804.md。*

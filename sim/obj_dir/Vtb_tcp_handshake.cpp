// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_tcp_handshake__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_tcp_handshake::Vtb_tcp_handshake(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_tcp_handshake__Syms(contextp(), _vcname__, this)}
    , clk_50m_in{vlSymsp->TOP.clk_50m_in}
    , reset_l{vlSymsp->TOP.reset_l}
    , rgmii_rxc{vlSymsp->TOP.rgmii_rxc}
    , rgmii_rxd{vlSymsp->TOP.rgmii_rxd}
    , rgmii_rx_ctl{vlSymsp->TOP.rgmii_rx_ctl}
    , uart_rx{vlSymsp->TOP.uart_rx}
    , led_o{vlSymsp->TOP.led_o}
    , uart_tx{vlSymsp->TOP.uart_tx}
    , mac_tx_sop{vlSymsp->TOP.mac_tx_sop}
    , mac_tx_en{vlSymsp->TOP.mac_tx_en}
    , mac_tx_data{vlSymsp->TOP.mac_tx_data}
    , mac_tx_eop{vlSymsp->TOP.mac_tx_eop}
    , mac_rx_sop{vlSymsp->TOP.mac_rx_sop}
    , mac_rx_en{vlSymsp->TOP.mac_rx_en}
    , mac_rx_data{vlSymsp->TOP.mac_rx_data}
    , mac_rx_eop{vlSymsp->TOP.mac_rx_eop}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__u_xpm_memory_tdpram_bank}
    , __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__u_xpm_memory_tdpram_bank{vlSymsp->TOP.__PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__u_xpm_memory_tdpram_bank}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb_tcp_handshake::Vtb_tcp_handshake(const char* _vcname__)
    : Vtb_tcp_handshake(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_tcp_handshake::~Vtb_tcp_handshake() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_tcp_handshake___024root___eval_debug_assertions(Vtb_tcp_handshake___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_tcp_handshake___024root___eval_static(Vtb_tcp_handshake___024root* vlSelf);
void Vtb_tcp_handshake___024root___eval_initial(Vtb_tcp_handshake___024root* vlSelf);
void Vtb_tcp_handshake___024root___eval_settle(Vtb_tcp_handshake___024root* vlSelf);
void Vtb_tcp_handshake___024root___eval(Vtb_tcp_handshake___024root* vlSelf);

void Vtb_tcp_handshake::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_tcp_handshake::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_tcp_handshake___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_tcp_handshake___024root___eval_static(&(vlSymsp->TOP));
        Vtb_tcp_handshake___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_tcp_handshake___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_tcp_handshake___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_tcp_handshake::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_tcp_handshake::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_tcp_handshake::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_tcp_handshake___024root___eval_final(Vtb_tcp_handshake___024root* vlSelf);

VL_ATTR_COLD void Vtb_tcp_handshake::final() {
    Vtb_tcp_handshake___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_tcp_handshake::hierName() const { return vlSymsp->name(); }
const char* Vtb_tcp_handshake::modelName() const { return "Vtb_tcp_handshake"; }
unsigned Vtb_tcp_handshake::threads() const { return 1; }
void Vtb_tcp_handshake::prepareClone() const { contextp()->prepareClone(); }
void Vtb_tcp_handshake::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_tcp_handshake::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtb_tcp_handshake___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_tcp_handshake___024root__trace_init_top(Vtb_tcp_handshake___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_tcp_handshake___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_tcp_handshake___024root*>(voidSelf);
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_tcp_handshake___024root__trace_decl_types(tracep);
    Vtb_tcp_handshake___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_tcp_handshake___024root__trace_register(Vtb_tcp_handshake___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_tcp_handshake::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_tcp_handshake::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtb_tcp_handshake___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}

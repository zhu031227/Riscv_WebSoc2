// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_tcp_handshake.h for the primary calling header

#include "Vtb_tcp_handshake__pch.h"
#include "Vtb_tcp_handshake___024root.h"

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_static__TOP(Vtb_tcp_handshake___024root* vlSelf);

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_static(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_tcp_handshake___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_static__TOP(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__have_expect = 0U;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__read_time_out_cnt = 0U;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__cmd_count = 0U;
}

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_final(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__stl(Vtb_tcp_handshake___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_tcp_handshake___024root___eval_phase__stl(Vtb_tcp_handshake___024root* vlSelf);

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_settle(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_tcp_handshake___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_tcp_handshake.v", 6, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_tcp_handshake___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__stl(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_tcp_handshake___024root___stl_sequent__TOP__0(Vtb_tcp_handshake___024root* vlSelf);

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_stl(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_tcp_handshake___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_tcp_handshake___024root___eval_triggers__stl(Vtb_tcp_handshake___024root* vlSelf);

VL_ATTR_COLD bool Vtb_tcp_handshake___024root___eval_phase__stl(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_tcp_handshake___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_tcp_handshake___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__ico(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__act(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_tcp_handshake.u_dut.clk_125m)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_tcp_handshake.u_dut.sys_rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk_50m_in)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_txc_oddr.async_rst)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_txc_oddr.async_set)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(negedge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_tx_ctl_oddr.async_rst)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_tx_ctl_oddr.async_set)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[0].u_txd_oddr.async_rst)\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[0].u_txd_oddr.async_set)\n");
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[1].u_txd_oddr.async_rst)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[1].u_txd_oddr.async_set)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 13 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[2].u_txd_oddr.async_rst)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 14 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[2].u_txd_oddr.async_set)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 15 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[3].u_txd_oddr.async_rst)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 16 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[3].u_txd_oddr.async_set)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 17 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.rgmii_rxc_bufg)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 18 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.u_rx_ctl_iddr.async_rst)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 19 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.u_rx_ctl_iddr.async_set)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 20 is active: @(negedge tb_tcp_handshake.u_dut.u_bridge.u_rx.rgmii_rxc_bufg)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 21 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[0].u_rxd_iddr.async_rst)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 22 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[0].u_rxd_iddr.async_set)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 23 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[1].u_rxd_iddr.async_rst)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 24 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[1].u_rxd_iddr.async_set)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 25 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[2].u_rxd_iddr.async_rst)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 26 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[2].u_rxd_iddr.async_set)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 27 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[3].u_rxd_iddr.async_rst)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 28 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[3].u_rxd_iddr.async_set)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 29 is active: @(posedge tb_tcp_handshake.u_dut.gmii_rx_clk)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 30 is active: @(posedge tb_tcp_handshake.u_dut.clk_50m)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 31 is active: @(negedge reset_l)\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 32 is active: @(negedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.reset_l_s)\n");
    }
    if ((0x200000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 33 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[0].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 34 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[0].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 35 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[1].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 36 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[1].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 37 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[2].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 38 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[2].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 39 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[3].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x10000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 40 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[3].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x20000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 41 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[4].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x40000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 42 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[4].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x80000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 43 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[5].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x100000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 44 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[5].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x200000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 45 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[6].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 46 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[6].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 47 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[7].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 48 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[7].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 49 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[8].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 50 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[8].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 51 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[9].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x10000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 52 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[9].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x20000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 53 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[10].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x40000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 54 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[10].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x80000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 55 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[11].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x100000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 56 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[11].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x200000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 57 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[12].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 58 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[12].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 59 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[13].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 60 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[13].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 61 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[14].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 62 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[14].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 63 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[15].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(1U))) {
        VL_DBG_MSGF("         'act' region trigger index 64 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[15].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(1U))) {
        VL_DBG_MSGF("         'act' region trigger index 65 is active: @(edge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(1U))) {
        VL_DBG_MSGF("         'act' region trigger index 66 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(1U))) {
        VL_DBG_MSGF("         'act' region trigger index 67 is active: @([changed] tb_tcp_handshake.u_dut.u_riscv.jtag_ack)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__nba(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_tcp_handshake.u_dut.clk_125m)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_tcp_handshake.u_dut.sys_rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk_50m_in)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_txc_oddr.async_rst)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_txc_oddr.async_set)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(negedge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_tx_ctl_oddr.async_rst)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.u_tx_ctl_oddr.async_set)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[0].u_txd_oddr.async_rst)\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[0].u_txd_oddr.async_set)\n");
    }
    if ((0x800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[1].u_txd_oddr.async_rst)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[1].u_txd_oddr.async_set)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 13 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[2].u_txd_oddr.async_rst)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 14 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[2].u_txd_oddr.async_set)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 15 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[3].u_txd_oddr.async_rst)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 16 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_tx.gen_txd_oddr[3].u_txd_oddr.async_set)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 17 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.rgmii_rxc_bufg)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 18 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.u_rx_ctl_iddr.async_rst)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 19 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.u_rx_ctl_iddr.async_set)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 20 is active: @(negedge tb_tcp_handshake.u_dut.u_bridge.u_rx.rgmii_rxc_bufg)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 21 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[0].u_rxd_iddr.async_rst)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 22 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[0].u_rxd_iddr.async_set)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 23 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[1].u_rxd_iddr.async_rst)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 24 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[1].u_rxd_iddr.async_set)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 25 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[2].u_rxd_iddr.async_rst)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 26 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[2].u_rxd_iddr.async_set)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 27 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[3].u_rxd_iddr.async_rst)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 28 is active: @(posedge tb_tcp_handshake.u_dut.u_bridge.u_rx.gen_rxd_iddr[3].u_rxd_iddr.async_set)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 29 is active: @(posedge tb_tcp_handshake.u_dut.gmii_rx_clk)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 30 is active: @(posedge tb_tcp_handshake.u_dut.clk_50m)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 31 is active: @(negedge reset_l)\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 32 is active: @(negedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.reset_l_s)\n");
    }
    if ((0x200000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 33 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[0].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 34 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[0].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 35 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[1].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 36 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[1].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 37 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[2].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 38 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[2].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 39 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[3].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x10000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 40 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[3].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x20000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 41 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[4].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x40000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 42 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[4].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x80000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 43 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[5].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x100000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 44 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[5].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x200000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 45 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[6].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 46 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[6].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 47 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[7].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 48 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[7].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 49 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[8].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 50 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[8].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 51 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[9].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x10000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 52 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[9].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x20000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 53 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[10].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x40000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 54 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[10].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x80000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 55 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[11].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x100000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 56 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[11].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x200000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 57 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[12].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x400000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 58 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[12].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x800000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 59 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[13].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 60 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[13].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 61 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[14].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 62 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[14].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 63 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[15].u_xpm_memory_tdpram_bank.clka)\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(1U))) {
        VL_DBG_MSGF("         'nba' region trigger index 64 is active: @(posedge tb_tcp_handshake.u_dut.u_riscv.riscv_cpu_generation.u_riscv_cpu.u_instru_ram.gen_xilinx_xpm_tdpram.xpm_bank[15].u_xpm_memory_tdpram_bank.clkb)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(1U))) {
        VL_DBG_MSGF("         'nba' region trigger index 65 is active: @(edge tb_tcp_handshake.u_dut.clk_125m_tx)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(1U))) {
        VL_DBG_MSGF("         'nba' region trigger index 66 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(1U))) {
        VL_DBG_MSGF("         'nba' region trigger index 67 is active: @([changed] tb_tcp_handshake.u_dut.u_riscv.jtag_ack)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_tcp_handshake___024root___ctor_var_reset(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_50m_in = VL_RAND_RESET_I(1);
    vlSelf->reset_l = VL_RAND_RESET_I(1);
    vlSelf->rgmii_rxc = VL_RAND_RESET_I(1);
    vlSelf->rgmii_rxd = VL_RAND_RESET_I(4);
    vlSelf->rgmii_rx_ctl = VL_RAND_RESET_I(1);
    vlSelf->uart_rx = VL_RAND_RESET_I(1);
    vlSelf->led_o = VL_RAND_RESET_I(4);
    vlSelf->uart_tx = VL_RAND_RESET_I(1);
    vlSelf->mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__clk_50m_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__rgmii_rxc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__rgmii_rxd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__rgmii_rx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__uart_rx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__led_o = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__uart_tx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__rgmii_txc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__rgmii_txd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__rgmii_tx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__Eth0_MDC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__Eth0_MDIO = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__rgmii_reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__clk_50m_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_txc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_txd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_tx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_rxc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_rxd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_rx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__Eth0_MDC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__Eth0_MDIO = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__rgmii_reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__uart_rx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__uart_tx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__led_o = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__clk_50m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__clk_125m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__clk_200m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__clk_125m_tx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__pll_locked = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__phy_rst_cnt = VL_RAND_RESET_I(21);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__phy_rst_n_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_dv = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_txd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__gmii_tx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_rx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_tx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_rpkt_pop_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wen_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wpkt_push_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_raddr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_waddr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_wpkt_len = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_rpkt_len = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__bus_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__pram_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__pram_addr = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__pram_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__riscv_reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_build_date = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__fpga_build_time = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__led_val = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_50m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_125m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_200m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_125m_tx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_50m_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__locked = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_fb = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_125m_unbuf = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_200m_unbuf = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_125m_tx_unbuf = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__clk_50m_cpu_unbuf = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKFBOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKFBOUTB = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT0B = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT1B = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT2B = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT3 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT3B = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT4 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT5 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKOUT6 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__LOCKED = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__PWRDWN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__RST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKFBIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__CLKIN1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__lock_cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__locked_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_125__DOT__I = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_125__DOT__O = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_200__DOT__I = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_200__DOT__O = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_125_tx__DOT__I = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_125_tx__DOT__O = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_50_cpu__DOT__I = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_bufg_50_cpu__DOT__O = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_build_time__DOT__build_date = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_build_time__DOT__build_time = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_tx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_txd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_tx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rxd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rx_dv = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_txc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_txd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_tx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_rxc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_rxd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_rx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__idelay_refclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_tx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_txd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_tx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_tx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__Q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__D1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__D2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rgmii_rxc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rgmii_rxd = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rgmii_rx_ctl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rxd = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rx_dv = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rx_er = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__idelay_refclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rgmii_rxc_bufg = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_delayed = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rx_ctl_delayed = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q1 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q2 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rx_ctl_q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rx_ctl_q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_idelayctrl__DOT__RDY = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_idelayctrl__DOT__REFCLK = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_idelayctrl__DOT__RST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rxc_bufg__DOT__I = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rxc_bufg__DOT__O = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__DATAOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__IDATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__INC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__LD = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__LDPIPEEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__CNTVALUEIN = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__CNTVALUEOUT = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__CINVCTRL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__DATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_idelay__DOT__REGRST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__Q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__D = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__DATAOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__IDATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__INC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__LD = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__LDPIPEEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__CNTVALUEIN = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__CNTVALUEOUT = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__CINVCTRL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__DATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__0__KET____DOT__u_rxd_idelay__DOT__REGRST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__DATAOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__IDATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__INC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__LD = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__LDPIPEEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__CNTVALUEIN = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__CNTVALUEOUT = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__CINVCTRL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__DATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__1__KET____DOT__u_rxd_idelay__DOT__REGRST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__DATAOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__IDATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__INC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__LD = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__LDPIPEEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__CNTVALUEIN = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__CNTVALUEOUT = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__CINVCTRL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__DATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__2__KET____DOT__u_rxd_idelay__DOT__REGRST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__DATAOUT = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__IDATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__INC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__LD = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__LDPIPEEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__CNTVALUEIN = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__CNTVALUEOUT = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__CINVCTRL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__DATAIN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_idelay__BRA__3__KET____DOT__u_rxd_idelay__DOT__REGRST = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__Q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__D = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__Q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__D = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__Q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__D = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__Q2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__CE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__D = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__R = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__S = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__async_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__async_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__sync_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__sync_set = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXD = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXEN = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXER = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXDV = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXER = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXD = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_rx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__mac_tx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_full_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_empty_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_data_err_line = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_correct_pkt_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_crc_err_pkt_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_correct_pkt_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_error_pkt_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_data = VL_RAND_RESET_I(10);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_data_en_mac_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_data_mac_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_data_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_mac_out = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_rx_asyncfifo__write_data = VL_RAND_RESET_I(10);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_eth_presemble__rx_data_err_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_eth_presemble__rx_data_en_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_eth_presemble__rx_data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__write_data = VL_RAND_RESET_I(10);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__read_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__read_data = VL_RAND_RESET_I(10);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__next_in_ptr = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__in_ptr = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__in_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__out_ptr_gray1 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__out_ptr_gray2 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__next_out_ptr = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__out_ptr = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__out_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__in_ptr_gray1 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__in_ptr_gray2 = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__read_addr = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__empty_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full_s = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(10);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_en_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_err_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_out = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_en_out = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_data_err_out = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_in = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_eth_byte_cnt = VL_RAND_RESET_I(14);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_preamble_seen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__rx_valid_header = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_dly = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt = VL_RAND_RESET_I(14);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT____Vcellinp__u_fix_delay__data_in = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__data_in = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__data_out = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__fun_log2__Vstatic__cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__fun_log2__Vstatic__div = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__di_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__do_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__di_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__dii_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__do_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__wren_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__data_a = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__address_a = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__address_b = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__q_b = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__eff_addr_a = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__eff_addr_b = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__q_b_int = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__ram[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__q_b_r = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__byte_idx_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_stat_cnt_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_rx_stat_cnt_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_stat_cnt_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__mac_tx_stat_cnt_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__mac_rx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__stat_cnt_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__stat_cnt_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_done = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__rx_en_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__rx_data_r = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__o_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__o_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__o_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__o_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__o_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_data_d0 = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__i_err_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__data_in_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__data_byte_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__crc_done = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__crc_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc_bits__Vstatic__crc_o_width = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc32_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc32_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc32_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc32_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc32_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ccitt_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ccitt_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ccitt_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ccitt_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ccitt_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ibm_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ibm_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ibm_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ibm_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc16_ibm_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc8_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc8_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc8_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc8_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc8_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__fun_crc7_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(7);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__data_in_rev = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__data_in_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__crc_out_t = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__crc_out_s = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__m = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__crc32_d8_gen__DOT__crc_init = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__mac_tx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__stat_cnt_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__stat_cnt_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o_en_d = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o_d = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_done = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_done_dlyed = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__ins_crc_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_out_r = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT____Vcellinp__u_fix_delay__data_in = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT____Vcellinp__u_crc__data_in_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__data_in = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__data_out = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__fun_log2__Vstatic__cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__fun_log2__Vstatic__div = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__di_addr = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__do_addr = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__di_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__dii_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__do_data = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__wren_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__data_a = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__address_a = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__address_b = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__q_b = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__eff_addr_a = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__eff_addr_b = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__q_b_int = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__ram[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__q_b_r = VL_RAND_RESET_I(9);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__byte_idx_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_byte_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc_done = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc_bits__Vstatic__crc_o_width = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc32_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc32_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc32_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc32_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc32_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ccitt_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ccitt_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ccitt_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ccitt_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ccitt_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ibm_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ibm_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ibm_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ibm_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc16_ibm_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc8_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc8_d8__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc8_d16__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc8_d24__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc8_d32__Vstatic__crc_out_tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__fun_crc7_d1__Vstatic__crc_out_tmp = VL_RAND_RESET_I(7);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in_rev = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc_out_t = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc_out_s = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__m = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc32_d8_gen__DOT__crc_init = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_rx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_rx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_rx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_tx_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_tx_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_tx_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__recv_pkt_drop_cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__dbg_fifo_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__dbg_fifo_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__dbg_fifo_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_wpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__frame_hit = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__rx_byte_cnt_r = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__rx_byte_cnt = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_wpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__mac_in_rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__tx_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__ram_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__ram_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__ram_waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__ram_wpara = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__ram_wen_permit = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__wpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wclk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__wpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rclk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__underflow = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_wptr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_wclk_s1 = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_wclk_s2 = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__wpkt_para_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_para_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_para_data_r = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_reg = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_pop_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__full_i = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__full_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__empty_i = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_pop_wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__para_wdata_r = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__para_wen_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__avail_space = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__wptr_ext = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rptr_ext = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__used_words = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_para_data_wclk = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__rpkt_pop_wclk_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__nb_rptr_wclk_latch = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__wpkt_data_addr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_data_addr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_for_data = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__ram_addr_a_r = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__ram_wren_a_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__ram_data_a_r = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__clk_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__clk_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_as = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bs = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bss = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bsss = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__write_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__next_in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__next_out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full_s = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(26);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__write_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__Vstatic__gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__Vstatic__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__next_in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__next_out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__empty_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__full_s = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(26);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT____Vlvbound_h9df47209__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__clock_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__clock_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__wren_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__data_a = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__address_a = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__address_b = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__q_b = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_a = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_b = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__q_b_int = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__ram[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__q_b_r = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__byte_idx_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wclk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__wpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rclk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__underflow = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_wptr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_wclk_s1 = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_wclk_s2 = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__wpkt_para_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_para_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_para_data_r = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_reg = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_pop_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_i = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__empty_i = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_pop_wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__para_wdata_r = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__para_wen_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__avail_space = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__wptr_ext = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rptr_ext = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__used_words = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_para_data_wclk = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__rpkt_pop_wclk_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__nb_rptr_wclk_latch = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__wpkt_data_addr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_data_addr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_for_data = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_addr_a_r = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_wren_a_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_data_a_r = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__clk_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__clk_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_as = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bs = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bss = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_bsss = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__write_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__next_in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__next_out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full_s = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(26);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__wclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__write_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__rclk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_data = VL_RAND_RESET_I(26);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__Vstatic__gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__Vstatic__i = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__next_in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__next_out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__out_ptr_gray = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray1 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__in_ptr_gray2 = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__read_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__empty_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__full_s = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(26);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT____Vlvbound_h9df47209__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__clock_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__clock_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__wren_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__data_a = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__address_a = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__address_b = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__q_b = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_a = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_b = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__q_b_int = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__ram[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__q_b_r = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__byte_idx_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__rpkt_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__rpkt_para = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__raddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__rdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ipg_adjust = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ram_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ram_wdata = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ram_waddr = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ram_wpara = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__op_doing = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__rpkt_pop_dly = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__data_len = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ipg_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__ren_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__clk_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__o_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__o_en = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__o_data = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__o_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__o_err = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_data_d0 = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__i_err_d0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__uart_rx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__uart_tx = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__pram_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__pram_addr = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__pram_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__pram_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_address_s = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_ack_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__rddata_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata_2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address_2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_ack_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__rddata_2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__rddata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req_1_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req_2_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh_1_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata_1_r = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address_1_r = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh_2_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata_2_r = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address_2_r = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__cur_state = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__OP_DONE = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__RD_DATA = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__ADDRESS = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__WR_DATA = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__RH_WL = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__EXEC = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__file = 0;
    VL_RAND_RESET_W(1024, vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__command);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__temp_addr = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__temp_data = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__dly_t = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__have_expect = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__expect_data = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__read_time_out_cnt = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__cmd_count = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__ret = 0;
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__wr_byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__program_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__program_waddr = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__program_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__program_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__irq = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__req_m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__rhwl_m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__wr_byte_en_m = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__wdata_m = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__address_m = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__rdata_m = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__ack_m = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__reset_l_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_Req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_RhWl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_ReqAddr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_DataWr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_DataRd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__SUBBUS_RiscV_Ctrl_Ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RlWh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_ByteEn = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_Addr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_WrData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RdData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__wr_byte_en_d = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__wr_byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__irq = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__rv_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__resetn = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__trap = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_read = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_write = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_insn = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_rs1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_rs2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_rd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__eoi = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__trace_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__trace_data = VL_RAND_RESET_Q(36);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__count_cycle = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__count_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_op1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_op2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__reg_sh = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__next_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq_delay = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq_mask = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq_pending = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__timer = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpuregs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x3 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x4 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x5 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x6 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x7 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x8 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x9 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x10 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x11 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x12 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x13 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x14 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x15 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x16 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x17 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x18 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x19 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x20 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x21 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x22 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x23 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x24 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x25 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x26 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x27 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x28 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x29 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x30 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_reg_x31 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_mul_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_mul_rd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_mul_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_mul_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_div_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_div_rd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_div_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_div_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_int_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_int_rd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_int_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_int_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_state = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_wordsize = VL_RAND_RESET_I(2);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_rdata_word = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_rdata_q = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_do_prefetch = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_do_rinst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_do_rdata = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_do_wdata = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_xfer = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_secondword = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_firstword_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__last_mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_firstword = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_firstword_xfer = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__prefetched_high_word = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__clear_prefetched_high_word = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_16bit_buffer = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_rdata_latched_noshuffle = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_rdata_latched = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_la_use_prefetched_high_word = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__mem_done = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lui = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_auipc = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_beq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_bne = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_blt = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_bge = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_bltu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_bgeu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lb = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lw = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lbu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_lhu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sb = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sw = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_addi = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_slti = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sltiu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_xori = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_ori = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_andi = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_slli = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_srli = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_srai = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_add = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sub = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sll = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_slt = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sltu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_xor = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_srl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_sra = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_or = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_and = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_rdcycle = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_rdcycleh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_rdinstr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_rdinstrh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_ecall_ebreak = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_getq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_setq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_retirq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_maskirq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_waitirq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_timer = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__instr_trap = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_imm_j = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoder_trigger = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoder_trigger_q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoder_pseudo_trigger = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoder_pseudo_trigger_q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__compressed_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_lui_auipc_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_lb_lh_lw_lbu_lhu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_slli_srli_srai = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_sb_sh_sw = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_sll_srl_sra = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_slti_blt_slt = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_sltiu_bltu_sltu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_lbu_lhu_lw = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_alu_reg_imm = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_alu_reg_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_compare = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__is_rdcycle_rdcycleh_rdinstr_rdinstrh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__new_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_rs1val = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_rs2val = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_rs1val_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_rs2val_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__q_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_next = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__launch_next_insn = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_valid_insn = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cached_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpu_state = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__irq_state = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__dbg_ascii_state);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__set_mem_do_rinst = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__set_mem_do_rdata = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__set_mem_do_wdata = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_store = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_stalu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_compr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_trace = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_is_lu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_is_lh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_is_lb = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__latched_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__current_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_timeout_counter = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__pcpi_timeout = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__next_irq_pending = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__do_waitirq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_out = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_out_q = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_out_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_out_0_q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_wait_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_add_sub = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_shl = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_shr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_eq = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_ltu = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__alu_lts = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__clear_prefetched_high_word_q = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpuregs_write = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpuregs_wrdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpuregs_rs1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__cpuregs_rs2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_picorv32__DOT__decoded_rs = VL_RAND_RESET_I(5);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__wr_byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__cur_state = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_opdone_s = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_RiscV32_LocalBus__DOT__u_RiscV32IntfBridge__DOT__rv_rdata_s = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_Req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_RhWl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_ReqAddr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_DataWr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_DataRd = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_riscv_ctrl_Ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_RlWh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_Addr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_WrData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_RdData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__timeout_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__is_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__is_req_cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__reg_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__reg_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__riscv_ctrl_sb_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__riscv_ctrl_sb_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_instuct_ram_Req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_instuct_ram_RhWl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_instuct_ram_ReqAddr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__SUBBUS_instuct_ram_DataWr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__instuct_ram_sb_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__instuct_ram_sb_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_RdData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_RlWh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_ByteEn = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_Addr = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_WrData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__address = VL_RAND_RESET_I(31);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__req_d = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__rhwl_d = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__wren_a = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__data_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__address_a = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_a = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__wren_b = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__data_b = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__address_b = VL_RAND_RESET_I(13);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_b = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__wren_byte_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__wren_byte_b_eff = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__eff_addr_a = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__eff_addr_b = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_a_int = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_b_int = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__addr_a_idx = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__addr_b_idx = VL_RAND_RESET_I(12);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__addr_a_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__addr_b_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_addr_a = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_addr_b = VL_RAND_RESET_I(8);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_valid_r = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_valid_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xa = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xb = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__wea_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__bank_b_active = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__web_b = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT____VdfgRegularize_h1e0df310_0_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT____VdfgRegularize_h1e0df310_2_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__fpga_build_date = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__fpga_build_time = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__sw_build_date = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__sw_build_time = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_1 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_2 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_3 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_5 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_6 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_7 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_8 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_9 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_10 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__Scrach_RW_11 = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__led = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__pll_locked = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rpkt_pop = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rpkt_pop_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rpkt_len = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rpkt_para = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_ren = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_raddr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_reop_pre = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_full = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wen_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_waddr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wpkt_len = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wpkt_push = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_wpkt_push_ind = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__riscv_reset_l = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_RlWh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_Addr = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_WrData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_RdData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__timeout_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__is_req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__is_req_cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__reg_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__reg_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__SUBBUS_program_ram_Req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__SUBBUS_program_ram_RhWl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__SUBBUS_program_ram_ReqAddr = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__SUBBUS_program_ram_DataWr = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__program_ram_sb_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__program_ram_sb_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_RdData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_RlWh = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_ByteEn = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_Addr = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_WrData = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__rhwl = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__address = VL_RAND_RESET_I(16);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__req_d = VL_RAND_RESET_I(3);
    vlSelf->tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__rhwl_d = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__2__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__2__data_in = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__8__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__8__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__12__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__12__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__14__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__14__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__18__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__18__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__20__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__20__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__22__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__bin2gray__22__data_in = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt = VL_RAND_RESET_I(14);
    vlSelf->__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__pulse_as = VL_RAND_RESET_I(1);
    vlSelf->__VdlyVal__tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__ram__v0 = VL_RAND_RESET_I(8);
    vlSelf->__VdlyDim0__tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__ram__v0 = VL_RAND_RESET_I(12);
    vlSelf->__VdlySet__tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__gen_inferred_ram__DOT__ram__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__clk_125m__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk_50m_in__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__clk_125m_tx__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rgmii_rxc_bufg__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__async_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__async_set__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__clk_50m__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset_l__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__reset_l_s__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__u_xpm_memory_tdpram_bank__clka__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__u_xpm_memory_tdpram_bank__clkb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_ack__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}

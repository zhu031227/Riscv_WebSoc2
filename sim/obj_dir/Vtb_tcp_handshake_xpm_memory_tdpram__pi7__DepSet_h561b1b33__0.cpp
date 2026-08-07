// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_tcp_handshake.h for the primary calling header

#include "Vtb_tcp_handshake__pch.h"
#include "Vtb_tcp_handshake_xpm_memory_tdpram__pi7.h"

VL_INLINE_OPT void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___eval_initial__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___eval_initial__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sbiterra = 0U;
    vlSelfRef.dbiterra = 0U;
    vlSelfRef.sbiterrb = 0U;
    vlSelfRef.dbiterrb = 0U;
}

VL_INLINE_OPT void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__0(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__mem__v0 = 0U;
    vlSelfRef.__VdlySet__mem__v1 = 0U;
}

VL_INLINE_OPT void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__1(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.enb) & (IData)(vlSelfRef.web))) {
        vlSelfRef.__VdlyVal__mem__v1 = vlSelfRef.dinb;
        vlSelfRef.__VdlyDim0__mem__v1 = vlSelfRef.addrb;
        vlSelfRef.__VdlySet__mem__v1 = 1U;
    }
    if (((IData)(vlSelfRef.enb) & (IData)(vlSelfRef.regceb))) {
        vlSelfRef.doutb = vlSelfRef.mem[vlSelfRef.addrb];
    }
}

VL_INLINE_OPT void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__2(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.ena) & (IData)(vlSelfRef.wea))) {
        vlSelfRef.__VdlyVal__mem__v0 = vlSelfRef.dina;
        vlSelfRef.__VdlyDim0__mem__v0 = vlSelfRef.addra;
        vlSelfRef.__VdlySet__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.ena) & (IData)(vlSelfRef.regcea))) {
        vlSelfRef.douta = vlSelfRef.mem[vlSelfRef.addra];
    }
}

VL_INLINE_OPT void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__3(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___nba_sequent__TOP__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__mem__v0) {
        vlSelfRef.mem[vlSelfRef.__VdlyDim0__mem__v0] 
            = vlSelfRef.__VdlyVal__mem__v0;
    }
    if (vlSelfRef.__VdlySet__mem__v1) {
        vlSelfRef.mem[vlSelfRef.__VdlyDim0__mem__v1] 
            = vlSelfRef.__VdlyVal__mem__v1;
    }
}

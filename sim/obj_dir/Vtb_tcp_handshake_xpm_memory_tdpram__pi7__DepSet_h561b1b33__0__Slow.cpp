// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_tcp_handshake.h for the primary calling header

#include "Vtb_tcp_handshake__pch.h"
#include "Vtb_tcp_handshake_xpm_memory_tdpram__pi7.h"

VL_ATTR_COLD void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___ctor_var_reset(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_tcp_handshake_xpm_memory_tdpram__pi7___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->sleep = VL_RAND_RESET_I(1);
    vlSelf->clka = VL_RAND_RESET_I(1);
    vlSelf->rsta = VL_RAND_RESET_I(1);
    vlSelf->ena = VL_RAND_RESET_I(1);
    vlSelf->regcea = VL_RAND_RESET_I(1);
    vlSelf->wea = VL_RAND_RESET_I(1);
    vlSelf->addra = VL_RAND_RESET_I(8);
    vlSelf->dina = VL_RAND_RESET_I(32);
    vlSelf->injectsbiterra = VL_RAND_RESET_I(1);
    vlSelf->injectdbiterra = VL_RAND_RESET_I(1);
    vlSelf->douta = VL_RAND_RESET_I(32);
    vlSelf->sbiterra = VL_RAND_RESET_I(1);
    vlSelf->dbiterra = VL_RAND_RESET_I(1);
    vlSelf->clkb = VL_RAND_RESET_I(1);
    vlSelf->rstb = VL_RAND_RESET_I(1);
    vlSelf->enb = VL_RAND_RESET_I(1);
    vlSelf->regceb = VL_RAND_RESET_I(1);
    vlSelf->web = VL_RAND_RESET_I(1);
    vlSelf->addrb = VL_RAND_RESET_I(8);
    vlSelf->dinb = VL_RAND_RESET_I(32);
    vlSelf->injectsbiterrb = VL_RAND_RESET_I(1);
    vlSelf->injectdbiterrb = VL_RAND_RESET_I(1);
    vlSelf->doutb = VL_RAND_RESET_I(32);
    vlSelf->sbiterrb = VL_RAND_RESET_I(1);
    vlSelf->dbiterrb = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__VdlyVal__mem__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyDim0__mem__v0 = VL_RAND_RESET_I(10);
    vlSelf->__VdlySet__mem__v0 = 0;
    vlSelf->__VdlyVal__mem__v1 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyDim0__mem__v1 = VL_RAND_RESET_I(10);
    vlSelf->__VdlySet__mem__v1 = 0;
}

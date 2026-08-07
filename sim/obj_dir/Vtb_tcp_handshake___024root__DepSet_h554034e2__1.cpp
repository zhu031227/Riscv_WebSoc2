// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_tcp_handshake.h for the primary calling header

#include "Vtb_tcp_handshake__pch.h"
#include "Vtb_tcp_handshake___024root.h"

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__1(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_data 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array
        [vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr];
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__rpkt_para_data 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array
        [vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr];
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_data 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array
        [vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr];
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_para_data 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__mem_array
        [vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__read_addr];
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__2(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_rhwl 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__RH_WL;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_wdata 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__WR_DATA;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_address 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__ADDRESS;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_req 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__lcpu_sim__DOT__u_lcpu_bfm__DOT__EXEC;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrl_rdh_1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_rhwl;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__wrdata_1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_wdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__address_1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_address;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__u_lcpu_merge__DOT__op_req_1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__jtag_req;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__58(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__58\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pll_locked 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__locked_r;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__pll_locked 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pll_locked;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__59(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__59\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_rpkt_len 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_rpkt_len;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_a 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_addr_a_r;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full_s 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__next_in_ptr;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((3U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | (4U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 
                    = (1U & ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in) 
                             ^ ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in) 
                                >> 1U)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((6U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = 1U;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 
                    = (1U & VL_REDXOR_4((6U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__data_in))));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((5U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0) 
                          << 1U));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = 2U;
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__Vfuncout 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray;
            }(), (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__16__Vfuncout)) 
           == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr_gray2));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__in_ptr_gray2) 
           == ([&]() {
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__out_ptr;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((3U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | (4U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 
                    = (1U & ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in) 
                             ^ ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in) 
                                >> 1U)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((6U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = 1U;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0 
                    = (1U & VL_REDXOR_4((6U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__data_in))));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray 
                    = ((5U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray)) 
                       | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT____Vlvbound_h9df47209__0) 
                          << 1U));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__i = 2U;
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__Vfuncout 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__Vstatic__gray;
            }(), (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__bin2gray__10__Vfuncout)));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_rpkt_len 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_rpkt_len;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_data_a_r 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n)
            ? (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wdata)
            : 0U);
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_wren_a_r 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_wen_ind) 
               & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg))));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__full_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_rd_empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__empty_i 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__empty_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_rd_empty 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_rd_empty;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__data_a 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_data_a_r;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__wren_a 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__ram_wren_a_r;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n) 
           & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_i));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_i 
        = (0x5eeU > (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__avail_space));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__cpu_wr_full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__cpu_wr_full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__full_reg;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__cpu_wr_full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__fpga_cpu_wr_full;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__3(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_b 
        = (0xfffU & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_for_data) 
                     + (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__cpu_rd_raddr)));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_data_addr 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__eff_addr_b;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__data_ram_dual__DOT__u_data_ram__DOT__address_b 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__rpkt_data_addr;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__62(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__62\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_set) 
               || (1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__sync_rst)))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__63(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__63\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_set) 
               || ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__sync_rst)) 
                   & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__sync_set))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__64(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__64\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_set) 
               || ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_rst)) 
                   & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_set) 
                      | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d1)))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__65(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__65\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_set) 
               || ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_rst)) 
                   & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__sync_set) 
                      | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d2)))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__4(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux = 0U;
    if ((0U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0U];
    }
    if ((1U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [1U];
    }
    if ((2U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [2U];
    }
    if ((3U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [3U];
    }
    if ((4U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [4U];
    }
    if ((5U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [5U];
    }
    if ((6U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [6U];
    }
    if ((7U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [7U];
    }
    if ((8U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [8U];
    }
    if ((9U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [9U];
    }
    if ((0xaU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xaU];
    }
    if ((0xbU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xbU];
    }
    if ((0xcU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xcU];
    }
    if ((0xdU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xdU];
    }
    if ((0xeU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xeU];
    }
    if ((0xfU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_bank
            [0xfU];
    }
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RdData 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_b_valid_r)
            ? vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_b_mux
            : 0U);
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_b 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RdData;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_b_int 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RdData;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_RdData 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__RAMIF_Instuct_Ram_Ram_RdData;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram__DOT__Ram_RdData 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_riscv_reg__DOT__RAMIF_instuct_ram_Ram_RdData;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__5(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__5\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux = 0U;
    if ((0U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0U];
    }
    if ((1U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [1U];
    }
    if ((2U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [2U];
    }
    if ((3U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [3U];
    }
    if ((4U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [4U];
    }
    if ((5U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [5U];
    }
    if ((6U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [6U];
    }
    if ((7U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [7U];
    }
    if ((8U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [8U];
    }
    if ((9U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [9U];
    }
    if ((0xaU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xaU];
    }
    if ((0xbU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xbU];
    }
    if ((0xcU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xcU];
    }
    if ((0xdU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xdU];
    }
    if ((0xeU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xeU];
    }
    if ((0xfU == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_r))) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux 
            = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_bank
            [0xfU];
    }
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__bank_sel_a_valid_r)
            ? vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__q_a_mux
            : 0U);
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__pram_rdata 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__program_rdata 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_a 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__q_a_int 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_RdData 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__pram_rdata;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram__DOT__Ram_RdData 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_reg__DOT__RAMIF_program_ram_Ram_RdData;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__6(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__6\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__Q1) 
           ^ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__Q2));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXER 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rx_er 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rx_er 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__7(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__7\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q1 
        = ((((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__Q1) 
             << 3U) | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__Q1) 
                       << 2U)) | (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__Q1) 
                                   << 1U) | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__Q1)));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__8(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__8\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q2 
        = ((((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__Q2) 
             << 3U) | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__Q2) 
                       << 2U)) | (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__Q2) 
                                   << 1U) | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__Q2)));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__66(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__66\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__67(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__67\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 4U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__68(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__68\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 1U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__69(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__69\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 5U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__70(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__70\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 2U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__71(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__71\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 6U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__72(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__72\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 3U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__73(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__73\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__Q 
        = ((1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_rst))) 
           && ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_set) 
               || (1U & ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_rst)) 
                         & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__sync_set) 
                            | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                               >> 7U))))));
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__9(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__9\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT____Vcellinp__u_crc__data_in_en 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o_en) 
           & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__data_o_en_d));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in_en 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT____Vcellinp__u_crc__data_in_en;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_done 
        = ((~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT____Vcellinp__u_crc__data_in_en)) 
           & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__data_in_en_d0));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__crc_done 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__crc_done;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__74(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__74\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full_s 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__next_in_ptr;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray 
                    = ((7U & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray)) 
                       | (8U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray 
                    = ((0xeU & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in) 
                                ^ ((IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in) 
                                   >> 1U))));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__i = 1U;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray 
                    = ((0xdU & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray)) 
                       | (2U & (VL_REDXOR_4((6U & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in))) 
                                << 1U)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__i = 2U;
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray 
                    = ((0xbU & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray)) 
                       | (4U & (VL_REDXOR_4((0xcU & (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__data_in))) 
                                << 2U)));
                vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__i = 3U;
                vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__Vfuncout 
                    = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__Vstatic__gray;
            }(), (IData)(vlSelfRef.__Vfunc_tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__bin2gray__0__Vfuncout)) 
           == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__out_ptr_gray2));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__rx_afifo_full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full_s;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__full_s;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__75(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__75\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__rgmii_txc 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__rgmii_txc = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_txc 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txc 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__Q;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__76(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__76\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__rgmii_tx_ctl 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__rgmii_tx_ctl = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_tx_ctl 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_tx_ctl 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__Q;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__10(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__10\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd 
        = (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q2) 
            << 4U) | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rxd_q1));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_RXD 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_rxd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gmii_rxd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__81(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__81\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n) {
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out = 0U;
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out = 0U;
        vlSelfRef.__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt = 0U;
        if (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out) 
             | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_dly) 
                >> 8U))) {
            vlSelfRef.__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt 
                = (0x3fffU & ((IData)(1U) + (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt)));
        }
        if ((7U > (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt))) {
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out 
                = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out;
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out = 0x55U;
        }
        if ((7U == (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt))) {
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out 
                = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out;
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out = 0xd5U;
        }
        if ((7U < (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt))) {
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out 
                = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_dly) 
                         >> 8U));
            vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out 
                = (0xffU & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_dly));
        }
    } else {
        vlSelfRef.__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt = 0U;
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out = 0U;
        vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out = 0U;
    }
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt 
        = vlSelfRef.__Vdly__tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_eth_byte_cnt;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__tx_en;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_in 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__tx_data_en_mac_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXEN 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d2 
        = ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXER) 
           ^ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_tx_en 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_en_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__D1 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 0U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__D2 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 4U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__D1 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 1U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__D2 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 5U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__D1 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 2U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__D2 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 6U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__D1 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 3U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__D2 
        = (1U & ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out) 
                 >> 7U));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__Eth_TXD 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_txd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_out;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__D1 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d1;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__D2 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__tx_ctl_d2;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_tx_en 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_tx_en;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_txd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_txd;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_tx_en 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_tx_en;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gmii_txd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__gmii_txd;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__11(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__11\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_rx_asyncfifo__write_data 
        = (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rx_er) 
            << 9U) | (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__Q1) 
                       << 8U) | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__gmii_rxd)));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__write_data 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT____Vcellinp__u_rx_asyncfifo__write_data;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_comb__TOP__12(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_comb__TOP__12\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txd 
        = ((((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__Q) 
             << 3U) | ((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__Q) 
                       << 2U)) | (((IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__Q) 
                                   << 1U) | (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__Q)));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__rgmii_txd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txd;
    vlSelfRef.tb_tcp_handshake__DOT__rgmii_txd = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txd;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rgmii_txd 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rgmii_txd;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__82(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__82\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__tx_data_dly 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__delay_using_ram_generation__DOT__u_dly_data_buf__DOT__gen_inferred_ram__DOT__q_b_r;
}

VL_INLINE_OPT void Vtb_tcp_handshake___024root___nba_sequent__TOP__83(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___nba_sequent__TOP__83\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n 
        = ((IData)(vlSelfRef.reset_l) & (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_pll__DOT__u_mmcm__DOT__locked_r));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_idelayctrl__DOT__RDY 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rst_n 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst 
        = (1U & (~ (IData)(vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__sys_rst_n)));
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__rst_n 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__rst_n 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__rst_n;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_rx_asyncfifo__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_ram2pktfifo_int__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_pktfifo2ram_int__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_sop_eop_gen__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_idelayctrl__DOT__RST 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__R 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_txc_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__u_tx_ctl_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__0__KET____DOT__u_txd_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__1__KET____DOT__u_txd_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__2__KET____DOT__u_txd_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_tx__DOT__gen_txd_oddr__BRA__3__KET____DOT__u_txd_oddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__u_rx_ctl_iddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__1__KET____DOT__u_rxd_iddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__2__KET____DOT__u_rxd_iddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__3__KET____DOT__u_rxd_iddr__DOT__async_rst 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_bridge__DOT__u_rx__DOT__gen_rxd_iddr__BRA__0__KET____DOT__u_rxd_iddr__DOT__async_rst;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__u_fix_delay__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_eth_presemble__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_rd__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_rptr_sync__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_dual_clk_cdc__DOT__u_para_fifo__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__none_blk_mode__DOT__nb_rptr_cdc__DOT__u_para_fifo_wclk__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_cpu_channel__DOT__u_package_fifo_cpu_wr__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__u_sop_eop_gen__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__crc_chk_gen__DOT__u_crc__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_rx__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_fix_delay__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__reset_l;
    vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__u_crc__DOT__reset_l 
        = vlSelfRef.tb_tcp_handshake__DOT__u_dut__DOT__u_gmii2mac__DOT__u_mac_top__DOT__u_mac_tx__DOT__reset_l;
}

void Vtb_tcp_handshake___024root___timing_resume(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x40000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h5692267f__0.resume(
                                                   "@(posedge tb_tcp_handshake.u_dut.clk_50m)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(1U))) {
        vlSelfRef.__VtrigSched_h449a949e__0.resume(
                                                   "@([changed] tb_tcp_handshake.u_dut.u_riscv.jtag_ack)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(1U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_tcp_handshake___024root___timing_commit(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (0x40000000ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h5692267f__0.commit(
                                                   "@(posedge tb_tcp_handshake.u_dut.clk_50m)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(1U)))) {
        vlSelfRef.__VtrigSched_h449a949e__0.commit(
                                                   "@([changed] tb_tcp_handshake.u_dut.u_riscv.jtag_ack)");
    }
}

void Vtb_tcp_handshake___024root___eval_triggers__act(Vtb_tcp_handshake___024root* vlSelf);
void Vtb_tcp_handshake___024root___eval_act(Vtb_tcp_handshake___024root* vlSelf);

bool Vtb_tcp_handshake___024root___eval_phase__act(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<68> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_tcp_handshake___024root___eval_triggers__act(vlSelf);
    Vtb_tcp_handshake___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_tcp_handshake___024root___timing_resume(vlSelf);
        Vtb_tcp_handshake___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_tcp_handshake___024root___eval_nba(Vtb_tcp_handshake___024root* vlSelf);

bool Vtb_tcp_handshake___024root___eval_phase__nba(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_tcp_handshake___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__ico(Vtb_tcp_handshake___024root* vlSelf);
#endif  // VL_DEBUG
bool Vtb_tcp_handshake___024root___eval_phase__ico(Vtb_tcp_handshake___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__nba(Vtb_tcp_handshake___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_tcp_handshake___024root___dump_triggers__act(Vtb_tcp_handshake___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_tcp_handshake___024root___eval(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtb_tcp_handshake___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("tb_tcp_handshake.v", 6, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtb_tcp_handshake___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_tcp_handshake___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_tcp_handshake.v", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_tcp_handshake___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_tcp_handshake.v", 6, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_tcp_handshake___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_tcp_handshake___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_tcp_handshake___024root___eval_debug_assertions(Vtb_tcp_handshake___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_tcp_handshake__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_tcp_handshake___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_50m_in & 0xfeU))) {
        Verilated::overWidthError("clk_50m_in");}
    if (VL_UNLIKELY((vlSelfRef.reset_l & 0xfeU))) {
        Verilated::overWidthError("reset_l");}
    if (VL_UNLIKELY((vlSelfRef.rgmii_rxc & 0xfeU))) {
        Verilated::overWidthError("rgmii_rxc");}
    if (VL_UNLIKELY((vlSelfRef.rgmii_rxd & 0xf0U))) {
        Verilated::overWidthError("rgmii_rxd");}
    if (VL_UNLIKELY((vlSelfRef.rgmii_rx_ctl & 0xfeU))) {
        Verilated::overWidthError("rgmii_rx_ctl");}
    if (VL_UNLIKELY((vlSelfRef.uart_rx & 0xfeU))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG

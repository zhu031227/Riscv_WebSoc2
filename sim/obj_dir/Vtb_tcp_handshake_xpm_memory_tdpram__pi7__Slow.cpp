// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_tcp_handshake.h for the primary calling header

#include "Vtb_tcp_handshake__pch.h"
#include "Vtb_tcp_handshake__Syms.h"
#include "Vtb_tcp_handshake_xpm_memory_tdpram__pi7.h"

// Parameter definitions for Vtb_tcp_handshake_xpm_memory_tdpram__pi7
constexpr CData/*7:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MEMORY_INIT_PARAM;
constexpr CData/*7:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_RESET_VALUE_A;
constexpr CData/*7:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_RESET_VALUE_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MEMORY_SIZE;
constexpr VlWide<3>/*95:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::CLOCKING_MODE;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::ECC_TYPE;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MEMORY_INIT_FILE;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::USE_MEM_INIT;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::USE_MEM_INIT_MMI;
constexpr VlWide<4>/*103:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WAKEUP_TIME;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::AUTO_SLEEP_TIME;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MESSAGE_CONTROL;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::USE_EMBEDDED_CONSTRAINT;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MEMORY_OPTIMIZATION;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::CASCADE_HEIGHT;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::RAM_DECOMP;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::SIM_ASSERT_CHK;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WRITE_PROTECT;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::IGNORE_INIT_SYNTH;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WRITE_DATA_WIDTH_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_DATA_WIDTH_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::BYTE_WRITE_WIDTH_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::ADDR_WIDTH_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_LATENCY_A;
constexpr VlWide<3>/*79:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WRITE_MODE_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::RST_MODE_A;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WRITE_DATA_WIDTH_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_DATA_WIDTH_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::BYTE_WRITE_WIDTH_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::ADDR_WIDTH_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::READ_LATENCY_B;
constexpr VlWide<3>/*79:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::WRITE_MODE_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::RST_MODE_B;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MAX_WIDTH;
constexpr IData/*31:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::DEPTH;
constexpr QData/*39:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::MEMORY_PRIMITIVE;
constexpr QData/*47:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::ECC_MODE;
constexpr QData/*39:0*/ Vtb_tcp_handshake_xpm_memory_tdpram__pi7::ECC_BIT_RANGE;


void Vtb_tcp_handshake_xpm_memory_tdpram__pi7___ctor_var_reset(Vtb_tcp_handshake_xpm_memory_tdpram__pi7* vlSelf);

Vtb_tcp_handshake_xpm_memory_tdpram__pi7::Vtb_tcp_handshake_xpm_memory_tdpram__pi7(Vtb_tcp_handshake__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7___ctor_var_reset(this);
}

void Vtb_tcp_handshake_xpm_memory_tdpram__pi7::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_tcp_handshake_xpm_memory_tdpram__pi7::~Vtb_tcp_handshake_xpm_memory_tdpram__pi7() {
}

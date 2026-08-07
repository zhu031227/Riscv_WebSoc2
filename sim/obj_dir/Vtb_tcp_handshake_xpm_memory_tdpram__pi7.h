// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_tcp_handshake.h for the primary calling header

#ifndef VERILATED_VTB_TCP_HANDSHAKE_XPM_MEMORY_TDPRAM__PI7_H_
#define VERILATED_VTB_TCP_HANDSHAKE_XPM_MEMORY_TDPRAM__PI7_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_tcp_handshake__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_tcp_handshake_xpm_memory_tdpram__pi7 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clka,0,0);
    VL_IN8(clkb,0,0);
    VL_IN8(sleep,0,0);
    VL_IN8(rsta,0,0);
    VL_IN8(ena,0,0);
    VL_IN8(regcea,0,0);
    VL_IN8(wea,0,0);
    VL_IN8(addra,7,0);
    VL_IN8(injectsbiterra,0,0);
    VL_IN8(injectdbiterra,0,0);
    VL_OUT8(sbiterra,0,0);
    VL_OUT8(dbiterra,0,0);
    VL_IN8(rstb,0,0);
    VL_IN8(enb,0,0);
    VL_IN8(regceb,0,0);
    VL_IN8(web,0,0);
    VL_IN8(addrb,7,0);
    VL_IN8(injectsbiterrb,0,0);
    VL_IN8(injectdbiterrb,0,0);
    VL_OUT8(sbiterrb,0,0);
    VL_OUT8(dbiterrb,0,0);
    CData/*0:0*/ __VdlySet__mem__v0;
    CData/*0:0*/ __VdlySet__mem__v1;
    SData/*9:0*/ __VdlyDim0__mem__v0;
    SData/*9:0*/ __VdlyDim0__mem__v1;
    VL_IN(dina,31,0);
    VL_OUT(douta,31,0);
    VL_IN(dinb,31,0);
    VL_OUT(doutb,31,0);
    IData/*31:0*/ __VdlyVal__mem__v0;
    IData/*31:0*/ __VdlyVal__mem__v1;
    VlUnpacked<IData/*31:0*/, 1024> mem;

    // INTERNAL VARIABLES
    Vtb_tcp_handshake__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*7:0*/ MEMORY_INIT_PARAM = 0x30U;
    static constexpr CData/*7:0*/ READ_RESET_VALUE_A = 0x30U;
    static constexpr CData/*7:0*/ READ_RESET_VALUE_B = 0x30U;
    static constexpr IData/*31:0*/ MEMORY_SIZE = 0x00002000U;
    static constexpr VlWide<3>/*95:0*/ CLOCKING_MODE = {{
        0x6c6f636b, 0x6f6e5f63, 0x636f6d6d
    }};
    static constexpr IData/*31:0*/ ECC_TYPE = 0x4e4f4e45U;
    static constexpr IData/*31:0*/ MEMORY_INIT_FILE = 0x6e6f6e65U;
    static constexpr IData/*31:0*/ USE_MEM_INIT = 0U;
    static constexpr IData/*31:0*/ USE_MEM_INIT_MMI = 0U;
    static constexpr VlWide<4>/*103:0*/ WAKEUP_TIME = {{
        0x6c656570, 0x6c655f73, 0x69736162, 0x00000064
    }};
    static constexpr IData/*31:0*/ AUTO_SLEEP_TIME = 0U;
    static constexpr IData/*31:0*/ MESSAGE_CONTROL = 0U;
    static constexpr IData/*31:0*/ USE_EMBEDDED_CONSTRAINT = 0U;
    static constexpr IData/*31:0*/ MEMORY_OPTIMIZATION = 0x74727565U;
    static constexpr IData/*31:0*/ CASCADE_HEIGHT = 0U;
    static constexpr IData/*31:0*/ RAM_DECOMP = 0x6175746fU;
    static constexpr IData/*31:0*/ SIM_ASSERT_CHK = 0U;
    static constexpr IData/*31:0*/ WRITE_PROTECT = 1U;
    static constexpr IData/*31:0*/ IGNORE_INIT_SYNTH = 0U;
    static constexpr IData/*31:0*/ WRITE_DATA_WIDTH_A = 0x00000020U;
    static constexpr IData/*31:0*/ READ_DATA_WIDTH_A = 0x00000020U;
    static constexpr IData/*31:0*/ BYTE_WRITE_WIDTH_A = 8U;
    static constexpr IData/*31:0*/ ADDR_WIDTH_A = 8U;
    static constexpr IData/*31:0*/ READ_LATENCY_A = 1U;
    static constexpr VlWide<3>/*79:0*/ WRITE_MODE_A = {{
        0x69727374, 0x61645f66, 0x00007265
    }};
    static constexpr IData/*31:0*/ RST_MODE_A = 0x53594e43U;
    static constexpr IData/*31:0*/ WRITE_DATA_WIDTH_B = 0x00000020U;
    static constexpr IData/*31:0*/ READ_DATA_WIDTH_B = 0x00000020U;
    static constexpr IData/*31:0*/ BYTE_WRITE_WIDTH_B = 8U;
    static constexpr IData/*31:0*/ ADDR_WIDTH_B = 8U;
    static constexpr IData/*31:0*/ READ_LATENCY_B = 1U;
    static constexpr VlWide<3>/*79:0*/ WRITE_MODE_B = {{
        0x69727374, 0x61645f66, 0x00007265
    }};
    static constexpr IData/*31:0*/ RST_MODE_B = 0x53594e43U;
    static constexpr IData/*31:0*/ MAX_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ DEPTH = 0x00000400U;
    static constexpr QData/*39:0*/ MEMORY_PRIMITIVE = 0x000000626c6f636bULL;
    static constexpr QData/*47:0*/ ECC_MODE = 0x00006e6f5f656363ULL;
    static constexpr QData/*39:0*/ ECC_BIT_RANGE = 0x0000005b373a305dULL;

    // CONSTRUCTORS
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7(Vtb_tcp_handshake__Syms* symsp, const char* v__name);
    ~Vtb_tcp_handshake_xpm_memory_tdpram__pi7();
    VL_UNCOPYABLE(Vtb_tcp_handshake_xpm_memory_tdpram__pi7);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

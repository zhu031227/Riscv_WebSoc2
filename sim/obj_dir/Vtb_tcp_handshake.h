// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTB_TCP_HANDSHAKE_H_
#define VERILATED_VTB_TCP_HANDSHAKE_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtb_tcp_handshake__Syms;
class Vtb_tcp_handshake___024root;
class VerilatedVcdC;
class Vtb_tcp_handshake_xpm_memory_tdpram__pi7;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtb_tcp_handshake VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtb_tcp_handshake__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_50m_in,0,0);
    VL_IN8(&reset_l,0,0);
    VL_IN8(&rgmii_rxc,0,0);
    VL_IN8(&rgmii_rxd,3,0);
    VL_IN8(&rgmii_rx_ctl,0,0);
    VL_IN8(&uart_rx,0,0);
    VL_OUT8(&led_o,3,0);
    VL_OUT8(&uart_tx,0,0);
    VL_OUT8(&mac_tx_sop,0,0);
    VL_OUT8(&mac_tx_en,0,0);
    VL_OUT8(&mac_tx_data,7,0);
    VL_OUT8(&mac_tx_eop,0,0);
    VL_OUT8(&mac_rx_sop,0,0);
    VL_OUT8(&mac_rx_en,0,0);
    VL_OUT8(&mac_rx_data,7,0);
    VL_OUT8(&mac_rx_eop,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__0__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__1__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__2__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__3__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__4__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__5__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__6__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__7__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__8__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__9__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__10__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__11__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__12__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__13__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__14__KET____DOT__u_xpm_memory_tdpram_bank;
    Vtb_tcp_handshake_xpm_memory_tdpram__pi7* const __PVT__tb_tcp_handshake__DOT__u_dut__DOT__u_riscv__DOT__riscv_cpu_generation__DOT__u_riscv_cpu__DOT__u_instru_ram__DOT__gen_xilinx_xpm_tdpram__DOT__xpm_bank__BRA__15__KET____DOT__u_xpm_memory_tdpram_bank;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtb_tcp_handshake___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtb_tcp_handshake(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtb_tcp_handshake(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtb_tcp_handshake();
  private:
    VL_UNCOPYABLE(Vtb_tcp_handshake);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard

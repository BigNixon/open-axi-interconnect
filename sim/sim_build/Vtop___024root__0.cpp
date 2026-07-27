// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.axi_lite_slave__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.axi_lite_slave__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.axi_lite_slave__DOT__awaddr 
                        = vlSelfRef.awaddr;
                    vlSelfRef.axi_lite_slave__DOT__awvalid 
                        = vlSelfRef.awvalid;
                    vlSelfRef.axi_lite_slave__DOT__wdata 
                        = vlSelfRef.wdata;
                    vlSelfRef.axi_lite_slave__DOT__wstrb 
                        = vlSelfRef.wstrb;
                    vlSelfRef.axi_lite_slave__DOT__wvalid 
                        = vlSelfRef.wvalid;
                    vlSelfRef.bvalid = vlSelfRef.axi_lite_slave__DOT__bvalid;
                    vlSelfRef.axi_lite_slave__DOT__bready 
                        = vlSelfRef.bready;
                    vlSelfRef.axi_lite_slave__DOT__araddr 
                        = vlSelfRef.araddr;
                    vlSelfRef.axi_lite_slave__DOT__arvalid 
                        = vlSelfRef.arvalid;
                    vlSelfRef.rdata = vlSelfRef.axi_lite_slave__DOT__rdata;
                    vlSelfRef.rvalid = vlSelfRef.axi_lite_slave__DOT__rvalid;
                    vlSelfRef.axi_lite_slave__DOT__rready 
                        = vlSelfRef.rready;
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.axi_lite_slave__DOT__rst_n)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__rst_n__0)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.axi_lite_slave__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__clk__0 
            = vlSelfRef.axi_lite_slave__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__rst_n__0 
            = vlSelfRef.axi_lite_slave__DOT__rst_n;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    CData/*0:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid = 0;
                    CData/*0:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid = 0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid 
                        = vlSelfRef.axi_lite_slave__DOT__rvalid;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid 
                        = vlSelfRef.axi_lite_slave__DOT__bvalid;
                    if (vlSelfRef.axi_lite_slave__DOT__rst_n) {
                        if (vlSelfRef.axi_lite_slave__DOT__arvalid) {
                            __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid = 1U;
                            vlSelfRef.axi_lite_slave__DOT__rdata 
                                = ((8U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                    ? ((4U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                        ? ((2U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                             ? 0U : vlSelfRef.axi_lite_slave__DOT__reg_version))
                                        : ((2U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                             ? 0U : vlSelfRef.axi_lite_slave__DOT__reg_data)))
                                    : ((4U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                        ? ((2U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                             ? 0U : vlSelfRef.axi_lite_slave__DOT__reg_status))
                                        : ((2U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.axi_lite_slave__DOT__araddr))
                                             ? 0U : vlSelfRef.axi_lite_slave__DOT__reg_control))));
                        }
                        if (((IData)(vlSelfRef.axi_lite_slave__DOT__rvalid) 
                             & (IData)(vlSelfRef.axi_lite_slave__DOT__rready))) {
                            __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid = 0U;
                        }
                        if (((IData)(vlSelfRef.axi_lite_slave__DOT__awvalid) 
                             & (IData)(vlSelfRef.axi_lite_slave__DOT__wvalid))) {
                            __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid = 1U;
                            if ((0U != (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                if ((4U != (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                    if ((8U != (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                        if ((0x0cU 
                                             == (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                            vlSelfRef.axi_lite_slave__DOT__reg_version 
                                                = vlSelfRef.axi_lite_slave__DOT__wdata;
                                        }
                                    }
                                    if ((8U == (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                        vlSelfRef.axi_lite_slave__DOT__reg_data 
                                            = vlSelfRef.axi_lite_slave__DOT__wdata;
                                    }
                                }
                                if ((4U == (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                    vlSelfRef.axi_lite_slave__DOT__reg_status 
                                        = vlSelfRef.axi_lite_slave__DOT__wdata;
                                }
                            }
                            if ((0U == (IData)(vlSelfRef.axi_lite_slave__DOT__awaddr))) {
                                vlSelfRef.axi_lite_slave__DOT__reg_control 
                                    = vlSelfRef.axi_lite_slave__DOT__wdata;
                            }
                        }
                        if (((IData)(vlSelfRef.axi_lite_slave__DOT__bvalid) 
                             & (IData)(vlSelfRef.axi_lite_slave__DOT__bready))) {
                            __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid = 0U;
                        }
                    } else {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid = 0U;
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid = 0U;
                        vlSelfRef.axi_lite_slave__DOT__rdata = 0U;
                        vlSelfRef.axi_lite_slave__DOT__reg_version = 1U;
                        vlSelfRef.axi_lite_slave__DOT__reg_data = 0U;
                        vlSelfRef.axi_lite_slave__DOT__reg_status = 0xdeadbeefU;
                        vlSelfRef.axi_lite_slave__DOT__reg_control = 0U;
                    }
                    vlSelfRef.axi_lite_slave__DOT__rvalid 
                        = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__rvalid;
                    vlSelfRef.axi_lite_slave__DOT__bvalid 
                        = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__axi_lite_slave__DOT__bvalid;
                    vlSelfRef.rvalid = vlSelfRef.axi_lite_slave__DOT__rvalid;
                    vlSelfRef.bvalid = vlSelfRef.axi_lite_slave__DOT__bvalid;
                    vlSelfRef.rdata = vlSelfRef.axi_lite_slave__DOT__rdata;
                }
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/mnt/c/Users/Nixon/Desktop/Proyectos/AXI_Subsystem/open-axi-interconnect/sim/../rtl/axi/axi_lite_slave.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/mnt/c/Users/Nixon/Desktop/Proyectos/AXI_Subsystem/open-axi-interconnect/sim/../rtl/axi/axi_lite_slave.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/mnt/c/Users/Nixon/Desktop/Proyectos/AXI_Subsystem/open-axi-interconnect/sim/../rtl/axi/axi_lite_slave.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.awaddr & 0xf0U)))) {
        Verilated::overWidthError("awaddr");
    }
    if (VL_UNLIKELY(((vlSelfRef.awvalid & 0xfeU)))) {
        Verilated::overWidthError("awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.wstrb & 0xf0U)))) {
        Verilated::overWidthError("wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.wvalid & 0xfeU)))) {
        Verilated::overWidthError("wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.bready & 0xfeU)))) {
        Verilated::overWidthError("bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.araddr & 0xf0U)))) {
        Verilated::overWidthError("araddr");
    }
    if (VL_UNLIKELY(((vlSelfRef.arvalid & 0xfeU)))) {
        Verilated::overWidthError("arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.rready & 0xfeU)))) {
        Verilated::overWidthError("rready");
    }
}
#endif  // VL_DEBUG

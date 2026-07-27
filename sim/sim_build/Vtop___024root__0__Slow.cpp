// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__clk__0 
        = vlSelfRef.axi_lite_slave__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_slave__DOT__rst_n__0 
        = vlSelfRef.axi_lite_slave__DOT__rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.awready = 1U;
        vlSelfRef.wready = 1U;
        vlSelfRef.bresp = 0U;
        vlSelfRef.arready = 1U;
        vlSelfRef.rresp = 0U;
        vlSelfRef.axi_lite_slave__DOT__awready = 1U;
        vlSelfRef.axi_lite_slave__DOT__wready = 1U;
        vlSelfRef.axi_lite_slave__DOT__arready = 1U;
        vlSelfRef.axi_lite_slave__DOT__bresp = 0U;
        vlSelfRef.axi_lite_slave__DOT__rresp = 0U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/mnt/c/Users/Nixon/Desktop/Proyectos/AXI_Subsystem/open-axi-interconnect/sim/../rtl/axi/axi_lite_slave.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
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
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge axi_lite_slave.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge axi_lite_slave.rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->awaddr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10741232094138379896ull);
    vlSelf->awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077405313628979207ull);
    vlSelf->awready = 1U;
    ;
    vlSelf->wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890271867161903902ull);
    vlSelf->wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15125268524300477597ull);
    vlSelf->wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135585445238253745ull);
    vlSelf->wready = 1U;
    ;
    vlSelf->bresp = 0U;
    ;
    vlSelf->bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14655036748745407948ull);
    vlSelf->bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16336171827316305440ull);
    vlSelf->araddr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17685200476622543275ull);
    vlSelf->arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774798297805906817ull);
    vlSelf->arready = 1U;
    ;
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->rresp = 0U;
    ;
    vlSelf->rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14125721737830190460ull);
    vlSelf->rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8930348232195030647ull);
    vlSelf->axi_lite_slave__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6894010958780385490ull);
    vlSelf->axi_lite_slave__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17671314720978737822ull);
    vlSelf->axi_lite_slave__DOT__awaddr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6600248198257282853ull);
    vlSelf->axi_lite_slave__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12985302544793898317ull);
    vlSelf->axi_lite_slave__DOT__awready = 1U;
    ;
    vlSelf->axi_lite_slave__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13550007969131016866ull);
    vlSelf->axi_lite_slave__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1857771254185815878ull);
    vlSelf->axi_lite_slave__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16628339067131177341ull);
    vlSelf->axi_lite_slave__DOT__wready = 1U;
    ;
    vlSelf->axi_lite_slave__DOT__bresp = 0U;
    ;
    vlSelf->axi_lite_slave__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14224902076798887412ull);
    vlSelf->axi_lite_slave__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1401661413906489572ull);
    vlSelf->axi_lite_slave__DOT__araddr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15881835697729750308ull);
    vlSelf->axi_lite_slave__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12884679690054886608ull);
    vlSelf->axi_lite_slave__DOT__arready = 1U;
    ;
    vlSelf->axi_lite_slave__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4621705729463539539ull);
    vlSelf->axi_lite_slave__DOT__rresp = 0U;
    ;
    vlSelf->axi_lite_slave__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10260479126240841664ull);
    vlSelf->axi_lite_slave__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11794038765536400066ull);
    vlSelf->axi_lite_slave__DOT__reg_control = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13982813340878027193ull);
    vlSelf->axi_lite_slave__DOT__reg_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3399018108732022265ull);
    vlSelf->axi_lite_slave__DOT__reg_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15599565717698075828ull);
    vlSelf->axi_lite_slave__DOT__reg_version = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 377641101694692081ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_slave__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_slave__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__clk__0 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__rst_n__0 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__clk__0 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__rst_n__0 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__clk__0 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__rst_n__0 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__clk__0 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__rst_n__0 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.axi_subsystem__DOT__s_bresp = 0U;
        vlSelfRef.axi_subsystem__DOT__s_wready = 0x0fU;
        vlSelfRef.axi_subsystem__DOT__s_awready = 0x0fU;
        vlSelfRef.axi_subsystem__DOT__s_rresp = 0U;
        vlSelfRef.axi_subsystem__DOT__s_arready = 0x0fU;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__arready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__arready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__arready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__arready = 1U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bresp = 0U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rresp = 0U;
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
            VL_FATAL_MT("/home/bignixon/projects/open-axi-interconnect/sim/../rtl/top/axi_subsystem.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

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
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge axi_subsystem.u_ram.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge axi_subsystem.u_ram.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge axi_subsystem.u_uart.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge axi_subsystem.u_uart.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge axi_subsystem.u_timer.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge axi_subsystem.u_timer.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge axi_subsystem.u_gpio.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(negedge axi_subsystem.u_gpio.rst_n)\n");
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
    vlSelf->awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10741232094138379896ull);
    vlSelf->awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077405313628979207ull);
    vlSelf->awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9399710217136046492ull);
    vlSelf->wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890271867161903902ull);
    vlSelf->wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15125268524300477597ull);
    vlSelf->wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135585445238253745ull);
    vlSelf->wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2694481459927628098ull);
    vlSelf->bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3607396732575112162ull);
    vlSelf->bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14655036748745407948ull);
    vlSelf->bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16336171827316305440ull);
    vlSelf->araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17685200476622543275ull);
    vlSelf->arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774798297805906817ull);
    vlSelf->arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2587622265565774708ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 810448354640171968ull);
    vlSelf->rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14125721737830190460ull);
    vlSelf->rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8930348232195030647ull);
    vlSelf->uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1761512799854230840ull);
    vlSelf->uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2399467654730215438ull);
    vlSelf->timer_irq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14883114850945369791ull);
    vlSelf->gpio_pins = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18154230282108408052ull);
    vlSelf->axi_subsystem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11000206911834708243ull);
    vlSelf->axi_subsystem__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14301255155485990744ull);
    vlSelf->axi_subsystem__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10337982524530306460ull);
    vlSelf->axi_subsystem__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12592984920182596313ull);
    vlSelf->axi_subsystem__DOT__awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17503708541584650534ull);
    vlSelf->axi_subsystem__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15779909537748814611ull);
    vlSelf->axi_subsystem__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13293142117552714297ull);
    vlSelf->axi_subsystem__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12974309508452160779ull);
    vlSelf->axi_subsystem__DOT__wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5057840518209714978ull);
    vlSelf->axi_subsystem__DOT__bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12981748329961968174ull);
    vlSelf->axi_subsystem__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9216823071815558710ull);
    vlSelf->axi_subsystem__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3135780036705073539ull);
    vlSelf->axi_subsystem__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1990027714902100147ull);
    vlSelf->axi_subsystem__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8159423548133003581ull);
    vlSelf->axi_subsystem__DOT__arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6122445225768184869ull);
    vlSelf->axi_subsystem__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9295658280455434939ull);
    vlSelf->axi_subsystem__DOT__rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4385147230513357003ull);
    vlSelf->axi_subsystem__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8013324620636598897ull);
    vlSelf->axi_subsystem__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8588102724939555090ull);
    vlSelf->axi_subsystem__DOT__uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17719166216383012972ull);
    vlSelf->axi_subsystem__DOT__uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7189539666561491083ull);
    vlSelf->axi_subsystem__DOT__timer_irq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9177298809347985804ull);
    vlSelf->axi_subsystem__DOT__gpio_pins = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9266923935165824911ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__s_awaddr, __VscopeHash, 13598941705000251937ull);
    vlSelf->axi_subsystem__DOT__s_awvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6917354925254796651ull);
    vlSelf->axi_subsystem__DOT__s_awready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5848930013264649093ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__s_wdata, __VscopeHash, 8740376961410872554ull);
    vlSelf->axi_subsystem__DOT__s_wstrb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4845192672402139055ull);
    vlSelf->axi_subsystem__DOT__s_wvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3893510209590053214ull);
    vlSelf->axi_subsystem__DOT__s_wready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18124828940128278595ull);
    vlSelf->axi_subsystem__DOT__s_bresp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1132004294973679160ull);
    vlSelf->axi_subsystem__DOT__s_bvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7409239430482336084ull);
    vlSelf->axi_subsystem__DOT__s_bready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13358278054221838148ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__s_araddr, __VscopeHash, 13796048464758520453ull);
    vlSelf->axi_subsystem__DOT__s_arvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7842031948048071625ull);
    vlSelf->axi_subsystem__DOT__s_arready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8368515726485279446ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__s_rdata, __VscopeHash, 4958045569368357608ull);
    vlSelf->axi_subsystem__DOT__s_rresp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7778806640778499431ull);
    vlSelf->axi_subsystem__DOT__s_rvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9405287960303644164ull);
    vlSelf->axi_subsystem__DOT__s_rready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13586713430339018960ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2529856257234680693ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4827802588564056546ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14879027303816997936ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6990874485332876140ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3207431073258219311ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1497441843011712038ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3479860864806354471ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11205915870085644899ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11095894025966155371ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13195953903956686340ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3855559500254395111ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10670971815941312935ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8699650496885044359ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4868355062562477673ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5299454747172155835ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1582227326726340685ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__m_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16971301591992673909ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_awaddr, __VscopeHash, 3200124622906340478ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_awvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16158757450861921553ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_awready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13948808666383610710ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_wdata, __VscopeHash, 3714050990519452998ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_wstrb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13776643126143873139ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_wvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3917015280886203479ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_wready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11479904474558286138ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_bresp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18183656100801839622ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_bvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17911264951222929240ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_bready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14278462445573170420ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_araddr, __VscopeHash, 13481392561165425314ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_arvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12773859008187063173ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_arready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7684162039099976576ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_rdata, __VscopeHash, 13709207608649431962ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_rresp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7619760405847919191ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_rvalid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5421013541285696832ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__s_rready = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15532582386870200611ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__write_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1158993110133300779ull);
    vlSelf->axi_subsystem__DOT__u_interconnect__DOT__read_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14324812537977387699ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8263451868577707491ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3285652695181410702ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17422354187798285696ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16074396306976956520ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__awready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_ram__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16716565917209281116ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6075844533046771240ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4215649376827309219ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__wready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_ram__DOT__bresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_ram__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11348114877433616967ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1966320950490388229ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7536799269592281696ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3297364717885265849ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__arready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_ram__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13543092792411318034ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__rresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_ram__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16981938274425629507ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2797822337003331868ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->axi_subsystem__DOT__u_ram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15002935041430602804ull);
    }
    vlSelf->axi_subsystem__DOT__u_ram__DOT__reg_control = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16579181786870178580ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__reg_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8372800570873202723ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__reg_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2703208063781684348ull);
    vlSelf->axi_subsystem__DOT__u_ram__DOT__mem_addr = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 7582307870957924824ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6435761028794121929ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7284743284625398804ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 146884517478062651ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16077642204249823672ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__awready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_uart__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5284377844705088394ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7853224589610500283ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6869026751832464932ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__wready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_uart__DOT__bresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_uart__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13491069027571341619ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8805873928161818370ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17709803810009915512ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1835239164285367721ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__arready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10023519499946260866ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5168379245298210890ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8404391815148926972ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9193371302846625338ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5184279190541205218ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__reg_ctrl = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14352294885015188565ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__reg_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11396592402783717316ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3540724911908581543ull);
    vlSelf->axi_subsystem__DOT__u_uart__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7930294794326464835ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5161879927214716289ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11693087357845338626ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4453878011607311834ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5179230913306750037ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__awready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_timer__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15406264758361197870ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15967217106591793977ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9439611089266507305ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__wready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_timer__DOT__bresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_timer__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5857753339322168370ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14617036656183203523ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2800224873192587775ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11029053984063113788ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__arready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_timer__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17174715162406968833ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__rresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_timer__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3988478406746238425ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2759287925039936731ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__irq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15370958263779473766ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__reg_ctrl = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16369830931100574707ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__reg_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11351325290826490517ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__reg_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7687539457332434282ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__reg_compare = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15648403093505042126ull);
    vlSelf->axi_subsystem__DOT__u_timer__DOT__active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14592170115727607092ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4735522048341567098ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11608839047842430029ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17480902292993079311ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8353493528123093670ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__awready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2428416766762480088ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6258725538254527633ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8655256343129394982ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__wready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__bresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2865981282546166293ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8540810807358561081ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5810144627690006082ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5673871936282616786ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__arready = 1U;
    ;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 372262544688176855ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__rresp = 0U;
    ;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3167783973438822415ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10958779327198744989ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2978868779011041646ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__reg_dir = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11876725139004864127ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__reg_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14509124871716220992ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__reg_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7574249898625241460ull);
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30 = 0;
    vlSelf->axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}

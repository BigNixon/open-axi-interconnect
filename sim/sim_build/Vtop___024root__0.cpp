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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    // Body
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr 
        = (0x000003ffU & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address);
    vlSelfRef.axi_subsystem__DOT__uart_rx = vlSelfRef.uart_rx;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx = 
        (1U & ((~ vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl) 
               | (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx_data)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awready 
        = vlSelfRef.axi_subsystem__DOT__s_awready;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wready 
        = vlSelfRef.axi_subsystem__DOT__s_wready;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bresp 
        = vlSelfRef.axi_subsystem__DOT__s_bresp;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arready 
        = vlSelfRef.axi_subsystem__DOT__s_arready;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rresp 
        = vlSelfRef.axi_subsystem__DOT__s_rresp;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active 
        = (1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl);
    vlSelfRef.axi_subsystem__DOT__clk = vlSelfRef.clk;
    vlSelfRef.axi_subsystem__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.axi_subsystem__DOT__s_bvalid = ((((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bvalid) 
                                                << 3U) 
                                               | ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bvalid) 
                                                  << 2U)) 
                                              | (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bvalid) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bvalid)));
    vlSelfRef.axi_subsystem__DOT__s_rvalid = ((((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rvalid) 
                                                << 3U) 
                                               | ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rvalid) 
                                                  << 2U)) 
                                              | (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rvalid) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rvalid)));
    vlSelfRef.axi_subsystem__DOT__s_rdata[0U] = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rdata;
    vlSelfRef.axi_subsystem__DOT__s_rdata[1U] = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rdata;
    vlSelfRef.axi_subsystem__DOT__s_rdata[2U] = (IData)(
                                                        (((QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata)) 
                                                          << 0x00000020U) 
                                                         | (QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata))));
    vlSelfRef.axi_subsystem__DOT__s_rdata[3U] = (IData)(
                                                        ((((QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata)) 
                                                           << 0x00000020U) 
                                                          | (QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata))) 
                                                         >> 0x00000020U));
    vlSelfRef.axi_subsystem__DOT__wdata = vlSelfRef.wdata;
    vlSelfRef.axi_subsystem__DOT__wstrb = vlSelfRef.wstrb;
    vlSelfRef.axi_subsystem__DOT__awvalid = vlSelfRef.awvalid;
    vlSelfRef.axi_subsystem__DOT__wvalid = vlSelfRef.wvalid;
    vlSelfRef.axi_subsystem__DOT__bready = vlSelfRef.bready;
    vlSelfRef.axi_subsystem__DOT__arvalid = vlSelfRef.arvalid;
    vlSelfRef.axi_subsystem__DOT__rready = vlSelfRef.rready;
    vlSelfRef.axi_subsystem__DOT__araddr = vlSelfRef.araddr;
    vlSelfRef.axi_subsystem__DOT__awaddr = vlSelfRef.awaddr;
    __VdfgRegularize_h6e95ff9d_0_0 = (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir 
                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out);
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rx = vlSelfRef.axi_subsystem__DOT__uart_rx;
    vlSelfRef.axi_subsystem__DOT__uart_tx = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__irq 
        = ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active) 
           & (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count 
              >= vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare));
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__clk = vlSelfRef.axi_subsystem__DOT__clk;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__clk 
        = vlSelfRef.axi_subsystem__DOT__clk;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__clk 
        = vlSelfRef.axi_subsystem__DOT__clk;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__clk 
        = vlSelfRef.axi_subsystem__DOT__clk;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rst_n 
        = vlSelfRef.axi_subsystem__DOT__rst_n;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rst_n 
        = vlSelfRef.axi_subsystem__DOT__rst_n;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rst_n 
        = vlSelfRef.axi_subsystem__DOT__rst_n;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rst_n 
        = vlSelfRef.axi_subsystem__DOT__rst_n;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bvalid 
        = vlSelfRef.axi_subsystem__DOT__s_bvalid;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rvalid 
        = vlSelfRef.axi_subsystem__DOT__s_rvalid;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[0U] 
        = vlSelfRef.axi_subsystem__DOT__s_rdata[0U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[1U] 
        = vlSelfRef.axi_subsystem__DOT__s_rdata[1U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[2U] 
        = vlSelfRef.axi_subsystem__DOT__s_rdata[2U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[3U] 
        = vlSelfRef.axi_subsystem__DOT__s_rdata[3U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wdata 
        = vlSelfRef.axi_subsystem__DOT__wdata;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb 
        = vlSelfRef.axi_subsystem__DOT__wstrb;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awvalid 
        = vlSelfRef.axi_subsystem__DOT__awvalid;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wvalid 
        = vlSelfRef.axi_subsystem__DOT__wvalid;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bready 
        = vlSelfRef.axi_subsystem__DOT__bready;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_arvalid 
        = vlSelfRef.axi_subsystem__DOT__arvalid;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rready 
        = vlSelfRef.axi_subsystem__DOT__rready;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr 
        = vlSelfRef.axi_subsystem__DOT__araddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr 
        = vlSelfRef.axi_subsystem__DOT__awaddr;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16 
        = ((0xfffffffeU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16) 
           | (1U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31 
        = ((0xfffffffdU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31) 
           | (2U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30 
        = ((0xfffffffbU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30) 
           | (4U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29 
        = ((0xfffffff7U & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29) 
           | (8U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28 
        = ((0xffffffefU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28) 
           | (0x00000010U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27 
        = ((0xffffffdfU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27) 
           | (0x00000020U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26 
        = ((0xffffffbfU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26) 
           | (0x00000040U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25 
        = ((0xffffff7fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25) 
           | (0x00000080U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24 
        = ((0xfffffeffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24) 
           | (0x00000100U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23 
        = ((0xfffffdffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23) 
           | (0x00000200U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22 
        = ((0xfffffbffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22) 
           | (0x00000400U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21 
        = ((0xfffff7ffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21) 
           | (0x00000800U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20 
        = ((0xffffefffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20) 
           | (0x00001000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19 
        = ((0xffffdfffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19) 
           | (0x00002000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18 
        = ((0xffffbfffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18) 
           | (0x00004000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17 
        = ((0xffff7fffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17) 
           | (0x00008000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0 
        = ((0xfffeffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0) 
           | (0x00010000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15 
        = ((0xfffdffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15) 
           | (0x00020000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14 
        = ((0xfffbffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14) 
           | (0x00040000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13 
        = ((0xfff7ffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13) 
           | (0x00080000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12 
        = ((0xffefffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12) 
           | (0x00100000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11 
        = ((0xffdfffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11) 
           | (0x00200000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10 
        = ((0xffbfffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10) 
           | (0x00400000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9 
        = ((0xff7fffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9) 
           | (0x00800000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8 
        = ((0xfeffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8) 
           | (0x01000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7 
        = ((0xfdffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7) 
           | (0x02000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6 
        = ((0xfbffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6) 
           | (0x04000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5 
        = ((0xf7ffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5) 
           | (0x08000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4 
        = ((0xefffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4) 
           | (0x10000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3 
        = ((0xdfffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3) 
           | (0x20000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2 
        = ((0xbfffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2) 
           | (0x40000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1 
        = ((0x7fffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1) 
           | (0x80000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.uart_tx = vlSelfRef.axi_subsystem__DOT__uart_tx;
    vlSelfRef.axi_subsystem__DOT__timer_irq = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__irq;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[0U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wdata;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[1U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wdata;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[2U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wdata;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[3U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wdata;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wstrb 
        = (0x0000ffffU & (((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb) 
                           << 0x0000000cU) | (((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb) 
                                               << 8U) 
                                              | (((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb) 
                                                  << 4U) 
                                                 | (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb)))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[0U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[1U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[2U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[3U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel 
        = (((0x40000000U <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr) 
            & (0x40000fffU >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr))
            ? 1U : (((0x40010000U <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr) 
                     & (0x40010fffU >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr))
                     ? 2U : (3U & (- (IData)(((0x40020000U 
                                               <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr) 
                                              & (0x40020fffU 
                                                 >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_araddr)))))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[0U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[1U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[2U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[3U] 
        = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel 
        = (((0x40000000U <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr) 
            & (0x40000fffU >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr))
            ? 1U : (((0x40010000U <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr) 
                     & (0x40010fffU >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr))
                     ? 2U : (3U & (- (IData)(((0x40020000U 
                                               <= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr) 
                                              & (0x40020fffU 
                                                 >= vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr)))))));
    vlSelfRef.gpio_pins = (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir 
                           & ((0x00010000U & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0 
                                              & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                              | ((0x80000000U & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1 
                                                 & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                 | ((0x40000000U & 
                                     (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2 
                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                    | ((0x20000000U 
                                        & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3 
                                           & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                       | ((0x10000000U 
                                           & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4 
                                              & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                          | ((0x08000000U 
                                              & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5 
                                                 & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                             | ((0x04000000U 
                                                 & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6 
                                                    & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                | ((0x02000000U 
                                                    & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7 
                                                       & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                   | ((0x01000000U 
                                                       & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8 
                                                          & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                      | ((0x00800000U 
                                                          & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9 
                                                             & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                         | ((0x00400000U 
                                                             & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10 
                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                            | ((0x00200000U 
                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11 
                                                                   & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                               | ((0x00100000U 
                                                                   & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12 
                                                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                  | ((0x00080000U 
                                                                      & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13 
                                                                         & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                     | ((0x00040000U 
                                                                         & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14 
                                                                            & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                        | ((0x00020000U 
                                                                            & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15 
                                                                               & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                           | ((1U 
                                                                               & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                              | ((0x00008000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00004000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00002000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00001000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000800U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000400U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000200U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000100U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000080U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000040U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000020U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000010U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((8U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((4U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | (2U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir))))))))))))))))))))))))))))))))));
    vlSelfRef.timer_irq = vlSelfRef.axi_subsystem__DOT__timer_irq;
    vlSelfRef.axi_subsystem__DOT__s_wdata[0U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[0U];
    vlSelfRef.axi_subsystem__DOT__s_wdata[1U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[1U];
    vlSelfRef.axi_subsystem__DOT__s_wdata[2U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[2U];
    vlSelfRef.axi_subsystem__DOT__s_wdata[3U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wdata[3U];
    vlSelfRef.axi_subsystem__DOT__s_wstrb = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wstrb;
    vlSelfRef.axi_subsystem__DOT__s_araddr[0U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[0U];
    vlSelfRef.axi_subsystem__DOT__s_araddr[1U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[1U];
    vlSelfRef.axi_subsystem__DOT__s_araddr[2U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[2U];
    vlSelfRef.axi_subsystem__DOT__s_araddr[3U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_araddr[3U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_arready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arready) 
                 >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rdata 
        = (((0U == (0x0000001fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                   << 5U))) ? 0U : 
            (vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata
             [(((IData)(0x0000001fU) + ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                        << 5U)) >> 5U)] 
             << ((IData)(0x00000020U) - (0x0000001fU 
                                         & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                            << 5U))))) 
           | (vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata
              [(0x07ffffffU & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))] 
              >> (0x0000001fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                 << 5U))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rresp 
        = (3U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rresp) 
                 >> ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                     << 1U)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rvalid) 
                 >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arvalid = 0U;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arvalid 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))) 
            & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arvalid)) 
           | (0x0fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_arvalid) 
                       << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rready = 0U;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rready 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))) 
            & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rready)) 
           | (0x0fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rready) 
                       << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))));
    vlSelfRef.axi_subsystem__DOT__s_awaddr[0U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[0U];
    vlSelfRef.axi_subsystem__DOT__s_awaddr[1U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[1U];
    vlSelfRef.axi_subsystem__DOT__s_awaddr[2U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[2U];
    vlSelfRef.axi_subsystem__DOT__s_awaddr[3U] = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr[3U];
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awready) 
                 >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wready) 
                 >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bresp 
        = (3U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bresp) 
                 >> ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel) 
                     << 1U)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bvalid) 
                 >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel)));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bready = 0U;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bready 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))) 
            & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bready)) 
           | (0x0fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bready) 
                       << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awvalid = 0U;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awvalid 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))) 
            & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awvalid)) 
           | (0x0fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awvalid) 
                       << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))));
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wvalid = 0U;
    vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wvalid 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))) 
            & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wvalid)) 
           | (0x0fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wvalid) 
                       << (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel))));
    vlSelfRef.axi_subsystem__DOT__gpio_pins = vlSelfRef.gpio_pins;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata 
        = vlSelfRef.axi_subsystem__DOT__s_wdata[0U];
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wdata 
        = vlSelfRef.axi_subsystem__DOT__s_wdata[1U];
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wdata 
        = vlSelfRef.axi_subsystem__DOT__s_wdata[2U];
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wdata 
        = vlSelfRef.axi_subsystem__DOT__s_wdata[3U];
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb 
        = (0x0000000fU & (IData)(vlSelfRef.axi_subsystem__DOT__s_wstrb));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wstrb 
        = (0x0000000fU & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wstrb) 
                          >> 4U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wstrb 
        = (0x0000000fU & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wstrb) 
                          >> 8U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wstrb 
        = (0x0000000fU & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wstrb) 
                          >> 0x0000000cU));
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr 
        = vlSelfRef.axi_subsystem__DOT__s_araddr[0U];
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr 
        = vlSelfRef.axi_subsystem__DOT__s_araddr[1U];
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr 
        = vlSelfRef.axi_subsystem__DOT__s_araddr[2U];
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__araddr 
        = vlSelfRef.axi_subsystem__DOT__s_araddr[3U];
    vlSelfRef.axi_subsystem__DOT__arready = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_arready;
    vlSelfRef.axi_subsystem__DOT__rdata = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rdata;
    vlSelfRef.axi_subsystem__DOT__rresp = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rresp;
    vlSelfRef.axi_subsystem__DOT__rvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rvalid;
    vlSelfRef.axi_subsystem__DOT__s_arvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_arvalid;
    vlSelfRef.axi_subsystem__DOT__s_rready = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rready;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
        = vlSelfRef.axi_subsystem__DOT__s_awaddr[0U];
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
        = vlSelfRef.axi_subsystem__DOT__s_awaddr[1U];
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
        = vlSelfRef.axi_subsystem__DOT__s_awaddr[2U];
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awaddr 
        = vlSelfRef.axi_subsystem__DOT__s_awaddr[3U];
    vlSelfRef.axi_subsystem__DOT__awready = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_awready;
    vlSelfRef.axi_subsystem__DOT__wready = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_wready;
    vlSelfRef.axi_subsystem__DOT__bresp = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bresp;
    vlSelfRef.axi_subsystem__DOT__bvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bvalid;
    vlSelfRef.axi_subsystem__DOT__s_bready = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bready;
    vlSelfRef.axi_subsystem__DOT__s_awvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_awvalid;
    vlSelfRef.axi_subsystem__DOT__s_wvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_wvalid;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins 
        = vlSelfRef.axi_subsystem__DOT__gpio_pins;
    vlSelfRef.arready = vlSelfRef.axi_subsystem__DOT__arready;
    vlSelfRef.rdata = vlSelfRef.axi_subsystem__DOT__rdata;
    vlSelfRef.rresp = vlSelfRef.axi_subsystem__DOT__rresp;
    vlSelfRef.rvalid = vlSelfRef.axi_subsystem__DOT__rvalid;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__arvalid 
        = (1U & (IData)(vlSelfRef.axi_subsystem__DOT__s_arvalid));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__arvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_arvalid) 
                 >> 1U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__arvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_arvalid) 
                 >> 2U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__arvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_arvalid) 
                 >> 3U));
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rready 
        = (1U & (IData)(vlSelfRef.axi_subsystem__DOT__s_rready));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_rready) 
                 >> 1U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_rready) 
                 >> 2U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_rready) 
                 >> 3U));
    vlSelfRef.awready = vlSelfRef.axi_subsystem__DOT__awready;
    vlSelfRef.wready = vlSelfRef.axi_subsystem__DOT__wready;
    vlSelfRef.bresp = vlSelfRef.axi_subsystem__DOT__bresp;
    vlSelfRef.bvalid = vlSelfRef.axi_subsystem__DOT__bvalid;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bready 
        = (1U & (IData)(vlSelfRef.axi_subsystem__DOT__s_bready));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_bready) 
                 >> 1U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_bready) 
                 >> 2U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bready 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_bready) 
                 >> 3U));
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awvalid 
        = (1U & (IData)(vlSelfRef.axi_subsystem__DOT__s_awvalid));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_awvalid) 
                 >> 1U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_awvalid) 
                 >> 2U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_awvalid) 
                 >> 3U));
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wvalid 
        = (1U & (IData)(vlSelfRef.axi_subsystem__DOT__s_wvalid));
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wvalid) 
                 >> 1U));
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wvalid) 
                 >> 2U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wvalid 
        = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__s_wvalid) 
                 >> 3U));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_in 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins;
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
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__old_val;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__new_val;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__mask;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__old_val;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__new_val;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__mask;
    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__mask = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid = 0;
    // Body
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out;
    __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir;
    if (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rst_n) {
        if (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__arvalid) {
            __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid = 1U;
            vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata 
                = ((0U == (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__araddr))
                    ? vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir
                    : ((4U == (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__araddr))
                        ? vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out
                        : ((8U == (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__araddr))
                            ? vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_in
                            : 0U)));
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rready))) {
            __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid = 0U;
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wvalid))) {
            __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid = 1U;
            if ((0U != (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awaddr))) {
                if ((4U == (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awaddr))) {
                    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb 
                        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wstrb;
                    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__new_val 
                        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wdata;
                    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__old_val 
                        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out;
                    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__mask 
                        = ((((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb) 
                                                            >> 3U)))) 
                                             << 8U)) 
                             | (0x000000ffU & (- (IData)(
                                                         (1U 
                                                          & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb) 
                                                             >> 2U)))))) 
                            << 0x00000010U) | ((0x0000ff00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb) 
                                                                  >> 1U)))) 
                                                   << 8U)) 
                                               | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__strb)))))));
                    __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__Vfuncout 
                        = ((__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__old_val 
                            & (~ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__mask)) 
                           | (__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__new_val 
                              & __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__mask));
                    __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out 
                        = __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__12__Vfuncout;
                }
            }
            if ((0U == (0x0000000fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__awaddr))) {
                __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb 
                    = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wstrb;
                __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__new_val 
                    = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__wdata;
                __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__old_val 
                    = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir;
                __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__mask 
                    = ((((0x0000ff00U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb) 
                                                        >> 3U)))) 
                                         << 8U)) | 
                         (0x000000ffU & (- (IData)(
                                                   (1U 
                                                    & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb) 
                                                       >> 2U)))))) 
                        << 0x00000010U) | ((0x0000ff00U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb) 
                                                              >> 1U)))) 
                                               << 8U)) 
                                           | (0x000000ffU 
                                              & (- (IData)(
                                                           (1U 
                                                            & (IData)(__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__strb)))))));
                __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__Vfuncout 
                    = ((__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__old_val 
                        & (~ __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__mask)) 
                       | (__Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__new_val 
                          & __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__mask));
                __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir 
                    = __Vfunc_axi_subsystem__DOT__u_gpio__DOT__apply_wstrb__11__Vfuncout;
            }
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bready))) {
            __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid = 0U;
        }
    } else {
        __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out = 0U;
        __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir = 0U;
        vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata = 0U;
    }
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rvalid 
        = __Vdly__axi_subsystem__DOT__u_gpio__DOT__rvalid;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bvalid 
        = __Vdly__axi_subsystem__DOT__u_gpio__DOT__bvalid;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out 
        = __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_out;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir 
        = __Vdly__axi_subsystem__DOT__u_gpio__DOT__reg_dir;
    __VdfgRegularize_h6e95ff9d_0_0 = (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir 
                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_out);
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16 
        = ((0xfffffffeU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16) 
           | (1U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31 
        = ((0xfffffffdU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31) 
           | (2U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30 
        = ((0xfffffffbU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30) 
           | (4U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29 
        = ((0xfffffff7U & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29) 
           | (8U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28 
        = ((0xffffffefU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28) 
           | (0x00000010U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27 
        = ((0xffffffdfU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27) 
           | (0x00000020U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26 
        = ((0xffffffbfU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26) 
           | (0x00000040U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25 
        = ((0xffffff7fU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25) 
           | (0x00000080U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24 
        = ((0xfffffeffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24) 
           | (0x00000100U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23 
        = ((0xfffffdffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23) 
           | (0x00000200U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22 
        = ((0xfffffbffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22) 
           | (0x00000400U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21 
        = ((0xfffff7ffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21) 
           | (0x00000800U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20 
        = ((0xffffefffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20) 
           | (0x00001000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19 
        = ((0xffffdfffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19) 
           | (0x00002000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18 
        = ((0xffffbfffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18) 
           | (0x00004000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17 
        = ((0xffff7fffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17) 
           | (0x00008000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0 
        = ((0xfffeffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0) 
           | (0x00010000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15 
        = ((0xfffdffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15) 
           | (0x00020000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14 
        = ((0xfffbffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14) 
           | (0x00040000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13 
        = ((0xfff7ffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13) 
           | (0x00080000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12 
        = ((0xffefffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12) 
           | (0x00100000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11 
        = ((0xffdfffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11) 
           | (0x00200000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10 
        = ((0xffbfffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10) 
           | (0x00400000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9 
        = ((0xff7fffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9) 
           | (0x00800000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8 
        = ((0xfeffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8) 
           | (0x01000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7 
        = ((0xfdffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7) 
           | (0x02000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6 
        = ((0xfbffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6) 
           | (0x04000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5 
        = ((0xf7ffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5) 
           | (0x08000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4 
        = ((0xefffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4) 
           | (0x10000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3 
        = ((0xdfffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3) 
           | (0x20000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2 
        = ((0xbfffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2) 
           | (0x40000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1 
        = ((0x7fffffffU & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1) 
           | (0x80000000U & __VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.gpio_pins = (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir 
                           & ((0x00010000U & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out0 
                                              & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                              | ((0x80000000U & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out1 
                                                 & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                 | ((0x40000000U & 
                                     (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out2 
                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                    | ((0x20000000U 
                                        & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out3 
                                           & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                       | ((0x10000000U 
                                           & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out4 
                                              & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                          | ((0x08000000U 
                                              & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out5 
                                                 & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                             | ((0x04000000U 
                                                 & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out6 
                                                    & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                | ((0x02000000U 
                                                    & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out7 
                                                       & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                   | ((0x01000000U 
                                                       & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out8 
                                                          & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                      | ((0x00800000U 
                                                          & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out9 
                                                             & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                         | ((0x00400000U 
                                                             & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out10 
                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                            | ((0x00200000U 
                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out11 
                                                                   & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                               | ((0x00100000U 
                                                                   & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out12 
                                                                      & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                  | ((0x00080000U 
                                                                      & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out13 
                                                                         & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                     | ((0x00040000U 
                                                                         & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out14 
                                                                            & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                        | ((0x00020000U 
                                                                            & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out15 
                                                                               & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                           | ((1U 
                                                                               & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out16 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                              | ((0x00008000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out17 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00004000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out18 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00002000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out19 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00001000U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out20 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000800U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out21 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000400U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out22 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000200U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out23 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000100U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out24 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000080U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out25 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000040U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out26 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000020U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out27 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((0x00000010U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out28 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((8U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out29 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | ((4U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out30 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir)) 
                                                                                | (2U 
                                                                                & (vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins__out__strong__out31 
                                                                                & vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_dir))))))))))))))))))))))))))))))))));
    vlSelfRef.axi_subsystem__DOT__gpio_pins = vlSelfRef.gpio_pins;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins 
        = vlSelfRef.axi_subsystem__DOT__gpio_pins;
    vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__reg_in 
        = vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__gpio_pins;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__old_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__new_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__mask;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__old_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__new_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__mask;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__old_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__new_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__mask;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__old_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__new_val;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__mask;
    __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__mask = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid = 0;
    // Body
    __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count;
    __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl 
        = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl;
    if (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rst_n) {
        if (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__arvalid) {
            __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid = 1U;
            vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata 
                = ((8U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                    ? ((4U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count)))
                    : ((4U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_status))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl))));
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rready))) {
            __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid = 0U;
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wvalid))) {
            __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid = 1U;
            if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr)) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_status;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__mask));
                            __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status 
                                = __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__9__Vfuncout;
                        }
                    }
                }
            }
            if ((8U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr)) {
                if ((4U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr)) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__mask));
                            __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare 
                                = __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__7__Vfuncout;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                              >> 2U)))) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count;
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__mask));
                            __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count 
                                = __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__8__Vfuncout;
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                                 >> 2U)))) {
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr 
                              >> 1U)))) {
                    if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_timer__DOT__awaddr))) {
                        __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb 
                            = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wstrb;
                        __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__new_val 
                            = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__wdata;
                        __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__old_val 
                            = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl;
                        __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__mask 
                            = ((((0x0000ff00U & ((- (IData)(
                                                            (1U 
                                                             & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb) 
                                                                >> 3U)))) 
                                                 << 8U)) 
                                 | (0x000000ffU & (- (IData)(
                                                             (1U 
                                                              & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb) 
                                                                 >> 2U)))))) 
                                << 0x00000010U) | (
                                                   (0x0000ff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb) 
                                                                      >> 1U)))) 
                                                       << 8U)) 
                                                   | (0x000000ffU 
                                                      & (- (IData)(
                                                                   (1U 
                                                                    & (IData)(__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__strb)))))));
                        __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__Vfuncout 
                            = ((__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__old_val 
                                & (~ __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__mask)) 
                               | (__Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__new_val 
                                  & __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__mask));
                        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl 
                            = __Vfunc_axi_subsystem__DOT__u_timer__DOT__apply_wstrb__10__Vfuncout;
                    }
                }
            }
        } else if (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active) {
            __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count 
                = ((2U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl)
                    ? 0U : ((IData)(1U) + vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count));
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bready))) {
            __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid = 0U;
        }
        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status 
            = ((0xfffffffeU & __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status) 
               | (IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active));
    } else {
        __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status = 0U;
        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare = 0xffffffffU;
        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl = 0U;
        __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count = 0U;
        vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata = 0U;
    }
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rvalid 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__rvalid;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bvalid 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__bvalid;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_status 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_status;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_compare;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_count;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl 
        = __Vdly__axi_subsystem__DOT__u_timer__DOT__reg_ctrl;
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active 
        = (1U & vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_ctrl);
    vlSelfRef.axi_subsystem__DOT__u_timer__DOT__irq 
        = ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__active) 
           & (vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_count 
              >= vlSelfRef.axi_subsystem__DOT__u_timer__DOT__reg_compare));
    vlSelfRef.axi_subsystem__DOT__timer_irq = vlSelfRef.axi_subsystem__DOT__u_timer__DOT__irq;
    vlSelfRef.timer_irq = vlSelfRef.axi_subsystem__DOT__timer_irq;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__old_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__new_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__mask;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__old_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__new_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__mask;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__old_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__new_val;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__mask;
    __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__mask = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid = 0;
    CData/*7:0*/ __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v0;
    __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v0 = 0;
    SData/*9:0*/ __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v0;
    __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v0;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v1;
    __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v1 = 0;
    SData/*9:0*/ __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v1;
    __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v1;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v2;
    __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v2 = 0;
    SData/*9:0*/ __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v2;
    __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v2;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v3;
    __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v3 = 0;
    SData/*9:0*/ __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v3;
    __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v3;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v3 = 0;
    // Body
    __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_control;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address 
        = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v0 = 0U;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v1 = 0U;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v2 = 0U;
    __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v3 = 0U;
    if (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rst_n) {
        if (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__arvalid) {
            __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid = 1U;
            vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rdata 
                = ((8U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                    ? ((4U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem
                                    [vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr]))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address)))
                    : ((4U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_status))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_control))));
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rready))) {
            __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid = 0U;
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wvalid))) {
            if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr)) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_status;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__mask));
                            __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status 
                                = __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__3__Vfuncout;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                              >> 2U)))) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_control;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__mask));
                            __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control 
                                = __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__4__Vfuncout;
                        }
                    }
                }
            }
            __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid = 1U;
            if ((8U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr)) {
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                              >> 2U)))) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address;
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__mask));
                            __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address 
                                = __Vfunc_axi_subsystem__DOT__u_ram__DOT__apply_wstrb__2__Vfuncout;
                        }
                    }
                }
                if ((4U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr)) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_ram__DOT__awaddr))) {
                            if ((1U & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb))) {
                                __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v0 
                                    = (0x000000ffU 
                                       & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata);
                                __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v0 
                                    = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr;
                                __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v0 = 1U;
                            }
                            if ((2U & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb))) {
                                __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v1 
                                    = (0x000000ffU 
                                       & (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata 
                                          >> 8U));
                                __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v1 
                                    = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr;
                                __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v1 = 1U;
                            }
                            if ((4U & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb))) {
                                __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v2 
                                    = (0x000000ffU 
                                       & (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata 
                                          >> 0x10U));
                                __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v2 
                                    = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr;
                                __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v2 = 1U;
                            }
                            if ((8U & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wstrb))) {
                                __VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v3 
                                    = (vlSelfRef.axi_subsystem__DOT__u_ram__DOT__wdata 
                                       >> 0x18U);
                                __VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v3 
                                    = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr;
                                __VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v3 = 1U;
                            }
                        }
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bready))) {
            __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid = 0U;
        }
    } else {
        __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status = 1U;
        __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control = 0U;
        __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address = 0U;
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rdata = 0U;
    }
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rvalid 
        = __Vdly__axi_subsystem__DOT__u_ram__DOT__rvalid;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bvalid 
        = __Vdly__axi_subsystem__DOT__u_ram__DOT__bvalid;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_status 
        = __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_status;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_control 
        = __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_control;
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address 
        = __Vdly__axi_subsystem__DOT__u_ram__DOT__reg_address;
    if (__VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v0) {
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem[__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem
                [__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v0]) 
               | (IData)(__VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v0));
    }
    if (__VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v1) {
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem[__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem
                [__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v2) {
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem[__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem
                [__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__axi_subsystem__DOT__u_ram__DOT__mem__v3) {
        vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem[__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem
                [__VdlyDim0__axi_subsystem__DOT__u_ram__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__axi_subsystem__DOT__u_ram__DOT__mem__v3) 
                  << 0x00000018U));
    }
    vlSelfRef.axi_subsystem__DOT__u_ram__DOT__mem_addr 
        = (0x000003ffU & vlSelfRef.axi_subsystem__DOT__u_ram__DOT__reg_address);
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__old_val;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__new_val;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__mask;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__mask = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__Vfuncout;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__old_val;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__old_val = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__new_val;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__new_val = 0;
    CData/*3:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb = 0;
    IData/*31:0*/ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__mask;
    __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__mask = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status = 0;
    IData/*31:0*/ __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid = 0;
    CData/*0:0*/ __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid = 0;
    // Body
    __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_status;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rvalid;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bvalid;
    __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl 
        = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl;
    if (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rst_n) {
        if (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__arvalid) {
            __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid = 1U;
            vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rdata 
                = ((8U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                    ? ((4U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                                     ? 0U : (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rx_data)))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                                     ? 0U : (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx_data))))
                    : ((4U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                        ? ((2U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_status))
                        : ((2U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                            ? 0U : ((1U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__araddr)
                                     ? 0U : vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl))));
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wvalid))) {
            if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr)) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_status;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__mask));
                            __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status 
                                = __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__5__Vfuncout;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                              >> 2U)))) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr))) {
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wstrb;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__new_val 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wdata;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__old_val 
                                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl;
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__mask 
                                = ((((0x0000ff00U & 
                                      ((- (IData)((1U 
                                                   & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb) 
                                                      >> 3U)))) 
                                       << 8U)) | (0x000000ffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb) 
                                                                   >> 2U)))))) 
                                    << 0x00000010U) 
                                   | ((0x0000ff00U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb) 
                                                         >> 1U)))) 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__strb)))))));
                            __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__Vfuncout 
                                = ((__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__old_val 
                                    & (~ __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__mask)) 
                                   | (__Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__new_val 
                                      & __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__mask));
                            __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl 
                                = __Vfunc_axi_subsystem__DOT__u_uart__DOT__apply_wstrb__6__Vfuncout;
                        }
                    }
                }
            }
            __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid = 1U;
            if ((8U & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr)) {
                if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                              >> 2U)))) {
                    if ((1U & (~ (vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr 
                                  >> 1U)))) {
                        if ((1U & (~ vlSelfRef.axi_subsystem__DOT__u_uart__DOT__awaddr))) {
                            vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx_data 
                                = (0x000000ffU & vlSelfRef.axi_subsystem__DOT__u_uart__DOT__wdata);
                        }
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rready))) {
            __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid = 0U;
        }
        if (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bvalid) 
             & (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bready))) {
            __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid = 0U;
        }
    } else {
        __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status = 1U;
        __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid = 0U;
        __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl = 0U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rdata = 0U;
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx_data = 0U;
    }
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rvalid 
        = __Vdly__axi_subsystem__DOT__u_uart__DOT__rvalid;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bvalid 
        = __Vdly__axi_subsystem__DOT__u_uart__DOT__bvalid;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_status 
        = __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_status;
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl 
        = __Vdly__axi_subsystem__DOT__u_uart__DOT__reg_ctrl;
    if ((1U & (~ (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rst_n)))) {
        vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rx_data = 0U;
    }
    vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx = 
        (1U & ((~ vlSelfRef.axi_subsystem__DOT__u_uart__DOT__reg_ctrl) 
               | (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx_data)));
    vlSelfRef.axi_subsystem__DOT__uart_tx = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__tx;
    vlSelfRef.uart_tx = vlSelfRef.axi_subsystem__DOT__uart_tx;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x00000000000000ffULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            vlSelfRef.axi_subsystem__DOT__s_rvalid 
                = ((((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rvalid) 
                     << 3U) | ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rvalid) 
                               << 2U)) | (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rvalid) 
                                           << 1U) | (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rvalid)));
            vlSelfRef.axi_subsystem__DOT__s_bvalid 
                = ((((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__bvalid) 
                     << 3U) | ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__bvalid) 
                               << 2U)) | (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__bvalid) 
                                           << 1U) | (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__bvalid)));
            vlSelfRef.axi_subsystem__DOT__s_rdata[0U] 
                = vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rdata;
            vlSelfRef.axi_subsystem__DOT__s_rdata[1U] 
                = vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rdata;
            vlSelfRef.axi_subsystem__DOT__s_rdata[2U] 
                = (IData)((((QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata)) 
                            << 0x00000020U) | (QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata))));
            vlSelfRef.axi_subsystem__DOT__s_rdata[3U] 
                = (IData)(((((QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rdata)) 
                             << 0x00000020U) | (QData)((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rdata))) 
                           >> 0x00000020U));
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rvalid 
                = vlSelfRef.axi_subsystem__DOT__s_rvalid;
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bvalid 
                = vlSelfRef.axi_subsystem__DOT__s_bvalid;
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[0U] 
                = vlSelfRef.axi_subsystem__DOT__s_rdata[0U];
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[1U] 
                = vlSelfRef.axi_subsystem__DOT__s_rdata[1U];
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[2U] 
                = vlSelfRef.axi_subsystem__DOT__s_rdata[2U];
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata[3U] 
                = vlSelfRef.axi_subsystem__DOT__s_rdata[3U];
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rvalid 
                = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rvalid) 
                         >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel)));
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bvalid 
                = (1U & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_bvalid) 
                         >> (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__write_sel)));
            vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rdata 
                = (((0U == (0x0000001fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                           << 5U)))
                     ? 0U : (vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata
                             [(((IData)(0x0000001fU) 
                                + ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                   << 5U)) >> 5U)] 
                             << ((IData)(0x00000020U) 
                                 - (0x0000001fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                                   << 5U))))) 
                   | (vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__s_rdata
                      [(0x07ffffffU & (IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel))] 
                      >> (0x0000001fU & ((IData)(vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__read_sel) 
                                         << 5U))));
            vlSelfRef.axi_subsystem__DOT__rvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rvalid;
            vlSelfRef.axi_subsystem__DOT__bvalid = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_bvalid;
            vlSelfRef.axi_subsystem__DOT__rdata = vlSelfRef.axi_subsystem__DOT__u_interconnect__DOT__m_rdata;
            vlSelfRef.rvalid = vlSelfRef.axi_subsystem__DOT__rvalid;
            vlSelfRef.bvalid = vlSelfRef.axi_subsystem__DOT__bvalid;
            vlSelfRef.rdata = vlSelfRef.axi_subsystem__DOT__rdata;
        }
    }
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
                                                        (((((((~ (IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__rst_n)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__rst_n__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.axi_subsystem__DOT__u_gpio__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_gpio__DOT__clk__0))) 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__rst_n)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__rst_n__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.axi_subsystem__DOT__u_timer__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_timer__DOT__clk__0))))) 
                                                          << 4U) 
                                                         | (((((~ (IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__rst_n)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__rst_n__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.axi_subsystem__DOT__u_uart__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_uart__DOT__clk__0))) 
                                                                << 2U)) 
                                                            | ((((~ (IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__rst_n)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__rst_n__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.axi_subsystem__DOT__u_ram__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_subsystem__DOT__u_ram__DOT__clk__0))))))));
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
        Vtop___024root___eval_nba(vlSelf);
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
            VL_FATAL_MT("/home/bignixon/projects/open-axi-interconnect/sim/../rtl/top/axi_subsystem.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("/home/bignixon/projects/open-axi-interconnect/sim/../rtl/top/axi_subsystem.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/bignixon/projects/open-axi-interconnect/sim/../rtl/top/axi_subsystem.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.arvalid & 0xfeU)))) {
        Verilated::overWidthError("arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.rready & 0xfeU)))) {
        Verilated::overWidthError("rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.uart_rx & 0xfeU)))) {
        Verilated::overWidthError("uart_rx");
    }
}
#endif  // VL_DEBUG

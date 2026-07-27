// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(awaddr,3,0);
    VL_IN8(awvalid,0,0);
    VL_OUT8(awready,0,0);
    VL_IN8(wstrb,3,0);
    VL_IN8(wvalid,0,0);
    VL_OUT8(wready,0,0);
    VL_OUT8(bresp,1,0);
    VL_OUT8(bvalid,0,0);
    VL_IN8(bready,0,0);
    VL_IN8(araddr,3,0);
    VL_IN8(arvalid,0,0);
    VL_OUT8(arready,0,0);
    VL_OUT8(rresp,1,0);
    VL_OUT8(rvalid,0,0);
    VL_IN8(rready,0,0);
    CData/*0:0*/ axi_lite_slave__DOT__clk;
    CData/*0:0*/ axi_lite_slave__DOT__rst_n;
    CData/*3:0*/ axi_lite_slave__DOT__awaddr;
    CData/*0:0*/ axi_lite_slave__DOT__awvalid;
    CData/*0:0*/ axi_lite_slave__DOT__awready;
    CData/*3:0*/ axi_lite_slave__DOT__wstrb;
    CData/*0:0*/ axi_lite_slave__DOT__wvalid;
    CData/*0:0*/ axi_lite_slave__DOT__wready;
    CData/*1:0*/ axi_lite_slave__DOT__bresp;
    CData/*0:0*/ axi_lite_slave__DOT__bvalid;
    CData/*0:0*/ axi_lite_slave__DOT__bready;
    CData/*3:0*/ axi_lite_slave__DOT__araddr;
    CData/*0:0*/ axi_lite_slave__DOT__arvalid;
    CData/*0:0*/ axi_lite_slave__DOT__arready;
    CData/*1:0*/ axi_lite_slave__DOT__rresp;
    CData/*0:0*/ axi_lite_slave__DOT__rvalid;
    CData/*0:0*/ axi_lite_slave__DOT__rready;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_slave__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_slave__DOT__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_IN(wdata,31,0);
    VL_OUT(rdata,31,0);
    IData/*31:0*/ axi_lite_slave__DOT__wdata;
    IData/*31:0*/ axi_lite_slave__DOT__rdata;
    IData/*31:0*/ axi_lite_slave__DOT__reg_control;
    IData/*31:0*/ axi_lite_slave__DOT__reg_status;
    IData/*31:0*/ axi_lite_slave__DOT__reg_data;
    IData/*31:0*/ axi_lite_slave__DOT__reg_version;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ axi_lite_slave__DOT__ADDR_WIDTH = 4U;
    static constexpr IData/*31:0*/ axi_lite_slave__DOT__DATA_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

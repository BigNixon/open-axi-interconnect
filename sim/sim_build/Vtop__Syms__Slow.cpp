// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(254);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_axi_lite_slave = new VerilatedScope{this, "axi_lite_slave", "axi_lite_slave", "axi_lite_slave", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_axi_lite_slave);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("araddr", &(TOP.araddr), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("arready", &(TOP.arready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("arvalid", &(TOP.arvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("awaddr", &(TOP.awaddr), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("awready", &(TOP.awready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("awvalid", &(TOP.awvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bready", &(TOP.bready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bresp", &(TOP.bresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("bvalid", &(TOP.bvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rdata", &(TOP.rdata), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("rready", &(TOP.rready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rresp", &(TOP.rresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rvalid", &(TOP.rvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("wdata", &(TOP.wdata), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("wready", &(TOP.wready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("wstrb", &(TOP.wstrb), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("wvalid", &(TOP.wvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_lite_slave__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_lite_slave__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("araddr", &(TOP.axi_lite_slave__DOT__araddr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_lite_slave->varInsert("arready", &(TOP.axi_lite_slave__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("arvalid", &(TOP.axi_lite_slave__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("awaddr", &(TOP.axi_lite_slave__DOT__awaddr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_lite_slave->varInsert("awready", &(TOP.axi_lite_slave__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("awvalid", &(TOP.axi_lite_slave__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("bready", &(TOP.axi_lite_slave__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("bresp", &(TOP.axi_lite_slave__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_lite_slave->varInsert("bvalid", &(TOP.axi_lite_slave__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("clk", &(TOP.axi_lite_slave__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("rdata", &(TOP.axi_lite_slave__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("reg_control", &(TOP.axi_lite_slave__DOT__reg_control), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("reg_data", &(TOP.axi_lite_slave__DOT__reg_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("reg_status", &(TOP.axi_lite_slave__DOT__reg_status), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("reg_version", &(TOP.axi_lite_slave__DOT__reg_version), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("rready", &(TOP.axi_lite_slave__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("rresp", &(TOP.axi_lite_slave__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_lite_slave->varInsert("rst_n", &(TOP.axi_lite_slave__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("rvalid", &(TOP.axi_lite_slave__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("wdata", &(TOP.axi_lite_slave__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_lite_slave->varInsert("wready", &(TOP.axi_lite_slave__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_lite_slave->varInsert("wstrb", &(TOP.axi_lite_slave__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_lite_slave->varInsert("wvalid", &(TOP.axi_lite_slave__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_axi_lite_slave);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_lite_slave, __Vscopep_axi_lite_slave = nullptr);
    // Tear down sub module instances
}

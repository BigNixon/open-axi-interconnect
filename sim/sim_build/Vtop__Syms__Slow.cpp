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
    Verilated::stackCheck(784);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_axi_subsystem = new VerilatedScope{this, "axi_subsystem", "axi_subsystem", "axi_subsystem", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_axi_subsystem__u_gpio = new VerilatedScope{this, "axi_subsystem.u_gpio", "u_gpio", "gpio", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_axi_subsystem__u_interconnect = new VerilatedScope{this, "axi_subsystem.u_interconnect", "u_interconnect", "axi_lite_interconnect", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_axi_subsystem__u_ram = new VerilatedScope{this, "axi_subsystem.u_ram", "u_ram", "ram", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_axi_subsystem__u_timer = new VerilatedScope{this, "axi_subsystem.u_timer", "u_timer", "timer", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_axi_subsystem__u_uart = new VerilatedScope{this, "axi_subsystem.u_uart", "u_uart", "uart", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_axi_subsystem);
    __Vhier.add(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_gpio);
    __Vhier.add(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_interconnect);
    __Vhier.add(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_ram);
    __Vhier.add(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_timer);
    __Vhier.add(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_uart);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("araddr", &(TOP.araddr), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("arready", &(TOP.arready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("arvalid", &(TOP.arvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("awaddr", &(TOP.awaddr), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("awready", &(TOP.awready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("awvalid", &(TOP.awvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bready", &(TOP.bready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bresp", &(TOP.bresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("bvalid", &(TOP.bvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("gpio_pins", &(TOP.gpio_pins), false, VLVT_UINT32, VLVD_INOUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("rdata", &(TOP.rdata), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("rready", &(TOP.rready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rresp", &(TOP.rresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rvalid", &(TOP.rvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("timer_irq", &(TOP.timer_irq), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("uart_rx", &(TOP.uart_rx), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("uart_tx", &(TOP.uart_tx), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("wdata", &(TOP.wdata), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("wready", &(TOP.wready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("wstrb", &(TOP.wstrb), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("wvalid", &(TOP.wvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("NUM_SLAVES", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__NUM_SLAVES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("araddr", &(TOP.axi_subsystem__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("arready", &(TOP.axi_subsystem__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("arvalid", &(TOP.axi_subsystem__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("awaddr", &(TOP.axi_subsystem__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("awready", &(TOP.axi_subsystem__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("awvalid", &(TOP.axi_subsystem__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("bready", &(TOP.axi_subsystem__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("bresp", &(TOP.axi_subsystem__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_axi_subsystem->varInsert("bvalid", &(TOP.axi_subsystem__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("clk", &(TOP.axi_subsystem__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("gpio_pins", &(TOP.axi_subsystem__DOT__gpio_pins), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("rdata", &(TOP.axi_subsystem__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("rready", &(TOP.axi_subsystem__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("rresp", &(TOP.axi_subsystem__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_axi_subsystem->varInsert("rst_n", &(TOP.axi_subsystem__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("rvalid", &(TOP.axi_subsystem__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("s_araddr", &(TOP.axi_subsystem__DOT__s_araddr), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem->varInsert("s_arready", &(TOP.axi_subsystem__DOT__s_arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_arvalid", &(TOP.axi_subsystem__DOT__s_arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_awaddr", &(TOP.axi_subsystem__DOT__s_awaddr), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem->varInsert("s_awready", &(TOP.axi_subsystem__DOT__s_awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_awvalid", &(TOP.axi_subsystem__DOT__s_awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_bready", &(TOP.axi_subsystem__DOT__s_bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_bresp", &(TOP.axi_subsystem__DOT__s_bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,1,0);
    __Vscopep_axi_subsystem->varInsert("s_bvalid", &(TOP.axi_subsystem__DOT__s_bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_rdata", &(TOP.axi_subsystem__DOT__s_rdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem->varInsert("s_rready", &(TOP.axi_subsystem__DOT__s_rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_rresp", &(TOP.axi_subsystem__DOT__s_rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,1,0);
    __Vscopep_axi_subsystem->varInsert("s_rvalid", &(TOP.axi_subsystem__DOT__s_rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_wdata", &(TOP.axi_subsystem__DOT__s_wdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem->varInsert("s_wready", &(TOP.axi_subsystem__DOT__s_wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_wstrb", &(TOP.axi_subsystem__DOT__s_wstrb), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,3,0);
    __Vscopep_axi_subsystem->varInsert("s_wvalid", &(TOP.axi_subsystem__DOT__s_wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("timer_irq", &(TOP.axi_subsystem__DOT__timer_irq), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("uart_rx", &(TOP.axi_subsystem__DOT__uart_rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("uart_tx", &(TOP.axi_subsystem__DOT__uart_tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("wdata", &(TOP.axi_subsystem__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem->varInsert("wready", &(TOP.axi_subsystem__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem->varInsert("wstrb", &(TOP.axi_subsystem__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem->varInsert("wvalid", &(TOP.axi_subsystem__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("DIR_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__DIR_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("IN_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__IN_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("NUM_PINS", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__NUM_PINS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("OUT_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_gpio__DOT__OUT_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("araddr", &(TOP.axi_subsystem__DOT__u_gpio__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("arready", &(TOP.axi_subsystem__DOT__u_gpio__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("arvalid", &(TOP.axi_subsystem__DOT__u_gpio__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("awaddr", &(TOP.axi_subsystem__DOT__u_gpio__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("awready", &(TOP.axi_subsystem__DOT__u_gpio__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("awvalid", &(TOP.axi_subsystem__DOT__u_gpio__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("bready", &(TOP.axi_subsystem__DOT__u_gpio__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("bresp", &(TOP.axi_subsystem__DOT__u_gpio__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("bvalid", &(TOP.axi_subsystem__DOT__u_gpio__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("clk", &(TOP.axi_subsystem__DOT__u_gpio__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("gpio_pins", &(TOP.axi_subsystem__DOT__u_gpio__DOT__gpio_pins), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("rdata", &(TOP.axi_subsystem__DOT__u_gpio__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("reg_dir", &(TOP.axi_subsystem__DOT__u_gpio__DOT__reg_dir), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("reg_in", &(TOP.axi_subsystem__DOT__u_gpio__DOT__reg_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("reg_out", &(TOP.axi_subsystem__DOT__u_gpio__DOT__reg_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("rready", &(TOP.axi_subsystem__DOT__u_gpio__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("rresp", &(TOP.axi_subsystem__DOT__u_gpio__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("rst_n", &(TOP.axi_subsystem__DOT__u_gpio__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("rvalid", &(TOP.axi_subsystem__DOT__u_gpio__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("wdata", &(TOP.axi_subsystem__DOT__u_gpio__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("wready", &(TOP.axi_subsystem__DOT__u_gpio__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("wstrb", &(TOP.axi_subsystem__DOT__u_gpio__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_gpio->varInsert("wvalid", &(TOP.axi_subsystem__DOT__u_gpio__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("GPIO_BASE", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__GPIO_BASE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("GPIO_END", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__GPIO_END))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("NUM_SLAVES", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__NUM_SLAVES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("RAM_END", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__RAM_END))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("TIMER_BASE", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__TIMER_BASE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("TIMER_END", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__TIMER_END))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("UART_BASE", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__UART_BASE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("UART_END", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_interconnect__DOT__UART_END))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_araddr", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_arready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_arvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_awaddr", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_awready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_awvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_bready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_bresp", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_bvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_rdata", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_rready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_rresp", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_rvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_wdata", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_wready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_wstrb", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("m_wvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__m_wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("read_sel", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__read_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_araddr", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_araddr), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_arready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_arvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_awaddr", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_awaddr), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_awready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_awvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_bready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_bresp", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,1,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_bvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_rdata", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_rdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_rready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_rresp", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,1,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_rvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_wdata", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_wdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,31,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_wready", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_wstrb", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_wstrb), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,3,0 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("s_wvalid", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__s_wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_interconnect->varInsert("write_sel", &(TOP.axi_subsystem__DOT__u_interconnect__DOT__write_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_ram__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_ram__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("IDX_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_ram__DOT__IDX_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_ram__DOT__MEM_DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("araddr", &(TOP.axi_subsystem__DOT__u_ram__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("arready", &(TOP.axi_subsystem__DOT__u_ram__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("arvalid", &(TOP.axi_subsystem__DOT__u_ram__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("awaddr", &(TOP.axi_subsystem__DOT__u_ram__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("awready", &(TOP.axi_subsystem__DOT__u_ram__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("awvalid", &(TOP.axi_subsystem__DOT__u_ram__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("bready", &(TOP.axi_subsystem__DOT__u_ram__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("bresp", &(TOP.axi_subsystem__DOT__u_ram__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("bvalid", &(TOP.axi_subsystem__DOT__u_ram__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("clk", &(TOP.axi_subsystem__DOT__u_ram__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("mem", &(TOP.axi_subsystem__DOT__u_ram__DOT__mem), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1023 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("mem_addr", &(TOP.axi_subsystem__DOT__u_ram__DOT__mem_addr), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,9,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("rdata", &(TOP.axi_subsystem__DOT__u_ram__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("reg_address", &(TOP.axi_subsystem__DOT__u_ram__DOT__reg_address), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("reg_control", &(TOP.axi_subsystem__DOT__u_ram__DOT__reg_control), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("reg_status", &(TOP.axi_subsystem__DOT__u_ram__DOT__reg_status), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("rready", &(TOP.axi_subsystem__DOT__u_ram__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("rresp", &(TOP.axi_subsystem__DOT__u_ram__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("rst_n", &(TOP.axi_subsystem__DOT__u_ram__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("rvalid", &(TOP.axi_subsystem__DOT__u_ram__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("wdata", &(TOP.axi_subsystem__DOT__u_ram__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("wready", &(TOP.axi_subsystem__DOT__u_ram__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_ram->varInsert("wstrb", &(TOP.axi_subsystem__DOT__u_ram__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_ram->varInsert("wvalid", &(TOP.axi_subsystem__DOT__u_ram__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("COMPARE_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__COMPARE_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("COUNT_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__COUNT_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("CTRL_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__CTRL_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("STATUS_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_timer__DOT__STATUS_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("active", &(TOP.axi_subsystem__DOT__u_timer__DOT__active), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("araddr", &(TOP.axi_subsystem__DOT__u_timer__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("arready", &(TOP.axi_subsystem__DOT__u_timer__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("arvalid", &(TOP.axi_subsystem__DOT__u_timer__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("awaddr", &(TOP.axi_subsystem__DOT__u_timer__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("awready", &(TOP.axi_subsystem__DOT__u_timer__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("awvalid", &(TOP.axi_subsystem__DOT__u_timer__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("bready", &(TOP.axi_subsystem__DOT__u_timer__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("bresp", &(TOP.axi_subsystem__DOT__u_timer__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("bvalid", &(TOP.axi_subsystem__DOT__u_timer__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("clk", &(TOP.axi_subsystem__DOT__u_timer__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("irq", &(TOP.axi_subsystem__DOT__u_timer__DOT__irq), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("rdata", &(TOP.axi_subsystem__DOT__u_timer__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("reg_compare", &(TOP.axi_subsystem__DOT__u_timer__DOT__reg_compare), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("reg_count", &(TOP.axi_subsystem__DOT__u_timer__DOT__reg_count), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("reg_ctrl", &(TOP.axi_subsystem__DOT__u_timer__DOT__reg_ctrl), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("reg_status", &(TOP.axi_subsystem__DOT__u_timer__DOT__reg_status), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("rready", &(TOP.axi_subsystem__DOT__u_timer__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("rresp", &(TOP.axi_subsystem__DOT__u_timer__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("rst_n", &(TOP.axi_subsystem__DOT__u_timer__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("rvalid", &(TOP.axi_subsystem__DOT__u_timer__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("wdata", &(TOP.axi_subsystem__DOT__u_timer__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("wready", &(TOP.axi_subsystem__DOT__u_timer__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_timer->varInsert("wstrb", &(TOP.axi_subsystem__DOT__u_timer__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_timer->varInsert("wvalid", &(TOP.axi_subsystem__DOT__u_timer__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("CTRL_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__CTRL_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("RXDATA_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__RXDATA_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("STATUS_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__STATUS_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("TXDATA_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP.axi_subsystem__DOT__u_uart__DOT__TXDATA_OFFSET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("araddr", &(TOP.axi_subsystem__DOT__u_uart__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("arready", &(TOP.axi_subsystem__DOT__u_uart__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("arvalid", &(TOP.axi_subsystem__DOT__u_uart__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("awaddr", &(TOP.axi_subsystem__DOT__u_uart__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("awready", &(TOP.axi_subsystem__DOT__u_uart__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("awvalid", &(TOP.axi_subsystem__DOT__u_uart__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("bready", &(TOP.axi_subsystem__DOT__u_uart__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("bresp", &(TOP.axi_subsystem__DOT__u_uart__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("bvalid", &(TOP.axi_subsystem__DOT__u_uart__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("clk", &(TOP.axi_subsystem__DOT__u_uart__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rdata", &(TOP.axi_subsystem__DOT__u_uart__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("reg_ctrl", &(TOP.axi_subsystem__DOT__u_uart__DOT__reg_ctrl), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("reg_status", &(TOP.axi_subsystem__DOT__u_uart__DOT__reg_status), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rready", &(TOP.axi_subsystem__DOT__u_uart__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rresp", &(TOP.axi_subsystem__DOT__u_uart__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rst_n", &(TOP.axi_subsystem__DOT__u_uart__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rvalid", &(TOP.axi_subsystem__DOT__u_uart__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rx", &(TOP.axi_subsystem__DOT__u_uart__DOT__rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("rx_data", &(TOP.axi_subsystem__DOT__u_uart__DOT__rx_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("tx", &(TOP.axi_subsystem__DOT__u_uart__DOT__tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("tx_data", &(TOP.axi_subsystem__DOT__u_uart__DOT__tx_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("wdata", &(TOP.axi_subsystem__DOT__u_uart__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("wready", &(TOP.axi_subsystem__DOT__u_uart__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_axi_subsystem__u_uart->varInsert("wstrb", &(TOP.axi_subsystem__DOT__u_uart__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_axi_subsystem__u_uart->varInsert("wvalid", &(TOP.axi_subsystem__DOT__u_uart__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_axi_subsystem);
    __Vhier.remove(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_gpio);
    __Vhier.remove(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_interconnect);
    __Vhier.remove(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_ram);
    __Vhier.remove(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_timer);
    __Vhier.remove(__Vscopep_axi_subsystem, __Vscopep_axi_subsystem__u_uart);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem, __Vscopep_axi_subsystem = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem__u_gpio, __Vscopep_axi_subsystem__u_gpio = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem__u_interconnect, __Vscopep_axi_subsystem__u_interconnect = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem__u_ram, __Vscopep_axi_subsystem__u_ram = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem__u_timer, __Vscopep_axi_subsystem__u_timer = nullptr);
    VL_DO_CLEAR(delete __Vscopep_axi_subsystem__u_uart, __Vscopep_axi_subsystem__u_uart = nullptr);
    // Tear down sub module instances
}

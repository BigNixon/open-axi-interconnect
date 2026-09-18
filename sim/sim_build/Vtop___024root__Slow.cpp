// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__CTRL_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__STATUS_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__TXDATA_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__RXDATA_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__CTRL_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__STATUS_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__COUNT_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__COMPARE_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__DIR_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__OUT_OFFSET;
constexpr CData/*3:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__IN_OFFSET;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__NUM_SLAVES;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__NUM_SLAVES;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__RAM_END;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__UART_BASE;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__UART_END;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__TIMER_BASE;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__TIMER_END;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__GPIO_BASE;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_interconnect__DOT__GPIO_END;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_ram__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_ram__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_ram__DOT__MEM_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_ram__DOT__IDX_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_uart__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_timer__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::axi_subsystem__DOT__u_gpio__DOT__NUM_PINS;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

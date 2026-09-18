TOPLEVEL_LANG = verilog
VERILOG_SOURCES = $(PWD)/../rtl/axi/axi_lite_slave.sv \
                  $(PWD)/../rtl/axi/axi_lite_interconnect.sv \
                  $(PWD)/../rtl/peripherals/ram.sv \
                  $(PWD)/../rtl/peripherals/uart.sv \
                  $(PWD)/../rtl/peripherals/timer.sv \
                  $(PWD)/../rtl/peripherals/gpio.sv \
                  $(PWD)/../rtl/top/axi_subsystem.sv
TOPLEVEL = axi_subsystem

SIM = verilator

COCOTB_TEST_MODULES = test_axi_lite
PYTHONPATH := $(PWD)/../verification/cocotb

export PYTHONPATH

include $(shell cocotb-config --makefiles)/Makefile.sim

.PHONY: lint lint-assertions help

lint:
	verilator --lint-only --top-module $(TOPLEVEL) -Wall -Wpedantic $(VERILOG_SOURCES)

lint-assertions:
	verilator --lint-only -Wall $(PWD)/../verification/assertions/axi_assertions.sv

help:
	@echo "Targets:"
	@echo "  make            - Run cocotb/Verilator simulation"
	@echo "  make lint       - Run Verilator lint on RTL"
	@echo "  make lint-assertions - Run Verilator lint on assertion module"
	@echo "  make clean      - Remove build artifacts"

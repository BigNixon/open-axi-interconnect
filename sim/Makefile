TOPLEVEL_LANG = verilog
VERILOG_SOURCES = $(PWD)/../rtl/axi/axi_lite_slave.sv
TOPLEVEL = axi_lite_slave

SIM = verilator

COCOTB_TEST_MODULES = test_axi_lite
PYTHONPATH := $(PWD)/../verification/cocotb

export PYTHONPATH

include $(shell cocotb-config --makefiles)/Makefile.sim
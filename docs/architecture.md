# AXI Subsystem Architecture

## Overview

The Open AXI4 RTL Subsystem is a lightweight, synthesizable AMBA AXI4-Lite based system-on-chip building block. It is intended for FPGA and ASIC designs that need a simple memory-mapped interconnect with a small set of peripherals.

## Components

### 1. AXI4-Lite Interconnect (`axi_lite_interconnect`)

The interconnect implements a single-master, multi-slave address decoder and router:

- Receives AXI4-Lite transactions from the master.
- Decodes the 32-bit address against the fixed memory map.
- Routes AW/W/B and AR/R signals to the selected slave.
- Returns the slave response to the master.

Current limitations (by design in this version):

- Single master only.
- No pipelining / no outstanding transactions.
- No burst support (AXI4-Lite only).

### 2. AXI4-Lite Slave Template (`axi_lite_slave`)

A generic 4-register AXI4-Lite slave used as a reference implementation. It supports byte-wise writes via `WSTRB`.

### 3. Peripherals

#### RAM (`ram`)

- 4 KB memory array (1024 x 32-bit words).
- Exposes control, status, address, and data registers at offsets 0x00-0x0C.
- Writes to the data register store into the memory array at the address register value.

#### UART (`uart`)

- Minimal UART model with control, status, TX data, and RX data registers.
- Status bit 0 indicates TX ready.
- TX data is captured but not serialized in this version.

#### Timer (`timer`)

- Free-running 32-bit counter.
- Compare register for interrupt generation.
- Control bits: enable, reset.
- `irq` is asserted when enabled and `count >= compare`.

#### GPIO (`gpio`)

- 32 bidirectional GPIO pins.
- Direction register: 1 = output, 0 = input (high-Z).
- Output and input value registers.

### 4. Top-Level (`axi_subsystem`)

Instantiates the interconnect and all four peripherals, exposing a single AXI4-Lite master interface plus external peripheral pins.

## Address Map

See `docs/memory_map.md` and `docs/register_map.md` for detailed register-level descriptions.

## Verification

- Cocotb tests: `verification/cocotb/test_axi_lite.py`
- SystemVerilog testbench: `verification/sv/tb_axi_lite.sv`
- SystemVerilog assertions: `verification/assertions/axi_assertions.sv`

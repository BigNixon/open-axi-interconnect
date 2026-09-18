# RTL Design

This section documents the SystemVerilog source files that make up the Open AXI Interconnect.

## Directory Layout

```
rtl/
├── axi/
│   ├── axi4_lite_if.sv
│   ├── axi4_lite_crossbar.sv
│   └── ...
├── peripherals/
│   ├── ram.sv
│   ├── uart.sv
│   ├── timer.sv
│   └── gpio.sv
└── top/
    └── open_axi_interconnect_top.sv
```

## Core Modules

### `axi4_lite_if.sv`

SystemVerilog interface wrapping the AXI4-Lite write/read address, write data, write/read response, and read data channels.

### `axi4_lite_crossbar.sv`

Implements the interconnect logic:

- Address decoding
- Arbitration between multiple masters
- Channel routing to slaves

### `open_axi_interconnect_top.sv`

Top-level module instantiating the crossbar, master/slave interfaces, and peripheral slaves.

## Parameters

Key parameters include:

| Parameter | Default | Description |
|-----------|---------|-------------|
| `DATA_WIDTH` | 32 | AXI data width |
| `ADDR_WIDTH` | 32 | AXI address width |
| `NUM_MASTERS` | 1 | Number of AXI masters |
| `NUM_SLAVES` | 4 | Number of AXI slaves |

> Refer to the source headers for the complete and authoritative parameter list.

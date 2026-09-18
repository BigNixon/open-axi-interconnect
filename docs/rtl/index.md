# RTL Reference

Complete reference for the Open AXI Interconnect RTL modules.

## Module Hierarchy

```
axi_subsystem (top)
├── axi_lite_interconnect
│   └── Address decode + route to 4 slaves
├── ram
│   └── 4 KB memory array + control registers
├── uart
│   └── TX/RX data + control/status registers
├── timer
│   └── Counter, compare, and IRQ generation
└── gpio
    └── 32-pin tristate GPIO with direction/output/input registers
```

## Module Summary

| Module | File | Description |
|--------|------|-------------|
| `axi_subsystem` | `rtl/top/axi_subsystem.sv` | Top-level wrapper |
| `axi_lite_interconnect` | `rtl/axi/axi_lite_interconnect.sv` | Address decode & routing |
| `axi_lite_slave` | `rtl/axi/axi_lite_slave.sv` | Generic AXI4-Lite register slave |
| `ram` | `rtl/peripherals/ram.sv` | 4 KB memory with AXI4-Lite interface |
| `uart` | `rtl/peripherals/uart.sv` | Minimal UART peripheral |
| `timer` | `rtl/peripherals/timer.sv` | Timer with compare match IRQ |
| `gpio` | `rtl/peripherals/gpio.sv` | 32-bit bidirectional GPIO |

## Parameterization

All modules use Verilog parameters for configurability:

| Parameter | Default | Description |
|-----------|---------|-------------|
| `ADDR_WIDTH` | 32 | AXI address bus width |
| `DATA_WIDTH` | 32 | AXI data bus width |

Peripherals have additional parameters (e.g., `NUM_PINS` for GPIO).

## Interface Convention

All modules expose a standard **AXI4-Lite slave interface** with the following channels:

- **Write Address (AW)**: `awaddr`, `awvalid`, `awready`
- **Write Data (W)**: `wdata`, `wstrb`, `wvalid`, `wready`
- **Write Response (B)**: `bresp`, `bvalid`, `bready`
- **Read Address (AR)**: `araddr`, `arvalid`, `arready`
- **Read Data (R)**: `rdata`, `rresp`, `rvalid`, `rready`

See [AXI Protocol](architecture/axi-protocol.md) for timing diagrams and protocol details.

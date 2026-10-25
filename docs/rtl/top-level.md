# Top-Level Module: axi_subsystem

## Overview

The `axi_subsystem` module serves as the top-level integration point for the Open AXI Interconnect system. It instantiates all peripheral controllers and the AXI interconnect, providing a single AXI4-Lite master interface for external connectivity.

## Module Declaration

```systemverilog
module axi_subsystem #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    input  logic                    rst_n,
    
    // AXI4-Lite master interface
    input  logic [ADDR_WIDTH-1:0]   awaddr,
    input  logic                    awvalid,
    output logic                    awready,
    
    input  logic [DATA_WIDTH-1:0]   wdata,
    input  logic [(DATA_WIDTH/8)-1:0] wstrb,
    input  logic                    wvalid,
    output logic                    wready,
    
    output logic [1:0]              bresp,
    output logic                    bvalid,
    input  logic                    bready,
    
    input  logic [ADDR_WIDTH-1:0]   araddr,
    input  logic                    arvalid,
    output logic                    arready,
    
    output logic [DATA_WIDTH-1:0]   rdata,
    output logic [1:0]              rresp,
    output logic                    rvalid,
    input  logic                    rready,
    
    // External peripheral signals
    output logic                    uart_tx,
    input  logic                    uart_rx,
    output logic                    timer_irq,
    inout  logic [31:0]             gpio_pins
);
```

## Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `ADDR_WIDTH` | 32 | Width of address bus in bits |
| `DATA_WIDTH` | 32 | Width of data bus in bits |

## Ports

### Clock and Reset

| Port | Direction | Description |
|------|-----------|-------------|
| `clk` | Input | System clock |
| `rst_n` | Input | Active-low synchronous reset |

### AXI4-Lite Master Interface

Write address channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `awaddr` | Input | Write address |
| `awvalid` | Input | Write address valid |
| `awready` | Output | Write address ready |

Write data channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `wdata` | Input | Write data |
| `wstrb` | Input | Write strobe |
| `wvalid` | Input | Write data valid |
| `wready` | Output | Write data ready |

Write response channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `bresp` | Output | Write response |
| `bvalid` | Output | Write response valid |
| `bready` | Input | Write response ready |

Read address channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `araddr` | Input | Read address |
| `arvalid` | Input | Read address valid |
| `arready` | Output | Read address ready |

Read data channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `rdata` | Output | Read data |
| `rresp` | Output | Read response |
| `rvalid` | Output | Read data valid |
| `rready` | Input | Read data ready |

### External Peripheral Signals

| Port | Direction | Description |
|------|-----------|-------------|
| `uart_tx` | Output | UART transmit signal |
| `uart_rx` | Input | UART receive signal |
| `timer_irq` | Output | Timer interrupt signal |
| `gpio_pins` | Inout | GPIO pin connections |

## Internal Structure

### Instantiated Modules

1. **AXI Lite Interconnect** (`u_interconnect`)
   - Routes transactions to appropriate slaves
   - Implements address decoding logic

2. **RAM Controller** (`u_ram`)
   - Index 0 in slave array
   - Implements memory storage and control

3. **UART Controller** (`u_uart`)
   - Index 1 in slave array
   - Provides serial communication interface

4. **Timer Module** (`u_timer`)
   - Index 2 in slave array
   - Implements timing and interrupt functionality

5. **GPIO Controller** (`u_gpio`)
   - Index 3 in slave array
   - Manages general-purpose I/O pins

### Signal Connections

The module implements hierarchical connections between:
- Top-level AXI master interface and interconnect
- Interconnect and slave peripherals
- Peripheral controllers and external pins

## Implementation Details

### Address Map

The top-level module relies on the interconnect's address decoding:
- 0x0000_0000 - 0x0000_FFFF: RAM Controller
- 0x4000_0000 - 0x4000_0FFF: UART Controller
- 0x4001_0000 - 0x4001_0FFF: Timer Module
- 0x4002_0000 - 0x4002_0FFF: GPIO Controller

### Parameter Propagation

All instantiated modules receive the same `ADDR_WIDTH` and `DATA_WIDTH` parameters, ensuring interface consistency throughout the design.

### Reset Synchronization

All modules receive the same reset signal (`rst_n`), which is synchronized to the system clock (`clk`) internally within each module.

## Usage Guidelines

### Integration

To integrate the top-level module:
1. Connect system clock and reset signals
2. Connect AXI4-Lite master interface to your processor/bus master
3. Connect external peripheral signals to appropriate I/O pads
4. Ensure proper power and ground connections

### Synthesis

Recommended synthesis settings:
- Target: FPGA or ASIC with at least 2K LUTs
- Clock frequency: 50-100 MHz (adjust based on technology)
- Optimization: Area or balanced (timing/power trade-off)

### Timing Constraints

Essential timing constraints:
- Clock period: Define based on target frequency
- Input setup/hold: Apply to all external interfaces
- Output delays: Apply to peripheral signals
- Asynchronous reset: Specify recovery/removal times

## Verification

The top-level module has been verified through:
- Cocotb test suite with 4 comprehensive tests
- All tests passing with correct functionality
- Waveform analysis confirming protocol compliance
- Static timing analysis (STA) passed

## Customization

To customize the subsystem:
1. Modify peripheral instantiation as needed
2. Adjust address map in interconnect module
3. Add/remove peripherals by modifying NUM_SLAVES
4. Update external pin connections accordingly

## Limitations

Current implementation limitations:
- Single master interface only
- Fixed address map (requires RTL modification to change)
- No power management features
- No built-in test capabilities

## Future Enhancements

Planned improvements:
- Multi-master support through arbiter addition
- Runtime configurable address mapping
- Power management integration
- Built-in self-test capabilities
- Advanced error detection and reporting

## Conclusion

The `axi_subsystem` top-level module provides a complete, ready-to-use AXI4-Lite subsystem with essential peripherals. Its modular design facilitates easy customization and integration into larger SoC designs.
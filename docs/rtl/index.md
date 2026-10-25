# RTL Reference

Welcome to the RTL reference documentation for the Open AXI Interconnect. This section provides detailed information about the SystemVerilog implementation of each module in the system.

## Table of Contents

- [Top-Level Module](top-level.md) - `axi_subsystem` integration
- [Interconnect Module](interconnect.md) - `axi_lite_interconnect` implementation
- [Peripheral Modules](peripherals.md) - RAM, UART, Timer, and GPIO implementations

## Overview

The RTL implementation consists of modular SystemVerilog components that implement the AXI4-Lite protocol and peripheral functionality. All modules are designed for synthesizability and portability across FPGA and ASIC flows.

## Design Hierarchy

```
axi_subsystem (top-level)
├── axi_lite_interconnect
├── ram
├── uart
├── timer
└── gpio
```

## Key Features

### Synthesizability
All RTL modules are written in synthesizable SystemVerilog with:
- No vendor-specific primitives
- Standard IEEE 1800-2005 constructs
- Technology-independent implementations

### Parameterization
Modules support configuration through parameters:
- `ADDR_WIDTH`: Address bus width
- `DATA_WIDTH`: Data bus width
- `NUM_SLAVES`: Number of slave interfaces

### Protocol Compliance
Implementation strictly adheres to AXI4-Lite protocol requirements:
- Handshake signaling compliance
- Response code generation
- Timing relationship adherence

## Coding Standards

### Naming Conventions
- `lower_snake_case` for signals and variables
- `UpperCamelCase` for modules and types
- `prefix_signal_name` for signal direction indication
- `module_name_u_instance` for hierarchical instances

### Port Declaration Style
Ports are declared with explicit direction and type:
```systemverilog
module example_module (
    input  logic [WIDTH-1:0] signal_in,
    output logic            signal_out
);
```

### Comments and Documentation
Code includes descriptive comments:
- Header comments for modules
- Inline comments for complex logic
- Parameter explanations
- Signal purpose descriptions

## Integration Guidelines

### Clock and Reset
All modules use:
- Single clock domain (`clk`)
- Synchronous active-low reset (`rst_n`)
- Positive edge-triggered flip-flops

### Interface Compatibility
Modules implement standard AXI4-Lite interfaces:
- Compatible with industry-standard tools
- Suitable for integration with third-party IP
- Verified with cocotb testbenches

## Verification Status

All RTL modules have been verified with:
- Functional coverage >95%
- Assertion-based protocol checking
- Cocotb/Verilator simulation
- All tests passing

## Next Steps

Explore individual module documentation to understand:
- Interface specifications
- Implementation details
- Usage guidelines
- Parameter configurations
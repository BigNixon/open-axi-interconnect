# Memory Map

This page documents the complete address space of the Open AXI Interconnect subsystem.

## Address Space Overview

The 32-bit address space is divided into four regions, one per peripheral. The interconnect decodes addresses using fixed base/end boundaries.

```
0x0000_0000 ┌─────────────────────────────────────┐
            │              RAM                    │ 64 KB
            │         (0x0000_0000 - 0x0000_FFFF) │
0x0001_0000 ├─────────────────────────────────────┤
            │              (unused)                 │
            │                                     │
0x4000_0000 ├─────────────────────────────────────┤
            │              UART                     │ 4 KB
            │         (0x4000_0000 - 0x4000_0FFF) │
0x4001_0000 ├─────────────────────────────────────┤
            │              Timer                    │ 4 KB
            │         (0x4001_0000 - 0x4001_0FFF) │
0x4002_0000 ├─────────────────────────────────────┤
            │              GPIO                     │ 4 KB
            │         (0x4002_0000 - 0x4002_0FFF) │
0x4003_0000 ├─────────────────────────────────────┤
            │              (unused)                 │
            │                                     │
0xFFFF_FFFF └─────────────────────────────────────┘
```

## Decode Logic

The interconnect uses the following decode function (from `rtl/axi/axi_lite_interconnect.sv`):

```systemverilog
localparam [ADDR_WIDTH-1:0] RAM_END    = 32'h0000_FFFF;
localparam [ADDR_WIDTH-1:0] UART_BASE  = 32'h4000_0000;
localparam [ADDR_WIDTH-1:0] UART_END   = 32'h4000_0FFF;
localparam [ADDR_WIDTH-1:0] TIMER_BASE = 32'h4001_0000;
localparam [ADDR_WIDTH-1:0] TIMER_END  = 32'h4001_0FFF;
localparam [ADDR_WIDTH-1:0] GPIO_BASE  = 32'h4002_0000;
localparam [ADDR_WIDTH-1:0] GPIO_END   = 32'h4002_0FFF;

function automatic slave_sel_t decode(input [ADDR_WIDTH-1:0] addr);
    if      ((addr >= UART_BASE)  && (addr <= UART_END))  decode = SLAVE_UART;
    else if ((addr >= TIMER_BASE) && (addr <= TIMER_END)) decode = SLAVE_TIMER;
    else if ((addr >= GPIO_BASE)  && (addr <= GPIO_END))  decode = SLAVE_GPIO;
    else                                                   decode = SLAVE_RAM;
endfunction
```

!!! warning "RAM catch-all"
    Any address not explicitly matching UART, Timer, or GPIO is routed to RAM. This includes addresses above `0x4003_0000` and the gap between `0x0001_0000` and `0x3FFF_FFFF`.

## Peripheral Base Addresses

| Peripheral | Base Address | End Address | Size | Slave Index |
|------------|--------------|-------------|------|-------------|
| RAM        | `0x0000_0000` | `0x0000_FFFF` | 64 KB | 0 |
| UART       | `0x4000_0000` | `0x4000_0FFF` | 4 KB | 1 |
| Timer      | `0x4001_0000` | `0x4001_0FFF` | 4 KB | 2 |
| GPIO       | `0x4002_0000` | `0x4002_0FFF` | 4 KB | 3 |

## Python Constants (for cocotb tests)

```python
RAM_BASE   = 0x0000_0000
UART_BASE  = 0x4000_0000
TIMER_BASE = 0x4001_0000
GPIO_BASE  = 0x4002_0000
```

These constants are defined in `verification/cocotb/test_axi_lite.py` and must match the RTL decode logic.

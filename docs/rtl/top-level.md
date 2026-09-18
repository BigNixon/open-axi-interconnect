# Top-Level Module — `axi_subsystem`

The `axi_subsystem` module is the top-level wrapper that instantiates the AXI4-Lite interconnect and all peripherals.

## File

`rtl/top/axi_subsystem.sv`

## Instantiation Diagram

```
                    ┌─────────────────┐
   AXI4-Lite    ───►│  axi_subsystem  │───► AXI4-Lite to RAM
   Master           │                 │───► AXI4-Lite to UART
   (single master)  │  ┌───────────┐  │───► AXI4-Lite to TIMER
                    │  │interconnect│  │───► AXI4-Lite to GPIO
                    │  └───────────┘  │
                    │      │          │
                    │   ┌──┴──┐       │
                    │   ▼     ▼       │
                    │  RAM  UART      │
                    │ TIMER GPIO      │
                    └─────────────────┘
```

## Ports

| Port | Direction | Width | Description |
|------|-----------|-------|-------------|
| `clk` | Input | 1 | Global clock |
| `rst_n` | Input | 1 | Active-low reset |
| `uart_tx` | Output | 1 | UART transmit line |
| `uart_rx` | Input | 1 | UART receive line |
| `timer_irq` | Output | 1 | Timer interrupt request |
| `gpio_pins` | Inout | 32 | Bidirectional GPIO pins |

## AXI4-Lite Master Interface

The subsystem exposes a single AXI4-Lite master interface (from the interconnect's perspective, this is the master port). All AXI4-Lite signals are exposed at the top level for connection to an external CPU or bus master.

## Peripheral Base Addresses

| Peripheral | Base Address | Size |
|------------|-------------|------|
| RAM | `0x0000_0000` | 4 KB |
| UART | `0x4000_0000` | 4 KB |
| Timer | `0x4001_0000` | 4 KB |
| GPIO | `0x4002_0000` | 4 KB |

See [Memory Map](../architecture/memory-map.md) for full details.

## Integration Example

```systemverilog
axi_subsystem u_subsystem (
    .clk       (sys_clk),
    .rst_n     (sys_rst_n),
    .uart_tx   (uart_tx),
    .uart_rx   (uart_rx),
    .timer_irq (timer_irq),
    .gpio_pins (gpio_pins),

    // AXI4-Lite master interface
    .awaddr    (cpu_awaddr),
    .awvalid   (cpu_awvalid),
    .awready   (cpu_awready),
    // ... (other AXI signals)
);
```

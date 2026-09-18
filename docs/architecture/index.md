# Architecture

The Open AXI Interconnect subsystem is built around an AXI4-Lite crossbar that routes transactions from one or more masters to a configurable set of slaves.

## Top-Level Block Diagram

```
                    +------------------+
    Master(s) ----->|  AXI Crossbar    |-----> Slave 0 (RAM)
                    |                  |-----> Slave 1 (UART)
                    |                  |-----> Slave 2 (Timer)
                    |                  |-----> Slave 3 (GPIO)
                    +------------------+
```

## Components

- **AXI Master/Slave Interfaces** – standard AXI4-Lite signal bundles
- **AXI Crossbar** – address decode, arbitration, and routing
- **Peripherals** – RAM, UART, Timer, GPIO

## Address Map

| Slave | Base Address | Size | Description |
|-------|-------------|------|-------------|
| RAM   | `0x0000_0000` | 4 KB | General purpose memory |
| UART  | `0x4000_0000` | 4 KB | UART controller |
| Timer | `0x4000_1000` | 4 KB | System timer |
| GPIO  | `0x4000_2000` | 4 KB | General purpose I/O |

> Verify exact base addresses against `rtl/top/open_axi_interconnect_top.sv`.

## Clocking and Reset

The design uses a single system clock and an active-low reset. All AXI channels and peripherals operate synchronously to this clock.

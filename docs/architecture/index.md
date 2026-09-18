# Architecture Overview

The **Open AXI Interconnect** is a lightweight, synthesizable AMBA AXI4-Lite based system-on-chip building block. It is intended for FPGA and ASIC designs that need a simple memory-mapped interconnect with a small set of peripherals.

## System Block Diagram

```
                    ┌──────────────────────┐
                    │    AXI4-Lite Master  │
                    └──────────┬───────────┘
                               │
                               ▼
                    ┌──────────────────────┐
                    │  AXI4-Lite           │
                    │  Interconnect        │
                    │  (Address Decoder)   │
                    └──────┬───┬───┬───┬───┘
                           │   │   │   │
              ┌────────────┘   │   │   └────────────┐
              │                │   │                │
              ▼                ▼   ▼                ▼
        ┌─────────┐      ┌─────────┐      ┌─────────┐      ┌─────────┐
        │   RAM   │      │  UART   │      │  Timer  │      │  GPIO   │
        │ (4 KB)  │      │         │      │         │      │(32 pins)│
        └─────────┘      └────┬────┘      └────┬────┘      └────┬────┘
                              │                │                │
                              ▼                ▼                ▼
                           uart_tx          timer_irq        gpio_pins
                           uart_rx
```

## Key Components

| Component | Description |
|-----------|-------------|
| **AXI4-Lite Interconnect** | Single-master, multi-slave address decoder and router |
| **RAM** | 4 KB memory array with control/status registers |
| **UART** | Minimal UART with TX/RX data registers |
| **Timer** | Free-running 32-bit counter with compare interrupt |
| **GPIO** | 32 bidirectional pins with direction control |

## Design Characteristics

- **Single master only** — one AXI4-Lite master interface
- **No pipelining** — no outstanding transactions
- **No burst support** — AXI4-Lite only (single-beat)
- **Fixed address map** — peripherals at hardcoded base addresses
- **Configurable parameters** — data width, address width

## Address Map Summary

| Peripheral | Base Address | End Address | Size |
|------------|--------------|-------------|------|
| RAM        | `0x0000_0000` | `0x0000_FFFF` | 64 KB |
| UART       | `0x4000_0000` | `0x4000_0FFF` | 4 KB |
| Timer      | `0x4001_0000` | `0x4001_0FFF` | 4 KB |
| GPIO       | `0x4002_0000` | `0x4002_0FFF` | 4 KB |

## Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `ADDR_WIDTH` | 32 | Address bus width in bits |
| `DATA_WIDTH` | 32 | Data bus width in bits |
| `NUM_SLAVES` | 4 | Number of slave peripherals |

## Navigation

- [Detailed Overview](overview.md) — Component descriptions and design decisions
- [Memory Map](memory-map.md) — Complete address space specification
- [Register Map](register-map.md) — Per-register field definitions
- [FSM Diagrams](fsm-diagrams.md) — Transaction state machines
- [AXI Protocol](axi-protocol.md) — AXI4-Lite protocol compliance
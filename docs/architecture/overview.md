# System Architecture Overview

## Introduction

The Open AXI Interconnect is designed as a lightweight, synthesizable System-on-Chip (SoC) building block that implements a subset of the AMBA AXI4-Lite protocol. This document provides a comprehensive overview of the system architecture, design principles, and implementation details.

## System Block Diagram

```
                 +------------------+
                 |  AXI4-Lite Master |
                 +------------------+
                          |
                          | AXI4-Lite Interface
                          |
                 +------------------+
                 |                  |
                 |  Interconnect    |
                 |                  |
                 +------------------+
                    |     |    |    |
            +-------+ +---+--+ +-+--+ +-------+
            |         |        |      |       |
     +-------------+-----+ +------+ +-----+ +-----+
     |   RAM       | UART  | Timer  | GPIO  | ... |
     | Controller  |       |        |       |     |
     +-------------+-------+--------+-------+-----+
```

## Core Components

### 1. AXI4-Lite Interconnect

The central component that routes transactions between the master and multiple slave peripherals. Key features include:

- Single master, multi-slave topology
- Fixed address decoding scheme
- No pipelining or outstanding transactions
- AXI4-Lite protocol compliance (no burst support)

### 2. RAM Controller

Implements a simple memory array with associated control registers:

- 4KB memory array (1024 × 32-bit words)
- Control register for enabling/disabling
- Status register indicating readiness
- Address register for memory access
- Data register for read/write operations

### 3. UART Controller

Minimal UART implementation providing basic serial communication:

- Control register for enabling transmitter/receiver
- Status register indicating transmission readiness
- TX data register for outgoing characters
- RX data register for incoming characters

### 4. Timer Module

Free-running counter with interrupt generation capability:

- 32-bit free-running counter
- Configurable compare value for interrupt generation
- Control register for enabling/resetting
- Status register indicating activity
- Interrupt output signal

### 5. GPIO Controller

32 bidirectional GPIO pins with flexible configuration:

- Direction register (input/output control)
- Output value register
- Input value register (read-only)

## Address Map

The system uses a 32-bit address space with the following memory map:

| Peripheral | Base Address | End Address | Size |
|------------|--------------|-------------|------|
| RAM        | 0x0000_0000  | 0x0000_FFFF | 64 KB |
| UART       | 0x4000_0000  | 0x4000_0FFF | 4 KB  |
| Timer      | 0x4001_0000  | 0x4001_0FFF | 4 KB  |
| GPIO       | 0x4002_0000  | 0x4002_0FFF | 4 KB  |

## Design Constraints

### Protocol Limitations

Version 1 of the system implements only AXI4-Lite features:

- Single beat reads/writes only (no bursts)
- No AXI IDs
- No cache/coherent attributes
- 32-bit data width

### Implementation Choices

The design makes several intentional trade-offs:

1. **Single Master**: Simplifies arbitration logic
2. **No Pipelining**: Reduces complexity and resource usage
3. **Fixed Address Map**: Eliminates runtime configuration overhead
4. **Minimal Peripherals**: Focuses on core functionality

## Future Enhancements

Planned improvements include:

- AXI4 full protocol support
- Multi-master capability
- Burst transaction support
- Additional peripheral controllers
- DMA controller
- Interrupt controller

## Conclusion

The Open AXI Interconnect provides a solid foundation for learning about AXI protocols and implementing simple embedded systems. Its modular design allows easy extension with additional peripherals while maintaining predictable behavior and resource usage.
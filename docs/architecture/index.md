# Architecture Overview

Welcome to the architecture documentation for the Open AXI Interconnect. This section provides detailed information about the system architecture, design decisions, and implementation details.

## Table of Contents

- [Overview](overview.md) - High-level system architecture
- [Memory Map](memory-map.md) - Detailed memory map specification
- [Register Map](register-map.md) - Complete register-level specification
- [FSM Diagrams](fsm-diagrams.md) - State machine diagrams
- [AXI Protocol](axi-protocol.md) - AXI protocol implementation details

## System Architecture

The Open AXI Interconnect implements a lightweight, synthesizable AMBA AXI4-Lite based system-on-chip building block. It is intended for FPGA and ASIC designs that need a simple memory-mapped interconnect with a small set of peripherals.

### Key Components

1. **AXI4-Lite Interconnect** - Single-master, multi-slave address decoder and router
2. **RAM Controller** - 4KB memory array with control registers
3. **UART Controller** - Minimal UART implementation
4. **Timer Module** - Free-running counter with interrupt capability
5. **GPIO Controller** - 32 bidirectional GPIO pins

### Design Philosophy

The design focuses on simplicity and synthesizability while maintaining compatibility with standard AXI4-Lite protocols. It's optimized for educational purposes and small-scale embedded systems where a full AXI4 implementation would be overkill.

## Next Steps

Explore the individual sections to understand the detailed architecture of each component and how they interact within the system.
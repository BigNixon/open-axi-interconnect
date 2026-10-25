# Memory Map Specification

## Overview

This document defines the complete memory map for the Open AXI Interconnect system. Understanding the memory map is crucial for software development and system integration.

## Address Space Layout

The system utilizes a 32-bit address space organized into distinct regions for each peripheral. The memory map is fixed at compile time to minimize hardware complexity.

```
Address Range           Size    Peripheral
─────────────────────── ─────── ──────────────
0x0000_0000-0x0000_FFFF 64 KB   RAM Controller
0x4000_0000-0x4000_0FFF 4 KB    UART Controller
0x4001_0000-0x4001_0FFF 4 KB    Timer Module
0x4002_0000-0x4002_0FFF 4 KB    GPIO Controller
...                     ...     (Reserved)
──────────────────────────────────────────────
Total Addressable Space: ~4 GB
```

## RAM Controller (0x0000_0000)

The RAM controller occupies the bottom 64KB of the address space.

### Address Range
- **Base**: 0x0000_0000
- **End**: 0x0000_FFFF
- **Size**: 64 KB (1024 × 32-bit words)

### Memory Organization
The RAM controller implements a dual-access mechanism:
1. **Control Registers** (0x0000_0000 - 0x0000_000F)
2. **Memory Array** (accessed via address/data registers)

### Implementation Details
Addresses within the RAM region that are not control registers are handled by the address/data register mechanism:
- Write to ADDRESS register (0x08) to set memory location
- Write to DATA register (0x0C) to store data at that location
- Read from DATA register (0x0C) to retrieve data from that location

## UART Controller (0x4000_0000)

The UART controller provides serial communication capabilities.

### Address Range
- **Base**: 0x4000_0000
- **End**: 0x4000_0FFF
- **Size**: 4 KB

### Address Decoding
All addresses within this range route to the UART peripheral. The specific register is determined by the lower 4 bits of the address:

| Address Offset | Register | Function |
|----------------|----------|----------|
| 0x0000_0000 | CTRL | Control register |
| 0x0000_0004 | STATUS | Status register |
| 0x0000_0008 | TX_DATA | Transmit data |
| 0x0000_000C | RX_DATA | Receive data |

## Timer Module (0x4001_0000)

The timer module provides timing and interrupt capabilities.

### Address Range
- **Base**: 0x4001_0000
- **End**: 0x4001_0FFF
- **Size**: 4 KB

### Address Decoding
Similar to UART, addresses within this range route to timer registers:

| Address Offset | Register | Function |
|----------------|----------|----------|
| 0x0000_0000 | CTRL | Control register |
| 0x0000_0004 | STATUS | Status register |
| 0x0000_0008 | COUNT | Current counter value |
| 0x0000_000C | COMPARE | Interrupt compare value |

## GPIO Controller (0x4002_0000)

The GPIO controller manages 32 bidirectional I/O pins.

### Address Range
- **Base**: 0x4002_0000
- **End**: 0x4002_0FFF
- **Size**: 4 KB

### Address Decoding
GPIO registers are accessed via the following offsets:

| Address Offset | Register | Function |
|----------------|----------|----------|
| 0x0000_0000 | DIR | Direction control |
| 0x0000_0004 | OUT | Output value |
| 0x0000_0008 | IN | Input value (read-only) |

## Address Decoding Logic

The interconnect uses a simple priority-based address decoder:

1. Addresses 0x0000_0000 to 0x0000_FFFF → RAM Controller
2. Addresses 0x4000_0000 to 0x4000_0FFF → UART Controller
3. Addresses 0x4001_0000 to 0x4001_0FFF → Timer Module
4. Addresses 0x4002_0000 to 0x4002_0FFF → GPIO Controller
5. All other addresses → Default to RAM (fallback)

## Transaction Examples

### Write to UART Control Register
```
Address: 0x4000_0000
Data:    0x0000_0007  // Enable UART, TX, RX
```

### Read Timer Counter Value
```
Address: 0x4001_0008
Response: Current 32-bit counter value
```

### Write GPIO Output Values
```
Address: 0x4002_0004
Data:    0xA5A5_A5A5  // Set GPIO output pins
```

## Memory Map Consistency

The memory map is consistent across all documentation sources:
- Matches the implementation in `axi_lite_interconnect.sv`
- Aligned with register specifications in `register_map.md`
- Corresponds to test cases in `test_axi_lite.py`

## Future Considerations

When extending the system with additional peripherals, consider:
1. Maintaining alignment to 4KB boundaries for consistency
2. Reserving sufficient address space for peripheral expansion
3. Documenting any changes to the address decoding logic
4. Ensuring backward compatibility with existing software
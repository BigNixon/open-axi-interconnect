# AXI Subsystem Memory Map Specification

## 1. Overview

This document defines the memory map of the AXI4-Lite subsystem.

The subsystem implements a memory-mapped architecture where each peripheral
is assigned a unique address range.

The AXI master accesses peripherals using read and write transactions.

Architecture:
             AXI Master
                 |
                 |
          AXI4-Lite Interconnect
                 |
   +-------------+-------------+
   |             |             |
  RAM           UART          Timer


---

# 2. Address Space

The AXI subsystem uses a 32-bit address space.

Address allocation:

| Peripheral | Base Address | End Address | Size |
|------------|-------------|-------------|------|
| RAM        | 0x0000_0000 | 0x0000_FFFF | 64 KB |
| UART       | 0x4000_0000 | 0x4000_0FFF | 4 KB |
| TIMER      | 0x4001_0000 | 0x4001_0FFF | 4 KB |
| GPIO       | 0x4002_0000 | 0x4002_0FFF | 4 KB |

---

# 3. AXI Address Decoding

The interconnect is responsible for:

1. Receiving AXI requests from the master.
2. Comparing the address against peripheral ranges.
3. Routing the transaction to the correct slave.
4. Returning the response to the master.

Example:
```
Address = 0x40000010
0x40000000 - 0x40000FFF
    |
    v
   UART
```

---

# 4. Supported Transactions

Version 1:

Supported:

- Single beat reads
- Single beat writes
- 32-bit data width

Not supported:

- Bursts
- Multiple outstanding transactions
- AXI IDs
- Cache attributes


---

# 5. Transaction Examples

## Write UART Data
Master writes:
```
Address:
0x40000000

Data:
0x00000041

Operation:
Transmit character 'A'
```
---
## Read Timer Counter
```
Master reads:
Address:
0x40010008

Response:
Current timer value
```

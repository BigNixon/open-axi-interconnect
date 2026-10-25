# Register Map Specification

## Overview

This document provides a complete specification of all registers in the Open AXI Interconnect system. Each register is described with its address offset, access type, reset value, and bit field definitions.

## Register Conventions

All registers follow these conventions:

- **Width**: 32 bits
- **Access Size**: 32-bit aligned access only
- **Address Alignment**: 4-byte boundaries
- **Access Types**:
  - `RW`: Readable and writable
  - `RO`: Read-only
  - `WO`: Write-only (write value ignored for reads)

## RAM Controller Registers

**Base Address**: 0x0000_0000

### Control Register (Offset: 0x00)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:1 | - | - | 0x0000_0000 | Reserved |
| 0 | ENABLE | RW | 0 | RAM enable bit |

### Status Register (Offset: 0x04)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:1 | - | - | 0x0000_0000 | Reserved |
| 0 | READY | RO | 1 | RAM ready indicator |

### Address Register (Offset: 0x08)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | ADDR | RW | 0x0000_0000 | Memory address pointer |

### Data Register (Offset: 0x0C)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | DATA | RW | 0x0000_0000 | Read/write data at address |

## UART Controller Registers

**Base Address**: 0x4000_0000

### Control Register (Offset: 0x00)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:3 | - | - | 0x0000_0000 | Reserved |
| 2 | RX_ENABLE | RW | 0 | Enable receiver |
| 1 | TX_ENABLE | RW | 0 | Enable transmitter |
| 0 | ENABLE | RW | 0 | Enable UART |

### Status Register (Offset: 0x04)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:2 | - | - | 0x0000_0000 | Reserved |
| 1 | RX_VALID | RO | 0 | Received data available |
| 0 | TX_READY | RO | 1 | Transmit available |

### TX Data Register (Offset: 0x08)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:8 | - | - | 0x0000_0000 | Reserved |
| 7:0 | TX_BYTE | WO | 0x00 | Transmit data byte |

### RX Data Register (Offset: 0x0C)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:8 | - | - | 0x0000_0000 | Reserved |
| 7:0 | RX_BYTE | RO | 0x00 | Received data byte |

## Timer Module Registers

**Base Address**: 0x4001_0000

### Control Register (Offset: 0x00)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:2 | - | - | 0x0000_0000 | Reserved |
| 1 | RESET | RW | 0 | Reset counter to zero |
| 0 | ENABLE | RW | 0 | Enable counting |

### Status Register (Offset: 0x04)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:1 | - | - | 0x0000_0000 | Reserved |
| 0 | ACTIVE | RO | 0 | Timer is enabled |

### Count Register (Offset: 0x08)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | COUNT | RO | 0x0000_0000 | Current counter value |

### Compare Register (Offset: 0x0C)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | COMPARE | RW | 0x0000_0000 | Interrupt compare value |

## GPIO Controller Registers

**Base Address**: 0x4002_0000

### Direction Register (Offset: 0x00)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | DIR | RW | 0x0000_0000 | Pin direction (1=output, 0=input) |

Bit mapping:
- Bit 0: GPIO[0] direction
- Bit 1: GPIO[1] direction
- ...
- Bit 31: GPIO[31] direction

### Output Register (Offset: 0x04)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | OUT | RW | 0x0000_0000 | Output pin values |

Bit mapping:
- Bit 0: GPIO[0] output value
- Bit 1: GPIO[1] output value
- ...
- Bit 31: GPIO[31] output value

### Input Register (Offset: 0x08)

| Bits | Name | Access | Reset | Description |
|------|------|--------|-------|-------------|
| 31:0 | IN | RO | 0x0000_0000 | Input pin values |

Bit mapping:
- Bit 0: GPIO[0] input value
- Bit 1: GPIO[1] input value
- ...
- Bit 31: GPIO[31] input value

## Access Timing

All register accesses follow the AXI4-Lite protocol timing:

### Write Transaction
1. Master asserts `AWVALID` with address
2. Master asserts `WVALID` with data and write strobe
3. Slave asserts `AWREADY` and `WREADY`
4. Slave asserts `BVALID` with response
5. Master asserts `BREADY`

### Read Transaction
1. Master asserts `ARVALID` with address
2. Slave asserts `ARREADY`
3. Slave asserts `RVALID` with data and response
4. Master asserts `RREADY`

## Reset Behavior

Upon reset deassertion:
1. All registers initialize to their specified reset values
2. Timers start counting if enabled
3. UART transmitter becomes ready
4. GPIO pins assume default states based on direction settings

## Error Handling

The system handles invalid accesses as follows:
- Out-of-range addresses: Default to RAM controller
- Unaligned accesses: Not supported (32-bit aligned only)
- Invalid register accesses: Return zero for reads, ignore writes

## Software Usage Examples

### Initialize UART
```c
// Enable UART with TX/RX
*((volatile uint32_t*)0x40000000) = 0x7;

// Check if transmitter ready
while(!(*((volatile uint32_t*)0x40000004) & 0x1));

// Transmit character 'A'
*((volatile uint32_t*)0x40000008) = 0x41;
```

### Configure Timer
```c
// Set compare value for 1ms interrupt
*((volatile uint32_t*)0x4001000C) = 0x2710; // 10000 cycles

// Enable timer
*((volatile uint32_t*)0x40010000) = 0x1;

// Poll for interrupt or use timer_irq signal
```

### Configure GPIO
```c
// Set GPIO 0-15 as output, 16-31 as input
*((volatile uint32_t*)0x40020000) = 0x0000FFFF;

// Set output values for GPIO 0-15
*((volatile uint32_t*)0x40020004) = 0x00005555;

// Read input values from GPIO 16-31
uint32_t inputs = *((volatile uint32_t*)0x40020008);
```

## Verification

Each register has been verified through cocotb test cases:
- `test_axi_lite_basic` validates RAM controller registers
- `test_uart` validates UART controller registers
- `test_timer` validates Timer module registers
- `test_gpio` validates GPIO controller registers

All tests pass, confirming correct register behavior and address decoding.
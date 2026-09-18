# AXI Subsystem Register Map Specification

## 1. Register Conventions

All registers:

- Width: 32 bits
- Access size: 32 bits
- Reset value: defined per register
- Address offset relative to peripheral base address

Access types:

| Type | Meaning |
|------|---------|
| RW   | Read and Write |
| RO   | Read Only |
| WO   | Write Only |

---

# 2. RAM Controller

Base Address: `0x0000_0000`

The RAM peripheral provides simple memory storage.

## Register Map

| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| `0x00` | CONTROL  | RW     | Enable RAM |
| `0x04` | STATUS   | RO     | RAM status (READY=1) |
| `0x08` | ADDRESS  | RW     | Memory address pointer |
| `0x0C` | DATA     | RW     | Read/write data at ADDRESS |

### CONTROL Register

| Bit | Name   | Access | Description |
|-----|--------|--------|-------------|
| 0   | ENABLE | RW     | Enable RAM |

Reset: `0x0000_0000`

### STATUS Register

| Bit | Name  | Access | Description |
|-----|-------|--------|-------------|
| 0   | READY | RO     | RAM ready |

Reset: `0x0000_0001`

---

# 3. UART Peripheral

Base Address: `0x4000_0000`

Provides serial communication through AXI transactions.

## Register Map

| Offset | Register  | Access | Description |
|--------|-----------|--------|-------------|
| `0x00` | CTRL      | RW     | UART configuration |
| `0x04` | STATUS    | RO     | UART state |
| `0x08` | TX_DATA   | WO     | Transmit byte |
| `0x0C` | RX_DATA   | RO     | Received byte |

### CTRL Register

| Bit | Name      | Description |
|-----|-----------|-------------|
| 0   | ENABLE    | Enable UART |
| 1   | TX_ENABLE | Enable transmitter |
| 2   | RX_ENABLE | Enable receiver |

Reset: `0x0000_0000`

### STATUS Register

| Bit | Name     | Description |
|-----|----------|-------------|
| 0   | TX_READY | Transmit available |
| 1   | RX_VALID | Received data available |

Reset: `0x0000_0001` (TX_READY set)

---

# 4. Timer Peripheral

Base Address: `0x4001_0000`

Generates timing information and interrupts.

## Register Map

| Offset | Register  | Access | Description |
|--------|-----------|--------|-------------|
| `0x00` | CTRL      | RW     | Timer control |
| `0x04` | STATUS    | RO     | Timer state |
| `0x08` | COUNT     | RO     | Current counter |
| `0x0C` | COMPARE   | RW     | Interrupt compare value |

### CTRL Register

| Bit | Name   | Description |
|-----|--------|-------------|
| 0   | ENABLE | Enable counting |
| 1   | RESET  | Reset counter to zero |

### STATUS Register

| Bit | Name   | Description |
|-----|--------|-------------|
| 0   | ACTIVE | Timer is enabled |

---

# 5. GPIO Peripheral

Base Address: `0x4002_0000`

General purpose input/output.

## Register Map

| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| `0x00` | DIR      | RW     | Pin direction (1=output, 0=input) |
| `0x04` | OUT      | RW     | Output value |
| `0x08` | IN       | RO     | Input value |

---

# 6. Software Usage Examples

## UART transmit

1. Enable UART: `WRITE UART_CTRL, ENABLE=1`
2. Check status: `READ UART_STATUS` until `TX_READY==1`
3. Send byte: `WRITE UART_TX_DATA`

## Timer usage

1. Configure compare value: `WRITE TIMER_COMPARE`
2. Enable timer: `WRITE TIMER_CTRL, ENABLE=1`
3. Poll status or connect `irq` to interrupt controller.

## GPIO usage

1. Configure direction: `WRITE GPIO_DIR`
2. Set output: `WRITE GPIO_OUT`
3. Read input: `READ GPIO_IN`

---

# 7. Future Extensions

- DMA controller
- SPI controller
- I2C controller
- Interrupt controller
- AXI4 full support
- AXI burst transactions

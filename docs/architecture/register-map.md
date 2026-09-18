# Register Map

This page documents every register in each peripheral, including field-level bit definitions.

## RAM Registers

Base: `0x0000_0000`

| Offset | Name | Access | Reset | Description |
|--------|------|--------|-------|-------------|
| `0x00` | CONTROL | R/W | `0x0000_0000` | Memory enable |
| `0x04` | STATUS  | R   | `0x0000_0001` | Ready flag |
| `0x08` | ADDR    | R/W | `0x0000_0000` | Memory address pointer |
| `0x0C` | DATA    | R/W | `0x0000_0000` | Data at `ADDR` |

### RAM CONTROL (`0x00`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[0]` | ENABLE | `1` = memory array active |
| `[31:1]` | — | Reserved (read as 0) |

### RAM STATUS (`0x04`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[0]` | READY | Always `1` — memory is always ready |
| `[31:1]` | — | Reserved |

### RAM ADDR (`0x08`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[9:0]` | ADDR | Word address into 1024-entry array |
| `[31:10]` | — | Reserved |

### RAM DATA (`0x0C`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | DATA | Read/write data at `ADDR` |

---

## UART Registers

Base: `0x4000_0000`

| Offset | Name | Access | Reset | Description |
|--------|------|--------|-------|-------------|
| `0x00` | CTRL    | R/W | `0x0000_0000` | UART control |
| `0x04` | STATUS  | R   | `0x0000_0001` | UART status |
| `0x08` | TX_DATA | W   | `0x0000_0000` | Transmit data |
| `0x0C` | RX_DATA | R   | `0x0000_0000` | Receive data |

### UART CTRL (`0x00`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[0]` | ENABLE | `1` = UART active |
| `[1]` | TX_ENABLE | `1` = TX path enabled |
| `[2]` | RX_ENABLE | `1` = RX path enabled |
| `[31:3]` | — | Reserved |

### UART STATUS (`0x04`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[0]` | TX_READY | `1` = TX buffer empty, ready for next byte |
| `[1]` | RX_VALID | `1` = RX data valid |
| `[31:2]` | — | Reserved |

### UART TX_DATA (`0x08`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[7:0]` | DATA | Byte to transmit |
| `[31:8]` | — | Reserved |

### UART RX_DATA (`0x0C`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[7:0]` | DATA | Last received byte |
| `[31:8]` | — | Reserved |

---

## Timer Registers

Base: `0x4001_0000`

| Offset | Name | Access | Reset | Description |
|--------|------|--------|-------|-------------|
| `0x00` | CTRL     | R/W | `0x0000_0000` | Timer control |
| `0x04` | —        | —   | — | Reserved |
| `0x08` | COUNT    | R   | `0x0000_0000` | Current counter value |
| `0x0C` | COMPARE  | R/W | `0xFFFF_FFFF` | Compare threshold |

### Timer CTRL (`0x00`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[0]` | ENABLE | `1` = counter increments every clock |
| `[1]` | RESET  | `1` = clear counter to zero on next clock |
| `[31:2]` | — | Reserved |

### Timer COUNT (`0x08`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | COUNT | Current 32-bit counter value |

### Timer COMPARE (`0x0C`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | COMPARE | Threshold for `timer_irq` assertion |

---

## GPIO Registers

Base: `0x4002_0000`

| Offset | Name | Access | Reset | Description |
|--------|------|--------|-------|-------------|
| `0x00` | DIR | R/W | `0x0000_0000` | Pin direction |
| `0x04` | OUT | R/W | `0x0000_0000` | Output drive value |
| `0x08` | IN  | R   | `0x0000_0000` | Sampled pin value |

### GPIO DIR (`0x00`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | DIR | `1` = output, `0` = input (high-Z) |

### GPIO OUT (`0x04`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | OUT | Value driven when pin is output |

### GPIO IN (`0x08`)

| Bit | Field | Description |
|-----|-------|-------------|
| `[31:0]` | IN | Current sampled pin value |

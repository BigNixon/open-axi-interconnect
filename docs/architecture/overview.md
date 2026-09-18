# Detailed Architecture Overview

This page provides an in-depth look at each component in the Open AXI Interconnect subsystem.

## 1. AXI4-Lite Interconnect (`axi_lite_interconnect`)

The interconnect is the central routing fabric. It receives AXI4-Lite transactions from a single master and routes them to the appropriate slave based on the transaction address.

### Responsibilities

- **Address decode**: Compare the 32-bit address against fixed peripheral ranges
- **Write routing**: Drive `AW*`, `W*`, and `BREADY` to the selected slave
- **Read routing**: Drive `AR*` and `RREADY` to the selected slave
- **Response muxing**: Return the selected slave's response to the master

### Address Decode Function

```systemverilog
function automatic slave_sel_t decode(input [ADDR_WIDTH-1:0] addr);
    if      ((addr >= UART_BASE)  && (addr <= UART_END))  decode = SLAVE_UART;
    else if ((addr >= TIMER_BASE) && (addr <= TIMER_END)) decode = SLAVE_TIMER;
    else if ((addr >= GPIO_BASE)  && (addr <= GPIO_END))  decode = SLAVE_GPIO;
    else                                                   decode = SLAVE_RAM;
endfunction
```

!!! note "RAM as default"
    Any address not matching UART, Timer, or GPIO ranges falls through to RAM. This means RAM effectively occupies the entire lower 64 KB and all unmapped upper addresses.

### Current Limitations

| Limitation | Reason |
|------------|--------|
| Single master only | Simplifies arbitration — none needed |
| No outstanding transactions | Simplifies response tracking |
| No burst support | AXI4-Lite protocol restriction |
| Fixed memory map | Hardcoded for this subsystem version |

---

## 2. AXI4-Lite Slave Template (`axi_lite_slave`)

A generic 4-register AXI4-Lite slave used as a reference implementation. It demonstrates:

- Byte-wise writes via `WSTRB`
- Separate read/write state machines
- Register banking with reset values

### Register Layout

| Offset | Register | Reset Value | Description |
|--------|----------|-------------|-------------|
| `0x00` | CONTROL  | `0x0000_0000` | User control bits |
| `0x04` | STATUS   | `0xDEAD_BEEF` | User status bits |
| `0x08` | DATA     | `0x0000_0000` | General-purpose data |
| `0x0C` | VERSION  | `0x0000_0001` | IP version register |

---

## 3. Peripherals

### RAM (`ram`)

- **4 KB memory array** (1024 × 32-bit words)
- **Control register** (`0x00`): ENABLE bit
- **Status register** (`0x04`): READY flag
- **Address register** (`0x08`): Memory address pointer
- **Data register** (`0x0C`): Read/write data at the address pointer

Writes to the data register store into `mem[address]`. Reads from the data register return `mem[address]`.

### UART (`uart`)

- **Minimal UART model** with no actual serialization
- **CTRL register** (`0x00`): ENABLE, TX_ENABLE, RX_ENABLE
- **STATUS register** (`0x04`): TX_READY, RX_VALID
- **TX_DATA** (`0x08`): Write-only transmit byte
- **RX_DATA** (`0x0C`): Read-only received byte

In this version, `tx` is a placeholder line driven from `CTRL[0] ? tx_data[0] : 1'b1`.

### Timer (`timer`)

- **Free-running 32-bit counter**
- **CTRL register** (`0x00`): ENABLE (bit 0), RESET (bit 1)
- **COUNT register** (`0x08`): Current counter value (read-only)
- **COMPARE register** (`0x0C`): Interrupt threshold
- **`irq` output**: Asserted when `ENABLE==1` and `COUNT >= COMPARE`

When RESET is set, the counter clears to zero on the next clock edge.

### GPIO (`gpio`)

- **32 bidirectional pins**
- **DIR register** (`0x00`): `1` = output, `0` = input (high-Z)
- **OUT register** (`0x04`): Output drive value
- **IN register** (`0x08`): Sampled pin value (read-only)

Tristate implementation:
```systemverilog
assign gpio_pins[i] = reg_dir[i] ? reg_out[i] : 1'bz;
assign reg_in[i]    = gpio_pins[i];
```

---

## 4. Top-Level (`axi_subsystem`)

The top-level module instantiates:

1. `axi_lite_interconnect` — the routing fabric
2. `ram` — slave index 0
3. `uart` — slave index 1
4. `timer` — slave index 2
5. `gpio` — slave index 3

It exposes a single AXI4-Lite master interface plus external peripheral pins (`uart_tx`, `uart_rx`, `timer_irq`, `gpio_pins`).

### Parameterization

```systemverilog
module axi_subsystem #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    // ... ports ...
);
```

All sub-modules inherit these parameters, ensuring consistent bus widths throughout the hierarchy.

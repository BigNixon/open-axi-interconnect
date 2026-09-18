# AXI4-Lite Protocol Compliance

This page documents how the Open AXI Interconnect implements the AMBA AXI4-Lite protocol.

## Protocol Overview

AXI4-Lite is a lightweight subset of the full AXI4 protocol designed for simple control register access. It supports:

- Single-beat transactions only (no bursts)
- Fixed data width (32-bit in this design)
- No cache, protection, or QoS signals
- No exclusive access or locked transactions

## Signal Groups

### Write Address Channel (AW)

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| `AWVALID` | 1 | Master → Slave | Address/control valid |
| `AWREADY` | 1 | Slave → Master | Slave ready to accept address |
| `AWADDR`  | 32 | Master → Slave | Write address |
| `AWPROT`  | 3 | Master → Slave | Protection type (unused) |

### Write Data Channel (W)

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| `WVALID` | 1 | Master → Slave | Write data valid |
| `WREADY` | 1 | Slave → Master | Slave ready to accept data |
| `WDATA`  | 32 | Master → Slave | Write data |
| `WSTRB`  | 4 | Master → Slave | Write strobe (byte-wise enable) |

### Write Response Channel (B)

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| `BVALID` | 1 | Slave → Master | Response valid |
| `BREADY` | 1 | Master → Slave | Master ready to accept response |
| `BRESP`  | 2 | Slave → Master | Response status (`00` = OKAY) |

### Read Address Channel (AR)

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| `ARVALID` | 1 | Master → Slave | Address/control valid |
| `ARREADY` | 1 | Slave → Master | Slave ready to accept address |
| `ARADDR`  | 32 | Master → Slave | Read address |
| `ARPROT`  | 3 | Master → Slave | Protection type (unused) |

### Read Data Channel (R)

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| `RVALID` | 1 | Slave → Master | Read data valid |
| `RREADY` | 1 | Master → Slave | Master ready to accept data |
| `RDATA`  | 32 | Slave → Master | Read data |
| `RRESP`  | 2 | Slave → Master | Response status (`00` = OKAY) |

## Handshake Rules

1. **Source must not wait for READY before asserting VALID**
2. **Destination can wait for VALID before asserting READY**
3. **Once VALID is asserted, it must remain asserted until the handshake occurs**
4. **READY can be asserted before or after VALID**

## Response Codes

| Code | Name | Description |
|------|------|-------------|
| `00` | OKAY | Normal access success |
| `01` | EXOKAY | Exclusive access okay (not used in AXI4-Lite) |
| `10` | SLVERR | Slave error — access reached slave but slave returned error |
| `11` | DECERR | Decode error — no slave at the requested address |

!!! note "Current Implementation"
    All responses in this design return `OKAY` (`00`). SLVERR and DECERR are not yet implemented.

## Write Strobe (`WSTRB`)

`WSTRB` controls which bytes of `WDATA` are written:

| WSTRB | Bytes Written |
|-------|---------------|
| `0001` | Byte 0 only |
| `0010` | Byte 1 only |
| `0100` | Byte 2 only |
| `1000` | Byte 3 only |
| `0011` | Bytes 0-1 |
| `1100` | Bytes 2-3 |
| `1111` | All bytes |

The slave template (`axi_lite_slave`) implements byte-wise writes using:

```systemverilog
if (WSTRB[0]) reg_data[7:0]   <= WDATA[7:0];
if (WSTRB[1]) reg_data[15:8]  <= WDATA[15:8];
if (WSTRB[2]) reg_data[23:16] <= WDATA[23:16];
if (WSTRB[3]) reg_data[31:24] <= WDATA[31:24];
```

## Timing Diagram

### Write Transaction

```
CLK    ____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____
AWVALID    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
AWREADY    __________________________/‾‾‾‾\__________________
AWADDR     ═════[ADDR]═══════════════════════════════════════
WVALID     __________________________/‾‾‾‾\__________________
WREADY     __________________________________/‾‾‾‾\__________
WDATA      ════════════════════════[DATA]══════════════════════
WSTRB      ════════════════════════[1111]═════════════════════
BVALID     ______________________________________/‾‾‾‾\______
BREADY     __________________________________________/‾‾‾‾\__
BRESP      ════════════════════════════════════════[00]═══════
```

### Read Transaction

```
CLK    ____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____/‾‾‾‾\____
ARVALID    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
ARREADY    __________________________/‾‾‾‾\__________________
ARADDR     ═════[ADDR]═══════════════════════════════════════
RVALID     __________________________________/‾‾‾‾\__________
RREADY     ______________________________________/‾‾‾‾\______
RDATA      ════════════════════════════════════[DATA]════════
RRESP      ════════════════════════════════════[00]═══════════
```

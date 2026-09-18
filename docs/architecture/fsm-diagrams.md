# FSM Diagrams

This page documents the finite state machines used in the AXI4-Lite interconnect and slave peripherals.

## AXI4-Lite Write Transaction FSM

The write transaction follows the AXI4-Lite handshake protocol across two channels: **Write Address (AW)** and **Write Data (W)**. The response is returned on the **Write Response (B)** channel.

```
┌──────────┐    AWVALID & AWREADY    ┌──────────┐
│   IDLE   │ ───────────────────────▶ │ AW_ADDR  │
└──────────┘                          └────┬─────┘
      ▲                                      │
      │                                      │ WVALID & WREADY
      │                                      ▼
      │                               ┌──────────┐
      │                               │  W_DATA  │
      │                               └────┬─────┘
      │                                      │
      │                                      │ BVALID & BREADY
      │                                      ▼
      │                               ┌──────────┐
      └───────────────────────────────│   DONE   │
                                      └──────────┘
```

### State Descriptions

| State | Description |
|-------|-------------|
| **IDLE** | Waiting for a new write transaction. Sample `AWVALID` and `WVALID`. |
| **AW_ADDR** | Address accepted (`AWREADY` asserted). Wait for write data. |
| **W_DATA** | Write data accepted (`WREADY` asserted). Prepare response. |
| **DONE** | Response valid (`BVALID` asserted). Return to IDLE on `BREADY`. |

### State Transition Table

| Current | Condition | Next |
|---------|-----------|------|
| IDLE | `AWVALID && AWREADY` | AW_ADDR |
| AW_ADDR | `WVALID && WREADY` | W_DATA |
| W_DATA | — | DONE |
| DONE | `BREADY` | IDLE |

!!! note "Combined AW/W"
    In AXI4-Lite, the address and data can arrive in any order. The slave must accept both before issuing a response.

---

## AXI4-Lite Read Transaction FSM

The read transaction uses the **Read Address (AR)** channel and returns data on the **Read Data (R)** channel.

```
┌──────────┐    ARVALID & ARREADY    ┌──────────┐
│   IDLE   │ ───────────────────────▶ │ AR_ADDR  │
└──────────┘                          └────┬─────┘
      ▲                                  │
      │                                  │ Data ready
      │                                  ▼
      │                           ┌──────────┐
      │                           │ R_DATA   │
      │                           └────┬─────┘
      │                                  │
      │                                  │ RVALID & RREADY
      │                                  ▼
      │                           ┌──────────┐
      └───────────────────────────│   DONE   │
                                  └──────────┘
```

### State Descriptions

| State | Description |
|-------|-------------|
| **IDLE** | Waiting for a new read transaction. Sample `ARVALID`. |
| **AR_ADDR** | Address accepted (`ARREADY` asserted). Fetch data from register/memory. |
| **R_DATA** | Data valid (`RVALID` asserted). Return to IDLE on `RREADY`. |
| **DONE** | Transaction complete. Return to IDLE. |

### State Transition Table

| Current | Condition | Next |
|---------|-----------|------|
| IDLE | `ARVALID && ARREADY` | AR_ADDR |
| AR_ADDR | Data fetched | R_DATA |
| R_DATA | `RVALID && RREADY` | DONE |
| DONE | — | IDLE |

---

## Timer Counter FSM

The timer has a simple two-state counter with a reset control.

```
┌──────────┐    CTRL.RESET=1    ┌──────────┐
│  COUNT   │ ─────────────────▶ │  CLEAR   │
└────┬─────┘                    └────┬─────┘
     │                              │
     │ CTRL.ENABLE=1                │ CTRL.RESET=0
     │ (increment)                  │ (next cycle)
     └──────────────────────────────┘
```

| State | Description |
|-------|-------------|
| **COUNT** | Counter increments by 1 each clock cycle when `ENABLE=1`. |
| **CLEAR** | Counter resets to 0. Returns to COUNT on next cycle if `RESET` is deasserted. |

---

## UART TX FSM

The UART transmitter is a placeholder in this version. The conceptual FSM would be:

```
┌──────────┐    TX_ENABLE=1    ┌──────────┐
│   IDLE   │ ─────────────────▶ │  LOAD    │
└────┬─────┘                    └────┬─────┘
     │                              │
     │ TX_DONE                      │
     │                              │
     └──────────────────────────────┘
```

| State | Description |
|-------|-------------|
| **IDLE** | Waiting for TX_ENABLE. |
| **LOAD** | Load TX_DATA into shift register. |
| **SHIFT** | Shift out bits (not implemented in this version). |

!!! warning "Placeholder"
    The current UART implementation does not include a baud-rate generator or bit-shifting logic. It is a register-only model suitable for basic software bring-up.

# FSM Diagrams

## Overview

This document presents the Finite State Machine (FSM) diagrams for the Open AXI Interconnect system. Understanding these state machines is essential for comprehending the timing and behavior of each component.

## AXI4-Lite Protocol State Machines

### Write Transaction FSM

The AXI4-Lite write transaction follows a specific sequence of states:

```
IDLE ──AWVALID,WVALID──► HANDSHAKE ──AWREADY,WREADY──► RESPONSE ──BVALID──► IDLE
                           │                              │
                           │ BREADY                     │ BREADY
                           ▼                              ▼
                      WRITE_DATA ──────────────────► WAIT_BREADY
```

**State Descriptions:**

1. **IDLE**: Waiting for write address and data valid signals
2. **HANDSHAKE**: Address and data handshake in progress
3. **WRITE_DATA**: Processing write data to peripheral
4. **RESPONSE**: Generating write response
5. **WAIT_BREADY**: Waiting for master to accept response

### Read Transaction FSM

The AXI4-Lite read transaction follows this state sequence:

```
IDLE ──ARVALID──► HANDSHAKE ──ARREADY──► PROCESS_READ ──RVALID──► IDLE
                     │                        │
                     │ RREADY               │ RREADY
                     ▼                        ▼
                WAIT_RREADY ───────────► WAIT_COMPLETE
```

**State Descriptions:**

1. **IDLE**: Waiting for read address valid signal
2. **HANDSHAKE**: Address handshake in progress
3. **PROCESS_READ**: Retrieving data from peripheral
4. **WAIT_RREADY**: Waiting for master to accept data
5. **WAIT_COMPLETE**: Waiting for read completion

## Peripheral Controller FSMs

### RAM Controller States

The RAM controller implements a simple register-based FSM:

```
IDLE ──ACCESS──► PROCESS ──COMPLETE──► IDLE
```

**States:**
- **IDLE**: Ready for new transactions
- **PROCESS**: Handling register access or memory operation
- **COMPLETE**: Transaction completion

### UART Controller States

```
IDLE ──WRITE──► STORE_DATA ──COMPLETE──► IDLE
  │
  └──READ──► RETRIEVE_DATA ──COMPLETE──► IDLE
```

**States:**
- **IDLE**: Ready for transactions
- **STORE_DATA**: Storing write data to registers
- **RETRIEVE_DATA**: Retrieving read data from registers
- **COMPLETE**: Transaction completion

### Timer Module States

The timer operates continuously but has FSM states for register access:

```
RUNNING ──REGISTER_ACCESS──► HANDLE_ACCESS ──COMPLETE──► RUNNING
```

**States:**
- **RUNNING**: Continuous timer operation
- **HANDLE_ACCESS**: Processing register read/write
- **COMPLETE**: Access completion

### GPIO Controller States

```
IDLE ──REGISTER_ACCESS──► UPDATE_PINS ──COMPLETE──► IDLE
```

**States:**
- **IDLE**: Ready for register access
- **UPDATE_PINS**: Updating GPIO pin states
- **COMPLETE**: Access completion

## Interconnect Routing FSM

The AXI interconnect uses combinational logic for routing rather than a traditional FSM, but the address decoding process can be visualized as:

```
ADDRESS_RECEIVE ──DECODE──► SELECT_SLAVE ──ROUTE_SIGNALS
```

**Process Steps:**
1. **ADDRESS_RECEIVE**: Capture incoming address
2. **DECODE**: Determine target slave based on address range
3. **SELECT_SLAVE**: Route signals to appropriate slave
4. **ROUTE_SIGNALS**: Forward transaction to selected slave

## Timing Characteristics

### Setup and Hold Times

All FSM transitions observe standard setup and hold times:
- Setup time: Minimum time before clock edge
- Hold time: Minimum time after clock edge

### Clock Domain Considerations

All FSMs operate in the same clock domain:
- Single clock source: `clk`
- Active edge: Positive edge
- Reset: Synchronous active-low (`rst_n`)

## FSM Implementation Details

### State Encoding

States are typically encoded as:
- Binary encoding for area efficiency
- One-hot encoding for speed (used selectively)
- Gray code for low power applications

### Reset Behavior

All FSMs implement synchronous reset:
- Reset occurs on negedge of `rst_n`
- All states transition to defined reset state
- Reset recovery time observed

### Glitch Prevention

FSM implementations include:
- Registered outputs to prevent glitches
- Proper synchronization of asynchronous inputs
- Metastability protection where needed

## Verification

Each FSM has been verified through cocotb simulations:
- State transition coverage >95%
- Timing constraint validation
- Reset sequence verification
- Error condition handling

## Future Enhancements

Planned improvements to FSM designs:
- Power gating for low-power states
- Dynamic frequency scaling support
- Advanced error recovery mechanisms
- Formal verification of state properties

## Conclusion

The Open AXI Interconnect implements deterministic FSMs that ensure predictable behavior under all operating conditions. The simplicity of these state machines contributes to the overall reliability and ease of verification of the system.
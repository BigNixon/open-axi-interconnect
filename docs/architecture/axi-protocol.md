# AXI Protocol Implementation

## Overview

This document details the implementation of the AXI4-Lite protocol in the Open AXI Interconnect system. Understanding the protocol implementation is essential for system integration and software development.

## AXI4-Lite Protocol Basics

The ARM Advanced eXtensible Interface (AXI) protocol defines a high-performance, scalable interface for connecting IP blocks in System-on-Chip (SoC) designs. This implementation focuses on AXI4-Lite, a simplified subset optimized for memory-mapped I/O.

### Key Characteristics

- **Separate Read and Write Channels**: Independent address/data flows
- **No Burst Support**: Single-beat transactions only
- **Fixed Response Types**: OKAY and EXOKAY responses
- **No ID Signals**: No transaction identification
- **No User Signals**: No user-defined sideband signals

## Signal Definitions

### Write Address Channel (AW)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `awaddr` | Input | Write address |
| `awvalid` | Input | Write address valid |
| `awready` | Output | Write address ready |

### Write Data Channel (W)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `wdata` | Input | Write data |
| `wstrb` | Input | Write strobe (byte enables) |
| `wvalid` | Input | Write data valid |
| `wready` | Output | Write data ready |

### Write Response Channel (B)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `bresp` | Output | Write response |
| `bvalid` | Output | Write response valid |
| `bready` | Input | Write response ready |

### Read Address Channel (AR)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `araddr` | Input | Read address |
| `arvalid` | Input | Read address valid |
| `arready` | Output | Read address ready |

### Read Data Channel (R)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `rdata` | Output | Read data |
| `rresp` | Output | Read response |
| `rvalid` | Output | Read data valid |
| `rready` | Input | Read data ready |

## Transaction Flow

### Write Transaction

1. **Address Phase**:
   - Master drives `awaddr` and asserts `awvalid`
   - Slave asserts `awready` when ready to accept address
   - Handshake completes when both `awvalid` and `awready` are asserted

2. **Data Phase**:
   - Master drives `wdata`, `wstrb` and asserts `wvalid`
   - Slave asserts `wready` when ready to accept data
   - Handshake completes when both `wvalid` and `wready` are asserted

3. **Response Phase**:
   - Slave drives `bresp` and asserts `bvalid`
   - Master asserts `bready` when ready to accept response
   - Handshake completes when both `bvalid` and `bready` are asserted

### Read Transaction

1. **Address Phase**:
   - Master drives `araddr` and asserts `arvalid`
   - Slave asserts `arready` when ready to accept address
   - Handshake completes when both `arvalid` and `arready` are asserted

2. **Data Phase**:
   - Slave drives `rdata`, `rresp` and asserts `rvalid`
   - Master asserts `rready` when ready to accept data
   - Handshake completes when both `rvalid` and `rready` are asserted

## Response Types

### Write Responses (bresp)

| Value | Name | Description |
|-------|------|-------------|
| 0b00 | OKAY | Normal access success |
| 0b01 | EXOKAY | Exclusive access success (not used in AXI4-Lite) |
| 0b10 | SLVERR | Slave error |
| 0b11 | DECERR | Decode error |

### Read Responses (rresp)

Same encoding as write responses.

## Implementation Details

### Address Decoding

The interconnect implements fixed address decoding:
- No runtime configuration
- Combinational logic for address comparison
- Priority-based slave selection

### Write Strobe Handling

Byte-level write enables are supported through the `wstrb` signal:
- `wstrb[0]` controls byte 0 (bits 7:0)
- `wstrb[1]` controls byte 1 (bits 15:8)
- `wstrb[2]` controls byte 2 (bits 23:16)
- `wstrb[3]` controls byte 3 (bits 31:24)

### Backpressure Management

Slaves can assert backpressure through ready signals:
- `awready` for write address channel
- `wready` for write data channel
- `arready` for read address channel
- `rready` for read data channel

## Timing Requirements

### Setup and Hold Times

All signals must meet standard setup and hold requirements:
- Setup time relative to positive clock edge
- Hold time relative to positive clock edge
- Minimum pulse width for valid/ready signals

### Clock Domain Crossing

All signals operate in a single clock domain:
- Clock: `clk`
- Reset: Active-low synchronous reset (`rst_n`)

## Protocol Compliance

### AXI4-Lite Compliance

The implementation complies with AXI4-Lite requirements:
- Single outstanding transaction per channel
- No burst support (single beat only)
- No exclusive access support
- No cache/coherent attribute signals

### Restrictions

Current implementation limitations:
- Single master only
- No pipelining of transactions
- Fixed address map
- No quality of service (QoS) support

## Error Handling

### Decode Errors

Addresses outside defined ranges:
- Default to RAM controller (fallback behavior)
- Return appropriate response codes
- Log errors for debugging

### Protocol Violations

Invalid signal sequences:
- Misaligned valid/ready handshakes
- Incorrect timing relationships
- Unsupported signal combinations

## Performance Characteristics

### Latency

Typical transaction latency:
- Write: 3-4 clock cycles
- Read: 3-4 clock cycles
- Includes all handshake phases

### Throughput

Maximum transaction rate:
- Limited by single outstanding transaction
- Dependent on slave response times
- Clock frequency dependent

## Verification

### Protocol Checking

Implemented using SystemVerilog Assertions:
- Valid/ready handshake checking
- Signal integrity verification
- Protocol sequence validation

### Test Coverage

Coverage points include:
- All valid transaction sequences
- Backpressure scenarios
- Error conditions
- Boundary cases

## Future Enhancements

### AXI4 Full Support

Planned additions:
- Burst transaction support
- AXI ID signal implementation
- Exclusive access support
- Cache/coherent attribute handling

### Performance Improvements

Potential optimizations:
- Multiple outstanding transactions
- Pipeline stage insertion
- Reduced latency paths
- Dynamic clock gating

## Conclusion

The Open AXI Interconnect implements a compliant subset of the AXI4-Lite protocol optimized for simplicity and reliability. The implementation provides predictable behavior suitable for embedded systems and educational purposes while maintaining compatibility with standard AXI tools and methodologies.
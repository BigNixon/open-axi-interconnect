# Interconnect Module: axi_lite_interconnect

## Overview

The `axi_lite_interconnect` module implements a single-master, multi-slave AXI4-Lite crossbar interconnect. It provides address decoding and routing functionality to connect a master to multiple slave peripherals.

## Module Declaration

```systemverilog
module axi_lite_interconnect #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter NUM_SLAVES = 4
)(
    // Master side (only one master supported in this version)
    input  logic [ADDR_WIDTH-1:0]   m_awaddr,
    input  logic                    m_awvalid,
    output logic                    m_awready,
    
    input  logic [DATA_WIDTH-1:0]   m_wdata,
    input  logic [(DATA_WIDTH/8)-1:0] m_wstrb,
    input  logic                    m_wvalid,
    output logic                    m_wready,
    
    output logic [1:0]              m_bresp,
    output logic                    m_bvalid,
    input  logic                    m_bready,
    
    input  logic [ADDR_WIDTH-1:0]   m_araddr,
    input  logic                    m_arvalid,
    output logic                    m_arready,
    
    output logic [DATA_WIDTH-1:0]   m_rdata,
    output logic [1:0]              m_rresp,
    output logic                    m_rvalid,
    input  logic                    m_rready,
    
    // Slave side
    output logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_awaddr,
    output logic [NUM_SLAVES-1:0]                s_awvalid,
    input  logic [NUM_SLAVES-1:0]                s_awready,
    
    output logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_wdata,
    output logic [NUM_SLAVES-1:0][(DATA_WIDTH/8)-1:0] s_wstrb,
    output logic [NUM_SLAVES-1:0]                s_wvalid,
    input  logic [NUM_SLAVES-1:0]                s_wready,
    
    input  logic [NUM_SLAVES-1:0][1:0]           s_bresp,
    input  logic [NUM_SLAVES-1:0]                s_bvalid,
    output logic [NUM_SLAVES-1:0]                s_bready,
    
    output logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_araddr,
    output logic [NUM_SLAVES-1:0]                s_arvalid,
    input  logic [NUM_SLAVES-1:0]                s_arready,
    
    input  logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_rdata,
    input  logic [NUM_SLAVES-1:0][1:0]           s_rresp,
    input  logic [NUM_SLAVES-1:0]                s_rvalid,
    output logic [NUM_SLAVES-1:0]                s_rready
);
```

## Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `ADDR_WIDTH` | 32 | Width of address bus in bits |
| `DATA_WIDTH` | 32 | Width of data bus in bits |
| `NUM_SLAVES` | 4 | Number of slave interfaces |

## Ports

### Master Side (Single Master Interface)

Write address channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `m_awaddr` | Input | Master write address |
| `m_awvalid` | Input | Master write address valid |
| `m_awready` | Output | Master write address ready |

Write data channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `m_wdata` | Input | Master write data |
| `m_wstrb` | Input | Master write strobe |
| `m_wvalid` | Input | Master write data valid |
| `m_wready` | Output | Master write data ready |

Write response channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `m_bresp` | Output | Master write response |
| `m_bvalid` | Output | Master write response valid |
| `m_bready` | Input | Master write response ready |

Read address channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `m_araddr` | Input | Master read address |
| `m_arvalid` | Input | Master read address valid |
| `m_arready` | Output | Master read address ready |

Read data channel:
| Port | Direction | Description |
|------|-----------|-------------|
| `m_rdata` | Output | Master read data |
| `m_rresp` | Output | Master read response |
| `m_rvalid` | Output | Master read data valid |
| `m_rready` | Input | Master read data ready |

### Slave Side (Multiple Slave Interfaces)

Arrays of slave interfaces, indexed by slave number:
| Port | Direction | Description |
|------|-----------|-------------|
| `s_awaddr` | Output | Slave write addresses |
| `s_awvalid` | Output | Slave write address valid signals |
| `s_awready` | Input | Slave write address ready signals |
| `s_wdata` | Output | Slave write data |
| `s_wstrb` | Output | Slave write strobes |
| `s_wvalid` | Output | Slave write data valid signals |
| `s_wready` | Input | Slave write data ready signals |
| `s_bresp` | Input | Slave write responses |
| `s_bvalid` | Input | Slave write response valid signals |
| `s_bready` | Output | Slave write response ready signals |
| `s_araddr` | Output | Slave read addresses |
| `s_arvalid` | Output | Slave read address valid signals |
| `s_arready` | Input | Slave read address ready signals |
| `s_rdata` | Input | Slave read data |
| `s_rresp` | Input | Slave read responses |
| `s_rvalid` | Input | Slave read data valid signals |
| `s_rready` | Output | Slave read data ready signals |

## Internal Structure

### Type Definitions

```systemverilog
typedef enum logic [1:0] {
    SLAVE_RAM   = 2'd0,
    SLAVE_UART  = 2'd1,
    SLAVE_TIMER = 2'd2,
    SLAVE_GPIO  = 2'd3
} slave_sel_t;
```

Enumeration defining the slave selection indices.

### Signal Declarations

| Signal | Type | Description |
|--------|------|-------------|
| `write_sel` | `slave_sel_t` | Selected slave for write transaction |
| `read_sel` | `slave_sel_t` | Selected slave for read transaction |

### Address Map Constants

Fixed address ranges for slave selection:
- RAM: 0x0000_0000 to 0x0000_FFFF
- UART: 0x4000_0000 to 0x4000_0FFF
- Timer: 0x4001_0000 to 0x4001_0FFF
- GPIO: 0x4002_0000 to 0x4002_0FFF

## Implementation Details

### Address Decoding

The address decoding function determines which slave should handle a transaction:

```systemverilog
function automatic slave_sel_t decode(input [ADDR_WIDTH-1:0] addr);
    begin
        if      ((addr >= UART_BASE)  && (addr <= UART_END))  decode = SLAVE_UART;
        else if ((addr >= TIMER_BASE) && (addr <= TIMER_END)) decode = SLAVE_TIMER;
        else if ((addr >= GPIO_BASE)  && (addr <= GPIO_END))  decode = SLAVE_GPIO;
        else                                                   decode = SLAVE_RAM;
    end
endfunction
```

### Write Routing Logic

The write routing logic connects master signals to the appropriate slave:

```systemverilog
always_comb begin
    // Broadcast addresses and data to all slaves
    s_awaddr  = {NUM_SLAVES{m_awaddr}};
    s_awvalid = {NUM_SLAVES{1'b0}};
    s_wdata   = {NUM_SLAVES{m_wdata}};
    s_wstrb   = {NUM_SLAVES{m_wstrb}};
    s_wvalid  = {NUM_SLAVES{1'b0}};
    s_bready  = {NUM_SLAVES{1'b0}};

    // Activate only the selected slave
    s_awvalid[write_sel] = m_awvalid;
    s_wvalid [write_sel] = m_wvalid;
    s_bready [write_sel] = m_bready;

    // Connect master responses from selected slave
    m_awready = s_awready[write_sel];
    m_wready  = s_wready [write_sel];
    m_bresp   = s_bresp  [write_sel];
    m_bvalid  = s_bvalid [write_sel];
end
```

### Read Routing Logic

Similar logic handles read transactions:

```systemverilog
always_comb begin
    // Broadcast addresses to all slaves
    s_araddr  = {NUM_SLAVES{m_araddr}};
    s_arvalid = {NUM_SLAVES{1'b0}};
    s_rready  = {NUM_SLAVES{1'b0}};

    // Activate only the selected slave
    s_arvalid[read_sel] = m_arvalid;
    s_rready [read_sel] = m_rready;

    // Connect master responses from selected slave
    m_arready = s_arready[read_sel];
    m_rdata   = s_rdata  [read_sel];
    m_rresp   = s_rresp  [read_sel];
    m_rvalid  = s_rvalid [read_sel];
end
```

## Key Features

### Single Master Support

The interconnect supports only one master, simplifying the design:
- No arbitration logic required
- Deterministic routing behavior
- Reduced resource utilization

### Fixed Address Mapping

Address decoding uses fixed ranges:
- No runtime configuration
- Combinational logic implementation
- Predictable performance characteristics

### Full AXI4-Lite Compliance

Implements all required AXI4-Lite channels:
- Write address, write data, write response
- Read address, read data
- Proper handshake signaling

## Performance Characteristics

### Latency

Transaction latency is minimal:
- Address decoding: Combinational logic (single cycle)
- Signal routing: Direct connection (single cycle)
- Total interconnect overhead: 1-2 cycles

### Resource Utilization

Resource usage scales linearly with number of slaves:
- Address decoding logic: Fixed (independent of slaves)
- Routing multiplexers: Proportional to NUM_SLAVES
- No FIFOs or buffering (no outstanding transactions)

## Verification

The interconnect has been verified through:
- Functional simulation with cocotb testbenches
- Assertion-based protocol checking
- Address decoding verification
- Routing correctness validation

## Usage Guidelines

### Integration

To integrate the interconnect:
1. Connect master interface to your AXI master
2. Connect slave interfaces to your peripherals
3. Ensure consistent ADDR_WIDTH and DATA_WIDTH parameters
4. Verify address map matches peripheral expectations

### Parameter Selection

Recommended parameter values:
- `ADDR_WIDTH`: 32 bits (standard for most systems)
- `DATA_WIDTH`: 32 bits (can be adjusted for wider data paths)
- `NUM_SLAVES`: Match to actual number of peripherals

### Address Map Modification

To modify the address map:
1. Update the address constants in the module
2. Adjust the decode function logic
3. Ensure consistency with peripheral address expectations
4. Update documentation to reflect changes

## Limitations

Current implementation limitations:
- Single master only (no multi-master support)
- No pipelining or outstanding transactions
- Fixed address map (requires RTL modification)
- No quality of service (QoS) support
- No protection or region signaling

## Future Enhancements

Planned improvements:
- Multi-master support with arbitration
- Outstanding transaction support
- Configurable address mapping
- QoS and protection features
- Performance monitoring capabilities

## Conclusion

The `axi_lite_interconnect` module provides a simple, efficient solution for connecting a single AXI4-Lite master to multiple slave peripherals. Its fixed address mapping and single-master design make it ideal for embedded systems where simplicity and predictability are valued over maximum flexibility.
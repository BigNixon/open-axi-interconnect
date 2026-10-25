# Peripheral Modules

## Overview

The Open AXI Interconnect system includes four essential peripheral modules that provide fundamental functionality for embedded systems. Each peripheral implements a standard AXI4-Lite slave interface and provides specific capabilities.

## Peripheral List

1. [RAM Controller](#ram-controller) - Memory storage and control
2. [UART Controller](#uart-controller) - Serial communication
3. [Timer Module](#timer-module) - Timing and interrupt generation
4. [GPIO Controller](#gpio-controller) - General-purpose I/O

## RAM Controller

### Module: ram

The RAM controller provides memory storage capabilities with associated control registers.

### Key Features
- 4KB memory array (1024 × 32-bit words)
- Control register for enabling/disabling
- Status register indicating readiness
- Address register for memory access
- Data register for read/write operations

### Address Offsets
| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| 0x00 | CONTROL | RW | RAM enable control |
| 0x04 | STATUS | RO | RAM status indicators |
| 0x08 | ADDRESS | RW | Memory address pointer |
| 0x0C | DATA | RW | Memory data access |

### Implementation Details
The RAM controller implements a dual-access mechanism:
1. Direct register access for control/status
2. Indirect memory access via address/data registers

### Usage Example
```systemverilog
// Write data to memory location 0
axi_write(RAM_BASE + 0x08, 32'h00000000); // Set address
axi_write(RAM_BASE + 0x0C, 32'h12345678); // Write data

// Read data from memory location 0
axi_read(RAM_BASE + 0x08); // Set address
data = axi_read(RAM_BASE + 0x0C); // Read data
```

## UART Controller

### Module: uart

The UART controller provides basic serial communication capabilities.

### Key Features
- Control register for enabling transmitter/receiver
- Status register indicating transmission readiness
- TX data register for outgoing characters
- RX data register for incoming characters

### Address Offsets
| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| 0x00 | CTRL | RW | UART control settings |
| 0x04 | STATUS | RO | UART status indicators |
| 0x08 | TX_DATA | WO | Transmit data register |
| 0x0C | RX_DATA | RO | Receive data register |

### Control Register (CTRL)
| Bits | Name | Access | Description |
|------|------|--------|-------------|
| 31:3 | - | - | Reserved |
| 2 | RX_ENABLE | RW | Enable receiver |
| 1 | TX_ENABLE | RW | Enable transmitter |
| 0 | ENABLE | RW | Enable UART |

### Status Register (STATUS)
| Bits | Name | Access | Description |
|------|------|--------|-------------|
| 31:2 | - | - | Reserved |
| 1 | RX_VALID | RO | Received data available |
| 0 | TX_READY | RO | Transmit available |

### Implementation Details
The current implementation provides a minimal UART model:
- No actual serial transmission/reception
- Data capture for TX register
- Placeholder for RX functionality
- Always-ready status for simplicity

### Usage Example
```systemverilog
// Enable UART with TX/RX
axi_write(UART_BASE + 0x00, 32'h00000007);

// Transmit character 'A'
axi_write(UART_BASE + 0x08, 32'h00000041);

// Check if transmitter ready
status = axi_read(UART_BASE + 0x04);
if (status & 1) {
    // Transmitter ready
}
```

## Timer Module

### Module: timer

The timer module provides timing capabilities with interrupt generation.

### Key Features
- Free-running 32-bit counter
- Configurable compare value for interrupt generation
- Control register for enabling/resetting
- Status register indicating activity
- Interrupt output signal

### Address Offsets
| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| 0x00 | CTRL | RW | Timer control settings |
| 0x04 | STATUS | RO | Timer status indicators |
| 0x08 | COUNT | RO | Current counter value |
| 0x0C | COMPARE | RW | Interrupt compare value |

### Control Register (CTRL)
| Bits | Name | Access | Description |
|------|------|--------|-------------|
| 31:2 | - | - | Reserved |
| 1 | RESET | RW | Reset counter to zero |
| 0 | ENABLE | RW | Enable counting |

### Status Register (STATUS)
| Bits | Name | Access | Description |
|------|------|--------|-------------|
| 31:1 | - | - | Reserved |
| 0 | ACTIVE | RO | Timer is enabled |

### Implementation Details
The timer implements a free-running counter:
- Increments every clock cycle when enabled
- Generates interrupt when count >= compare value
- Reset functionality to clear counter
- Continuous operation regardless of AXI transactions

### Usage Example
```systemverilog
// Set compare value for interrupt
axi_write(TIMER_BASE + 0x0C, 32'h00002710); // 10000 cycles

// Enable timer
axi_write(TIMER_BASE + 0x00, 32'h00000001);

// Read current count
count = axi_read(TIMER_BASE + 0x08);

// Check interrupt status
// timer_irq signal will be high when count >= compare
```

## GPIO Controller

### Module: gpio

The GPIO controller manages 32 bidirectional I/O pins.

### Key Features
- 32 bidirectional GPIO pins
- Direction register (input/output control)
- Output value register
- Input value register (read-only)

### Address Offsets
| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| 0x00 | DIR | RW | Pin direction control |
| 0x04 | OUT | RW | Output pin values |
| 0x08 | IN | RO | Input pin values |

### Direction Register (DIR)
Each bit controls the direction of the corresponding GPIO pin:
- 0: Input (high-impedance)
- 1: Output (driven)

### Output Register (OUT)
Each bit sets the output value for pins configured as outputs.

### Input Register (IN)
Each bit reflects the current input value for all pins.

### Implementation Details
The GPIO controller provides:
- Bidirectional pin control
- Individual pin direction configuration
- Simultaneous read/write of all 32 pins
- External pin connections via inout port

### Usage Example
```systemverilog
// Configure GPIO 0-15 as output, 16-31 as input
axi_write(GPIO_BASE + 0x00, 32'h0000FFFF);

// Set output values for GPIO 0-15
axi_write(GPIO_BASE + 0x04, 32'h00005555);

// Read input values from all pins
inputs = axi_read(GPIO_BASE + 0x08);
```

## Common Implementation Patterns

### AXI4-Lite Slave Interface

All peripherals implement the same AXI4-Lite slave interface pattern:
- Combinational ready signal assignment for immediate response
- Registered valid signal generation for response timing
- Byte-level write strobe handling through helper function
- Address-based register selection

### Register Access Helper

Common helper function for byte-level write operations:
```systemverilog
function automatic [31:0] apply_wstrb(
    input [31:0] old_val,
    input [31:0] new_val,
    input [3:0]  strb
);
    reg [31:0] mask;
    begin
        mask = {{8{strb[3]}}, {8{strb[2]}}, {8{strb[1]}}, {8{strb[0]}}};
        apply_wstrb = (old_val & ~mask) | (new_val & mask);
    end
endfunction
```

### Reset Handling

All peripherals implement synchronous reset:
- Active-low reset signal (`rst_n`)
- Reset values defined for all registers
- Proper initialization sequence on reset deassertion

## Verification Status

All peripheral modules have been verified through:
- Cocotb test suite with comprehensive test cases
- Register access validation
- Functional behavior confirmation
- Integration testing with interconnect

## Customization Guidelines

To add new peripherals:
1. Implement standard AXI4-Lite slave interface
2. Assign unique address range in interconnect
3. Update top-level instantiation
4. Add to cocotb test suite
5. Document in memory and register maps

## Future Enhancements

Planned peripheral improvements:
- Enhanced UART with actual serial transmission
- More sophisticated timer features (prescalers, multiple comparators)
- Advanced GPIO features (interrupts, pull-ups/pull-downs)
- Additional peripheral types (SPI, I2C, PWM)

## Conclusion

The peripheral modules provide essential functionality for embedded systems while maintaining simplicity and predictability. Each module implements standard AXI4-Lite interfaces and has been thoroughly verified, making them reliable building blocks for larger systems.
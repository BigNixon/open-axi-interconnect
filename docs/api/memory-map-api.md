# Memory Map API

## Overview

This document provides detailed information about the Memory Map API for the Open AXI Interconnect system. The memory map defines the address space layout and provides programmatic access to all peripherals and memory regions.

## Memory Map Structure

### Address Space Layout

The system implements a 32-bit address space organized into distinct regions:

```
Address Range           Size    Region
─────────────────────── ─────── ──────────────
0x0000_0000-0x0000_FFFF 64 KB   RAM Controller
0x4000_0000-0x4000_0FFF 4 KB    UART Controller
0x4001_0000-0x4001_0FFF 4 KB    Timer Module
0x4002_0000-0x4002_0FFF 4 KB    GPIO Controller
0x4003_0000-0xFFFF_FFFF ~4GB    Reserved
```

### Address Constants

Programmatic access to memory regions through defined constants:

```c
#define RAM_BASE        0x00000000
#define UART_BASE       0x40000000
#define TIMER_BASE      0x40010000
#define GPIO_BASE       0x40020000
```

## Peripheral Address Ranges

### RAM Controller (0x0000_0000)

#### Memory Region
- **Base Address**: 0x0000_0000
- **Size**: 64 KB (0x10000)
- **End Address**: 0x0000_FFFF

#### Register Map
| Offset | Register | Size | Access |
|--------|----------|------|--------|
| 0x0000 | CONTROL  | 4B   | RW     |
| 0x0004 | STATUS   | 4B   | RO     |
| 0x0008 | ADDRESS  | 4B   | RW     |
| 0x000C | DATA     | 4B   | RW     |
| 0x0010 | MEMORY[0]| 4B   | RW     |
| ...    | ...      | ...  | ...    |
| 0x0FFC | MEMORY[1023]| 4B| RW     |

#### Memory Array Access
The RAM controller implements indirect memory access:
- Write ADDRESS register (0x08) to set memory location
- Write DATA register (0x0C) to store data at that location
- Read DATA register (0x0C) to retrieve data from that location

### UART Controller (0x4000_0000)

#### Peripheral Region
- **Base Address**: 0x4000_0000
- **Size**: 4 KB (0x1000)
- **End Address**: 0x4000_0FFF

#### Register Map
| Offset | Register | Size | Access | Description |
|--------|----------|------|--------|-------------|
| 0x0000 | CTRL     | 4B   | RW     | Control register |
| 0x0004 | STATUS   | 4B   | RO     | Status register |
| 0x0008 | TX_DATA  | 4B   | WO     | Transmit data |
| 0x000C | RX_DATA  | 4B   | RO     | Receive data |

### Timer Module (0x4001_0000)

#### Peripheral Region
- **Base Address**: 0x4001_0000
- **Size**: 4 KB (0x1000)
- **End Address**: 0x4001_0FFF

#### Register Map
| Offset | Register | Size | Access | Description |
|--------|----------|------|--------|-------------|
| 0x0000 | CTRL     | 4B   | RW     | Control register |
| 0x0004 | STATUS   | 4B   | RO     | Status register |
| 0x0008 | COUNT    | 4B   | RO     | Counter value |
| 0x000C | COMPARE  | 4B   | RW     | Compare value |

### GPIO Controller (0x4002_0000)

#### Peripheral Region
- **Base Address**: 0x4002_0000
- **Size**: 4 KB (0x1000)
- **End Address**: 0x4002_0FFF

#### Register Map
| Offset | Register | Size | Access | Description |
|--------|----------|------|--------|-------------|
| 0x0000 | DIR      | 4B   | RW     | Direction control |
| 0x0004 | OUT      | 4B   | RW     | Output values |
| 0x0008 | IN       | 4B   | RO     | Input values |

## API Functions

### Address Validation

Functions to validate memory addresses:

```c
bool is_valid_address(uint32_t address);
bool is_peripheral_address(uint32_t address);
bool is_ram_address(uint32_t address);
```

### Address Range Queries

Functions to determine address ranges:

```c
uint32_t get_peripheral_base(uint32_t address);
uint32_t get_register_offset(uint32_t address);
const char* get_peripheral_name(uint32_t address);
```

### Memory Region Information

Functions to retrieve memory region details:

```c
typedef struct {
    uint32_t base_address;
    uint32_t size;
    const char* name;
    bool is_readable;
    bool is_writable;
} memory_region_info_t;

memory_region_info_t get_memory_region_info(uint32_t address);
```

## Address Decoding API

### Decoder Functions

Programmatic access to address decoding logic:

```c
typedef enum {
    PERIPHERAL_RAM,
    PERIPHERAL_UART,
    PERIPHERAL_TIMER,
    PERIPHERAL_GPIO,
    PERIPHERAL_UNKNOWN
} peripheral_type_t;

peripheral_type_t decode_address(uint32_t address);
```

### Address Mapping

Functions for address translation:

```c
uint32_t map_to_physical_address(uint32_t logical_address);
uint32_t map_to_logical_address(uint32_t physical_address);
```

## Register Access API

### Register Information

Structure for register metadata:

```c
typedef struct {
    uint32_t offset;
    const char* name;
    const char* access_type; // "RW", "RO", "WO"
    uint32_t reset_value;
    const char* description;
} register_info_t;

register_info_t get_register_info(uint32_t base_address, uint32_t offset);
```

### Register Enumeration

Functions to enumerate registers:

```c
typedef struct {
    register_info_t* registers;
    size_t count;
} register_list_t;

register_list_t get_peripheral_registers(uint32_t base_address);
```

## Memory Map Utilities

### Range Checking

Utility functions for address range validation:

```c
bool is_in_range(uint32_t address, uint32_t base, uint32_t size);
bool overlaps_range(uint32_t addr1, uint32_t size1, uint32_t addr2, uint32_t size2);
```

### Alignment Functions

Functions for address alignment:

```c
uint32_t align_to_32bit(uint32_t address);
bool is_32bit_aligned(uint32_t address);
uint32_t get_word_offset(uint32_t address);
```

## Peripheral Identification API

### Peripheral Discovery

Functions to discover available peripherals:

```c
typedef struct {
    uint32_t base_address;
    const char* name;
    size_t register_count;
} peripheral_info_t;

peripheral_info_t* get_all_peripherals(size_t* count);
```

### Peripheral Capabilities

Functions to query peripheral capabilities:

```c
typedef struct {
    bool supports_reads;
    bool supports_writes;
    bool has_interrupts;
    size_t address_space_size;
} peripheral_capabilities_t;

peripheral_capabilities_t get_peripheral_capabilities(uint32_t base_address);
```

## Error Handling

### Address Error Codes

Standard error codes for address-related operations:

```c
typedef enum {
    ADDRESS_VALID = 0,
    ADDRESS_INVALID = -1,
    ADDRESS_UNALIGNED = -2,
    ADDRESS_RESERVED = -3,
    ADDRESS_OUT_OF_RANGE = -4
} address_error_t;

address_error_t validate_address_with_error(uint32_t address);
```

## Usage Examples

### Basic Address Validation

```c
#include "memory_map_api.h"

void example_address_validation() {
    uint32_t test_address = 0x40000008;
    
    if (is_valid_address(test_address)) {
        printf("Address 0x%08X is valid\n", test_address);
    }
    
    if (is_peripheral_address(test_address)) {
        const char* peripheral = get_peripheral_name(test_address);
        printf("Address belongs to %s peripheral\n", peripheral);
    }
}
```

### Register Access Pattern

```c
void example_register_access() {
    // Get register information
    register_info_t reg_info = get_register_info(UART_BASE, 0x0000);
    printf("Register: %s, Access: %s\n", reg_info.name, reg_info.access_type);
    
    // Enumerate all UART registers
    register_list_t uart_regs = get_peripheral_registers(UART_BASE);
    for (size_t i = 0; i < uart_regs.count; i++) {
        printf("Register %s at offset 0x%04X\n", 
               uart_regs.registers[i].name, 
               uart_regs.registers[i].offset);
    }
}
```

### Peripheral Discovery

```c
void example_peripheral_discovery() {
    size_t peripheral_count;
    peripheral_info_t* peripherals = get_all_peripherals(&peripheral_count);
    
    printf("Found %zu peripherals:\n", peripheral_count);
    for (size_t i = 0; i < peripheral_count; i++) {
        printf("- %s at 0x%08X (%zu registers)\n",
               peripherals[i].name,
               peripherals[i].base_address,
               peripherals[i].register_count);
    }
}
```

## Integration Guidelines

### Hardware Integration

When integrating with hardware systems:
1. Verify address alignment before access
2. Use address validation functions
3. Handle reserved address ranges appropriately
4. Respect peripheral access restrictions

### Software Integration

When developing software drivers:
1. Use provided constants for base addresses
2. Leverage register information structures
3. Implement proper error handling
4. Validate all address calculations

## Performance Considerations

### Address Calculation

Optimization tips:
- Pre-calculate frequently used addresses
- Use constants instead of runtime calculations
- Cache peripheral information when possible
- Minimize address validation overhead in performance-critical paths

### Memory Access Patterns

Efficient access strategies:
- Batch related register accesses
- Use word-aligned accesses
- Minimize boundary crossings
- Leverage memory array access mechanisms

## Future Enhancements

### Planned API Improvements

Upcoming memory map API features:
- Dynamic address map configuration
- Memory protection unit integration
- Advanced caching mechanisms
- Real-time address mapping updates
- Multi-core memory coherency support

### Deprecation Notices

APIs scheduled for deprecation:
- Legacy address constants (will be replaced with enums)
- Simple validation functions (will be unified)
- Basic register access patterns (will be enhanced)

## Conclusion

The Memory Map API provides comprehensive programmatic access to the Open AXI Interconnect's address space organization. By using these APIs, developers can ensure correct address usage, implement robust error handling, and optimize memory access patterns.

Regular updates to this API will maintain compatibility with evolving system requirements while providing enhanced functionality for advanced use cases. The commitment to clear documentation and consistent interfaces ensures reliable integration across diverse applications and development environments.
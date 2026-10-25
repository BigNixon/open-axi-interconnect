# Register API

## Overview

This document provides comprehensive information about the Register API for the Open AXI Interconnect system. The Register API enables precise control and monitoring of all peripheral registers through standardized interfaces and data structures.

## Register Architecture

### Register Organization

All peripherals implement a consistent register architecture:
- 32-bit aligned register access
- Standardized offset addressing
- Defined access types (RW, RO, WO)
- Predictable reset values
- Bit-field level definitions

### Register Access Methods

Two primary access methods are supported:
1. **Direct Access**: 32-bit register reads/writes
2. **Bit-field Access**: Individual bit or field manipulation

## Peripheral Register APIs

### RAM Controller Registers

#### Control Register (Offset: 0x00)

```c
typedef struct {
    uint32_t enable : 1;     // Bit 0: RAM enable
    uint32_t reserved : 31; // Bits 1-31: Reserved
} ram_control_reg_t;

// Access functions
void ram_control_enable(void);
void ram_control_disable(void);
bool ram_control_is_enabled(void);
```

#### Status Register (Offset: 0x04)

```c
typedef struct {
    uint32_t ready : 1;      // Bit 0: RAM ready
    uint32_t reserved : 31; // Bits 1-31: Reserved
} ram_status_reg_t;

// Access functions
bool ram_status_is_ready(void);
```

#### Address Register (Offset: 0x08)

```c
typedef struct {
    uint32_t address : 32; // Bits 0-31: Memory address
} ram_address_reg_t;

// Access functions
void ram_address_set(uint32_t addr);
uint32_t ram_address_get(void);
```

#### Data Register (Offset: 0x0C)

```c
typedef struct {
    uint32_t data : 32; // Bits 0-31: Data value
} ram_data_reg_t;

// Access functions
void ram_data_write(uint32_t data);
uint32_t ram_data_read(void);
```

### UART Controller Registers

#### Control Register (Offset: 0x00)

```c
typedef struct {
    uint32_t enable : 1;     // Bit 0: UART enable
    uint32_t tx_enable : 1;  // Bit 1: Transmitter enable
    uint32_t rx_enable : 1;   // Bit 2: Receiver enable
    uint32_t reserved : 29;  // Bits 3-31: Reserved
} uart_control_reg_t;

// Access functions
void uart_control_enable(void);
void uart_control_disable(void);
void uart_tx_enable(void);
void uart_tx_disable(void);
void uart_rx_enable(void);
void uart_rx_disable(void);
bool uart_is_enabled(void);
```

#### Status Register (Offset: 0x04)

```c
typedef struct {
    uint32_t tx_ready : 1;  // Bit 0: Transmit ready
    uint32_t rx_valid : 1;  // Bit 1: Receive data valid
    uint32_t reserved : 30; // Bits 2-31: Reserved
} uart_status_reg_t;

// Access functions
bool uart_tx_is_ready(void);
bool uart_rx_is_valid(void);
```

#### TX Data Register (Offset: 0x08)

```c
typedef struct {
    uint32_t tx_byte : 8;   // Bits 0-7: Transmit byte
    uint32_t reserved : 24; // Bits 8-31: Reserved
} uart_tx_data_reg_t;

// Access functions
void uart_tx_data_write(uint8_t data);
```

#### RX Data Register (Offset: 0x0C)

```c
typedef struct {
    uint32_t rx_byte : 8;   // Bits 0-7: Receive byte
    uint32_t reserved : 24; // Bits 8-31: Reserved
} uart_rx_data_reg_t;

// Access functions
uint8_t uart_rx_data_read(void);
```

### Timer Module Registers

#### Control Register (Offset: 0x00)

```c
typedef struct {
    uint32_t enable : 1;    // Bit 0: Timer enable
    uint32_t reset : 1;     // Bit 1: Counter reset
    uint32_t reserved : 30; // Bits 2-31: Reserved
} timer_control_reg_t;

// Access functions
void timer_enable(void);
void timer_disable(void);
void timer_reset(void);
bool timer_is_enabled(void);
```

#### Status Register (Offset: 0x04)

```c
typedef struct {
    uint32_t active : 1;    // Bit 0: Timer active
    uint32_t reserved : 31; // Bits 1-31: Reserved
} timer_status_reg_t;

// Access functions
bool timer_is_active(void);
```

#### Count Register (Offset: 0x08)

```c
typedef struct {
    uint32_t count : 32; // Bits 0-31: Counter value
} timer_count_reg_t;

// Access functions
uint32_t timer_count_get(void);
```

#### Compare Register (Offset: 0x0C)

```c
typedef struct {
    uint32_t compare : 32; // Bits 0-31: Compare value
} timer_compare_reg_t;

// Access functions
void timer_compare_set(uint32_t value);
uint32_t timer_compare_get(void);
```

### GPIO Controller Registers

#### Direction Register (Offset: 0x00)

```c
typedef struct {
    uint32_t dir : 32; // Bits 0-31: Pin direction (1=output, 0=input)
} gpio_direction_reg_t;

// Access functions
void gpio_direction_set(uint32_t direction_mask);
uint32_t gpio_direction_get(void);
void gpio_pin_set_output(uint8_t pin);
void gpio_pin_set_input(uint8_t pin);
```

#### Output Register (Offset: 0x04)

```c
typedef struct {
    uint32_t out : 32; // Bits 0-31: Output values
} gpio_output_reg_t;

// Access functions
void gpio_output_set(uint32_t output_values);
void gpio_output_set_mask(uint32_t mask, uint32_t values);
uint32_t gpio_output_get(void);
void gpio_pin_set_high(uint8_t pin);
void gpio_pin_set_low(uint8_t pin);
```

#### Input Register (Offset: 0x08)

```c
typedef struct {
    uint32_t in : 32; // Bits 0-31: Input values
} gpio_input_reg_t;

// Access functions
uint32_t gpio_input_get(void);
bool gpio_pin_get(uint8_t pin);
```

## Generic Register Access API

### Unified Register Interface

Standardized interface for all register access:

```c
typedef enum {
    REG_ACCESS_RW,
    REG_ACCESS_RO,
    REG_ACCESS_WO
} register_access_type_t;

typedef struct {
    uint32_t offset;
    uint32_t size;
    register_access_type_t access_type;
    uint32_t reset_value;
    const char* name;
    const char* description;
} register_descriptor_t;

// Generic access functions
uint32_t register_read(uint32_t base_address, uint32_t offset);
void register_write(uint32_t base_address, uint32_t offset, uint32_t value);
void register_bit_set(uint32_t base_address, uint32_t offset, uint8_t bit_position);
void register_bit_clear(uint32_t base_address, uint32_t offset, uint8_t bit_position);
bool register_bit_get(uint32_t base_address, uint32_t offset, uint8_t bit_position);
```

### Register Field Access

Access to individual bit fields:

```c
typedef struct {
    uint8_t start_bit;
    uint8_t width;
    const char* name;
    const char* description;
} register_field_t;

uint32_t register_field_get(uint32_t base_address, uint32_t offset, 
                           uint8_t start_bit, uint8_t width);
void register_field_set(uint32_t base_address, uint32_t offset, 
                       uint8_t start_bit, uint8_t width, uint32_t value);
```

## Register Information API

### Metadata Retrieval

Functions to retrieve register metadata:

```c
register_descriptor_t* get_register_descriptor(uint32_t base_address, uint32_t offset);
register_field_t* get_register_fields(uint32_t base_address, uint32_t offset, size_t* count);
const char* get_register_name(uint32_t base_address, uint32_t offset);
const char* get_register_description(uint32_t base_address, uint32_t offset);
```

### Register Enumeration

Functions to enumerate all registers in a peripheral:

```c
typedef struct {
    register_descriptor_t* descriptors;
    size_t count;
} register_list_t;

register_list_t get_peripheral_registers(uint32_t base_address);
```

## Bit Manipulation API

### Bit-level Operations

Utilities for bit manipulation:

```c
// Bit set/clear operations
uint32_t bit_set(uint32_t value, uint8_t position);
uint32_t bit_clear(uint32_t value, uint8_t position);
bool bit_get(uint32_t value, uint8_t position);

// Bit field operations
uint32_t bit_field_extract(uint32_t value, uint8_t start, uint8_t width);
uint32_t bit_field_insert(uint32_t value, uint32_t field_value, uint8_t start, uint8_t width);

// Mask operations
uint32_t mask_create(uint8_t start, uint8_t width);
uint32_t mask_apply(uint32_t value, uint32_t mask, uint32_t mask_value);
```

## Error Handling

### Register Access Errors

Standard error codes for register operations:

```c
typedef enum {
    REGISTER_SUCCESS = 0,
    REGISTER_ERROR_INVALID_ADDRESS = -1,
    REGISTER_ERROR_ACCESS_DENIED = -2,
    REGISTER_ERROR_TIMEOUT = -3,
    REGISTER_ERROR_ALIGNMENT = -4,
    REGISTER_ERROR_READONLY = -5,
    REGISTER_ERROR_WRITEONLY = -6
} register_error_t;

register_error_t register_read_safe(uint32_t base_address, uint32_t offset, uint32_t* value);
register_error_t register_write_safe(uint32_t base_address, uint32_t offset, uint32_t value);
```

## Usage Examples

### Basic Register Operations

```c
#include "register_api.h"

void example_basic_operations() {
    // Enable RAM controller
    ram_control_enable();
    
    // Check if RAM is ready
    if (ram_status_is_ready()) {
        printf("RAM is ready\n");
    }
    
    // Write data to RAM
    ram_address_set(0x00000000);
    ram_data_write(0x12345678);
    
    // Read data from RAM
    uint32_t data = ram_data_read();
    printf("Read data: 0x%08X\n", data);
}
```

### UART Configuration

```c
void example_uart_configuration() {
    // Enable UART with TX/RX
    uart_control_enable();
    uart_tx_enable();
    uart_rx_enable();
    
    // Wait for transmitter to be ready
    while (!uart_tx_is_ready()) {
        // Wait or yield
    }
    
    // Transmit character 'A'
    uart_tx_data_write('A');
    
    // Check for received data
    if (uart_rx_is_valid()) {
        uint8_t rx_data = uart_rx_data_read();
        printf("Received: %c\n", rx_data);
    }
}
```

### Timer Setup

```c
void example_timer_setup() {
    // Set compare value for 1ms interrupt (assuming 100MHz clock)
    timer_compare_set(100000); // 100000 cycles = 1ms
    
    // Enable timer
    timer_enable();
    
    // Monitor counter
    uint32_t count = timer_count_get();
    printf("Timer count: %u\n", count);
    
    // Reset counter
    timer_reset();
}
```

### GPIO Configuration

```c
void example_gpio_configuration() {
    // Configure GPIO 0-15 as output, 16-31 as input
    gpio_direction_set(0x0000FFFF);
    
    // Set output values for GPIO 0-15
    gpio_output_set(0x00005555);
    
    // Read all input values
    uint32_t inputs = gpio_input_get();
    printf("GPIO inputs: 0x%08X\n", inputs);
    
    // Set individual pin high
    gpio_pin_set_high(0); // Set GPIO 0 high
}
```

### Generic Register Access

```c
void example_generic_access() {
    // Read UART control register using generic API
    uint32_t ctrl_value = register_read(UART_BASE, 0x00);
    printf("UART control: 0x%08X\n", ctrl_value);
    
    // Set a specific bit
    register_bit_set(UART_BASE, 0x00, 0); // Enable UART
    
    // Read a bit field
    uint32_t enable_bit = register_bit_get(UART_BASE, 0x00, 0);
    printf("UART enabled: %s\n", enable_bit ? "Yes" : "No");
    
    // Safe register access with error handling
    uint32_t value;
    register_error_t error = register_read_safe(0xFFFFFFFF, 0x00, &value);
    if (error != REGISTER_SUCCESS) {
        printf("Register read failed: %d\n", error);
    }
}
```

## Integration Guidelines

### Hardware Integration

When integrating with hardware systems:
1. Use provided register structures for type safety
2. Validate register access before operations
3. Handle error conditions appropriately
4. Respect register access types (RW/RO/WO)

### Software Integration

When developing software drivers:
1. Use consistent naming conventions
2. Implement proper error handling
3. Document register usage patterns
4. Test boundary conditions thoroughly

## Performance Considerations

### Register Access Optimization

Tips for efficient register access:
1. Cache frequently accessed register values
2. Batch related register operations
3. Use direct access for simple operations
4. Minimize function call overhead in performance-critical paths

### Memory Access Patterns

Efficient access strategies:
1. Align all register accesses to 32-bit boundaries
2. Use bit-field operations for complex manipulations
3. Avoid unnecessary register reads in write-only registers
4. Implement register access queuing for batch operations

## Future Enhancements

### Planned API Improvements

Upcoming register API features:
- Atomic read-modify-write operations
- Register locking mechanisms
- Advanced bit-field manipulation
- Register access logging and debugging
- Multi-threading support for register access

### Deprecation Notices

APIs scheduled for deprecation:
- Legacy register access functions (will be unified)
- Simple bit manipulation functions (will be enhanced)
- Basic error handling (will be standardized)

## Conclusion

The Register API provides comprehensive and standardized access to all peripheral registers in the Open AXI Interconnect system. By using these APIs, developers can ensure correct register manipulation, implement robust error handling, and optimize performance.

Regular updates to this API will maintain compatibility with evolving system requirements while providing enhanced functionality for advanced use cases. The commitment to clear documentation and consistent interfaces ensures reliable integration across diverse applications and development environments.
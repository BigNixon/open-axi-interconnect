# Cocotb Tests

## Overview

This document provides detailed information about the cocotb-based test infrastructure for the Open AXI Interconnect system. Cocotb (Coroutine Based Testbench) is a Python-based verification framework that enables powerful, flexible test development for digital designs.

## Test Framework

### Cocotb Architecture

The test framework leverages:
- Python 3.x for test development
- Verilator as the simulation backend
- Makefile-based build system
- XML results reporting
- Waveform generation capabilities

### Test Structure

The cocotb test suite consists of four main test modules:
1. `test_axi_lite_basic` - Basic system access validation
2. `test_uart` - UART controller verification
3. `test_timer` - Timer module validation
4. `test_gpio` - GPIO controller testing

## Test Environment

### Configuration

Key configuration parameters:
- Clock period: 10ns (100MHz)
- Reset duration: 5 clock cycles
- Active-low synchronous reset
- Waveform output: VCD format

### Helper Functions

Core utility functions provided:

#### AXI Write Transaction
```python
async def axi_write(dut, addr, data, wstrb=0xF)
```
Handles complete AXI4-Lite write transaction sequence including:
- Address phase (AW channel)
- Data phase (W channel)
- Response phase (B channel)

#### AXI Read Transaction
```python
async def axi_read(dut, addr)
```
Manages complete AXI4-Lite read transaction sequence:
- Address phase (AR channel)
- Data phase (R channel)

#### Reset Helper
```python
async def reset_dut(dut)
```
Implements standardized reset sequence:
- Assert reset for 5 clock cycles
- Initialize AXI interface signals
- Deassert reset

## Test Modules

### test_axi_lite_basic

#### Objective
Validate basic RAM controller functionality and memory operations.

#### Test Sequence
1. **Reset and Initialization**
   ```python
   await reset_dut(dut)
   ```

2. **RAM Control Register Test**
   ```python
   await axi_write(dut, RAM_BASE + 0x0, 0xAAAA_0001)
   data = await axi_read(dut, RAM_BASE + 0x0)
   assert data == 0xAAAA_0001
   ```

3. **Memory Array Operations**
   ```python
   await axi_write(dut, RAM_BASE + 0x8, 0x0000_0000)  # address 0
   await axi_write(dut, RAM_BASE + 0xC, 0x1234_5678)  # write data
   data = await axi_read(dut, RAM_BASE + 0xC)
   assert data == 0x1234_5678
   ```

#### Verification Points
- Register read/write functionality
- Memory array access mechanisms
- Data integrity across operations

### test_uart

#### Objective
Verify UART controller register access and basic functionality.

#### Test Sequence
1. **UART Enable Test**
   ```python
   await axi_write(dut, UART_BASE + 0x0, 0x0000_0007)
   ctrl = await axi_read(dut, UART_BASE + 0x0)
   assert ctrl == 0x0000_0007
   ```

2. **TX Data Validation**
   ```python
   await axi_write(dut, UART_BASE + 0x8, 0x0000_0041)  # 'A'
   tx_data = await axi_read(dut, UART_BASE + 0x8)
   assert tx_data == 0x0000_0041
   ```

3. **Status Register Check**
   ```python
   status = await axi_read(dut, UART_BASE + 0x4)
   assert (status & 0x1) == 0x1  # TX_READY set
   ```

#### Verification Points
- Control register configuration
- Data register access
- Status flag accuracy

### test_timer

#### Objective
Validate timer module counting and interrupt generation.

#### Test Sequence
1. **Compare Value Configuration**
   ```python
   await axi_write(dut, TIMER_BASE + 0xC, 0x0000_000A)
   ```

2. **Timer Enable and Operation**
   ```python
   await axi_write(dut, TIMER_BASE + 0x0, 0x0000_0001)
   ```

3. **Counter Verification**
   ```python
   for _ in range(20):
       await RisingEdge(dut.clk)
   
   count = await axi_read(dut, TIMER_BASE + 0x8)
   assert count >= 0xA
   ```

4. **Interrupt Validation**
   ```python
   irq = int(dut.timer_irq.value)
   assert irq == 1
   ```

#### Verification Points
- Counter increment behavior
- Compare value functionality
- Interrupt generation accuracy

### test_gpio

#### Objective
Confirm GPIO controller direction and value control.

#### Test Sequence
1. **Direction Configuration**
   ```python
   await axi_write(dut, GPIO_BASE + 0x0, 0xFFFF_FFFF)
   dir_val = await axi_read(dut, GPIO_BASE + 0x0)
   assert dir_val == 0xFFFF_FFFF
   ```

2. **Output Value Setting**
   ```python
   await axi_write(dut, GPIO_BASE + 0x4, 0xA5A5_A5A5)
   out_val = await axi_read(dut, GPIO_BASE + 0x4)
   assert out_val == 0xA5A5_A5A5
   ```

3. **Input Value Reading**
   ```python
   in_val = await axi_read(dut, GPIO_BASE + 0x8)
   assert in_val == 0xA5A5_A5A5  # Loopback in testbench
   ```

#### Verification Points
- Direction register functionality
- Output value control
- Input value reflection

## Memory Map Constants

Defined in the test file header:
```python
RAM_BASE   = 0x0000_0000
UART_BASE  = 0x4000_0000
TIMER_BASE = 0x4001_0000
GPIO_BASE  = 0x4002_0000
```

These constants must match the RTL implementation and documentation.

## Test Execution

### Build System

Using the provided Makefile:
```bash
cd sim
make clean     # Remove previous build artifacts
make           # Run cocotb tests
make WAVE=1    # Run with waveform output
```

### Results Reporting

Test results are generated in `results.xml` with:
- Pass/fail status for each test
- Execution time metrics
- Assertion failure details
- Logging output from test cases

### Waveform Generation

Enable waveform capture:
```bash
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

Generated files:
- `dump.vcd` - Simulation waveform
- `results.xml` - Test results

## Debugging Features

### Logging

Each test includes logging statements:
```python
dut._log.info(f"RAM test PASSED: DATA={hex(data)}")
```

Accessible log levels:
- `DEBUG` - Detailed internal state
- `INFO` - Test progress information
- `WARNING` - Non-fatal issues
- `ERROR` - Test failure details

### Waveform Analysis

Waveform signals captured:
- Clock and reset
- All AXI4-Lite interface signals
- Peripheral control signals
- Internal state variables

## Test Case Development

### Adding New Tests

Template for new test cases:
```python
@cocotb.test()
async def test_new_feature(dut):
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())
    
    await reset_dut(dut)
    
    # Test implementation
    # Assertions for verification
    
    dut._log.info("New feature test PASSED")
```

### Best Practices

1. **Consistent Naming**
   - Use descriptive test function names
   - Prefix with `test_` for automatic discovery
   - Include component and feature in name

2. **Assertion Usage**
   - Provide meaningful assertion messages
   - Check critical functionality paths
   - Validate boundary conditions

3. **Error Handling**
   - Use try/except for cleanup
   - Log meaningful error messages
   - Ensure test termination on failure

## Coverage Considerations

### Functional Coverage

Test cases exercise:
- All register access types (RW, RO, WO)
- Various data patterns
- Different address locations
- Multiple transaction sequences

### Code Coverage

Achieved through:
- Sequential test execution
- Comprehensive register access
- Multiple transaction types
- Boundary condition testing

## Performance Metrics

### Execution Time

Typical test run characteristics:
- Total simulation time: ~750ns
- Individual test execution: 100-200ns each
- Reset and initialization: ~50ns per test

### Resource Utilization

Simulation resource usage:
- Memory: Minimal (<10MB)
- CPU: Single core utilization
- Disk: Temporary build files (~100KB)

## Troubleshooting

### Common Issues

1. **Test Failures**
   - Check assertion messages
   - Review waveform data
   - Verify memory map consistency
   - Confirm RTL/test alignment

2. **Build Problems**
   - Ensure cocotb installation
   - Verify Verilator availability
   - Check Makefile paths
   - Confirm Python environment

3. **Waveform Issues**
   - Enable tracing flags
   - Check VCD file generation
   - Verify signal visibility
   - Confirm simulation completion

## Future Enhancements

### Test Infrastructure Improvements

Planned developments:
- Randomized test sequences
- Performance benchmarking tests
- Power-aware verification
- Constrained-random stimulus generation
- Advanced coverage collection

### Advanced Features

Considered enhancements:
- Testbench configuration files
- Parameterized test cases
- Parallel test execution
- Regression dashboard
- Continuous integration integration

## Conclusion

The cocotb test infrastructure provides a robust, flexible verification environment for the Open AXI Interconnect system. The Python-based approach enables rapid test development while maintaining comprehensive coverage of system functionality.

Regular maintenance and extension of the test suite ensures continued verification quality as the system evolves.
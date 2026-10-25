# Simulation Guide

This guide provides comprehensive information about simulating the Open AXI Interconnect system using the cocotb/Verilator framework.

## Overview

The Open AXI Interconnect uses cocotb (Coroutine Co-simulation Testbench) with Verilator as the simulation backend. This combination provides powerful, Python-based verification capabilities while leveraging Verilator's fast simulation performance.

## Simulation Environment

### Architecture

The simulation environment consists of:

```
Python Testbench (cocotb)
        ↓
Verilator Simulator
        ↓
SystemVerilog RTL
```

### Key Components

1. **cocotb**: Python framework for writing testbenches
2. **Verilator**: Fast SystemVerilog simulator
3. **Makefile**: Build automation and configuration
4. **Test Modules**: Python files containing test cases
5. **Results Reporter**: XML output for test results

## Running Simulations

### Basic Execution

Navigate to the simulation directory and run:

```bash
cd sim
make
```

This command:
1. Compiles the RTL with Verilator
2. Executes all test cases
3. Generates results in `results.xml`
4. Displays pass/fail summary

### Clean Build

To ensure a fresh simulation environment:

```bash
make clean
make
```

### Verbose Output

For detailed build information:

```bash
make VERBOSE=1
```

## Test Suite Structure

### Test Modules

The verification suite consists of four main test modules:

1. **test_axi_lite_basic.py** - RAM controller and basic system access
2. **test_uart.py** - UART controller verification
3. **test_timer.py** - Timer module testing
4. **test_gpio.py** - GPIO controller validation

### Test Case Organization

Each test module contains multiple test cases:

```python
@cocotb.test()
async def test_name(dut):
    # Test implementation
    pass
```

### Helper Functions

Shared utilities in test modules:

- `axi_write()` - AXI4-Lite write transaction
- `axi_read()` - AXI4-Lite read transaction
- `reset_dut()` - Device reset sequence

## Waveform Generation

### Enabling Waveforms

Generate VCD waveform files:

```bash
make clean
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

This creates `dump.vcd` for analysis with GTKWave or similar tools.

### Waveform Configuration

Customize waveform generation through Makefile variables:

```makefile
# Enable VCD dumping
VERILATOR_TRACE = 1

# Enable FST dumping (compressed)
VERILATOR_FST = 1

# Trace depth control
VERILATOR_TRACE_DEPTH = 1000
```

### Viewing Waveforms

Using GTKWave:

```bash
gtkwave dump.vcd
```

Waveforms include:
- Clock and reset signals
- All AXI4-Lite interface signals
- Peripheral control signals
- Internal state variables

## Advanced Simulation Options

### Running Specific Tests

Execute individual test cases:

```bash
make COCOTB_TESTCASE=test_uart
```

Run specific test modules:

```bash
make MODULE=test_axi_lite
```

### Test Parameters

Control simulation parameters:

```bash
# Set simulation time limit
make SIM_TIMEOUT=1000000

# Enable coverage collection
make COVERAGE=1

# Set random seed
make RANDOM_SEED=12345
```

### Performance Optimization

Speed up simulations with:

```bash
# Parallel compilation
make -j$(nproc)

# Optimize Verilator flags
export VERILATOR_ARGS="--O3 --inline-mult"
make
```

## Debugging Simulations

### Log Levels

Control verbosity with environment variables:

```bash
export COCOTB_LOG_LEVEL=DEBUG    # Most verbose
export COCOTB_LOG_LEVEL=INFO     # Default
export COCOTB_LOG_LEVEL=WARNING  # Less verbose
export COCOTB_LOG_LEVEL=ERROR    # Least verbose
```

### Debug Output

Enable detailed debugging:

```bash
export COCOTB_DEBUG=1
make
```

### Assertion Debugging

Enable assertion debugging:

```bash
export COCOTB_ASSERT_DEBUG=1
make
```

## Coverage Analysis

### Enabling Coverage

Collect coverage data during simulation:

```bash
make COVERAGE=1
```

### Coverage Types

The simulation collects multiple coverage metrics:

1. **Functional Coverage**: Register and transaction coverage
2. **Code Coverage**: Statement and branch coverage from Verilator
3. **Assertion Coverage**: SVA assertion activation

### Coverage Reports

Coverage data is generated in:
- XML format for parsing
- HTML reports for browsing
- Console summaries during execution

## Test Results

### Results File

Test results are stored in `sim/results.xml`:

```xml
<testsuite>
  <testcase name="test_name" classname="module.TestClass">
    <pass/> <!-- or <failure> with message -->
  </testcase>
</testsuite>
```

### Result Interpretation

Result categories:
- **PASS**: Test completed successfully
- **FAIL**: Test assertion failed
- **ERROR**: Simulation error occurred
- **SKIP**: Test was skipped

### Continuous Integration

Results format compatible with:
- Jenkins
- GitHub Actions
- GitLab CI
- Travis CI

## Performance Monitoring

### Timing Analysis

Monitor simulation performance:

```bash
# Time the simulation
time make

# Profile specific parts
time make build  # Build time
time make run    # Execution time
```

### Resource Usage

Track resource consumption:
- Memory usage during simulation
- Disk space for waveforms
- CPU utilization patterns

### Optimization Targets

Performance optimization areas:
- Test case execution time
- Memory footprint reduction
- Parallel processing opportunities
- Waveform compression

## Advanced Topics

### Custom Test Development

Creating new test cases:

```python
@cocotb.test()
async def my_new_test(dut):
    """Description of what this test does"""
    # Setup
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    # Test implementation
    await reset_dut(dut)
    
    # Assertions
    assert condition, "Failure message"
    
    # Cleanup
    dut._log.info("Test completed successfully")
```

### Parameterized Testing

Running tests with different parameters:

```python
@cocotb.test()
@cases.parametrize(param_name=[value1, value2, value3])
async def test_with_params(dut, param_name):
    # Test implementation using param_name
    pass
```

### Randomized Testing

Implement constrained-random testing:

```python
import random

@cocotb.test()
async def randomized_test(dut):
    # Generate random values within constraints
    random_value = random.randint(min_val, max_val)
    
    # Use in test
    await axi_write(dut, address, random_value)
```

## Integration with External Tools

### CI/CD Pipeline Integration

Configure for automated testing:

```yaml
# .github/workflows/ci.yml
steps:
  - name: Run Simulation
    run: |
      cd sim
      make
      # Check results.xml for failures
```

### IDE Integration

Configure editors for cocotb development:

**VS Code**:
```json
{
  "python.defaultInterpreterPath": "./venv/bin/python",
  "python.analysis.extraPaths": ["./verification/cocotb"]
}
```

### Remote Development

Set up remote simulation environments:
- SSH-based development
- Containerized simulation
- Cloud-based verification farms

## Troubleshooting

### Common Simulation Issues

#### Test Failures
```bash
# Run with debug output
export COCOTB_LOG_LEVEL=DEBUG
make COCOTB_TESTCASE=failing_test

# Generate waveforms for analysis
make COCOTB_TESTCASE=failing_test WAVE=1
```

#### Build Errors
```bash
# Clean and rebuild
make clean
make VERBOSE=1

# Check Verilator installation
verilator --version
```

#### Performance Issues
```bash
# Profile slow tests
time make COCOTB_TESTCASE=slow_test

# Reduce waveform detail
export TRACE_DEPTH=100
make WAVE=1
```

### Debugging Strategies

1. **Isolate failing tests**
   ```bash
   make COCOTB_TESTCASE=test_that_fails
   ```

2. **Enable detailed logging**
   ```bash
   export COCOTB_LOG_LEVEL=DEBUG
   make
   ```

3. **Generate waveforms**
   ```bash
   make WAVE=1 COCOTB_TESTCASE=problematic_test
   ```

4. **Check assertion violations**
   ```bash
   export COCOTB_ASSERT_DEBUG=1
   make
   ```

## Best Practices

### Test Development

Follow these guidelines for effective test development:

1. **Descriptive Test Names**
   ```python
   @cocotb.test()
   async def test_uart_transmit_single_character(dut):
   ```

2. **Clear Assertions**
   ```python
   assert data == expected, f"Expected {expected:x}, got {data:x}"
   ```

3. **Proper Cleanup**
   ```python
   dut._log.info("Test completed successfully")
   ```

### Performance Optimization

Optimize simulation performance:

1. **Minimize Waveform Data**
   ```bash
   # Only enable for debugging
   make WAVE=1  # Not for routine runs
   ```

2. **Batch Related Operations**
   ```python
   # Group related transactions
   for i in range(10):
       await axi_write(dut, addr + i*4, data[i])
   ```

3. **Use Efficient Data Structures**
   ```python
   # Use tuples for immutable data
   test_vectors = (
       (addr1, data1),
       (addr2, data2),
   )
   ```

## Future Enhancements

### Planned Improvements

Simulation infrastructure enhancements:

1. **Advanced Randomization**
   - Constraint solver integration
   - Coverage-driven test generation
   - Intelligent test vector creation

2. **Performance Monitoring**
   - Real-time performance dashboards
   - Resource utilization tracking
   - Bottleneck identification tools

3. **Cloud Integration**
   - Distributed simulation capabilities
   - Parallel test execution
   - Elastic compute resource allocation

## Conclusion

The Open AXI Interconnect simulation environment provides a robust platform for verifying system functionality. By leveraging cocotb and Verilator, the system achieves both ease of use and high performance.

Regular use of the simulation environment ensures design quality and facilitates rapid development iteration. The comprehensive test suite, combined with powerful debugging capabilities, enables confident system development and modification.

For ongoing development, maintain familiarity with the simulation environment and leverage its capabilities for both routine verification and complex debugging scenarios.

Explore the [Verification Documentation](../verification/index.md) for deeper insights into the testing methodology and [Development Guidelines](../development/index.md) for contribution processes.
# Quick Start Guide

Get up and running with the Open AXI Interconnect in just a few minutes!

## Overview

This quick start guide walks you through the fastest path to running your first simulation and verifying the system works correctly. By the end, you'll have executed the complete test suite and understood the basic operation of all peripherals.

## Prerequisites

Before starting, ensure you have:
- Git installed
- Python 3.8+ available
- Internet connection for package installation

## Step-by-Step Instructions

### 1. Clone the Repository

First, get the source code:

```bash
git clone https://github.com/open-axi-interconnect/open-axi-interconnect.git
cd open-axi-interconnect
```

### 2. Install Dependencies

Install the required Python packages:

```bash
pip install -r requirements.txt
```

This installs:
- cocotb (for testbenches)
- cocotb-bus (for bus interfaces)
- cocotb-coverage (for coverage analysis)
- Verilator (will need separate installation)

### 3. Install Verilator

Verilator must be installed separately:

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install verilator
```

**macOS (Homebrew):**
```bash
brew install verilator
```

**From source (if needed):**
Visit [Verilator.org](https://verilator.org/guide/latest/install.html) for detailed installation instructions.

### 4. Run the Tests

Navigate to the simulation directory and run the test suite:

```bash
cd sim
make
```

This will:
1. Compile the RTL with Verilator
2. Run all cocotb tests
3. Generate results in `results.xml`
4. Display test completion status

### 5. View Results

Check the test results:

```bash
cat results.xml
```

Or view the human-readable output from the terminal logs during simulation.

### 6. Run With Waveforms (Optional)

To generate waveforms for debugging:

```bash
make clean
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

This creates `dump.vcd` which can be viewed with GTKWave or similar tools.

## What Just Happened?

You've successfully:

1. **Built the System**: Compiled all RTL modules
2. **Ran Verification**: Executed 4 comprehensive test cases:
   - RAM controller basic access
   - UART controller functionality
   - Timer module operation
   - GPIO controller configuration
3. **Verified Operation**: Confirmed all peripherals work correctly
4. **Generated Reports**: Created test results and coverage data

## Understanding the Tests

### Test 1: RAM Controller Basic Access
- Writes to RAM control register
- Reads back control register value
- Writes data to memory array
- Reads back memory array data

### Test 2: UART Controller
- Enables UART controller
- Writes to UART control register
- Transmits data via TX register
- Checks status register

### Test 3: Timer Module
- Sets timer compare value
- Enables timer counting
- Verifies counter increments
- Checks interrupt generation

### Test 4: GPIO Controller
- Configures GPIO pin directions
- Sets output values
- Reads input values (loopback in testbench)

## Next Steps

Congratulations on your successful quick start! Now you can:

### Explore the System
- Review [Architecture Documentation](../architecture/index.md)
- Examine [RTL Source Code](../rtl/index.md)
- Study [Verification Infrastructure](../verification/index.md)

### Customize the Design
- Modify peripheral parameters
- Add new register mappings
- Extend test cases
- Integrate with your own modules

### Run Specific Tests
Execute individual test cases:

```bash
cd sim
make COCOTB_TESTCASE=test_uart
```

### Generate Documentation
Build the documentation locally:

```bash
pip install mkdocs mkdocs-material
mkdocs serve
```

Then visit http://localhost:8000 in your browser.

## Troubleshooting

### Common Issues

**Problem**: "Command 'verilator' not found"
**Solution**: Install Verilator using your system's package manager

**Problem**: Python import errors
**Solution**: Ensure you're in the correct directory and virtual environment

**Problem**: Tests fail unexpectedly
**Solution**: Clean and rebuild: `make clean && make`

### Need More Help?

- Check [Installation Guide](installation.md) for detailed setup
- Review [Simulation Guide](simulation.md) for advanced usage
- Visit [GitHub Issues](https://github.com/open-axi-interconnect/open-axi-interconnect/issues) for known issues

## What's Next?

Now that you've verified the system works, explore:

1. [Architecture Documentation](../architecture/index.md) - Understand the system design
2. [RTL Reference](../rtl/index.md) - Learn about implementation details
3. [API Reference](../api/index.md) - Discover programmatic interfaces
4. [Development Guide](../development/index.md) - Contribute to the project

## Feedback Welcome

Found something unclear in this guide? Have suggestions for improvement? 

Please [open an issue](https://github.com/open-axi-interconnect/open-axi-interconnect/issues) or submit a pull request to help us improve this documentation for future users.

Enjoy working with the Open AXI Interconnect!
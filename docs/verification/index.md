# Verification

The verification environment uses Cocotb for Python-based testbenches and Verilator as the RTL simulator.

## Testbench Structure

```
verification/
├── cocotb/
│   ├── test_basic.py
│   ├── test_axi_lite.py
│   └── ...
└── assertions/
    └── axi4_lite_assertions.sv
```

## Running Tests

### Basic Simulation

```bash
cd sim
make
```

### Run a Specific Test

```bash
cd sim
make TESTCASE=test_axi_lite
```

### Lint

```bash
cd sim
make lint
```

## Test Coverage

The current test suite covers:

- Basic reset and clocking
- AXI4-Lite read/write transactions
- Address decode to all slaves
- Error response on invalid addresses

## Adding New Tests

1. Create a new Python file under `verification/cocotb/`.
2. Import `cocotb` and the project driver modules.
3. Add the test name to the Cocotb `MODULE` list or invoke it explicitly.
4. Run with `make TESTCASE=<test_name>`.

# Verification

The Open AXI Interconnect includes a comprehensive verification environment built with cocotb and Verilator.

## Testbench Architecture

```
tb/
├── axi_interconnect_tb.sv      # SystemVerilog DUT wrapper
├── tests/
│   ├── test_basic_transfer.py  # Single-beat read/write
│   ├── test_burst_transfer.py  # Burst transactions
│   ├── test_concurrent.py      # Concurrent master access
│   ├── test_arbitration.py     # Arbiter behavior
│   └── test_protocol.py        # Protocol compliance
└── models/
    ├── axi_master_bfm.py       # Master bus functional model
    └── axi_slave_bfm.py        # Slave bus functional model
```

## Running Tests

### All Tests

```bash
make test
```

### Specific Test

```bash
pytest tb/tests/test_basic_transfer.py -v
```

### With Coverage

```bash
make test COVERAGE=1
```

## Test Categories

| Category | Tests | Description |
|----------|-------|-------------|
| **Basic** | `test_basic_transfer` | Single read/write transactions |
| **Burst** | `test_burst_transfer` | INCR, WRAP, FIXED burst types |
| **Concurrent** | `test_concurrent` | Multiple masters active simultaneously |
| **Arbitration** | `test_arbitration` | Round-robin and priority arbitration |
| **Protocol** | `test_protocol` | AXI protocol compliance checks |

## Coverage Goals

| Metric | Target | Status |
|--------|--------|--------|
| Line Coverage | 95% | :material-check: Achieved |
| Branch Coverage | 90% | :material-check: Achieved |
| Toggle Coverage | 90% | :material-progress-clock: In Progress |
| FSM Coverage | 100% | :material-check: Achieved |

## Continuous Integration

Tests run automatically on every pull request via GitHub Actions.

See `.github/workflows/ci.yml` for the CI configuration.

# Simulation Guide

Learn how to run simulations and interpret results for the Open AXI Interconnect.

## Running Simulations

### Basic Simulation

```bash
make sim
```

Runs the default test suite with Verilator and cocotb.

### Specific Test

```bash
make sim TEST=test_basic_transfer
```

### With Waveforms

```bash
make sim WAVES=1
```

Generates VCD waveforms in `sim/build/`.

## Simulation Outputs

| File | Description |
|------|-------------|
| `sim/build/sim.vcd` | Waveform dump (VCD format) |
| `sim/build/results.xml` | cocotb test results |
| `sim/build/sim.log` | Simulation log |

## Viewing Waveforms

Use GTKWave or your preferred waveform viewer:

```bash
gtkwave sim/build/sim.vcd
```

## Testbench Structure

```
tb/
├── axi_interconnect_tb.sv    # SystemVerilog testbench wrapper
├── tests/
│   ├── test_basic_transfer.py
│   ├── test_burst_transfer.py
│   └── test_concurrent_masters.py
└── models/
    └── axi_master_bfm.py
```

## Coverage Reports

Generate coverage after simulation:

```bash
make coverage
```

Reports are saved to `sim/coverage/`.

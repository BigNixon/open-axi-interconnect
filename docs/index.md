# Open AXI Interconnect

A compact, configurable AXI4-Lite interconnect fabric for embedded SoCs.

## Overview

This repository contains a synthesizable SystemVerilog implementation of an AXI4-Lite based subsystem with an integrated crossbar interconnect, address-decoded slave peripherals, and a Cocotb/Verilator simulation testbench.

## Features

- AXI4-Lite compliant master/slave interfaces
- Configurable crossbar interconnect supporting multiple masters and slaves
- Integrated peripherals: RAM, UART, Timer, GPIO
- Parameterized address map and data width
- Cocotb + Verilator simulation environment
- Continuous integration ready

## Repository Structure

```
open-axi-interconnect/
├── rtl/
│   ├── axi/              # AXI interfaces and interconnect
│   ├── peripherals/      # SoC peripherals
│   └── top/              # Top-level subsystem
├── verification/
│   ├── cocotb/           # Python testbench modules
│   └── assertions/       # SystemVerilog assertions
├── sim/                  # Simulation Makefile and scripts
├── docs/                 # Documentation website source
└── README.md
```

## Quick Start

### Run Simulation

```bash
cd sim
make
```

### Run Lint

```bash
cd sim
make lint
```

### Serve Documentation Locally

```bash
mkdocs serve
```

Open `http://127.0.0.1:8000` in a browser.

## Documentation

Full documentation is available at: **https://bignixon.github.io/open-axi-interconnect**

> Replace the URL above with the actual GitHub Pages URL once deployed.

## License

MIT License - see [LICENSE](../LICENSE) for details.

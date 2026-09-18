# Open AXI Interconnect

A synthesizable, open-source AXI4/AXI4-Lite crossbar interconnect written in SystemVerilog, with comprehensive cocotb/Verilator testbenches.

## Documentation

Full project documentation is published at:

**https://open-axi-interconnect.github.io/open-axi-interconnect**

> Replace the URL above with your actual GitHub Pages URL after enabling Pages.

To build and preview the documentation locally:

```bash
pip install -r requirements.txt
mkdocs serve
```

To build the documentation site once:

```bash
mkdocs build
```

## Overview

This project implements a parameterizable AXI4/AXI4-Lite crossbar interconnect for use in FPGA and ASIC designs. It supports multiple masters and slaves, address decoding, arbitration, and configurable data width.

## Repository Structure

```
.
├── docs/                   # Project documentation (MkDocs source)
├── rtl/                    # SystemVerilog RTL source files
├── sim/                    # Simulation scripts and cocotb testbenches
├── tests/                  # Additional test cases
├── mkdocs.yml              # MkDocs configuration
├── requirements.txt        # Python dependencies
└── README.md               # This file
```

## Quick Start

### Prerequisites

- Python 3.8+
- Verilator
- Cocotb
- Make

### Install Python Dependencies

```bash
pip install -r requirements.txt
```

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

## Features

- AXI4/AXI4-Lite protocol support
- Configurable number of masters and slaves
- Round-robin arbitration
- Address-based slave selection
- Parameterizable data/address widths
- cocotb/Verilator testbenches

## Contributing

1. Fork the repository.
2. Create a feature branch.
3. Add or update tests for RTL changes.
4. Update documentation under `docs/`.
5. Submit a pull request.

## License

See `LICENSE` for details.

# Installation

Complete installation guide for the Open AXI Interconnect development environment.

## System Requirements

- Linux or macOS (Windows with WSL2 supported)
- 4 GB RAM minimum (8 GB recommended)
- 2 GB free disk space

## Step 1: Install Python

Ensure Python 3.8 or newer is installed:

```bash
python3 --version
```

If not installed, download from [python.org](https://python.org) or use your package manager.

## Step 2: Install Verilator

=== "Ubuntu/Debian"

    ```bash
    sudo apt-get install verilator
    ```

=== "macOS"

    ```bash
    brew install verilator
    ```

=== "From Source"

    ```bash
    git clone https://github.com/verilator/verilator
    cd verilator
    autoconf
    ./configure
    make -j$(nproc)
    sudo make install
    ```

## Step 3: Install Python Dependencies

```bash
pip install -r requirements.txt
```

This installs:

- `cocotb` — Python testbench framework
- `cocotb-bus` — Bus functional models
- `pytest` — Unit testing framework

## Step 4: Verify Installation

```bash
make check
```

You should see all checks pass.

## Troubleshooting

!!! tip "Verilator not found"
    Ensure `verilator` is in your `PATH`. Add to `~/.bashrc` if needed:
    ```bash
    export PATH=/usr/local/bin:$PATH
    ```

!!! warning "Permission errors"
    Use `pip install --user` or a virtual environment if you encounter permission issues.

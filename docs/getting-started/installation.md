# Installation Guide

This comprehensive installation guide provides detailed instructions for setting up the Open AXI Interconnect development environment on various platforms.

## System Requirements

### Hardware Requirements
- CPU: Modern multi-core processor (x86_64 or ARM64)
- RAM: Minimum 8GB (16GB recommended)
- Disk Space: 500MB free space for tools and repositories
- Network: Internet connection for package downloads

### Supported Platforms
- Ubuntu 20.04 LTS or newer
- Debian 11 or newer
- macOS 10.15 (Catalina) or newer
- Windows 10/11 with WSL2 (Ubuntu 20.04+)
- CentOS/RHEL 8 or newer

## Installing Dependencies

### Python Environment

The Open AXI Interconnect requires Python 3.8 or higher. We recommend using a virtual environment.

#### Create Virtual Environment
```bash
python3 -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate
```

#### Upgrade pip
```bash
pip install --upgrade pip
```

### Required Python Packages

Install from requirements.txt:
```bash
pip install -r requirements.txt
```

This installs:
- cocotb>=1.6.0
- cocotb-bus>=0.1.0
- cocotb-coverage>=1.0.0
- pytest>=6.0.0 (for extended testing)

### Verilator Installation

Verilator is the primary simulation tool used for verification.

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install verilator
```

#### macOS
Using Homebrew:
```bash
brew install verilator
```

#### From Source (Advanced)
For latest features or when packages aren't available:

1. Download from [Verilator.org](https://verilator.org/)
2. Follow the [official installation guide](https://verilator.org/guide/latest/install.html)

#### Verify Installation
```bash
verilator --version
```

Expected output: `Verilator 4.xx.x`

### Optional Tools

For enhanced development experience:

#### GTKWave (Waveform Viewer)
```bash
# Ubuntu/Debian
sudo apt-get install gtkwave

# macOS
brew install gtkwave
```

#### Text Editors/IDEs
- VS Code with SystemVerilog extension
- Vim/Neovim with Verilog plugins
- Emacs with Verilog mode

## Repository Setup

### Clone the Repository
```bash
git clone https://github.com/open-axi-interconnect/open-axi-interconnect.git
cd open-axi-interconnect
```

### Repository Structure
```
open-axi-interconnect/
├── docs/              # Documentation source
├── rtl/               # RTL source code
├── sim/               # Simulation environment
├── verification/       # Verification infrastructure
├── synthesis/          # Synthesis scripts
├── .github/           # GitHub Actions workflows
├── mkdocs.yml         # Documentation configuration
├── requirements.txt   # Python dependencies
└── README.md          # Project overview
```

## Environment Configuration

### Environment Variables

Set up necessary environment variables:

```bash
export AXI_INTERCONNECT_HOME=/path/to/open-axi-interconnect
export PYTHONPATH=$AXI_INTERCONNECT_HOME/verification/cocotb:$PYTHONPATH
```

Add these to your shell profile (`.bashrc`, `.zshrc`, etc.) for persistence.

### PATH Configuration

Ensure tools are in your PATH:

```bash
export PATH=$PATH:/usr/local/bin  # Common location for Verilator
```

## Verification Setup

### Test Environment

Navigate to the simulation directory:
```bash
cd sim
```

### Run Basic Tests

Execute the test suite:
```bash
make
```

This compiles the design and runs all cocotb tests.

### Clean Build

To ensure a fresh build:
```bash
make clean
make
```

### Verbose Output

For debugging build issues:
```bash
make VERBOSE=1
```

## Platform-Specific Instructions

### Ubuntu/Debian

Install all system dependencies at once:
```bash
sudo apt-get update
sudo apt-get install python3 python3-pip verilator git make
```

### macOS

Install Homebrew if not already installed:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install dependencies:
```bash
brew install python3 verilator git make
```

### Windows (WSL2)

1. Install WSL2 from Microsoft Store
2. Install Ubuntu 20.04 or newer
3. Follow Ubuntu installation instructions within WSL

### CentOS/RHEL/Fedora

Install EPEL repository and dependencies:
```bash
sudo dnf install epel-release  # Fedora
# OR
sudo yum install epel-release    # CentOS/RHEL

sudo dnf install python3 python3-pip verilator git make  # Fedora
# OR
sudo yum install python3 python3-pip verilator git make  # CentOS/RHEL
```

## Docker Setup (Alternative)

For consistent environments across teams, consider Docker:

### Dockerfile Example
```dockerfile
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    verilator \
    git \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set up Python environment
WORKDIR /app
COPY requirements.txt .
RUN pip3 install -r requirements.txt

# Copy source code
COPY . .

# Set working directory
WORKDIR /app/sim
```

### Build and Run
```bash
docker build -t axi-interconnect .
docker run -it axi-interconnect make
```

## Troubleshooting Installation

### Common Issues and Solutions

#### Python Package Installation Failures
```bash
# Upgrade pip first
pip install --upgrade pip

# Install wheel if missing
pip install wheel

# Try installing packages individually
pip install cocotb
pip install cocotb-bus
pip install cocotb-coverage
```

#### Verilator Not Found
```bash
# Check installation
which verilator

# If not found, reinstall
sudo apt-get install --reinstall verilator

# Or add to PATH manually
export PATH=$PATH:/usr/local/share/verilator/bin
```

#### Permission Errors
```bash
# Run with sudo if needed (not recommended)
sudo make

# Better: Fix ownership
sudo chown -R $USER:$USER /path/to/repository
```

#### Compilation Errors
```bash
# Clean and rebuild
make clean
make

# Check Verilator version compatibility
verilator --version
```

### Debugging Tips

#### Enable Verbose Output
```bash
# Verbose make
make VERBOSE=1

# Debug cocotb
export COCOTB_LOG_LEVEL=DEBUG
make
```

#### Check Dependencies
```bash
# Verify Python packages
pip list | grep cocotb

# Verify Verilator
verilator --version
verilator --help
```

## Post-Installation Verification

### Run Complete Test Suite
```bash
cd sim
make clean
make
```

Expected output:
```
All tests passed!
```

### Generate Waveforms
```bash
make clean
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

### Check Coverage
```bash
# Coverage reports are generated automatically
# Look for coverage summary in test output
```

## Performance Tuning

### Simulation Optimization

For faster simulations:

1. **Use make -j for parallel builds**
   ```bash
   make -j$(nproc)
   ```

2. **Increase cocotb coroutine stack size**
   ```bash
   export COCOTB_STACK_SIZE=1048576
   ```

3. **Optimize Verilator flags**
   Add to Makefile:
   ```makefile
   VERILATOR_ARGS += --O3 --inline-mult --unroll-count 1000000
   ```

## Next Steps

After successful installation:

1. **Run Quick Start Tutorial**
   ```bash
   cd sim
   make
   ```

2. **Explore Documentation**
   ```bash
   pip install mkdocs mkdocs-material
   mkdocs serve
   ```

3. **Review Architecture**
   Examine `docs/architecture/` for system understanding

4. **Contribute**
   Follow [Development Guidelines](../development/index.md)

## Support and Community

Having installation issues?

1. **Check GitHub Issues** - Search for similar problems
2. **Create New Issue** - Provide system details and error messages
3. **Community Forums** - Join discussions on GitHub Discussions
4. **Documentation** - Review platform-specific installation guides

## Conclusion

You now have a fully functional Open AXI Interconnect development environment. The installation provides everything needed to simulate, verify, and extend the system.

Regular maintenance of your environment ensures compatibility with project updates:
- Keep Verilator updated
- Update Python packages periodically
- Sync with upstream repository changes
- Review release notes for breaking changes

With this setup, you're ready to explore the capabilities of the Open AXI Interconnect and contribute to its ongoing development.
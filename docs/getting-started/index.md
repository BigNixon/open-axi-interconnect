# Getting Started

Welcome to the Open AXI Interconnect! This section provides everything you need to begin using the system, from initial setup to your first successful transaction.

## Overview

The Open AXI Interconnect is a synthesizable, open-source AXI4/AXI4-Lite crossbar interconnect written in SystemVerilog. It provides a complete system-on-chip building block with essential peripherals for embedded applications.

## Quick Navigation

- [Quick Start Guide](quickstart.md) - Get up and running in minutes
- [Installation](installation.md) - Detailed setup instructions
- [Simulation Guide](simulation.md) - Running simulations and tests

## What You'll Learn

By following this getting started guide, you will learn how to:

1. Set up your development environment
2. Install required dependencies
3. Run the simulation environment
4. Execute the test suite
5. Verify system functionality
6. Begin developing your own applications

## System Requirements

Before beginning, ensure your system meets these minimum requirements:

### Hardware
- Modern CPU with at least 4 cores
- 8GB RAM (16GB recommended)
- 500MB free disk space
- Internet connection for downloads

### Software
- Linux, macOS, or Windows with WSL2
- Python 3.8 or higher
- Git version control system
- GNU Make or compatible build tool
- Verilator (latest stable version)

### Recommended Development Environment
- Text editor or IDE with SystemVerilog support
- Terminal or command prompt
- Python virtual environment (recommended)

## Key Concepts

### Architecture Overview

The Open AXI Interconnect implements a single-master, multi-slave architecture:

```
AXI Master
    ↓
AXI Interconnect
    ↓
├── RAM Controller (64KB)
├── UART Controller
├── Timer Module
└── GPIO Controller (32 pins)
```

### Address Map

Understanding the memory map is crucial for system usage:

| Peripheral | Base Address | Size |
|------------|--------------|------|
| RAM        | 0x0000_0000  | 64KB |
| UART       | 0x4000_0000  | 4KB  |
| Timer      | 0x4001_0000  | 4KB  |
| GPIO       | 0x4002_0000  | 4KB  |

## Next Steps

Choose your path based on your experience level:

### For Beginners
Start with the [Quick Start Guide](quickstart.md) for a streamlined introduction to the system.

### For Experienced Users
Jump to [Installation](installation.md) for detailed setup instructions.

### For Academic Users
Review the [Simulation Guide](simulation.md) to understand the verification environment.

## Support Resources

Need help? Check these resources:

- [Architecture Documentation](../architecture/index.md) - Deep dive into system design
- [RTL Reference](../rtl/index.md) - Implementation details
- [Verification Guide](../verification/index.md) - Testing methodology
- [API Reference](../api/index.md) - Programmatic interfaces
- [Development Guide](../development/index.md) - Contribution guidelines

## Community and Feedback

Join our community to connect with other users and contributors:

- GitHub Issues for bug reports and feature requests
- GitHub Discussions for general conversation
- Pull Requests for code contributions
- Documentation improvements welcome

## Ready to Begin?

Start your journey with the Open AXI Interconnect by proceeding to the [Quick Start Guide](quickstart.md) or [Installation](installation.md) instructions.

Whether you're exploring hardware design, learning about AXI protocols, or building embedded systems, the Open AXI Interconnect provides a robust, accessible platform for your projects.
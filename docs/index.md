# Open AXI Interconnect

Welcome to the **Open AXI Interconnect** documentation — a fully synthesizable, parameterizable AXI4/AXI4-Lite crossbar interconnect for FPGA and ASIC designs.

<div class="grid cards" markdown>

-   :material-rocket-launch-outline:{ .lg .middle } __Getting Started__

    ---

    New to the project? Start here to get up and running in minutes.

    [:octicons-arrow-right-24: Quick Start](getting-started/quickstart.md)

-   :material-sitemap:{ .lg .middle } __Architecture__

    ---

    Understand the system architecture, memory maps, and protocol details.

    [:octicons-arrow-right-24: Architecture Overview](architecture/index.md)

-   :material-code-braces:{ .lg .middle } __RTL Reference__

    ---

    Explore the RTL modules, interfaces, and integration guides.

    [:octicons-arrow-right-24: RTL Modules](rtl/index.md)

-   :material-test-tube:{ .lg .middle } __Verification__

    ---

    Review test plans, coverage reports, and simulation results.

    [:octicons-arrow-right-24: Test Plan](verification/index.md)

-   :material-source-branch:{ .lg .middle } __Development__

    ---

    Contributing guidelines, CI/CD setup, and release notes.

    [:octicons-arrow-right-24: Contributing](development/contributing.md)

-   :material-api:{ .lg .middle } __API Reference__

    ---

    Detailed API documentation for memory maps and registers.

    [:octicons-arrow-right-24: API Docs](api/index.md)

</div>

---

## Features

- **AXI4/AXI4-Lite Support**: Full crossbar interconnect with configurable master/slave counts
- **Parameterizable**: Data width, address width, and ID width are all configurable
- **Synthesizable**: Clean SystemVerilog RTL targeting both FPGA and ASIC flows
- **Well-Verified**: Comprehensive cocotb testbench with functional coverage
- **Open Source**: MIT licensed — free for commercial and academic use

## Quick Stats

| Metric | Value |
|--------|-------|
| Language | SystemVerilog |
| Masters | Configurable (default: 2) |
| Slaves | Configurable (default: 4) |
| Data Width | Configurable (default: 32-bit) |
| License | MIT |

## Repository

```bash
git clone https://github.com/open-axi-interconnect/open-axi-interconnect.git
cd open-axi-interconnect
```

## License

This project is licensed under the [MIT License](https://github.com/open-axi-interconnect/open-axi-interconnect/blob/main/LICENSE).

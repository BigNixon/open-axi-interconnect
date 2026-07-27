# Open AXI4 RTL Subsystem
Open-source AXI4 subsystem implementation featuring SystemVerilog RTL, assertions, cocotb tests, and Verilator simulation.
A synthesizable AMBA AXI4 subsystem implemented in SystemVerilog.

## Features

- AXI4-Lite slave interface
- AXI4 interconnect
- Round-robin arbitration
- GPIO/UART/Timer peripherals
- Cocotb verification
- SystemVerilog Assertions

## Tools

- Verilator
- Cocotb
- GTKWave
- Yosys

## Architecture

```
		AXI Master
		    |
		    |
		    |
		AXI Interconnect
			|
|-----------|------------|           
|RAM       UART        Timer
```

## Verification

Tests:
- read/write transactions
- invalid addresses
- burst transfers
- arbitration fairness
- protocol compliance
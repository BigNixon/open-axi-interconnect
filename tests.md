# Existing Tests Documentation

This document lists the existing tests in the workspace, what they verify, and how to reproduce them.

## Test Inventory

| # | Test File | Type | Top Level | Simulator | # Tests |
|---|-----------|------|-----------|-----------|---------|
| 1 | `verification/cocotb/test_axi_lite.py` | cocotb (Python) | `axi_subsystem` | Verilator | 4 |
| 2 | `verification/sv/tb_axi_lite.sv` | SystemVerilog testbench | `tb_axi_lite` | Not currently runnable as-is (see Notes) | N/A |

---

## 1. cocotb Tests (`verification/cocotb/test_axi_lite.py`)

These tests drive the top-level `axi_subsystem` through the cocotb/Verilator flow defined in `sim/Makefile`.

### Common infrastructure

- Clock: 10 ns period (`Clock(dut.clk, 10, unit="ns")`).
- Reset: 5 clock cycles active-low (`rst_n`).
- Helper tasks: `axi_write(dut, addr, data, wstrb=0xF)`, `axi_read(dut, addr)`, `reset_dut(dut)`.
- Memory map used by the tests:
  - `RAM_BASE   = 0x0000_0000`
  - `UART_BASE  = 0x4000_0000`
  - `TIMER_BASE = 0x4001_0000`
  - `GPIO_BASE  = 0x4002_0000`

### `test_axi_lite_basic`

**What it verifies:**
- Basic AXI-Lite write/read path through the interconnect to the RAM peripheral.
- RAM control register read-back.
- RAM data register read-back (writes to the memory array at address 0).

**Sequence:**
1. Reset DUT.
2. Write `0xAAAA_0001` to `RAM_BASE + 0x0` (control register); read back and expect `0xAAAA_0001`.
3. Write `0x0000_0000` to `RAM_BASE + 0x8` (address register).
4. Write `0x1234_5678` to `RAM_BASE + 0xC` (data register / memory array).
5. Read back `RAM_BASE + 0xC` and expect `0x1234_5678`.

**Expected result:** PASS.

### `test_uart`

**What it verifies:**
- UART control register read/write.
- UART TX data register read-back.
- UART status register reflects TX ready.

**Sequence:**
1. Reset DUT.
2. Write `0x0000_0007` to `UART_BASE + 0x0` (control register); read back and expect `0x0000_0007`.
3. Write `0x0000_0041` (`'A'`) to `UART_BASE + 0x8` (TX data); read back and expect `0x0000_0041`.
4. Read `UART_BASE + 0x4` (status) and check bit 0 (`TX_READY`) is set.

**Expected result:** PASS.

### `test_timer`

**What it verifies:**
- Timer compare register configuration.
- Timer enable and counting behavior.
- Timer interrupt (`timer_irq`) assertion when count reaches compare value.

**Sequence:**
1. Reset DUT.
2. Write `0x0000_000A` to `TIMER_BASE + 0xC` (compare register).
3. Write `0x0000_0001` to `TIMER_BASE + 0x0` (control register) to enable counting.
4. Wait 20 clock cycles.
5. Read `TIMER_BASE + 0x8` (count) and expect `count >= 0xA`.
6. Sample `dut.timer_irq` and expect `1`.

**Expected result:** PASS.

### `test_gpio`

**What it verifies:**
- GPIO direction register read/write.
- GPIO output register read/write.
- GPIO input register mirrors output value when pins are driven as outputs (loopback in testbench).

**Sequence:**
1. Reset DUT.
2. Write `0xFFFF_FFFF` to `GPIO_BASE + 0x0` (direction); read back and expect `0xFFFF_FFFF`.
3. Write `0xA5A5_A5A5` to `GPIO_BASE + 0x4` (output); read back and expect `0xA5A5_A5A5`.
4. Read `GPIO_BASE + 0x8` (input) and expect `0xA5A5_A5A5`.

**Expected result:** PASS.

---

## 2. SystemVerilog Testbench (`verification/sv/tb_axi_lite.sv`)

A self-checking SystemVerilog testbench that instantiates `axi_subsystem` as `dut` and performs the same basic checks as the cocotb tests (RAM control, UART TX data, timer count, GPIO output).

**Status / limitation:**
- The file declares `logic [31:0] rd;` inside an `initial` block, which is not supported by Verilator (or by strict IEEE 1800-2001 semantics). As a result, it cannot currently be compiled with Verilator without modification.
- No simulator other than Verilator was available in the workspace during this inspection (`iverilog` not installed).
- Therefore, this testbench was inspected but not executed.

---

## Waveform Generation

Waveforms are generated from the cocotb/Verilator flow by enabling Verilator VCD tracing.

### Command used

```bash
cd sim
make clean
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

### Waveform output

- File: `sim/waves_axi_subsystem_cocotb.vcd`
- Format: VCD (VerilatedVcd)
- Timescale: 1 ps
- Traces all top-level ports of `axi_subsystem` and internal hierarchy signals.
- Size: ~40 KB

### Signals captured (top-level)

- `clk`, `rst_n`
- AXI write address: `awaddr [31:0]`, `awvalid`, `awready`
- AXI write data: `wdata [31:0]`, `wstrb [3:0]`, `wvalid`, `wready`
- AXI write response: `bresp [1:0]`, `bvalid`, `bready`
- AXI read address: `araddr [31:0]`, `arvalid`, `arready`
- AXI read data: `rdata [31:0]`, `rresp [1:0]`, `rvalid`, `rready`
- Peripheral pins: `uart_tx`, `uart_rx`, `timer_irq`, `gpio_pins [31:0]`

---

## How to Reproduce

### Run cocotb tests (with waveform output)

```bash
cd sim
make clean
make WAVE=1 VERILATOR_TRACE=1 TRACE=1
```

Expected: all 4 cocotb tests PASS, `sim/results.xml` updated, `sim/dump.vcd` generated.

### Run lint on RTL

```bash
cd sim
make lint
```

### Run lint on assertions

```bash
cd sim
make lint-assertions
```

---

## Last Run Summary

| Metric | Value |
|--------|-------|
| Tests run | 4 |
| Passed | 4 |
| Failed | 0 |
| Skipped | 0 |
| Total simulation time | 750 ns |
| Waveform file | `sim/waves_axi_subsystem_cocotb.vcd` |

---

## Known Limitations

1. **SV testbench not runnable:** `verification/sv/tb_axi_lite.sv` has an in-`initial` variable declaration that Verilator rejects. It was not executed.
2. **No assertion-based simulation:** The assertions in `verification/assertions/axi_assertions.sv` are only linted; they are not currently bound into a running simulation.
3. **Waveform scope:** The generated VCD covers the cocotb test run only. Separate waveforms for the SV testbench or assertion-based tests were not generated because those simulations were not run.


 make WAVE=1 VERILATOR_TRACE=1 TRACE=1 COCOTB_TESTCASE=test_uart
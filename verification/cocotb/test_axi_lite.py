import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


# Base addresses (must match rtl/axi/axi_lite_interconnect.sv)
RAM_BASE   = 0x0000_0000
UART_BASE  = 0x4000_0000
TIMER_BASE = 0x4001_0000
GPIO_BASE  = 0x4002_0000


# -------------------------
# AXI write
# -------------------------
async def axi_write(dut, addr, data, wstrb=0xF):
    dut.awaddr.value  = addr
    dut.wdata.value   = data
    dut.wstrb.value   = wstrb
    dut.awvalid.value = 1
    dut.wvalid.value  = 1
    dut.bready.value  = 1

    await RisingEdge(dut.clk)

    dut.awvalid.value = 0
    dut.wvalid.value  = 0

    while not dut.bvalid.value:
        await RisingEdge(dut.clk)

    dut.bready.value = 0


# -------------------------
# AXI read
# -------------------------
async def axi_read(dut, addr):
    dut.araddr.value  = addr
    dut.arvalid.value = 1
    dut.rready.value  = 1

    await RisingEdge(dut.clk)

    dut.arvalid.value = 0

    while not dut.rvalid.value:
        await RisingEdge(dut.clk)

    value = int(dut.rdata.value)
    dut.rready.value = 0
    return value


# -------------------------
# Reset helper
# -------------------------
async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.awvalid.value = 0
    dut.wvalid.value  = 0
    dut.arvalid.value = 0
    dut.bready.value  = 0
    dut.rready.value  = 0
    dut.uart_rx.value = 1
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1


# -------------------------
# Test: AXI-Lite subsystem basic access
# -------------------------
@cocotb.test()
async def test_axi_lite_basic(dut):
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Write/read RAM control register
    await axi_write(dut, RAM_BASE + 0x0, 0xAAAA_0001)
    data = await axi_read(dut, RAM_BASE + 0x0)
    assert data == 0xAAAA_0001, f"RAM CONTROL mismatch: {hex(data)}"

    # Write/read RAM data register via memory array
    await axi_write(dut, RAM_BASE + 0x8, 0x0000_0000)  # address 0
    await axi_write(dut, RAM_BASE + 0xC, 0x1234_5678)  # write data to mem[0]
    data = await axi_read(dut, RAM_BASE + 0xC)
    assert data == 0x1234_5678, f"RAM DATA mismatch: {hex(data)}"

    dut._log.info(f"RAM test PASSED: DATA={hex(data)}")


@cocotb.test()
async def test_uart(dut):
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Enable UART
    await axi_write(dut, UART_BASE + 0x0, 0x0000_0007)
    ctrl = await axi_read(dut, UART_BASE + 0x0)
    assert ctrl == 0x0000_0007, f"UART CTRL mismatch: {hex(ctrl)}"

    # Write TX data
    await axi_write(dut, UART_BASE + 0x8, 0x0000_0041)  # 'A'
    tx_data = await axi_read(dut, UART_BASE + 0x8)
    assert tx_data == 0x0000_0041, f"UART TXDATA mismatch: {hex(tx_data)}"

    # Check status
    status = await axi_read(dut, UART_BASE + 0x4)
    assert (status & 0x1) == 0x1, f"UART TX_READY not set: {hex(status)}"

    dut._log.info(f"UART test PASSED: CTRL={hex(ctrl)} TXDATA={hex(tx_data)}")


@cocotb.test()
async def test_timer(dut):
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Set compare value
    await axi_write(dut, TIMER_BASE + 0xC, 0x0000_000A)

    # Enable timer
    await axi_write(dut, TIMER_BASE + 0x0, 0x0000_0001)

    # Wait for counter to reach compare
    for _ in range(20):
        await RisingEdge(dut.clk)

    count = await axi_read(dut, TIMER_BASE + 0x8)
    assert count >= 0xA, f"Timer count did not reach compare: {hex(count)}"

    irq = int(dut.timer_irq.value)
    assert irq == 1, f"Timer IRQ not asserted: {irq}"

    dut._log.info(f"Timer test PASSED: COUNT={hex(count)} IRQ={irq}")


@cocotb.test()
async def test_gpio(dut):
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Set all pins as output
    await axi_write(dut, GPIO_BASE + 0x0, 0xFFFF_FFFF)
    dir_val = await axi_read(dut, GPIO_BASE + 0x0)
    assert dir_val == 0xFFFF_FFFF, f"GPIO DIR mismatch: {hex(dir_val)}"

    # Write output value
    await axi_write(dut, GPIO_BASE + 0x4, 0xA5A5_A5A5)
    out_val = await axi_read(dut, GPIO_BASE + 0x4)
    assert out_val == 0xA5A5_A5A5, f"GPIO OUT mismatch: {hex(out_val)}"

    # Read input (should mirror output since pins are looped back in testbench)
    in_val = await axi_read(dut, GPIO_BASE + 0x8)
    assert in_val == 0xA5A5_A5A5, f"GPIO IN mismatch: {hex(in_val)}"

    dut._log.info(f"GPIO test PASSED: OUT={hex(out_val)} IN={hex(in_val)}")

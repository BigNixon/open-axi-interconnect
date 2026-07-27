import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


# -------------------------
# AXI write
# -------------------------
async def axi_write(dut, addr, data):
    dut.awaddr.value = addr
    dut.wdata.value  = data
    dut.awvalid.value = 1
    dut.wvalid.value  = 1
    dut.bready.value  = 1

    await RisingEdge(dut.clk)

    dut.awvalid.value = 0
    dut.wvalid.value  = 0

    # wait response
    while not dut.bvalid.value:
        await RisingEdge(dut.clk)


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

    return dut.rdata.value.integer


# -------------------------
# Test
# -------------------------
@cocotb.test()
async def test_axi_lite_basic(dut):

    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # reset
    dut.rst_n.value = 0
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    # init signals
    dut.awvalid.value = 0
    dut.wvalid.value  = 0
    dut.arvalid.value = 0
    dut.bready.value  = 0
    dut.rready.value  = 0

    # -------------------------
    # WRITE CONTROL
    # -------------------------
    await axi_write(dut, 0x0, 0xAAAA0001)

    # READ BACK CONTROL
    data = await axi_read(dut, 0x0)
    assert data == 0xAAAA0001, f"CONTROL mismatch: {hex(data)}"

    # -------------------------
    # WRITE DATA
    # -------------------------
    await axi_write(dut, 0x8, 0x12345678)

    data = await axi_read(dut, 0x8)
    assert data == 0x12345678, f"DATA mismatch: {hex(data)}"

    dut._log.info(f"TEST PASSED: DATA={hex(data)}")
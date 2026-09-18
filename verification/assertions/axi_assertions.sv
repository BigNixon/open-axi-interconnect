module axi_assertions #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    input  logic                    rst_n,

    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [ADDR_WIDTH-1:0]   awaddr,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic                    awvalid,
    input  logic                    awready,

    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [DATA_WIDTH-1:0]   wdata,
    input  logic [(DATA_WIDTH/8)-1:0] wstrb,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic                    wvalid,
    input  logic                    wready,

    input  logic [1:0]              bresp,
    input  logic                    bvalid,
    input  logic                    bready,

    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [ADDR_WIDTH-1:0]   araddr,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic                    arvalid,
    input  logic                    arready,

    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [DATA_WIDTH-1:0]   rdata,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic [1:0]              rresp,
    input  logic                    rvalid,
    input  logic                    rready
);

    // Once AWVALID is asserted, it must remain asserted until AWREADY is seen.
    property p_awvalid_stable;
        @(posedge clk) disable iff (!rst_n)
        (awvalid && !awready) |=> awvalid;
    endproperty
    assert property (p_awvalid_stable) else $error("AWVALID dropped before AWREADY");

    // Once WVALID is asserted, it must remain asserted until WREADY is seen.
    property p_wvalid_stable;
        @(posedge clk) disable iff (!rst_n)
        (wvalid && !wready) |=> wvalid;
    endproperty
    assert property (p_wvalid_stable) else $error("WVALID dropped before WREADY");

    // Once ARVALID is asserted, it must remain asserted until ARREADY is seen.
    property p_arvalid_stable;
        @(posedge clk) disable iff (!rst_n)
        (arvalid && !arready) |=> arvalid;
    endproperty
    assert property (p_arvalid_stable) else $error("ARVALID dropped before ARREADY");

    // Once RVALID is asserted, it must remain asserted until RREADY is seen.
    property p_rvalid_stable;
        @(posedge clk) disable iff (!rst_n)
        (rvalid && !rready) |=> rvalid;
    endproperty
    assert property (p_rvalid_stable) else $error("RVALID dropped before RREADY");

    // Once BVALID is asserted, it must remain asserted until BREADY is seen.
    property p_bvalid_stable;
        @(posedge clk) disable iff (!rst_n)
        (bvalid && !bready) |=> bvalid;
    endproperty
    assert property (p_bvalid_stable) else $error("BVALID dropped before BREADY");

    // Response codes must be valid (OKAY, EXOKAY, SLVERR, or DECERR).
    property p_bresp_valid;
        @(posedge clk) disable iff (!rst_n)
        bvalid |-> (bresp inside {2'b00, 2'b01, 2'b10, 2'b11});
    endproperty
    assert property (p_bresp_valid) else $error("Invalid BRESP");

    property p_rresp_valid;
        @(posedge clk) disable iff (!rst_n)
        rvalid |-> (rresp inside {2'b00, 2'b01, 2'b10, 2'b11});
    endproperty
    assert property (p_rresp_valid) else $error("Invalid RRESP");

endmodule

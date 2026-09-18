module axi_subsystem #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    input  logic                    rst_n,

    // AXI4-Lite master interface
    input  logic [ADDR_WIDTH-1:0]   awaddr,
    input  logic                    awvalid,
    output logic                    awready,

    input  logic [DATA_WIDTH-1:0]   wdata,
    input  logic [(DATA_WIDTH/8)-1:0] wstrb,
    input  logic                    wvalid,
    output logic                    wready,

    output logic [1:0]              bresp,
    output logic                    bvalid,
    input  logic                    bready,

    input  logic [ADDR_WIDTH-1:0]   araddr,
    input  logic                    arvalid,
    output logic                    arready,

    output logic [DATA_WIDTH-1:0]   rdata,
    output logic [1:0]              rresp,
    output logic                    rvalid,
    input  logic                    rready,

    // External peripheral signals
    output logic                    uart_tx,
    input  logic                    uart_rx,
    output logic                    timer_irq,
    inout  logic [31:0]             gpio_pins
);

    localparam NUM_SLAVES = 4;

    // Interconnect to slave signals
    logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_awaddr;
    logic [NUM_SLAVES-1:0]                s_awvalid;
    logic [NUM_SLAVES-1:0]                s_awready;

    logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_wdata;
    logic [NUM_SLAVES-1:0][(DATA_WIDTH/8)-1:0] s_wstrb;
    logic [NUM_SLAVES-1:0]                s_wvalid;
    logic [NUM_SLAVES-1:0]                s_wready;

    logic [NUM_SLAVES-1:0][1:0]           s_bresp;
    logic [NUM_SLAVES-1:0]                s_bvalid;
    logic [NUM_SLAVES-1:0]                s_bready;

    logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_araddr;
    logic [NUM_SLAVES-1:0]                s_arvalid;
    logic [NUM_SLAVES-1:0]                s_arready;

    logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_rdata;
    logic [NUM_SLAVES-1:0][1:0]           s_rresp;
    logic [NUM_SLAVES-1:0]                s_rvalid;
    logic [NUM_SLAVES-1:0]                s_rready;

    axi_lite_interconnect #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_SLAVES(NUM_SLAVES)
    ) u_interconnect (
        .m_awaddr(awaddr),
        .m_awvalid(awvalid),
        .m_awready(awready),

        .m_wdata(wdata),
        .m_wstrb(wstrb),
        .m_wvalid(wvalid),
        .m_wready(wready),

        .m_bresp(bresp),
        .m_bvalid(bvalid),
        .m_bready(bready),

        .m_araddr(araddr),
        .m_arvalid(arvalid),
        .m_arready(arready),

        .m_rdata(rdata),
        .m_rresp(rresp),
        .m_rvalid(rvalid),
        .m_rready(rready),

        .s_awaddr(s_awaddr),
        .s_awvalid(s_awvalid),
        .s_awready(s_awready),

        .s_wdata(s_wdata),
        .s_wstrb(s_wstrb),
        .s_wvalid(s_wvalid),
        .s_wready(s_wready),

        .s_bresp(s_bresp),
        .s_bvalid(s_bvalid),
        .s_bready(s_bready),

        .s_araddr(s_araddr),
        .s_arvalid(s_arvalid),
        .s_arready(s_arready),

        .s_rdata(s_rdata),
        .s_rresp(s_rresp),
        .s_rvalid(s_rvalid),
        .s_rready(s_rready)
    );

    // RAM slave (index 0)
    ram #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_ram (
        .clk(clk),
        .rst_n(rst_n),

        .awaddr(s_awaddr[0]),
        .awvalid(s_awvalid[0]),
        .awready(s_awready[0]),

        .wdata(s_wdata[0]),
        .wstrb(s_wstrb[0]),
        .wvalid(s_wvalid[0]),
        .wready(s_wready[0]),

        .bresp(s_bresp[0]),
        .bvalid(s_bvalid[0]),
        .bready(s_bready[0]),

        .araddr(s_araddr[0]),
        .arvalid(s_arvalid[0]),
        .arready(s_arready[0]),

        .rdata(s_rdata[0]),
        .rresp(s_rresp[0]),
        .rvalid(s_rvalid[0]),
        .rready(s_rready[0])
    );

    // UART slave (index 1)
    uart #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_uart (
        .clk(clk),
        .rst_n(rst_n),

        .awaddr(s_awaddr[1]),
        .awvalid(s_awvalid[1]),
        .awready(s_awready[1]),

        .wdata(s_wdata[1]),
        .wstrb(s_wstrb[1]),
        .wvalid(s_wvalid[1]),
        .wready(s_wready[1]),

        .bresp(s_bresp[1]),
        .bvalid(s_bvalid[1]),
        .bready(s_bready[1]),

        .araddr(s_araddr[1]),
        .arvalid(s_arvalid[1]),
        .arready(s_arready[1]),

        .rdata(s_rdata[1]),
        .rresp(s_rresp[1]),
        .rvalid(s_rvalid[1]),
        .rready(s_rready[1]),

        .tx(uart_tx),
        .rx(uart_rx)
    );

    // Timer slave (index 2)
    timer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_timer (
        .clk(clk),
        .rst_n(rst_n),

        .awaddr(s_awaddr[2]),
        .awvalid(s_awvalid[2]),
        .awready(s_awready[2]),

        .wdata(s_wdata[2]),
        .wstrb(s_wstrb[2]),
        .wvalid(s_wvalid[2]),
        .wready(s_wready[2]),

        .bresp(s_bresp[2]),
        .bvalid(s_bvalid[2]),
        .bready(s_bready[2]),

        .araddr(s_araddr[2]),
        .arvalid(s_arvalid[2]),
        .arready(s_arready[2]),

        .rdata(s_rdata[2]),
        .rresp(s_rresp[2]),
        .rvalid(s_rvalid[2]),
        .rready(s_rready[2]),

        .irq(timer_irq)
    );

    // GPIO slave (index 3)
    gpio #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_gpio (
        .clk(clk),
        .rst_n(rst_n),

        .awaddr(s_awaddr[3]),
        .awvalid(s_awvalid[3]),
        .awready(s_awready[3]),

        .wdata(s_wdata[3]),
        .wstrb(s_wstrb[3]),
        .wvalid(s_wvalid[3]),
        .wready(s_wready[3]),

        .bresp(s_bresp[3]),
        .bvalid(s_bvalid[3]),
        .bready(s_bready[3]),

        .araddr(s_araddr[3]),
        .arvalid(s_arvalid[3]),
        .arready(s_arready[3]),

        .rdata(s_rdata[3]),
        .rresp(s_rresp[3]),
        .rvalid(s_rvalid[3]),
        .rready(s_rready[3]),

        .gpio_pins(gpio_pins)
    );

endmodule

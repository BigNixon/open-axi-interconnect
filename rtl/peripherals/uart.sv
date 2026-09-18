module uart #(
    parameter ADDR_WIDTH = 12,
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    input  logic                    rst_n,

    // AXI4-Lite slave interface
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [ADDR_WIDTH-1:0]   awaddr,
    input  logic                    awvalid,
    /* verilator lint_on UNUSEDSIGNAL */
    output logic                    awready,

    input  logic [DATA_WIDTH-1:0]   wdata,
    input  logic [(DATA_WIDTH/8)-1:0] wstrb,
    input  logic                    wvalid,
    output logic                    wready,

    output logic [1:0]              bresp,
    output logic                    bvalid,
    input  logic                    bready,

    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [ADDR_WIDTH-1:0]   araddr,
    input  logic                    arvalid,
    /* verilator lint_on UNUSEDSIGNAL */
    output logic                    arready,

    output logic [DATA_WIDTH-1:0]   rdata,
    output logic [1:0]              rresp,
    output logic                    rvalid,
    input  logic                    rready,

    // External UART signals
    output logic                    tx,
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic                    rx
    /* verilator lint_on UNUSEDSIGNAL */
);

    // Register offsets
    localparam CTRL_OFFSET   = 4'h0;
    localparam STATUS_OFFSET = 4'h4;
    localparam TXDATA_OFFSET = 4'h8;
    localparam RXDATA_OFFSET = 4'hC;

    logic [31:0] reg_ctrl;
    logic [31:0] reg_status;
    logic [7:0]  tx_data;
    logic [7:0]  rx_data;

    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign arready = 1'b1;
    assign bresp   = 2'b00;
    assign rresp   = 2'b00;

    // Simple TX ready flag: always ready in this minimal model
    assign tx = reg_ctrl[0] ? tx_data[0] : 1'b1; // placeholder tx line

    // Byte-wise write helper
    function automatic [31:0] apply_wstrb(
        input [31:0] old_val,
        input [31:0] new_val,
        input [3:0]  strb
    );
        reg [31:0] mask;
        begin
            mask = {{8{strb[3]}}, {8{strb[2]}}, {8{strb[1]}}, {8{strb[0]}}};
            apply_wstrb = (old_val & ~mask) | (new_val & mask);
        end
    endfunction

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            reg_ctrl   <= 32'h0000_0000;
            reg_status <= 32'h0000_0001; // TX_READY
            tx_data    <= 8'h00;
            rx_data    <= 8'h00;
            bvalid     <= 1'b0;
        end else begin
            if (awvalid && wvalid) begin
                case (awaddr[3:0])
                    CTRL_OFFSET:   reg_ctrl   <= apply_wstrb(reg_ctrl,   wdata, wstrb);
                    STATUS_OFFSET: reg_status <= apply_wstrb(reg_status, wdata, wstrb);
                    TXDATA_OFFSET: tx_data    <= wdata[7:0];
                    RXDATA_OFFSET: ; // read-only
                    default: ;
                endcase
                bvalid <= 1'b1;
            end

            if (bvalid && bready)
                bvalid <= 1'b0;
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rvalid <= 1'b0;
            rdata  <= 32'h0000_0000;
        end else begin
            if (arvalid) begin
                case (araddr[3:0])
                    CTRL_OFFSET:   rdata <= reg_ctrl;
                    STATUS_OFFSET: rdata <= reg_status;
                    TXDATA_OFFSET: rdata <= {24'h0, tx_data};
                    RXDATA_OFFSET: rdata <= {24'h0, rx_data};
                    default:       rdata <= 32'h0000_0000;
                endcase
                rvalid <= 1'b1;
            end

            if (rvalid && rready)
                rvalid <= 1'b0;
        end
    end

endmodule

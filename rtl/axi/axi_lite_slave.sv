module axi_lite_slave #(
    parameter ADDR_WIDTH = 4,
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    input  logic                    rst_n,

    // AW* channel
    input  logic [ADDR_WIDTH-1:0]   awaddr,
    input  logic                    awvalid,
    output logic                    awready,

    // W channel
    input  logic [DATA_WIDTH-1:0]   wdata,
    input  logic [(DATA_WIDTH/8)-1:0] wstrb,
    input  logic                    wvalid,
    output logic                    wready,

    // B response
    output logic [1:0]              bresp,
    output logic                    bvalid,
    input  logic                    bready,

    // AR* channel
    input  logic [ADDR_WIDTH-1:0]   araddr,
    input  logic                    arvalid,
    output logic                    arready,

    // R channel
    output logic [DATA_WIDTH-1:0]   rdata,
    output logic [1:0]              rresp,
    output logic                    rvalid,
    input  logic                    rready
);

    // -------------------------
    // Register bank
    // -------------------------
    logic [31:0] reg_control;
    logic [31:0] reg_status;
    logic [31:0] reg_data;
    logic [31:0] reg_version;

    // -------------------------
    // Defaults
    // -------------------------
    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign arready = 1'b1;

    assign bresp   = 2'b00;
    assign rresp   = 2'b00;

    // -------------------------
    // WRITE
    // -------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            reg_control <= 0;
            reg_status  <= 32'hDEAD_BEEF;
            reg_data    <= 0;
            reg_version <= 32'h0000_0001;
            bvalid      <= 0;
        end else begin

            if (awvalid && wvalid) begin
                case (awaddr)
                    4'h0: reg_control <= wdata;
                    4'h4: reg_status  <= wdata;
                    4'h8: reg_data    <= wdata;
                    4'hC: reg_version <= wdata;
                endcase
                bvalid <= 1'b1;
            end

            if (bvalid && bready)
                bvalid <= 1'b0;
        end
    end

    // -------------------------
    // READ
    // -------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rvalid <= 0;
            rdata  <= 0;
        end else begin

            if (arvalid) begin
                case (araddr)
                    4'h0: rdata <= reg_control;
                    4'h4: rdata <= reg_status;
                    4'h8: rdata <= reg_data;
                    4'hC: rdata <= reg_version;
                    default: rdata <= 32'h0;
                endcase
                rvalid <= 1'b1;
            end

            if (rvalid && rready)
                rvalid <= 1'b0;
        end
    end

endmodule
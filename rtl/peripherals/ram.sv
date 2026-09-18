module ram #(
    parameter ADDR_WIDTH = 16,
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
    input  logic                    rready
);

    localparam MEM_DEPTH = 1024; // 4 KB memory array
    localparam IDX_WIDTH = $clog2(MEM_DEPTH);

    logic [DATA_WIDTH-1:0] mem [0:MEM_DEPTH-1];

    // Control / status registers at offsets 0x00-0x0C
    logic [31:0] reg_control;
    logic [31:0] reg_status;
    logic [31:0] reg_address;

    logic [IDX_WIDTH-1:0] mem_addr;

    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign arready = 1'b1;
    assign bresp   = 2'b00;
    assign rresp   = 2'b00;

    assign mem_addr = reg_address[IDX_WIDTH-1:0];

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

    // Write handling
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            reg_control <= 32'h0000_0000;
            reg_status  <= 32'h0000_0001; // READY
            reg_address <= 32'h0000_0000;
            bvalid      <= 1'b0;
        end else begin
            if (awvalid && wvalid) begin
                case (awaddr[3:0])
                    4'h0: reg_control <= apply_wstrb(reg_control, wdata, wstrb);
                    4'h4: reg_status  <= apply_wstrb(reg_status,  wdata, wstrb);
                    4'h8: reg_address <= apply_wstrb(reg_address, wdata, wstrb);
                    4'hC: begin
                        // DATA register write -> write to memory at reg_address
                        if (wstrb[0]) mem[mem_addr][7:0]   <= wdata[7:0];
                        if (wstrb[1]) mem[mem_addr][15:8]  <= wdata[15:8];
                        if (wstrb[2]) mem[mem_addr][23:16] <= wdata[23:16];
                        if (wstrb[3]) mem[mem_addr][31:24] <= wdata[31:24];
                    end
                    default: ;
                endcase
                bvalid <= 1'b1;
            end

            if (bvalid && bready)
                bvalid <= 1'b0;
        end
    end

    // Read handling
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rvalid   <= 1'b0;
            rdata    <= 32'h0000_0000;
        end else begin
            if (arvalid) begin
                case (araddr[3:0])
                    4'h0: rdata <= reg_control;
                    4'h4: rdata <= reg_status;
                    4'h8: rdata <= reg_address;
                    4'hC: rdata <= mem[mem_addr];
                    default: rdata <= 32'h0000_0000;
                endcase
                rvalid <= 1'b1;
            end

            if (rvalid && rready)
                rvalid <= 1'b0;
        end
    end

endmodule

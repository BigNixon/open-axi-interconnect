module gpio #(
    parameter ADDR_WIDTH = 12,
    parameter DATA_WIDTH = 32,
    parameter NUM_PINS   = 32
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

    inout  logic [NUM_PINS-1:0]     gpio_pins
);

    // Register offsets
    localparam DIR_OFFSET = 4'h0;
    localparam OUT_OFFSET = 4'h4;
    localparam IN_OFFSET  = 4'h8;

    logic [NUM_PINS-1:0] reg_dir;
    logic [NUM_PINS-1:0] reg_out;
    logic [NUM_PINS-1:0] reg_in;

    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign arready = 1'b1;
    assign bresp   = 2'b00;
    assign rresp   = 2'b00;

    // Tristate GPIO pins: output when dir == 1, high-Z input when dir == 0
    genvar i;
    generate
        for (i = 0; i < NUM_PINS; i++) begin : gen_gpio
            assign gpio_pins[i] = reg_dir[i] ? reg_out[i] : 1'bz;
            assign reg_in[i]    = gpio_pins[i];
        end
    endgenerate

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
            reg_dir <= {NUM_PINS{1'b0}};
            reg_out <= {NUM_PINS{1'b0}};
            bvalid  <= 1'b0;
        end else begin
            if (awvalid && wvalid) begin
                case (awaddr[3:0])
                    DIR_OFFSET: reg_dir <= apply_wstrb(reg_dir, wdata, wstrb);
                    OUT_OFFSET: reg_out <= apply_wstrb(reg_out, wdata, wstrb);
                    IN_OFFSET:  ; // read-only
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
            rdata  <= {DATA_WIDTH{1'b0}};
        end else begin
            if (arvalid) begin
                case (araddr[3:0])
                    DIR_OFFSET: rdata <= {{(DATA_WIDTH-NUM_PINS){1'b0}}, reg_dir};
                    OUT_OFFSET: rdata <= {{(DATA_WIDTH-NUM_PINS){1'b0}}, reg_out};
                    IN_OFFSET:  rdata <= {{(DATA_WIDTH-NUM_PINS){1'b0}}, reg_in};
                    default:    rdata <= {DATA_WIDTH{1'b0}};
                endcase
                rvalid <= 1'b1;
            end

            if (rvalid && rready)
                rvalid <= 1'b0;
        end
    end

endmodule

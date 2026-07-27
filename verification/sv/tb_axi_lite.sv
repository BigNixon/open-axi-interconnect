module tb_axi_lite;

    logic clk = 0;
    always #5 clk = ~clk;

    logic rst_n;

    // signals
    logic [3:0] awaddr;
    logic awvalid;
    logic awready;

    logic [31:0] wdata;
    logic [3:0] wstrb;
    logic wvalid;
    logic wready;

    logic bvalid;
    logic bready;

    logic [3:0] araddr;
    logic arvalid;
    logic arready;

    logic [31:0] rdata;
    logic rvalid;
    logic rready;

    // DUT
    axi_lite_slave dut (
        .clk(clk),
        .rst_n(rst_n),

        .awaddr(awaddr),
        .awvalid(awvalid),
        .awready(awready),

        .wdata(wdata),
        .wstrb(wstrb),
        .wvalid(wvalid),
        .wready(wready),

        .bresp(),
        .bvalid(bvalid),
        .bready(bready),

        .araddr(araddr),
        .arvalid(arvalid),
        .arready(arready),

        .rdata(rdata),
        .rresp(),
        .rvalid(rvalid),
        .rready(rready)
    );

    task axi_write(input [3:0] addr, input [31:0] data);
        begin
            awaddr  = addr;
            wdata   = data;
            awvalid = 1;
            wvalid  = 1;
            bready  = 1;

            @(posedge clk);
            awvalid = 0;
            wvalid  = 0;

            wait(bvalid);
        end
    endtask

    task axi_read(input [3:0] addr, output [31:0] data);
        begin
            araddr  = addr;
            arvalid = 1;
            rready  = 1;

            @(posedge clk);
            arvalid = 0;

            wait(rvalid);
            data = rdata;
        end
    endtask

    initial begin
        // init
        awvalid = 0;
        wvalid  = 0;
        arvalid = 0;
        bready  = 0;
        rready  = 0;

        rst_n = 0;
        repeat(5) @(posedge clk);
        rst_n = 1;

        // WRITE CONTROL
        axi_write(4'h0, 32'hAAAA_0001);

        // READ CONTROL
        logic [31:0] rd;
        axi_read(4'h0, rd);

        $display("READ CONTROL = %h", rd);

        // WRITE DATA
        axi_write(4'h8, 32'h1234_5678);

        axi_read(4'h8, rd);
        $display("READ DATA = %h", rd);

        $finish;
    end

endmodule
module axi_lite_interconnect #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter NUM_SLAVES = 4
)(
    // Master side (only one master supported in this version)
    input  logic [ADDR_WIDTH-1:0]   m_awaddr,
    input  logic                    m_awvalid,
    output logic                    m_awready,

    input  logic [DATA_WIDTH-1:0]   m_wdata,
    input  logic [(DATA_WIDTH/8)-1:0] m_wstrb,
    input  logic                    m_wvalid,
    output logic                    m_wready,

    output logic [1:0]              m_bresp,
    output logic                    m_bvalid,
    input  logic                    m_bready,

    input  logic [ADDR_WIDTH-1:0]   m_araddr,
    input  logic                    m_arvalid,
    output logic                    m_arready,

    output logic [DATA_WIDTH-1:0]   m_rdata,
    output logic [1:0]              m_rresp,
    output logic                    m_rvalid,
    input  logic                    m_rready,

    // Slave side
    output logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_awaddr,
    output logic [NUM_SLAVES-1:0]                s_awvalid,
    input  logic [NUM_SLAVES-1:0]                s_awready,

    output logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_wdata,
    output logic [NUM_SLAVES-1:0][(DATA_WIDTH/8)-1:0] s_wstrb,
    output logic [NUM_SLAVES-1:0]                s_wvalid,
    input  logic [NUM_SLAVES-1:0]                s_wready,

    input  logic [NUM_SLAVES-1:0][1:0]           s_bresp,
    input  logic [NUM_SLAVES-1:0]                s_bvalid,
    output logic [NUM_SLAVES-1:0]                s_bready,

    output logic [NUM_SLAVES-1:0][ADDR_WIDTH-1:0] s_araddr,
    output logic [NUM_SLAVES-1:0]                s_arvalid,
    input  logic [NUM_SLAVES-1:0]                s_arready,

    input  logic [NUM_SLAVES-1:0][DATA_WIDTH-1:0] s_rdata,
    input  logic [NUM_SLAVES-1:0][1:0]           s_rresp,
    input  logic [NUM_SLAVES-1:0]                s_rvalid,
    output logic [NUM_SLAVES-1:0]                s_rready
);

    // Memory map
    localparam [ADDR_WIDTH-1:0] RAM_END    = 32'h0000_FFFF;
    localparam [ADDR_WIDTH-1:0] UART_BASE  = 32'h4000_0000;
    localparam [ADDR_WIDTH-1:0] UART_END   = 32'h4000_0FFF;
    localparam [ADDR_WIDTH-1:0] TIMER_BASE = 32'h4001_0000;
    localparam [ADDR_WIDTH-1:0] TIMER_END  = 32'h4001_0FFF;
    localparam [ADDR_WIDTH-1:0] GPIO_BASE  = 32'h4002_0000;
    localparam [ADDR_WIDTH-1:0] GPIO_END   = 32'h4002_0FFF;

    typedef enum logic [1:0] {
        SLAVE_RAM   = 2'd0,
        SLAVE_UART  = 2'd1,
        SLAVE_TIMER = 2'd2,
        SLAVE_GPIO  = 2'd3
    } slave_sel_t;

    slave_sel_t write_sel;
    slave_sel_t read_sel;

    // Address decode: RAM occupies the bottom 64 KB; everything else is decoded explicitly.
    function automatic slave_sel_t decode(input [ADDR_WIDTH-1:0] addr);
        begin
            if      ((addr >= UART_BASE)  && (addr <= UART_END))  decode = SLAVE_UART;
            else if ((addr >= TIMER_BASE) && (addr <= TIMER_END)) decode = SLAVE_TIMER;
            else if ((addr >= GPIO_BASE)  && (addr <= GPIO_END))  decode = SLAVE_GPIO;
            else                                                   decode = SLAVE_RAM;
        end
    endfunction

    assign write_sel = decode(m_awaddr);
    assign read_sel  = decode(m_araddr);

    // Write routing
    always_comb begin
        s_awaddr  = {NUM_SLAVES{m_awaddr}};
        s_awvalid = {NUM_SLAVES{1'b0}};
        s_wdata   = {NUM_SLAVES{m_wdata}};
        s_wstrb   = {NUM_SLAVES{m_wstrb}};
        s_wvalid  = {NUM_SLAVES{1'b0}};
        s_bready  = {NUM_SLAVES{1'b0}};

        s_awvalid[write_sel] = m_awvalid;
        s_wvalid [write_sel] = m_wvalid;
        s_bready [write_sel] = m_bready;

        m_awready = s_awready[write_sel];
        m_wready  = s_wready [write_sel];
        m_bresp   = s_bresp  [write_sel];
        m_bvalid  = s_bvalid [write_sel];
    end

    // Read routing
    always_comb begin
        s_araddr  = {NUM_SLAVES{m_araddr}};
        s_arvalid = {NUM_SLAVES{1'b0}};
        s_rready  = {NUM_SLAVES{1'b0}};

        s_arvalid[read_sel] = m_arvalid;
        s_rready [read_sel] = m_rready;

        m_arready = s_arready[read_sel];
        m_rdata   = s_rdata  [read_sel];
        m_rresp   = s_rresp  [read_sel];
        m_rvalid  = s_rvalid [read_sel];
    end

endmodule

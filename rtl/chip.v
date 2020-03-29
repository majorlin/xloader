/*
 *  PicoSoC - A simple example SoC using PicoRV32
 *
 *  Copyright (C) 2017  Clifford Wolf <clifford@clifford.at>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

`timescale 1 ns / 100 ps
module chip #(
	parameter TOTAL_GPIOS = 8
)(
	input clk,
	input resetn,
	input uart_rx,
	output uart_tx,
    output qspi_sck,
    inout qspi_dq0,
    inout qspi_dq1,
    inout qspi_dq2,
    inout qspi_dq3,
    output qspi_cs0,
    output qspi_cs1,
    output qspi_cs2,
    output qspi_cs3,
    output soc_fail,
    output [7:0]pads
);
	parameter [0:0] BARREL_SHIFTER = 1;
	parameter [0:0] ENABLE_MULDIV = 1;
	parameter [0:0] ENABLE_FAST_MUL = 1;
	parameter [0:0] ENABLE_COMPRESSED = 1;
	parameter [0:0] ENABLE_COUNTERS = 1;
	parameter [0:0] ENABLE_IRQ_QREGS = 1;
	parameter [ 0:0] ENABLE_IRQ = 1;
	parameter [ 0:0] REGS_INIT_ZERO = 1;

	parameter integer MEM_WORDS = 32 * 1024 / 4;
	parameter [31:0] STACKADDR = (31 * 1024);       // end of memory
	parameter [31:0] PROGADDR_RESET = 32'h 0000_0000; // ROM start address
	parameter [31:0] PROGADDR_IRQ = 32'h 0000_0060;
    
	// CPU
	wire mem_valid;
	wire mem_instr;
	wire mem_ready;
	wire [31:0] mem_addr;
	wire [31:0] mem_wdata;
	wire [ 3:0] mem_wstrb;
	wire [31:0] mem_rdata;

	wire soc_clk;
	wire soc_resetn;
    wire soc_trap;
	assign soc_clk = clk;
	assign soc_resetn = resetn;
    assign soc_fail = soc_trap;

	// SRAM
	wire sram_mem_valid;
	reg sram_mem_ready;
    always @(posedge clk) begin
        sram_mem_ready <= sram_mem_valid;
    end
	wire [31:0] sram_mem_rdata;
	assign sram_mem_valid = mem_valid && (mem_addr[31:24] == 8'h00);

    // GPIO
	wire gpio_mem_valid;
	wire gpio_mem_ready;
	wire [31:0] gpio_mem_rdata;
	assign gpio_mem_valid = mem_valid && (mem_addr[20]);

	wire [TOTAL_GPIOS-1:0] gpio_do;
	wire [TOTAL_GPIOS-1:0] gpio_obe;
	wire [TOTAL_GPIOS-1:0] gpio_ind;

    generate
        genvar i;
        for (i = 0; i < TOTAL_GPIOS; i = i+1) begin: input_mux
            assign gpio_ind[i] = gpio_obe[i] ? gpio_do[i] : pads[i];
            assign pads[i] = gpio_obe[i] ? gpio_do[i] : 1'bz;
        end // for
    endgenerate


    // UART 
	wire uart_mem_valid;
	wire uart_mem_ready;
	wire [31:0] uart_mem_rdata;
	assign uart_mem_valid = mem_valid && (mem_addr[21]);

    // QSPI
	wire qspi_mem_valid;
	wire qspi_mem_ready;
	wire [31:0] qspi_mem_rdata;
	assign qspi_mem_valid = mem_valid && (mem_addr[22]);

	assign mem_rdata = ({32{sram_mem_ready}} & sram_mem_rdata)
		| ({32{gpio_mem_ready}} & gpio_mem_rdata)
		| ({32{uart_mem_ready}} & uart_mem_rdata)
		| ({32{qspi_mem_ready}} & qspi_mem_rdata)
        ;
	assign mem_ready = sram_mem_ready
		| gpio_mem_ready
		| uart_mem_ready
		| qspi_mem_ready
        ;
	// Interrupt request
	wire [31:0] soc_irq;
	assign soc_irq = 32'h0;


	picorv32 #(
		.STACKADDR(STACKADDR),
		.PROGADDR_RESET(PROGADDR_RESET),
		.PROGADDR_IRQ(PROGADDR_IRQ),
		.BARREL_SHIFTER(BARREL_SHIFTER),
		.COMPRESSED_ISA(ENABLE_COMPRESSED),
		.ENABLE_COUNTERS(ENABLE_COUNTERS),
		.ENABLE_MUL(ENABLE_MULDIV),
		.ENABLE_FAST_MUL(ENABLE_FAST_MUL),
		.ENABLE_DIV(ENABLE_MULDIV),
		.ENABLE_IRQ(ENABLE_IRQ),
		.REGS_INIT_ZERO(REGS_INIT_ZERO),
		.ENABLE_IRQ_QREGS(ENABLE_IRQ_QREGS)
	) cpu (
		.clk         (soc_clk        ),
		.resetn      (soc_resetn     ),
		.trap        (soc_trap     ),
		.mem_valid   (mem_valid  ),
		.mem_instr   (mem_instr  ),
		.mem_ready   (mem_ready  ),
		.mem_addr    (mem_addr   ),
		.mem_wdata   (mem_wdata  ),
		.mem_wstrb   (mem_wstrb  ),
		.mem_rdata   (mem_rdata  ),
		.irq         (soc_irq    )
	);



	sram_byte_en_model sram (
		.addra(mem_addr[14:2]),     	// Address bus, width determined from RAM_DEPTH
		.dina(mem_wdata),      // RAM input data, width determined from NB_COL*COL_WIDTH
		.clka(soc_clk),       		// Clock
		.wea(mem_wstrb),       // Byte-write enable, width determined from NB_COL
		.ena(sram_mem_valid),       // RAM Enable, for additional power savings, disable port when not in use
		.douta(sram_mem_rdata)      // RAM output data, width determined from NB_COL*COL_WIDTH
	);

	gpio #(
        .TOTAL_GPIOS(TOTAL_GPIOS)
    )gpio(
    	.mem_clk(soc_clk),         // gpio memory access and module clock
    	.rst_n(soc_resetn),
    	.mem_valid(gpio_mem_valid),        // Module valid
    	.mem_wdata(mem_wdata),
    	.mem_addr(mem_addr[5:2]),
    	.mem_wstrb(mem_wstrb),
    	.gpio_ind(gpio_ind),
    	.gpio_do(gpio_do),
    	.gpio_obe(gpio_obe),
    	.mem_ready(gpio_mem_ready),
    	.mem_rdata(gpio_mem_rdata)
	);

    assign uart_mem_ready = uart_mem_valid;
    sirv_uart_top uart(
        .clk(soc_clk),
        .rst_n(soc_resetn),

        .i_icb_cmd_valid(uart_mem_valid),
        .i_icb_cmd_ready(),
        .i_icb_cmd_addr(mem_addr), 
        .i_icb_cmd_read(4'b0 == mem_wstrb), 
        .i_icb_cmd_wdata(mem_wdata),

        .i_icb_rsp_valid(),
        .i_icb_rsp_ready(1'b1),
        .i_icb_rsp_rdata(uart_mem_rdata),

        .io_interrupts_0_0(),                
        .io_port_txd(uart_tx),
        .io_port_rxd(uart_rx)
    );

    wire qspi_dq0_i;
    wire qspi_dq0_o;
    wire qspi_dq0_oe;
    assign qspi_dq0_i = qspi_dq0;
    assign qspi_dq0 = qspi_dq0_oe ? qspi_dq0_o : 1'bz;

    wire qspi_dq1_i;
    wire qspi_dq1_o;
    wire qspi_dq1_oe;
    assign qspi_dq1_i = qspi_dq1;
    assign qspi_dq1 = qspi_dq1_oe ? qspi_dq1_o : 1'bz;

    wire qspi_dq2_i;
    wire qspi_dq2_o;
    wire qspi_dq2_oe;
    assign qspi_dq2_i = qspi_dq2;
    assign qspi_dq2 = qspi_dq2_oe ? qspi_dq2_o : 1'bz;

    wire qspi_dq3_i;
    wire qspi_dq3_o;
    wire qspi_dq3_oe;
    assign qspi_dq3_i = qspi_dq3;
    assign qspi_dq3 = qspi_dq3_oe ? qspi_dq3_o : 1'bz;

    assign qspi_mem_ready = qspi_mem_valid;
    sirv_qspi_4cs_top qspi(
        .clk(soc_clk),
        .rst_n(soc_resetn),

        .i_icb_cmd_valid(qspi_mem_valid),
        .i_icb_cmd_ready(),
        .i_icb_cmd_addr(mem_addr), 
        .i_icb_cmd_read(4'b0 == mem_wstrb), 
        .i_icb_cmd_wdata(mem_wdata),

        .i_icb_rsp_valid(),
        .i_icb_rsp_ready(1'b1),
        .i_icb_rsp_rdata(qspi_mem_rdata),

        .io_port_sck(qspi_sck),
        .io_port_dq_0_i (qspi_dq0_i),
        .io_port_dq_0_o (qspi_dq0_o),
        .io_port_dq_0_oe(qspi_dq0_oe),
        .io_port_dq_1_i (qspi_dq1_i),
        .io_port_dq_1_o (qspi_dq1_o),
        .io_port_dq_1_oe(qspi_dq1_oe),
        .io_port_dq_2_i (qspi_dq2_i),
        .io_port_dq_2_o (qspi_dq2_o),
        .io_port_dq_2_oe(qspi_dq2_oe),
        .io_port_dq_3_i (qspi_dq3_i),
        .io_port_dq_3_o (qspi_dq3_o),
        .io_port_dq_3_oe(qspi_dq3_oe),
        .io_port_cs_0(qspi_cs0),
        .io_port_cs_1(qspi_cs1),
        .io_port_cs_2(qspi_cs2),
        .io_port_cs_3(qspi_cs3),
        .io_tl_i_0_0()
    );
	
endmodule

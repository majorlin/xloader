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
	assign soc_clk = clk;
	assign soc_resetn = resetn;

    // GPIO
	wire gpio_mem_valid;
	wire gpio_mem_ready;
	wire [31:0] gpio_mem_rdata;
	assign gpio_mem_valid = mem_valid && (mem_addr[20] == 1'b1);

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

	// SRAM
	wire sram_mem_valid;
	reg sram_mem_ready;
    always @(posedge clk) begin
        sram_mem_ready <= sram_mem_valid;
    end
	wire [31:0] sram_mem_rdata;
	assign sram_mem_valid = mem_valid && (mem_addr[31:24] == 8'h00);

	assign mem_rdata = ({32{sram_mem_ready}} & sram_mem_rdata)
		| ({32{gpio_mem_ready}} & gpio_mem_rdata)
        ;
	assign mem_ready = sram_mem_ready
		| gpio_mem_ready
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
	
endmodule

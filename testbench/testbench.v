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

module testbench;
    reg clk;
    reg reset_n;
    wire [31:0] PADS;
    always #5 clk = (clk === 1'b0);

    initial begin
        $dumpfile("testbench.vcd");
        $dumpvars(0, testbench);
        reset_n = 0;
        #160;
        reset_n = 1;

        repeat (2) begin
            repeat (5000) @(posedge clk);
        end
        $finish;
    end

    integer cycle_cnt = 0;

    always @(posedge clk) begin
        cycle_cnt <= cycle_cnt + 1;
    end

    chip chip(
        .clk      (clk      ),
        .resetn   (reset_n  ),
        .uart_rx  (uart_tx),
        .uart_tx  (uart_tx),
        .qspi_sck (qspi_sck),
        .qspi_dq0 (qspi_dq0),
        .qspi_dq1 (qspi_dq1),
        .qspi_dq2 (qspi_dq2),
        .qspi_dq3 (qspi_dq3),
        .qspi_cs0 (qspi_cs0),
        .qspi_cs1 (qspi_cs1),
        .qspi_cs2 (qspi_cs2),
        .qspi_cs3 (qspi_cs3),
        .pads  	  (pads)
    );
    uart_vip #(
        .CLK_HZ (100000000),
        .BAUDRATE(25000000)
    ) uart (
        .clk (clk),
        .uart_rx(uart_tx)
    );
    W25Q16JV flash(
        .CSn(qspi_cs0), 
        .CLK(qspi_sck), 
        .DIO(qspi_dq0), 
        .DO (qspi_dq1), 
        .WPn (qspi_dq2), 
        .HOLDn(qspi_dq3)
    );
    
endmodule

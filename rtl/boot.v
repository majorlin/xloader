/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: boot.v
 * Created Date: Sunday, February 23rd 2020, 9:11:07 pm
 * Author: Major Lin
 * -----
 * Last Modified: Mon Feb 24 2020
 * Modified By: Major Lin
 * -----
 * 
 * -----
 * HISTORY:
 * Date      	By           	Comments
 * ----------	-------------	----------------------------------------------------------
 * ******************************************************************************
 */

`timescale 1 ns / 100 ps
module boot
(
    input mem_clk,
    input icap_clk,
    input rst_n,
    input mem_valid, 
    input [31:0]mem_wdata,
    input [3:0]mem_addr,
    input [3:0]mem_wstrb,
    input reboot_key,
    output mem_ready,
    output [31:0]mem_rdata
);
    // write access
    reg [23:0] spi_addr = 'h80000;
    reg  reboot = 0;
    always @(posedge mem_clk or negedge rst_n) begin
        if(!rst_n) begin
            spi_addr <= 'h80000;
            reboot <= 1'b0;
        end
        else if (mem_valid & (&(mem_wstrb))) begin
            case (mem_addr)
                'h0: spi_addr <= mem_wdata;
                'h1: reboot <= mem_wdata; 
                default: begin
                    spi_addr <= spi_addr;
                    reboot <= reboot;
                end
            endcase
            end
        else begin
            spi_addr <= spi_addr;
            reboot <= reboot;
        end
    end
    // read access
    assign mem_rdata = mem_valid ? 
        mem_addr == 'h0 ? spi_addr: 
        mem_addr == 'h1 ? reboot: 
        mem_addr == 'h2 ? reboot_key: 
        32'h0 : 32'h0; 
    assign mem_ready = mem_valid;

    multiboot icap (
        .clk_icap(icap_clk),
        .spi_addr(spi_addr),
        .REBOOT(reboot)
    );
endmodule

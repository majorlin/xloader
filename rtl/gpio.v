/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: gpio.v
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
module gpio #(
	parameter TOTAL_GPIOS = 8
)
(
    input mem_clk,          // gpio memory access and module clock
    input rst_n,
    input mem_valid,        // Module valid
    input [31:0]mem_wdata,
    input [3:0]mem_addr,
    input [3:0]mem_wstrb,
    input [TOTAL_GPIOS-1:0] gpio_ind,
    output [TOTAL_GPIOS-1:0] gpio_do,
    output [TOTAL_GPIOS-1:0] gpio_obe,
    output mem_ready,
    output [31:0]mem_rdata
);
    reg [TOTAL_GPIOS-1:0] PDOR;
    reg [TOTAL_GPIOS-1:0] PDDR;
    // write access
    always @(posedge mem_clk or negedge rst_n) begin
        if(!rst_n) begin
            PDOR <= 32'h0;
            PDDR <= 32'h0;
        end
        else if (mem_valid & (&(mem_wstrb))) begin
            case (mem_addr)
                'h0: PDOR <= mem_wdata;
                'h1: PDOR <= PDOR | mem_wdata; // set output
                'h2: PDOR <= PDOR & (~mem_wdata); // clear output
                'h3: PDOR <= PDOR & (~mem_wdata) | ((~(PDOR & mem_wdata))& mem_wdata); // toggle output
                'h5: PDDR <= mem_wdata; // output direction
                default: begin
                    PDOR <= PDOR;
                    PDDR <= PDDR;
                end
            endcase
            end
        else begin
            PDOR <= PDOR;
            PDDR <= PDDR;
        end
    end
    // read access
    assign mem_rdata = mem_valid ? 
        mem_addr == 'h0 ? PDOR : 
        mem_addr == 'h3 ? PDDR : 
        mem_addr == 'h4 ? gpio_ind : 
        32'h0 : 32'h0; 
    assign mem_ready = mem_valid;

    assign gpio_obe = PDDR;
    assign gpio_do = PDOR;

endmodule

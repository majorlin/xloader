/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: icap_reboot.v
 * Created Date: Monday, March 30th 2020, 10:14:07 pm
 * Author: Major Lin
 * -----
 * Last Modified: Tue Mar 31 2020
 * Modified By: Major Lin
 * -----
 * 
 * -----
 * HISTORY:
 * Date      	By           	Comments
 * ----------	-------------	----------------------------------------------------------
 * ******************************************************************************
 */


module icap_reboot(
    input clk,
    input reboot
);
wire busy;
reg[15:0] wdata;
reg icap_en = 0;
reg [3:0] cnt = 0;

always @(posedge clk) begin
    if(!reboot) begin
        icap_en <= 1'b0;
        cnt <= 4'h0;
    end else begin
        icap_en <= 1'b1;
        cnt <= cnt + 4'h1;
    end
end

always @(*) begin
    case(cnt)
        4'h0: wdata = 16'hFFFF; // Dummy word
        4'h1: wdata = 16'hFFFF; // Dummy word
        4'h2: wdata = 16'h5599; // 16'hAA99; // Sync word
        4'h3: wdata = 16'hAA66; // 16'h5566; // Sync word
        4'h4: wdata = 16'h3261; // General 1
        4'h5: wdata = 16'h0000; // Boot start address [15:0]
        4'h6: wdata = 16'h3281; // General 2
        4'h7: wdata = 16'h0008; // Opcode and boot start address [23:16]
        4'h8: wdata = 16'h32A1; // General 3
        4'h9: wdata = 16'h0000; // Fallback start address [15:0]
        4'hA: wdata = 16'h32C1; // General 4
        4'hB: wdata = 16'h0000; // Opcode and fallback start address [23:16]
        4'hC: wdata = 16'h30A1; // CMD 
        4'hD: wdata = 16'h000E; // IPROG command
        4'hE: wdata = 16'h2000; // NO OP
        4'hF: wdata = 16'h2000; // NO OP
        default: wdata = 16'h2000; // NO OP
    endcase
end

X_ICAP_SPARTAN6 #(
    .DEVICE_ID(32'h04002093)
) icap (
    .BUSY(),
    .O(),
    .CE(),
    .CLK(clk),
    .I(),
    .WRITE()
);
endmodule
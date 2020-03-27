`timescale 1 ns / 1 ps

module uart_vip #(
    parameter CLK_HZ = 12_000_000,
    parameter BAUDRATE = 115200
) (
    input clk,
    input uart_rx
);
	localparam uart_half_period = CLK_HZ / BAUDRATE / 2;
	event uart_sample;

	reg [7:0] buffer = 0;

	always begin
		@(negedge uart_rx);

		repeat (uart_half_period) @(posedge clk);
		-> uart_sample; // start bit

		repeat (8) begin
			repeat (uart_half_period) @(posedge clk);
			repeat (uart_half_period) @(posedge clk);
			buffer = {uart_rx, buffer[7:1]};
			-> uart_sample; // data bit
		end

		repeat (uart_half_period) @(posedge clk);
		repeat (uart_half_period) @(posedge clk);
		-> uart_sample; // stop bit

	    $write("%c", buffer);
	end
endmodule

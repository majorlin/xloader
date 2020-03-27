
//  Xilinx Single Port Byte-Write Write First RAM
//  This code implements a parameterizable single-port byte-write write-first memory where when data
//  is written to the memory, the output reflects the new memory contents.
//  If a reset or enable is not necessary, it may be tied off or removed from the code.
//  Modify the parameters for the desired RAM characteristics.

// The following is an instantiation template for xilinx_single_port_byte_write_ram_write_first
/*
//  Xilinx Single Port Byte-Write Write First RAM
sram_byte_en_model #(
    .NB_COL(4),        // Specify number of columns (number of bytes)
    .COL_WIDTH(8),     // Specify column width (byte width, typically 8 or 9)
    .RAM_DEPTH(512),   // Specify RAM depth (number of entries)
    .INIT_FILE("")     // Specify name/location of RAM initialization file if using one (leave blank if not)
) u_sram (
    .addra(addra),     // Address bus, width determined from RAM_DEPTH
    .dina(dina),       // RAM input data, width determined from NB_COL*COL_WIDTH
    .clka(clka),       // Clock
    .wea(wea),         // Byte-write enable, width determined from NB_COL
    .ena(ena),         // RAM Enable, for additional power savings, disable port when not in use
    .douta(douta),     // RAM output data, width determined from NB_COL*COL_WIDTH
);
*/

module sram_byte_en_model #(
    parameter NB_COL = 4,                           // Specify number of columns (number of bytes)
    parameter COL_WIDTH = 8,                        // Specify column width (byte width, typically 8 or 9)
    parameter RAM_DEPTH = 8192,                     // Specify RAM depth (number of entries)
    parameter INIT_FILE = "./code/build/firmware.hex"  // Specify name/location of RAM initialization file if using one (leave blank if not)
) (
    input [clogb2(RAM_DEPTH-1)-1:0] addra,  // Address bus, width determined from RAM_DEPTH
    input [(NB_COL*COL_WIDTH)-1:0] dina,  // RAM input data
    input clka,                           // Clock
    input [NB_COL-1:0] wea,               // Byte-write enable
    input ena,                            // RAM Enable, for additional power savings, disable port when not in use
    output [(NB_COL*COL_WIDTH)-1:0] douta          // RAM output data
);

reg [(NB_COL*COL_WIDTH)-1:0] mem [RAM_DEPTH-1:0]/*synthesis syn_ramstyle = "block_ram" */;
reg [(NB_COL*COL_WIDTH)-1:0] q = {(NB_COL*COL_WIDTH){1'b0}};

// The following code either initializes the memory values to a specified file or to all zeros to match hardware
generate
    if (INIT_FILE != "") begin: use_init_file
    initial
        $readmemh(INIT_FILE, mem, 0, RAM_DEPTH-1);
    end else begin: init_bram_to_zero
        integer ram_index;
        initial
            for (ram_index = 0; ram_index < RAM_DEPTH; ram_index = ram_index + 1)
            mem[ram_index] = {(NB_COL*COL_WIDTH){1'b0}};
    end
endgenerate

always @(posedge clka)
    if (ena) 
        q <= mem[addra];
    else
        q <= 'h0;


generate
    genvar i;
    for (i = 0; i < NB_COL; i = i+1) begin: byte_write
        always @(posedge clka)
            if (ena)
                if (wea[i]) begin
                    mem[addra][(i+1)*COL_WIDTH-1:i*COL_WIDTH] <= dina[(i+1)*COL_WIDTH-1:i*COL_WIDTH];
                end
        end // for
endgenerate

    // The following is a 1 clock cycle read latency at the cost of a longer clock-to-out timing
    assign douta = q;
    // assign douta = ena ? mem[addra] : {(NB_COL*COL_WIDTH){1'b0}};

    //  The following function calculates the address width based on specified RAM depth
    function integer clogb2;
        input integer depth;
        for (clogb2=0; depth>0; clogb2=clogb2+1)
            depth = depth >> 1;
    endfunction

endmodule


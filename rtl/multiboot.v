module multiboot (
    input wire clk_icap,
	input wire REBOOT
);
              
    reg [23:0] spi_addr = 24'h080000;  // SPI address of the bitstream
    reg [4:0] q = 5'b00000;
    reg reboot_ff = 1'b0;

    always @(posedge clk_icap) begin
      q[0] <= REBOOT; q[1] <= q[0]; q[2] <= q[1]; q[3] <= q[2]; q[4] <= q[3];
      reboot_ff <= (q[4] && (!q[3]) && (!q[2]) && (!q[1]) );
    end
	 
    multiboot_spartan6 multiboot (
        .CLK(clk_icap),
        .MBT_RESET(1'b0),
        .MBT_REBOOT(reboot_ff),
        .spi_addr(spi_addr)
    );
endmodule            
    
module multiboot_spartan6 (
    input wire CLK,
    input wire MBT_RESET,
    input wire MBT_REBOOT,
    input wire [23:0] spi_addr
  );

reg  [15:0] icap_din;
reg         icap_ce;
reg         icap_wr;

reg  [15:0] icapd_r;
reg         ff_icap_ce;
reg         ff_icap_wr;

  ICAP_SPARTAN6 ICAP_SPARTAN6_inst (
  
    .CE        (ff_icap_ce),
    .CLK       (CLK),
    .I         (icapd_r), 
    .WRITE     (ff_icap_wr)
  );

//  ICAP FSM
parameter         
	IDLE     = 0, 
	SYNC_H   = 1,  SYNC_L   = 2,      
	CWD_H    = 3,  CWD_L    = 4,  
	GEN1_H   = 5,  GEN1_L   = 6,  
	GEN2_H   = 7,  GEN2_L   = 8,  
	GEN3_H   = 9,  GEN3_L   = 10, 
	GEN4_H   = 11, GEN4_L   = 12, 
	GEN5_H   = 13, GEN5_L   = 14, 
	NUL_H    = 15, NUL_L    = 16, 
	MOD_H    = 17, MOD_L    = 18, 
	HCO_H    = 19, HCO_L    = 20, 
	RBT_H    = 21, RBT_L    = 22, 
	NOOP_0   = 23, NOOP_1   = 24,
	NOOP_2   = 25, NOOP_3   = 26;
                   
reg [4:0]     state;
reg [4:0]     next_state;

always @*
   begin: COMB
      case (state)
         IDLE:
            begin
               if (MBT_REBOOT)
                  begin
                     next_state  = SYNC_H;
                     icap_ce     = 0; icap_wr     = 0;
                     icap_din    = 16'hAA99;  // Sync1 
                  end
               else
                  begin
                     next_state  = IDLE;
                     icap_ce     = 1; icap_wr     = 1;
                     icap_din    = 16'hFFFF;
                  end
            end          
        SYNC_H:
            begin
               next_state  = SYNC_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h5566;    // Sync2
            end
        SYNC_L:
            begin
               next_state  = NUL_H;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h30A1;   
            end
        NUL_H:
            begin
              // next_state  = NUL_L;
	       next_state  = GEN1_H;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h0000;   // Null 
            end
        GEN1_H:
            begin
               next_state  = GEN1_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h3261;    // reg GENERAL_1
            end
        GEN1_L:
            begin
               next_state  = GEN2_H;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = spi_addr[15:0]; // SPI BAJA
            end

        GEN2_H:
            begin
               next_state  = GEN2_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h3281;   // reg GENERAL_2
            end

        GEN2_L:
            begin
               next_state  = MOD_H;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = {8'h6B, spi_addr[23:16]}; //  SPI opcode + SPI ALTA 
            end
        MOD_H: 	 // Registro MODE (4x tras reboot)
            begin
               next_state  = MOD_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h3301;   // reg MODE
            end

        MOD_L:
            begin
               next_state  = NUL_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h3100; // bit lectura 4x
            end				
        NUL_L:
            begin
               next_state  = RBT_H;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h30A1;   
            end
        RBT_H:
            begin
               next_state  = RBT_L;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h000E;    // REBOOT
            end
        RBT_L:
            begin
               next_state  = NOOP_0;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h2000;    //  NOOP
            end
        NOOP_0:
            begin
               next_state  = NOOP_1;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h2000;    // NOOP
            end
        NOOP_1:
            begin
               next_state  = NOOP_2;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h2000;    // NOOP
            end
        NOOP_2:
            begin
               next_state  = NOOP_3;
               icap_ce     = 0; icap_wr     = 0;
               icap_din    = 16'h2000;    // NOOP
            end
        NOOP_3:
            begin
               next_state  = IDLE;
               icap_ce     = 1; icap_wr     = 1;
               icap_din    = 16'h1111;    // NULL
            end       
        default:
            begin
               next_state  = IDLE;
               icap_ce     = 1; icap_wr     = 1;
               icap_din    = 16'h1111;
            end
      endcase
   end

always @(posedge CLK)

   begin: SEQ
      if (MBT_RESET)
         state <= IDLE;
      else
         state <= next_state;
   end

always @(posedge CLK)

   begin:   ICAP_FF
	//reverse bits to ICAP. D0 bit is read first   
        icapd_r[0]  <= icap_din[7];  icapd_r[1]  <= icap_din[6]; 
        icapd_r[2]  <= icap_din[5];  icapd_r[3]  <= icap_din[4]; 
        icapd_r[4]  <= icap_din[3];  icapd_r[5]  <= icap_din[2]; 
        icapd_r[6]  <= icap_din[1];  icapd_r[7]  <= icap_din[0]; 
        icapd_r[8]  <= icap_din[15]; icapd_r[9]  <= icap_din[14];
        icapd_r[10] <= icap_din[13]; icapd_r[11] <= icap_din[12];
        icapd_r[12] <= icap_din[11]; icapd_r[13] <= icap_din[10];
        icapd_r[14] <= icap_din[9];  icapd_r[15] <= icap_din[8]; 
        ff_icap_ce  <= icap_ce; ff_icap_wr  <= icap_wr;
   end       
endmodule

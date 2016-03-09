
module led_control(
	input i_gnd,
	input i_clock,
	output o_gnd,
	output o_clock
	);

  assign o_gnd = i_gnd;
  assign o_clock = i_clock;

endmodule

module count(
	input i_count,
	output [26:0] o_clk
	);

	

endmodule

module pisca;

	led_control ld(i_gnd,i_clock,o_gnd,o_clock);

	reg i_gnd, ;
	
	wire 
		o_gnd,
		o_clock
	;

    always #1 i_clock = ~i_clock;

  
  initial begin
    $dumpvars(0, ld);
    #10;
    i_gnd <= 1'b0;
    i_clock <=  1'b0;
    #500;
    $finish;
  end
endmodule

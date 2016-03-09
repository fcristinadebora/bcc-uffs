module counter(
	input  ,
	output q
);

	reg [26:0]count, state;
	wire q;

	assign q = state;

	always@(posedge clock) begin
		if(count == 26'd50000000000)
			begin	
				count <= 26'd0;
				//reseta o count
				if(state == 1)
					state <= 1'b0;//muda estado							
				else		
					state <= 1'b1;//muda estado
				
			end
		else
			begin
				//incrementa count
				count <= count + 1;
			end
	end

endmodule

// input CLOCK_50
// input [0:0] KEY
// output [0:0] LEDG



module led_test;

	counter cnt();
	
	initial begin
		$dumpvars(0, clock);
		clock

		$finish;
	end  	
  $dumpvars(0, ld);
    #10;
    i_gnd <= 1'b0;
    i_clock <=  1'b0;
    #500;
    $finish;
  

endmodule

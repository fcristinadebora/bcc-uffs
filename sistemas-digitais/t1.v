module clock;

	reg clk;

	always #1 clk = ~clk;

	initial begin
		$dumpvars(0,clk);
			clk <= 0;
			#200;
		$finish;
	end

endmodule

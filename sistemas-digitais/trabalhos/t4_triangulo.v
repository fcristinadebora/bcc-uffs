module main(
	input [9:0]ax,
	input [9:0]ay,
	input [9:0]bx,
	input [9:0]by,
	input [9:0]cx,
	input [9:0]cy
	);

	reg [9:0]px;
	reg [9:0]py;
	reg [18:0]detABC;
	reg [18:0]detABP;
	reg [18:0]detAPC;
	reg [18:0]detPBC;
	reg [9:0]y;
	reg [9:0]x;
	reg [9:0]MAX_LINHAS=9'd50;
	reg [9:0]MAX_COLUNAS=9'd75;
	reg [18:0]dPrincipal;
	reg [18:0]dSecundaria;
	 
	wire [9:0]ax;
	wire [9:0]ay;
	wire [9:0]bx;
	wire [9:0]by;
	wire [9:0]cx;
	wire [9:0]cy;

	assign ax = 9'd0;
	assign ay = 9'd0;
	assign bx = 9'd10;
	assign by = 9'd0;
	assign cx = 9'd0;
	assign cy = 9'd30;
   
	initial begin
		
		//detABC
		assign dPrincipal = ((ax*by)+(ay*cx)+(bx*cy));
		assign dSecundaria = ((by*cx)+(ax*cy)+(ay*bx));
		
		if (dPrincipal > dSecundaria)
			detABC = dPrincipal - dSecundaria;
		else
			detABC = dSecundaria - dPrincipal;
		//Fim detABC
		
		for (y=MAX_LINHAS+1;y>0;y=y-1) begin
			py = y-1;
			for (x=0;x<MAX_COLUNAS+1;x=x+1) begin
				px = x;
					
				//detABP
				assign dPrincipal = ((ax*by)+(ay*px)+(bx*py));
				assign dSecundaria = ((by*px)+(ax*py)+(ay*bx));
		
				if (dPrincipal > dSecundaria)
				detABP = dPrincipal - dSecundaria;
				else
				detABP = dSecundaria - dPrincipal;
				//Fim detABP

				//detAPC
				assign dPrincipal = ((ax*py)+(ay*cx)+(px*by));
				assign dSecundaria = ((py*cx)+(ax*cy)+(ay*px));        
		
				if (dPrincipal > dSecundaria)
				detAPC = dPrincipal - dSecundaria;
				else
				detAPC = dSecundaria - dPrincipal;
				//Fim detAPC

				//detPBC
				assign dPrincipal = ((px*by)+(py*cx)+(bx*cy));
				assign dSecundaria = ((by*cx)+(px*cy)+(py*bx));        
		
				if (dPrincipal > dSecundaria)
					detPBC = dPrincipal - dSecundaria;
				else
					detPBC = dSecundaria - dPrincipal;
				//Fim detPBC

				if(detABC < (detABP+detAPC+detPBC))
					$write("-");
				else
					$write(" ");
		end

		$display("");
		end


      $finish ;
    end
endmodule

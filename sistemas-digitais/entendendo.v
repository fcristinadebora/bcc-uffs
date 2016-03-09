module AluSeq(//começo das variáveis "locais"
  input clk, 
  input [7:0] a, //da pra dizer que as entradas terão oito fios, de 0 a 7
  input [7:0] b, 
  input [1:0] op, 
  output [7:0] c);//e uma saída de 8 fios.

  reg [7:0] c_reg;

// por que ele precisa criar um registro dentro da função?
//ans: é ela que vai receber um valor, dependendo do operador, e depois esse operador vai sair em "c"

  assign c = c_reg;//como visto aqui



// a partir daqui da pra ver os condicionais da ULA
  always @(posedge clk) begin
//aqui diz que essa condicional é sensível a subida(ou descida?) de clock.
    case (op)
      0: c_reg <= a + b;
      1: c_reg <= a - b;
      2: c_reg <= a & b;
      3: c_reg <= a | b;
      default: c_reg <= 0;
//mesmo efeito que o case do C
    endcase
  end
//e é isso aí
endmodule

module test(output v); // pra que essa saída v?

  reg clk; //cria-se um registrador clk
  always #3 clk <= ~clk;//a cada 3 unidades arbitrárias clock recebe a negação dele

  reg [7:0] a;
  reg [7:0] b;
  reg [1:0] op;
// ele criou os registradores, depois associou com as variáveis fazendo um call na função
  wire [7:0] c;
//foi criado esse fio, que será a saída do modulo "alu"

  AluSeq A(clk, a, b, op, c);//aqui será a chamada pra alu


  initial begin
    $dumpvars(0, A);
    #2;
    clk <= 0;
    #10;
    a <= 7;
    b <= 3;
    op <= 0;
    #20;
    op <= 1;
    #30;
    op <= 2;
    #40;
    op <= 3;
    #50;
    op <= 0;
    #500;
    $finish;
  end
endmodule

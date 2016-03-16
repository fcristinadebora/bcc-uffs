#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x,y;
}ponto;

unsigned int determinante(ponto triA, ponto triB, ponto triC);

int main(){
	unsigned matriz[800][600],i, detABC, detABP, detAPC, detPBC;
	ponto tri[3], p;

	for(i=0;i<3;i++){
		printf("Digite as coordenadas xy do ponto %d\n", i);
		scanf("%d %d", &tri[i].x, &tri[i].y);
	}

	detABC = determinante(tri[0], tri[1], tri[2]);
	if(!detABC){ //Se det = 0, pontos alinhados e não formam triângulo
		return 0;
	}

	printf("Digite as coordenadas xy do ponto P\n");
	scanf("%d %d", &p.x, &p.y);

	detABC = determinante(tri[0], tri[1], tri[2]);
	detABP = determinante(tri[0], tri[1], p);
	detAPC = determinante(tri[0], p, tri[2]);
	detPBC = determinante(p, tri[1], tri[2]);

	if(detABC != (detABP + detAPC + detPBC)){
		printf("Ponto não pertence ao triângulo\n");
	}else{
		printf("Ponto pertence ao triângulo\n");
	}

	return 0;
}

//Calcula a determinante das coordenadas
unsigned int determinante(ponto triA, ponto triB, ponto triC){
	int diagonalPrincipal, diagonalOposta;

	diagonalPrincipal = (triA.x*triB.y)+(triA.y*triC.x)+(triB.x*triC.y);
	diagonalOposta = (triB.y*triC.x)+(triA.x*triC.y)+(triA.y*triB.x);

	if(diagonalPrincipal>diagonalOposta){
		return diagonalPrincipal - diagonalOposta;
	}else{
		return diagonalOposta - diagonalPrincipal;
	}
}
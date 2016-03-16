#include <stdio.h>
#include <stdlib.h>

#define M_X 70
#define M_Y 50

typedef struct ponto{
	int x,y;
}ponto;

int determinante(ponto triA, ponto triB, ponto triC);

int main(){
	int y, x, detABC, detABP, detAPC, detPBC;
	ponto tri[3], p, k;

	for(y=0;y<3;y++){
		scanf("%d %d", &tri[y].x, &tri[y].y);
	}

	detABC = determinante(tri[0], tri[1], tri[2]);
	if(!detABC){ //Se det = 0, pontos alinhados e não formam triângulo
		return 0;
	}

	detABC = determinante(tri[0], tri[1], tri[2]);

	for(y=M_Y;y>0;y--){
		for(x=0;x<M_X;x++){
			p.x = x;
			p.y = y;
	
			detABP = determinante(tri[0], tri[1], p);
			detAPC = determinante(tri[0], p, tri[2]);
			detPBC = determinante(p, tri[1], tri[2]);
	
			if(detABC != (detABP + detAPC + detPBC)){
				printf("-");
			}else{
				printf(" ");
			}
	
		}
		printf("\n");
	}
	
	return 0;
}

//Calcula a determinante das coordenadas
int determinante(ponto triA, ponto triB, ponto triC){
	int diagonalPrincipal, diagonalOposta;

	diagonalPrincipal = (triA.x*triB.y)+(triA.y*triC.x)+(triB.x*triC.y);
	diagonalOposta = (triB.y*triC.x)+(triA.x*triC.y)+(triA.y*triB.x);

	if(diagonalPrincipal>diagonalOposta){
		return diagonalPrincipal - diagonalOposta;
	}else{
		return diagonalOposta - diagonalPrincipal;
	}
}

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int *p, *pAux, num, controle, aux=0,i;

	p = (int*)malloc(5*sizeof(int));
	if(p == NULL){
		printf("Erro: memória insuficiente");
		return 0;
	}

	controle = 5; //Tem 5 alocações para ocupar
	while(scanf("%d", (int*)(p+aux))){
		if(!controle){
			pAux = p;
			if(realloc(pAux,5*sizeof(int)) == NULL){
				printf("Erro: memória insuficiente");
				break;
			}
			controle = 5;
			
		}
	controle--;
	}

	return 0;
}

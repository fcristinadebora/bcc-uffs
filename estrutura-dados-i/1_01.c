#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int *p, *pAux, *pAux2, num, controle, aux=0;

	p = (int*)malloc(5*sizeof(int));
	pAux = p;
	if(p == NULL){
		printf("Erro: memória insuficiente");
		return 0;
	}

	controle = 5; //Tem 5 alocações para ocupar
	while(scanf("%d", &p[aux])){
		if(!controle){
			pAux = p+aux;
			printf("Realocou\n");
			if((int*)realloc(pAux,5*sizeof(int)) == NULL){
				printf("Erro: memória insuficiente");
				break;
			}
			controle = 5;
			
		}
	controle--;
	aux++;
	}

	return 0;
}

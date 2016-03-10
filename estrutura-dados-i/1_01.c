#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int *p, num, controle, aux=0;

	p = (int*)malloc(5*sizeof(int));
	if(p == NULL){
		printf("Erro: memória insuficiente");
		return 0;
	}
	controle = 5; //Tem 5 alocações para ocupar
	while(scanf("%d", &p[aux])){
		if(!controle){
			p = realloc(p,(aux + 6)*sizeof(int));			
			printf("Realocou, %p\n", p);
			if(p == NULL){
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

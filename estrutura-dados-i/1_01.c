#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int *p, num, controle, aux=0,i;

	p = (int*)malloc(5*sizeof(int));

	controle = 5; //Tem 5 alocações para ocupar
	while(scanf("%d", (int*)(p+aux))){
		if(!controle){
			realloc(p,5*sizeof(int));
			controle = 5;
		}
	controle--;
	aux++;
	}

	return 0;
}
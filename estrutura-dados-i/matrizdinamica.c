#include <stdlib.h>
#include <stdio.h>

#define MAX_LINHAS 10;
#define MAX_COLUNAS 10;


int main(){
	int i, j, nLinhas, nColunas, **pMatriz;
  
	nLinhas = rand() % MAX_LINHAS;

	/* aloca as linhas da matriz */
	pMatriz =  malloc(nLinhas * sizeof(int));
	if (pMatriz == NULL) {
		printf ("Erro: Memoria Insuficiente");
		return 0;
	}
	
	/* aloca as colunas da matriz */
	for (i=0;i<nLinhas;i++) {
		nColunas = rand() % MAX_COLUNAS;
		pMatriz[i] =  malloc(nColunas * sizeof(int));
		if (pMatriz[i] == NULL) {
			printf ("Erro: Memoria Insuficiente");
			return 0;
		}

		printf("%p: ", pMatriz[i]);
		for(j=0;j<nColunas;j++){
			pMatriz[i][j] = rand() % 10;
			printf("%d ", pMatriz[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}

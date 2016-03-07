#include <stdlib.h>
#include <stdio.h>

#define MAX_LINHAS 10;
#define MAX_COLUNAS 2;


int main(){
	int nColunas, nLinhas, i, j;

	//Obtém randomicamente o número de linhas
	//nLinhas = rand() % MAX_LINHAS;
	nLinhas = 3;

	int *p[3];

	*p[0] = 1;
	*p[1] = 2;
	*p[2] = 3;

	int **pLinhas = (int**) malloc(nLinhas * sizeof(int));

	pLinhas[0] = p;
	pLinhas[1] = p;
	pLinhas[2] = p;

	for(i=0;i<nLinhas;i++){
		printf("%p: %d\n", pLinhas[i], *pLinhas[i]);
	}

	/*
	for(i=0;i<nLinhas;i++){
		//Obtém randomicamente o número de colunas
		nColunas = rand() % MAX_LINHAS;
		
		printf("%p\n", pLinhas);
	}
	*/

	return 0;
}
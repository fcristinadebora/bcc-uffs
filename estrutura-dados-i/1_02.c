#include <stdlib.h>
#include <stdio.h>

#define MAX_ELEMENTOS 10

int* uniao(int *v1, int n1, int *v2, int n2);

int main(){
	int n1, n2, i, *p;

	//Gera randomicamente o tamanho dos vetores
	n1 = rand() % MAX_ELEMENTOS;
	n2 = rand() % MAX_ELEMENTOS;

	//Vetores
	int v1[n1], v2[n2];

	//Preenche os vetores
	for(i=0;i<n1;i++){
		v1[i] = rand() % 10;
	}
	for(i=0;i<n2;i++){
		v2[i] = rand() % 10;
	}

	p = uniao(v1, n1, v2, n2);
	if(p == NULL){
		return 0;
	}
	

	for(i=0;i<(n1+n2);i++){
		printf("%d ", p[i]);
	}
	printf("\n");

	free(p);

	return 0;
}

int* uniao(int *v1, int n1, int *v2, int n2){
	int i;
	int *p = (int*)malloc((n1+n2)*sizeof(int));
	if(p == NULL){
		printf("Erro: memória insuficiente");
		return NULL;
	}

	for(i=0;i<n1;i++){
		p[i] = v1[i];
	}
	for(i=0;i<n2;i++){
		p[i+n1] = v2[i];
	}

	return p;
}

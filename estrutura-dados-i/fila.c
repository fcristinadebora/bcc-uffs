#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
	int num;
	node no;

	node *pHead = init();
	
	printf("Digite um número ou um caractere diferente para parar");
	while(scanf("%d",&num)){
		
		}
		printf("\n");
	};
}

void printaFila(node *p){
	/*
	*Printa todos os elementos da fila
	*pHead: primeira posição da fila
	*/
	int i = 1;
	while(p != NULL){
		printf("%d - %p: %d\n", i, p, p->num);
		p = p->prox;
		i++;
	}
	printf("\n");
}

int verificaAlocacao(node *p){
	/*
	*Verifica se a alocação foi bem sucedida
	*p: Endereço da alocação
	*Return 1: True, bem sucedida
	*Return 0: False, falhou
	*/
	if(p==NULL){
		printf("Erro: memória insuficiente");
		return 0;
	}

	return 1;
}

node * init(){
	//Inicializa a fila
	return NULL;
}

node * pushCrescente(node * pHead){
	/*
	*Aloca um nó no fim da fila
	*pTail: fim da fila
	*Return NULL: Operação sem sucesso
	*Return p: Retorna ponteiro para a posição alocada
	*/
	node *p = (node*)malloc(sizeof(node));
	
	if(*pTail != NULL){ //Se primeiro push
		(*pTail)->prox = p;
	}
	
	if(!verificaAlocacao(p)){
		return NULL;
	}
	
	*pTail = p;
	(*pTail)->prox = NULL;
	return p;
}

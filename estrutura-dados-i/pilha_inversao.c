#include <stdio.h>
#include <stdlib.h>

typedef struct item{
	char conteudo;
	void *prox;
}item;

//Protótipo das funções
item* push(); //Adiciona mais um item na pilha
int pop(item *pHead); //Remove ultimo item da pilha
void verificaAlocacao(item *p);

int main(){
	item *pHead, *p;
	
	//Inicia a lista
	pHead = push();
	
	//Ponteiro auxiliar
	p = pHead;
	scanf("%c",&p->conteudo);

	while(p->conteudo != '\n'){
		p->prox = push();
		p = p->prox;
		scanf("%c",&p->conteudo);
	}

	while(pop(pHead));

	printf("\n");

	return 0;
}

item * push(){
	//Aloca mais um espaço dinâmico de mem.
	item *p = (item*) malloc(sizeof(item));

	//Verifica se a alocação foi bem sucedida
	verificaAlocacao(p);

	//Retorna endereço da alocação
	return p;
}

int pop(item *pHead){
	//Return 0 = Lista vazia
	//Return 1 = ainda há elementos

	item *p, *pAnt;

	if(pHead->prox==NULL){ //Se a cabeça não aponta pra nada
		printf("%c", pHead->conteudo);
		return 0;
	}

	p = pHead;
	while(p->prox != NULL){
		pAnt = p;
		p = pAnt->prox;
	}

	pAnt->prox = NULL;
	if(p->conteudo != '\n'){
		printf("%c", p->conteudo);
	}
	free(p);
	
	return 1;
}

void verificaAlocacao(item *p){
	if(p == NULL){
		printf("Falha na alocação\n");
		exit(0);
	}
}
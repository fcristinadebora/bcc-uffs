#include <stdio.h>
#include <stdlib.h>

typedef struct item{
	char conteudo;
	void *prox;
}item;

item *push();
//item *pop(char it);
int verificaAlocacao(item *p);

int main(){
	item *pHead = NULL, *pAuxiliar = NULL;
	int i;

	pHead = push();
	scanf("%c", &pHead->conteudo);
	pHead->prox = NULL;

	pAuxiliar = pHead;
	do{
		if(pAuxiliar->conteudo == '.'){
			pAuxiliar->prox = NULL;
			break;
		}else{
			scanf("%c", &pAuxiliar->conteudo);
			pAuxiliar->prox = push();
		}				
	}while(1);

	printf("%c\n", pHead->conteudo);

	//while(scanf())

	return 0;
}

int verificaAlocacao(item *p){
	//Se o ponteiro é igual NULL, retorna False (0)
	if(p == NULL){
		printf("Erro: falha na alocação.\n");
		exit(0);
	} 		

	return 1; //Else, retorna  True (1)
}

//Aloca uma posição de memória e retorna o ponteiro para ela
item *push(){
	item *p = (item*)malloc(sizeof(item));
	verificaAlocacao(p);

	return p;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct item{
	char conteudo;
	void *prox;
}item;

void *push();
//item *pop(char it);
int verificaAlocacao(item *p);

int main(){
	item *pHead = NULL, *pAuxiliar = NULL;
	int count=0,i;

	pHead = push();
	scanf("%c", &pHead->conteudo);
	getchar();
	pHead->prox = NULL;

	pAuxiliar = pHead;
	do{
		if(pAuxiliar->conteudo == '.'){
			pAuxiliar->prox = NULL;
			break;
		}else{
			scanf("%c", &pAuxiliar->conteudo);
			getchar();
			printf("%c foi alocado em %p\n", pAuxiliar->conteudo, pAuxiliar->prox);
			pAuxiliar->prox = push();
		}
	count++;			
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
void *push(){
	void *p = malloc(sizeof(item));
	verificaAlocacao(p);

	return p;
}
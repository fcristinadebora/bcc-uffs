#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
	int num;
	node no;

	node *pHead = initL();
	printf("initL();\n");
	
}

int verificaAlocacao(node *p){
	if(p==NULL)
		return 0;

	return 1;
}

int isEmpty(node *pHead){
	if(pHead == NULL)
		return 0;

	return 1;
}

node * initL(){
	return NULL;
}

node * insereInicio(node ** pHead){
	node *p = (node*)malloc(sizeof(node));
	
	if(isEmpty(*pHead))
}
node * inserePos(node ** pHead, int num);
node * insereFim(node ** pTail);
node removeInicio(node ** pHead);
node removePos(node ** pHead, int num);
node removeFim(node ** pHead);
void printaL(node * pHead);



#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int valor;
  struct node *esq, *dir;
}raiz;


int menu(){
  int op;
  printf("Selecione uma opção:\n");
  printf("1 - Inserir elemento na arvore\n");
  printf("2- Imprimir arvore\n");
  printf("3- Remover elemento\n");
  printf("4- Sair\n");
  printf("Op: "); scanf("%d", &op);
  return op;
}

void imprimePonto(int n){
  int i;
  for (i = 0; i < n; i++) printf(".");
}

int lerValor(){
  int valor;
  printf("Informe o valor: ");
  scanf("%d", &valor);
  return valor;
}

void inserirFolha(raiz **arvore, int valor){
  if (*arvore == NULL){
    (*arvore) = (raiz *)malloc(sizeof(raiz));
    (*arvore)->valor = valor;
    (*arvore)->esq = (*arvore)->dir = NULL;
    return ;
  }
  if (valor < (*arvore)->valor){ inserirFolha(&(*arvore)->esq, valor); return ; }
  inserirFolha(&(*arvore)->dir, valor);
}



void imprimeArvore(raiz *arvore, int nivel){
  if (arvore == NULL) return ;
  imprimePonto(nivel * 2 + 2);
  printf("%d\n", arvore->valor);
  imprimeArvore(arvore->esq, nivel + 1);
  imprimeArvore(arvore->dir, nivel+1);
}

void finalizaArvore(raiz **arvore){
  if (*arvore == NULL) return ;
  finalizaArvore(&(*arvore)->esq);
  finalizaArvore(&(*arvore)->dir);
  *arvore = NULL;
}

raiz * removeR(raiz * pai, raiz * arvore, int num){
  if(!arvore) return NULL;

  raiz * aux, * ant;

  if(num > arvore->valor){
    arvore->dir = removeR(arvore, arvore->dir,num);

  }else if(num < arvore->valor){
    arvore->esq = removeR(arvore, arvore->esq,num);

  }else if(arvore->valor == num){ //Encontrou o valor
    if(!(arvore->dir || arvore->esq)){ //Não possui subárvores
      aux = NULL;
    }else if(arvore->esq && !arvore->dir){ //Possui subárvore à esquerda
      aux = arvore->esq;
    }else if(arvore->dir && !arvore->esq){ //Possui subárvore à direita
      aux = arvore->dir;
    }else{ //Possui duas subárvores
      //Encontra o maior elemento à esquerda
      ant = arvore; //Variável de controle
      aux = arvore->esq;
      while(aux->dir){
        ant = aux;
        aux = aux->dir;
      }

      //Reaponteiramento
      ant->esq = aux->esq;
      aux->dir = arvore->dir;
      aux->esq = arvore->esq;
    }
    
    free(arvore);
    return aux;
  }
}

int main(void){
  int op, num;
  raiz *arvore = NULL;
  inserirFolha(&arvore, 5);
  inserirFolha(&arvore, 10);
  inserirFolha(&arvore, 4);
  inserirFolha(&arvore, 15);
  inserirFolha(&arvore, 20);
  inserirFolha(&arvore, 16);
  inserirFolha(&arvore, 25);
  inserirFolha(&arvore, 3);
  inserirFolha(&arvore, 2);

  while (op = menu(), op != 4){
    switch(op){
    case 1:
      num = lerValor();
      inserirFolha(&arvore, num);
      printf("ELEMENTO INSERIDO COM SUCESSO!\n\n");
      break;

      case 2:
      printf("ARVORE IMPRESSA:\n");
      imprimeArvore(arvore, 0);
      printf("\n");
  break;
    case 3:
      num = lerValor();
      arvore = removeR(NULL, arvore, num);
      printf("ELEMENTO REMOVIDO COM SUCESSO!\n\n");
      break;
    }
  }
  finalizaArvore(&arvore);
  return 0;
}

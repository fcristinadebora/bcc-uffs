//Structs
struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

//Functions

nt verificaAlocacao(node *p);
//Verifica se alocação foi bem sucedida
//node *p: ponteiro para pos. alocada
//return 0: Falha
//return 1: Alocada com sucesso

int isEmpty(node *pHead);
//Verifica se lista está vazia
//node *p: cabeça da lista
//return 0: Vazia
//return 1: Não vazia

node * initL();
//Inicializa a lista
//return NULL

node * insereInicio(node ** pHead);


node * inserePos(node ** pHead, int pos, int n);
node * insereFim(node ** pTail, int n);
node removeInicio(node ** pHead, int n);
node removePos(node ** pHead, int num);
node removeFim(node ** pHead);
void printaL(node * pHead);
void printaPos(node * pHead, int pos);
void printaVal(node * pHead, int val);

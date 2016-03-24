//Structs
struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

//Functions
int verificaAlocacao(node *p);
node * init();
node * pushCrescente(node * pHead);
void printaFila(node * pHead);

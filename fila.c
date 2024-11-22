//estruturas//

typedef struct lista_encadeada lista_encadeada;

struct lista_encadeada {
    int dados;
    lista_encadeada *prox;  
};

typedef struct {
    lista_encadeada * prim;  
}fila;

//////////////////////////////////////////

//funçoes//
void criar_pilha(fila **p); //cria pilha
void esvaziar(fila**p); //esvazeia a lista
int pilha_vazia(fila *p);//verifica se esta vazia
void mostrar (fila *p); //mostra a pilha
void remove(fila **p); //remove um elemento
void push(fila **p,int info); //insere mais um elemento

/////////////////////////////////////////
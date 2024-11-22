#include <stdio.h> 
#include <stdlib.h>

//estruturas//

typedef struct lista_encadeada lista_encadeada;

struct lista_encadeada {
    int dados;
    lista_encadeada *prox;  
};

typedef struct {
    lista_encadeada * prim;  
}pilha;

//////////////////////////////////////////

//funçoes//
void criar_pilha(pilha **p); //cria pilha
void esvaziar(pilha**p); //esvazeia a lista
int pilha_vazia(pilha *p);//verifica se esta vazia
void mostrar (pilha *p); //mostra a pilha
void pop(pilha **p); //remove um elemento
void push(pilha **p,int info); //insere mais um elemento

/////////////////////////////////////////

//main//

int main(){
    pilha *p;

    criar_pilha(&p);
    push(&p, 4);
    mostrar(p);
    pop(&p);
    mostrar(p);
    puts("/////////////////////////");
    push(&p, 4);
    push(&p, 8);
    push(&p, 12);
    esvaziar(&p);
    mostrar(p);
    puts("////////////////////////");
    
    return 0;
}

////////////////////////////////////////

//escopo das funçoes//
void criar_pilha(pilha**p){
    
    *p = (pilha *)malloc(sizeof(pilha));
    (*p) -> prim = NULL;
}

void esvaziar(pilha**p){
    if (*p != NULL){

        while ((*p) ->prim != NULL){
            pop(p);    
        }
        puts("Lista esvaziada com sucesso");
    }else{
        puts("Lista já esta vazia");
    }
}

int pilha_vazia(pilha *p){
    
    if(p->prim== NULL){
        return 0;
    }else{
        return 1;
    }
}

void mostrar (pilha *p){
    if(p->prim == NULL){
        puts("Lista esta vazia");
    }else{
        printf("%d\n", p ->prim->dados );
        pop(&p);
    }
}

void pop(pilha **p){
    if((*p)->prim == NULL){
        puts("Lista esta vazia");
    }else{
        lista_encadeada *aux1;
        aux1 = (*p) ->prim;
        (*p)->prim = (*p) -> prim->prox;
            free(aux1);
            
    }
}

void push(pilha **p,int info){
    lista_encadeada *novo = (lista_encadeada *)malloc(sizeof(lista_encadeada));
    
    if (novo == NULL) {
        puts("Erro ao alocar memoria");
        return;
    }

    novo->dados = info;
    novo->prox = NULL;

    novo->prox = (*p)->prim;
    (*p) ->prim = novo;
    puts("Inserido com sucesso no inicio");
    
}
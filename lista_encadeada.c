#include <stdio.h> 
#include <stdlib.h>

//estruturas//

typedef struct lista_encadeada lista_encadeada;

struct lista_encadeada {
    int dados;
    lista_encadeada *prox;  
};

//////////////////////////////////////////

//funçoes//

void criar_lista(lista_encadeada **l); //cria lista
void inserir(lista_encadeada **l, int pos, int info); //insere mais um elemento
void esvaziar(lista_encadeada**l); //esvazeia a lista
void mostrar (lista_encadeada *l); //mostra a lista
void remover(lista_encadeada **l, int info); //remove um elemento


/////////////////////////////////////////

//main//

int main(){
    lista_encadeada *l;

    criar_lista(&l);
    inserir(&l,0,3);
    inserir(&l,1,2);
    inserir(&l,0,5);
    inserir(&l,2,6);
    mostrar(l);
    remover(&l,3);
    puts("////////////////////////");
    mostrar(l);
    esvaziar(&l);
    mostrar(l);
    esvaziar(&l);
    
    return 0;
}

////////////////////////////////////////

//escopo das funçoes//

void criar_lista(lista_encadeada **l){
    *l = 0;
}

void inserir(lista_encadeada **l, int pos, int info) {
    lista_encadeada *novo = (lista_encadeada *)malloc(sizeof(lista_encadeada));
    lista_encadeada *aux1 = *l;
    int cont = 0;
    
    if (novo == NULL) {
        puts("Erro ao alocar memoria");
        return;
    }
    novo->dados = info;
    novo->prox = NULL;

    if (pos == 0) {  // Inserção no início
        novo->prox = *l;
        *l = novo;
        puts("Inserido com sucesso no inicio");
        return;
    }

    // Encontrar a posição para inserir
    while (aux1 != NULL && cont < pos - 1) {
        aux1 = aux1->prox;
        cont++;
    }

    if (aux1 == NULL) {
        puts("Erro, posicao invalida");
        free(novo);
    } else {
        // Inserir no meio ou no final
        novo->prox = aux1->prox;
        aux1->prox = novo;
        puts("Inserido com sucesso");
    }
}

void mostrar(lista_encadeada *l){

    lista_encadeada *aux;
    
    aux = l;
    
    if(aux == 0){
        puts("lista vazia");
    }else{
        while(aux){
            printf("numero: %d\n", aux ->dados);
            aux = aux ->prox;
        }
    }
}

void remover(lista_encadeada **l, int info){
    lista_encadeada *aux1 = *l;
    lista_encadeada *aux2 = NULL;

    if (*l ==0){
            puts("Erro, lista vazia");
            return;
    }

    else if(aux1 ->prox == 0){

        if(aux1 ->dados == info){
            free(aux1);
            *l = 0;
        }else{
            puts("Item nao encontrado");
        }

    }else{
        
        while (aux1 != NULL && aux1->dados != info) {
            aux2 = aux1;
            aux1 = aux1->prox;
    }


        if(info == aux1 ->dados){
            
            aux2 ->prox = aux1 ->prox; 
            free(aux1); 
        }else{
            puts("Item nao foi encontrado");
        }
    }
}

void esvaziar(lista_encadeada **l){
    lista_encadeada *aux ;

    if (*l == NULL){
        puts("lista ja esta vazia");
        return; 
    }else{

        while(*l != NULL){
            aux = *l;
            *l = aux->prox;
            free(aux);
        }
        puts("Lista esvaziada com sucesso");
    }
}
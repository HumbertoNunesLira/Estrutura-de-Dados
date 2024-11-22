#include <stdio.h> 
#include <stdlib.h>

//estruturas//

typedef struct lista_encadeada lista_encadeada;

struct lista_encadeada {
    int dados;
    lista_encadeada *prox;
    lista_encadeada *ant;  
};

//////////////////////////////////////////

//funçoes//

lista_encadeada* criar_lista(void); //cria lista
void inserir(lista_encadeada **l,int info); //insere mais um elemento
void esvaziar(lista_encadeada**l); //esvazeia a lista
void mostrar (lista_encadeada *l); //mostra a lista
void remover(lista_encadeada **l, int info); //remove um elemento

/////////////////////////////////////////

//main//

int main(){
    return 0;
}

////////////////////////////////////////

//escopo das funçoes//

lista_encadeada * criar_lista(void){
    return NULL;  
}

void inserir(lista_encadeada **l, int info){

    

}
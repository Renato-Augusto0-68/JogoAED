#include <stdio.h>
#include <stdlib.h>
#include "fase.h"
#include "fases.h"
#include "jogador.h"
#include "movement.h"
#include "falas.h"


falas *alocarFalas(){
    falas *aux = (falas*) malloc(sizeof(falas));
    if(aux!=NULL){
        return aux;
    }
    return NULL;
}

void inserirFalas(falas *falaAtual){
    FILE *arquivo;
    falas *aux= falaAtual;
    arquivo = fopen("dialogues/falas.txt","r");
    if(arquivo==NULL)
        return;
    while(aux!=NULL){
        falas *novo = alocarFalas();
        if(fscanf(arquivo, "%d %[^\n]", &novo->id, novo->falas)!=EOF){
            aux->prox = novo;
            aux=aux->prox;
        }else{
            free(novo);
            break;
        }
    }
    fclose(arquivo);

}

void ordenarFalas(falas *falaAtual){
    falas *aux = falaAtual->prox;




}

falas *meio(falas *falaAtual , falas **a, falas **b){
    falas *h = falaAtual->prox;
    falas *end = falaAtual->prox->prox;
    while(end!=NULL){
        h=h->prox;
        end=end->prox;
    }
    *a = falaAtual;
    *b= h->prox;
    h->prox=NULL;
    
}

void showFalas(falas *falaAtual){
    falas *aux = falaAtual;
    while(aux!=NULL){
        printf("%d  %s\n", aux->id, aux->falas);
        aux=aux->prox;
    }
}


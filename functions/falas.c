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
        aux->prox=NULL;
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

void meio(falas *falaAtual , falas **a, falas **b){
    falas *h = falaAtual;
    falas *end = falaAtual->prox;
    while(end!=NULL && end->prox!=NULL){
        h=h->prox;
        end=end->prox->prox;
    }
    *a = falaAtual;
    *b= h->prox;
    h->prox=NULL;
    
}

falas *ordenarfalas(falas *a, falas *b){
    falas *resultado = NULL;
    
    if (a==NULL) return b;
    if (b==NULL) return a;
    
    if(a->id<=b->id){
        resultado=a;
        resultado->prox=ordenarfalas(a->prox, b);
    }else{
        resultado=b;
        resultado->prox=ordenarfalas(a,b->prox);
    }
    return resultado;
}

falas *mergeSort(falas *falaAtual){
    if (falaAtual == NULL || falaAtual->prox == NULL) {
        return falaAtual;
    }
    falas *a;
    falas *b;
    meio(falaAtual,&a,&b);
    a=mergeSort(a);
    b=mergeSort(b);
    return ordenarfalas(a,b); 
}

void showFalas(falas *falaAtual){
    falas *aux = falaAtual;
    while(aux!=NULL){
        printf("%d  %s\n", aux->id, aux->falas);
        aux=aux->prox;
    }
}


#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "fases.h"
#include "fase.h"
#include "movement.h"


fases *alocarFases(){
    fases *aux = malloc(sizeof(fases)*3);
    if(aux!=NULL)
        aux->head=NULL;
        aux->tail=NULL;
        return aux;
    return NULL;
}

nos *alocarNo(){
    nos *aux = malloc(sizeof(nos));
    if(aux!=NULL)
        aux->prox=NULL;
        aux->ant=NULL;
        return aux;
    return NULL;
}


void alocarPosicoes(fases *atual){
    nos *aux = atual->head;
    /*jog[i].ballPos=(Vector3){1.2f,0.0f,0.5f};
        if(i==1)
             jog[i].ballPos=(Vector3){2.1f,3.8f,0.8f};
        if(i==2)
            jog[i].ballPos=(Vector3){0.0f,1.0f,2.0f};
    }*/
    
    aux->predefinicoes = (Vector3){0.0f,0.1f,0.2f};
}

void setFases(fases *atual){
    for(int i=0;i<3;i++){
            nos *aux = atual[i].head;
            for(int g=0;g<3;g++){
                nos *novo=alocarNo();
                novo->numeroFase=g;
                novo->prox=NULL;
                if(aux==NULL){
                    aux=novo;
                }else{
                    novo->ant=aux;
                    aux->prox=novo;
                }
                atual[i].tail = novo; 
            }
        }
    }       



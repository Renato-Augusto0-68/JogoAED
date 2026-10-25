#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "fases.h"
#include "fase.h"
#include "movement.h"


fases *alocarFases(){
    fases *aux = malloc(sizeof(fases)*3);
    if(aux!=NULL){
        aux[0].head=NULL;
        aux[1].head=NULL;
        aux[2].head=NULL;
        aux[0].tail=NULL;
        aux[1].tail=NULL;
        aux[2].tail=NULL;
        
        return aux;
    }
    return NULL;
}

nos *alocarNo(){
    nos *aux = malloc(sizeof(nos));
    if(aux!=NULL){
        aux->prox=NULL;
        aux->ant=NULL;
        return aux;
    }
    return NULL;
}
void setFases(fases *atual){
    for(int i=0;i<3;i++){
        nos *aux = atual[i].head;
        for(int g=0;g<3;g++){
            
            nos *novo=alocarNo();
            if(novo==NULL){
                return;
            }
            novo->numeroFase=g;
            novo->prox=NULL;
            if(aux==NULL){
                novo->ant=NULL;
                aux=novo;
                atual[i].head=novo;
            }else{
                novo->ant=aux;  
                aux->prox=novo; 
                aux=aux->prox;
            }
            atual[i].tail = novo;
        }
    }
}       

void alocarPosicoes(fases *atual){
    for(int i=0;i<3;i++){
        nos *aux = atual[i].head;
        int g=0;
        do{
            if(g==0)
                aux->predefinicoes = (Vector3){0.4f+i,0.1f,0.2f};
            if(g==1)
                aux->predefinicoes = (Vector3){0.3f, 0.2f, 0.1f+i};
            if(g==2)
                aux->predefinicoes = (Vector3){0.44f, 0.13f+i, 0.11f};
            g++;
            aux=aux->prox;
        }while(aux!=NULL);
    }
    /*jog[i].ballPos=(Vector3){1.2f,0.0f,0.5f};
        if(i==1)
             jog[i].ballPos=(Vector3){2.1f,3.8f,0.8f};
        if(i==2)
            jog[i].ballPos=(Vector3){0.0f,1.0f,2.0f};
    }*/
}

void mudarFase(jogador *jog, int *faseAtual){
    if((jog->contPontos%3)==0 &&jog->contPontos!=0){
        (*faseAtual)++;
    }
    
}



#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas(){
    jogador *aux = malloc(sizeof(jogador));
    if(aux!=NULL){
        aux->contPontos=0;
        return aux;
    }
    return NULL;
}


void escolher(int *pieceControl){
    if(IsKeyPressed(KEY_KP_1)){
        *pieceControl=1;
    }
    if(IsKeyPressed(KEY_KP_2)){
        *pieceControl=2;
    }
    if(IsKeyPressed(KEY_KP_0)){
        *pieceControl=0;
    }
}

void zerar(fases *atual, int unityControl, jogador *jog){
    nos *aux = atual->head;
    for(int i=0;i<3;i++){
        if((aux->numeroFase)==unityControl){
            break;
        }
        aux=aux->prox;
    }
    if(aux!=NULL){
        aux->predefinicoes=(Vector3){10.0f,10.0f,10.0f};
        (jog->contPontos)+=1;
        DrawText(TextFormat("Muda de peca, cara... pegasse a pista! "),
                 10, 190, 15, BLACK);

    }
}
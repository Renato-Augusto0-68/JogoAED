#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas(){
    jogador *aux = malloc(sizeof(jogador));
    if(aux!=NULL){
        aux->quantFases=5;
        aux->contPontos=0;
        aux->contTotal=0;
        aux->mousePosit=(Vector2){0.0f,0.0f};
        return aux;
    }
    return NULL;
}

void Jogar(int * valor){
    if (IsKeyPressed(KEY_ENTER))
        *valor = 1;
}

void escolher(int *pieceControl, fases* atual){
    
        
    if(IsKeyPressed(KEY_KP_3)){
            *pieceControl=3;
    }
    
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
    if(aux==NULL){
        return;
    }
    for(int i=0;i<(aux->quantidadePistas);i++){
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
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas(int quantidade){
    jogador *aux = malloc(sizeof(jogador)*quantidade);
    if(aux!=NULL){
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
    }if(IsKeyPressed(KEY_KP_0)){
        *pieceControl=0;
    }

}




/*void setPosicoes(jogador *jog, int quantidade){
    
    for(int i=0;i<quantidade;i++){
        jog[i].id=i;
        if(i==0)
            jog[i].ballPos=(Vector3){1.2f,0.0f,0.5f};
        if(i==1)
             jog[i].ballPos=(Vector3){2.1f,3.8f,0.8f};
        if(i==2)
            jog[i].ballPos=(Vector3){0.0f,1.0f,2.0f};
    }
}
*/
void zerar(fases *atual){
    atual->head->predefinicoes=(Vector3){10.0f,10.0f,10.0f};
    DrawText(TextFormat("Muda de peca, cara... pegasse a pista! "),
                 10, 190, 15, BLACK);

}
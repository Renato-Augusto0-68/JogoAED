#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "jogador.h"
#include "fases.h"
#include "raymath.h"

void atualizarCameraPan(Camera3D *camera){
    const float panSensibilidade = 0.02f;
    const float zoomSensibilidade = 1.0f;
    Vector3 frente;
    Vector3 direita;
    Vector3 cima;

    if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)){
        Vector2 delta = GetMouseDelta();
        frente = Vector3Normalize(Vector3Subtract(camera->target, camera->position));
        direita = Vector3Normalize(Vector3CrossProduct(frente, camera->up));
        cima = Vector3Normalize(Vector3CrossProduct(direita, frente));

        Vector3 deslocamento = Vector3Add(
            Vector3Scale(direita, -delta.x * panSensibilidade),
            Vector3Scale(cima, delta.y * panSensibilidade)
        );
        camera->position = Vector3Add(camera->position, deslocamento);
        camera->target = Vector3Add(camera->target, deslocamento);
    }

    float wheel = GetMouseWheelMove();
    if(wheel != 0.0f){
        frente = Vector3Normalize(Vector3Subtract(camera->target, camera->position));
        Vector3 deslocamento = Vector3Scale(frente, wheel * zoomSensibilidade);
        camera->position = Vector3Add(camera->position, deslocamento);
    }
}

float distanciaPecaMouse(nos *noAtual, jogador *jog){
    nos *aux = noAtual;
    Vector2 vectorAux = {aux->predefinicoes.x,aux->predefinicoes.y};
    float distancia = Vector2Distance(vectorAux, jog->mousePosit);
    return distancia;
}



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

void escolher(int *pieceControl, jogador *jog, fases *atual, Camera3D camera){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 auxVector =GetMousePosition();
        Ray ray = GetMouseRay(auxVector, camera);
        nos *aux = atual->head;
        int selecionada = -1;
        float menorDistancia = 0.0f;

        while(aux != NULL){
            RayCollision colisao = GetRayCollisionSphere(ray, aux->predefinicoes, 2.5f);
            if(colisao.hit && (selecionada == -1 || colisao.distance < menorDistancia)){
                selecionada = aux->numeroFase;
                menorDistancia = colisao.distance;
            }
            aux = aux->prox;
        }

        if(selecionada != -1){
            *pieceControl = selecionada;
        }
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
        float dist = distanciaPecaMouse(aux,jog);
        if(dist<=0.5)
            (jog->contPontos)+=1;
        DrawText(TextFormat("Muda de peca, cara... pegasse a pista! "),
                 10, 190, 15, BLACK);

    }
}
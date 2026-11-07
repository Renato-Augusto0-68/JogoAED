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

jogador *alocarPecas(){
    jogador *aux = malloc(sizeof(jogador));
    if(aux!=NULL){
        aux->quantFases=5;
        aux->contPontos=0;
        aux->contTotal=0;
        aux->mousePosit=(Vector2){0.0f,0.0f};
        aux->pausado=0;
        aux->contErros=0;
        aux->anomalia=-1;
        aux->anomaliaResolvida=0;
        aux->modoAnomalia=0;
        return aux;
    }
    return NULL;
}

void Jogar(int * valor){
    if (IsKeyPressed(KEY_ENTER))
        *valor = 1;
}

int zerar(fases *atual, Camera3D camera, jogador *jog){
    nos *aux = atual->head;
    if(aux==NULL){
        return -1;
    }

    Ray ray = GetMouseRay(GetMousePosition(), camera);
    nos *selecionada = NULL;
    float menorDistancia = 0.0f;

    while(aux != NULL){
        if(Vector3Equals(aux->predefinicoes, (Vector3){10.0f, 10.0f, 10.0f})){
            aux = aux->prox;
            continue;
        }
        RayCollision colisao = GetRayCollisionSphere(ray, aux->predefinicoes, 2.5f);
        if(colisao.hit && (selecionada == NULL || colisao.distance < menorDistancia)){
            selecionada = aux;
            menorDistancia = colisao.distance;
        }
        aux=aux->prox;
    }

    if(selecionada != NULL){
        if(selecionada->numeroFase != jog->anomalia){
            jog->contErros++;
            return 0;
        }

        selecionada->predefinicoes=(Vector3){10.0f,10.0f,10.0f};
        jog->contPontos++;
        jog->anomaliaResolvida=1;
        jog->modoAnomalia=0;
        return 1;
    }

    return -1;
}

void selecionarAnomalia(fases *atual, jogador *jog) {
    if (atual == NULL || atual->head == NULL) {
        return;
    }

    int quantidade = atual->head->quantidadePistas;
    int indice = rand() % quantidade;

    nos *aux = atual->head;

    for (int i = 0; i < indice; i++) {
        aux = aux->prox;
    }

    jog->anomalia = aux->numeroFase;
    jog->anomaliaResolvida = 0;
    jog->modoAnomalia = 1;
    jog->pausado = 0;
}

void passarAnomalia(jogador *jog) {
    jog->anomaliaResolvida = 1;
    jog->modoAnomalia = 0;
}
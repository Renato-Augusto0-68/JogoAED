#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas();

void atualizarCameraPan(Camera3D *camera);

void Jogar(int* valor);

void zerar(fases *atual, int unityControl, jogador *jog);

void escolher(int *unityControl, jogador *jog, fases *atual, Camera3D camera);

//void setPosicoes(jogador *jog, int quantidade);



#endif
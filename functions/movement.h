#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas();

void atualizarCameraPan(Camera3D *camera);

void Jogar(int* valor);

int zerar(fases *atual, Camera3D camera, jogador *jog);

void selecionarAnomalia(fases *atual, jogador *jog);

void passarAnomalia(jogador *jog);

//void setPosicoes(jogador *jog, int quantidade);



#endif
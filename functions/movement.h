#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas();



void zerar(fases *atual, int unityControl, jogador *jog);

void escolher(int *unityControl);

//void setPosicoes(jogador *jog, int quantidade);



#endif
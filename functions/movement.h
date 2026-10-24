#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"
#include "fases.h"

jogador *alocarPecas(int quantidade);



void zerar(fases *atual);

void escolher(int *unityControl);

void setPosicoes(jogador *jog, int quantidade);



#endif
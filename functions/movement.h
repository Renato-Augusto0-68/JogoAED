#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"

jogador *alocarPecas(int quantidade);

void mover(jogador *jog);

void zerar(jogador *jog);

void escolher(int *unityControl);

void setPosicoes(jogador *jog, int quantidade);



#endif
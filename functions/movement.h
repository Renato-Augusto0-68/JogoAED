#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "raylib.h"
#include "jogador.h"
#include "fases.h"

int distanciaPecaMouse(fases *atual, jogador *jog);

jogador *alocarPecas();

void Jogar(int* valor);

void zerar(fases *atual, int unityControl, jogador *jog);

void escolher(int *unityControl,jogador *jog ,fases *atual);

//void setPosicoes(jogador *jog, int quantidade);



#endif
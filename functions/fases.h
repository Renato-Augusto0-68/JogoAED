#ifndef FASES_H
#define FASES_H
#include "raylib.h"
#include "jogador.h"
#include "fase.h" 

fases *alocarFases();

nos *alocarNo();
void setFases(fases *atual);
void alocarPosicoes(fases *atual);
void mudarFase(jogador *jog, int *faseAtual);
#endif
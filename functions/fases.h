#ifndef FASES_H
#define FASES_H
#include "raylib.h"
#include "jogador.h"
#include "fases.c"


fases *alocarFases();

void setFases(fases *atual);

nos *alocarNo();

void alocarPosicoes(fases *atual);
#endif
#ifndef JOGADOR_H
#define JOGADOR_H
#include "raylib.h"
#include <stdio.h>


/*
gcc main.c functions/movement.c functions/fases.c     -Iraylib/raylib/src     -Lraylib/raylib/src     -o game     raylib/raylib/src/libraylib.a     -lGL -lm -lpthread -ldl -lrt -lX11 && ./game
*/
typedef struct jogador {
    int contPontos;
    int quantFases;
    int contTotal;
}jogador;


#endif
#ifndef JOGADOR_H
#define JOGADOR_H
#include "raylib.h"
#include <stdio.h>


/*
gcc main.c functions/movement.c \
    -Iraylib/raylib/src \
    -Lraylib/raylib/src \
    -o game \
    raylib/raylib/src/libraylib.a \
    -lGL -lm -lpthread -ldl -lrt -lX11
    && ./game
*/
typedef struct jogador {
    int id;
    Vector3 ballPos;
}jogador;


#endif
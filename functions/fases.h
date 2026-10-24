#ifndef FASES_H
#define FASES_H
#include "raylib.h"
#include "jogador.h"

typedef struct nos{
    int numeroFase;
    struct nos *prox;
    struct nos *ant;
}nos;

typedef struct fases{
    nos *head;
    nos *tail;

}fases;



#endif
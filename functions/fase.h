#ifndef FASE_H
#define FASE_H
#include "raylib.h"
#include "jogador.h"

typedef struct nos{
    int numeroFase;
    Vector3 predefinicoes;
   
    struct nos *prox;
    struct nos *ant;
}nos;

typedef struct fases{
    nos *head;
    nos *tail;

}fases;



#endif
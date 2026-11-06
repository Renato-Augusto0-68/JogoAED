#ifndef FALAS_H
#define FALAS_H

#include "raylib.h"

typedef struct falas{
    int id;
    char falas[90];
    struct falas *prox;
}falas;

falas *alocarFalas();

void inserirFalas(falas *falaAtual);

void ordenarFalas(falas *falaAtual);

void showFalas(falas *falaAtual);


#endif
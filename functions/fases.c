#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "fases.h"
#include "fase.h"
#include "movement.h"


fases *alocarFases(){
    fases *aux = malloc(sizeof(fases)*3);
    if(aux!=NULL)
        aux->head=NULL;
        aux->tail=NULL;
        return aux;
    return NULL;
}


void setFases(fases *atual){
    for(int i=0;i<3;i++){
    
        fases *aux = atual;

    }
}



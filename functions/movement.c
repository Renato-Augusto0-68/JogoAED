#include <raylib.h>
#include <stdio.h>
#include "movement.h"
#include "jogador.h"

    void mover(jogador *jog){
        Vector3 x = jog->ballPos;
        if (IsKeyDown(KEY_RIGHT))
            x.x += 0.5f; 
        if (IsKeyDown(KEY_LEFT))
            x.x -= 0.5f;
        if (IsKeyDown(KEY_UP)){
            x.x+=0.5;
            x.y -= 0.5f;
        }
        if (IsKeyDown(KEY_DOWN)){
            x.y += 0.5f;
        }
        jog->ballPos = x;
    }
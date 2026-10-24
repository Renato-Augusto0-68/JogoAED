#include <raylib.h>
#include <stdio.h>
#include "movement.h"

    void mover(pecas *x){
       Vector3 x = x.ballPos;
        if (IsKeyDown(KEY_RIGHT)){ 
            x.x += 0.5f; } ;
        if (IsKeyDown(KEY_LEFT))
            x.x -= 0.5f;
        if (IsKeyDown(KEY_UP))
            x.y -= 0.5f;
        if (IsKeyDown(KEY_DOWN))
            x.y += 0.5f;
    }
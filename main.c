#include <stdio.h>
#include "raylib.h"
#include "functions/fase.h"
#include "functions/fases.h"

#include "functions/jogador.h"
#include "functions/movement.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
    
    
    Camera3D camera = { 0, };
    int presente=0;
    fases *atual = alocarFases();
    setFases(atual);
    alocarPosicoes(atual);

    jogador *x = alocarPecas();
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
    
   

    Vector3 axis = (Vector3){ 12.5f, 12.5f, 12.5f };
    
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int unityControl=0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        escolher(&unityControl);
        // Update
        //----------------------------------------------------------------------------------
       // mover(&x[unityControl]);
        //----------------------------------------------------------------------------------
        
        if(IsKeyPressed(KEY_B)){
            zerar(&atual[presente], unityControl, x);
        }
        mudarFase(x,&presente);
       
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        BeginMode3D(camera);
            ClearBackground(RAYWHITE);

            DrawText("protótipo", 10, 10, 20, DARKGRAY);
            nos *aux = atual[presente].head;
            while(aux!=NULL){ 
                DrawCircle3D(aux->predefinicoes, 2.5f, axis, 45.0f, RED);
                aux=aux->prox;
            }
        
            EndMode3D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
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
    jogador *jog = alocarPecas();
    int iniciou=-1;
    int acabou=0; //uma flag pra poder determinar se o jogo comecou ou não... e com ela determinar também a permissão de troca
    // porque assim isso evita o ocmportamento indevido de mudarFase, pra que ela mude só, mas corretamente...
    Camera3D camera = { 0, };
    int presente=0;
    fases *atual = alocarFases();
    setFases(&atual[0]);
    for(int i=0;i<jog->quantFases;i++){
        alocarPosicoes(&atual[i]);
    }

   
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
    while (!WindowShouldClose()){   
        if(!acabou)
            Jogar(&iniciou);
        if(iniciou==1){
           
        
            escolher(&unityControl);
        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        
            if(IsKeyPressed(KEY_B)){
                zerar(&atual[presente], unityControl, jog);
            }
        
            acabou=mudarFase(jog,&presente,&atual[presente]);
            if(acabou){
                iniciou=-2;
            }
        }
        
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        BeginMode3D(camera);
            ClearBackground(RAYWHITE);

            DrawText("protótipo", 10, 10, 20, DARKGRAY);
            if(iniciou>-1){
                nos *aux = atual[presente].head;
                while(aux!=NULL){ 
                    DrawCircle3D(aux->predefinicoes, 2.5f, axis, 45.0f, RED);
                    aux=aux->prox;
                }
            }
            EndMode3D();
            if(iniciou>-1){
                DrawText(TextFormat("valor total: %d",jog->contTotal), 10, 10, 10, DARKGRAY);
            }
            if(iniciou==-1){
                DrawText(TextFormat("Pressione enter para começar o jogo"), 100, 10, 10, DARKGRAY);
 
            }
            if(acabou){
                DrawText(TextFormat("THIS IS THE END, MY ONLY FRIEND, THE END, ALL THE DREAMS WE HAD, THE END"), 100, 10, 10, DARKGRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL contejogt
    //--------------------------------------------------------------------------------------

    return 0;
}
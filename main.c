#include <stdio.h>
#include "raylib.h"
#include "functions/fase.h"
#include "functions/fases.h"
#include "functions/falas.h"
#include "functions/jogador.h"
#include "functions/movement.h"
#include <stdlib.h>
#include <time.h>

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
    int anterior=0;
    falas *falasAtual=alocarFalas();
    inserirFalas(falasAtual);
    fases *atual = alocarFases();
    setFases(atual);
    InitAudioDevice();
    alocarPosicoes(atual);
    srand((unsigned int)time(NULL));
    selecionarAnomalia(&atual[0], jog);
    //Music musica_tema= LoadMusicStream("arquivo");
    //float volume = 0.7f;
    //PlayMusicStream(musica_tema);
    //SetMusicVolume(musica_tema, volume);
    
   
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 75.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE ;            // Camera mode type
    
   

    Vector3 axis = (Vector3){ 12.5f, 12.5f, 12.5f };
    
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()){   
        if(!acabou)
            Jogar(&iniciou);
        if(iniciou==1){
            if(IsKeyPressed(KEY_P)){
                jog->pausado = !jog->pausado;
            }

            if(!jog->pausado){
                atualizarCameraPan(&camera);

                if(IsKeyPressed(KEY_SPACE)){
                    passarAnomalia(jog);
                }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    zerar(&atual[presente], camera, jog);
                }

                if(jog->contErros >= 3){
                    acabou=2;
                }else{
                    int faseAnterior = presente;
                    acabou = mudarFase(jog, &presente, &atual[presente]);
                    if(presente != faseAnterior){
                        selecionarAnomalia(&atual[presente], jog);
                    }
                }
            }
        }
        
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        BeginMode3D(camera);
            ClearBackground(RAYWHITE);
            DrawText("protótipo", 10, 10, 20, DARKGRAY);
            if(iniciou>-1 && falasAtual!=NULL){
                mergeSort(falasAtual);
                nos *aux = atual[presente].head;
                while(aux!=NULL){ 
                    DrawCircle3D(aux->predefinicoes, 2.5f, axis, 45.0f, RED);
                    aux=aux->prox;
                }
                DrawText(TextFormat("valor total: %s", falasAtual->falas),
                         10, 10, 10, DARKGRAY);
            }
            EndMode3D();
            if(iniciou>-1){
                DrawText(TextFormat("Fase: %d  Pontos: %d  Erros: %d",
                                    presente + 1, jog->contTotal + jog->contPontos,
                                    jog->contErros), 10, 10, 20, DARKGRAY);
                DrawText("P: pausar/retomar | ESPACO: passar anomalia",
                         10, 35, 16, DARKGRAY);
                if(jog->pausado){
                    DrawText("JOGO PAUSADO - pressione P para continuar",
                             250, 210, 20, BLUE);
                }
                if(jog->anomaliaResolvida){
                    DrawText("Anomalia encontrada!", 10, 65, 20, GREEN);
                }
            }
            if(iniciou==-1){
                DrawText(TextFormat("Pressione enter para começar o jogo"), 100, 10, 10, DARKGRAY);
 
            }
            if(acabou==1){
                DrawText(TextFormat("THIS IS THE END, MY ONLY FRIEND, THE END, ALL THE DREAMS WE HAD, THE END"), 100, 10, 10, DARKGRAY);
            }
            if(acabou==2 || jog->contErros>=3){
                DrawText("VOCE PERDEU: tres erros.", 250, 210, 24, RED);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //UnloadAudioStream(musica_tema);
    //CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL contejogt
    //--------------------------------------------------------------------------------------

    return 0;
}
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
    int modoImagens=1;
    int acabou=0; //uma flag pra poder determinar se o jogo comecou ou não... e com ela determinar também a permissão de troca
    // porque assim isso evita o ocmportamento indevido de mudarFase, pra que ela mude só, mas corretamente...
    Camera3D camera = { 0, };
    int presente=0;
    int anterior=0;
    falas *falasAtual=alocarFalas();
    inserirFalas(falasAtual);
    falasAtual = mergeSort(falasAtual);
    falas *auxF = falasAtual;

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
    
    // preparar o cenário em que nao aparece pista... ai eu uso o falas.c...
    // no caso, via iniciou e acabou...
    // mas o jogo já iniciou assim, só não o modo de busca... nesse caso ai eu precisarei de acabou, 
    //rpa ativar o cenário, e de forma a ficar dentro de iniciou pq o njogo 
    //já está rodando, sõ nao nesse modo

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()){   
        if(!acabou)
            Jogar(&iniciou);
        if(iniciou==1){       
            if(modoImagens==1){
                if(IsKeyPressed(KEY_C)/*falasAtual!=NULL*/)
                    modoImagens=0;
            }
            if(modoImagens==0){
            if(IsKeyPressed(KEY_P)){
                jog->pausado = !jog->pausado;
            }

            if(!jog->pausado){
                atualizarCameraPan(&camera);

                if(IsKeyPressed(KEY_SPACE)){
                    passarAnomalia(jog);
                    modoImagens=1;
                }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if((zerar(&atual[presente], camera, jog))==1)
                        modoImagens=1;
                }

                if(jog->contPontos==3 && jog->contErros<3){
                    iniciou=-2;
                }

                if(jog->contErros >= 3){
                    acabou=2;
                }else{
                    int faseAnterior = presente;
                    acabou = mudarFase(jog, &presente, &atual[presente]);
                    if(presente != faseAnterior){
                        selecionarAnomalia(&atual[presente], jog);
                        if(auxF!=NULL){auxF=auxF->prox;}
                        modoImagens=1;
                    }
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
            if(iniciou>-1 && modoImagens==0 && falasAtual!=NULL){
                nos *aux = atual[presente].head;
                while(aux!=NULL){ 
                    DrawCircle3D(aux->predefinicoes, 2.5f, axis, 45.0f, RED);
                    aux=aux->prox;
                }
            }
            EndMode3D();
            if(modoImagens==0){
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
                if(acabou==2 || jog->contErros>=3){
                    DrawText("VOCE PERDEU: tres erros. Encerre o jogo!", 250, 110, 24, RED);
                }
            }
           
            }
            if(modoImagens==1){

                if(iniciou!=-1 && auxF!=NULL){
                    DrawText(TextFormat("%s", auxF->falas),
                         10, 10, 10, DARKGRAY);
                
                    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
                         auxF=auxF->prox;
                }
            }
            if(iniciou==-1){
                DrawText(TextFormat("Pressione enter para começar o jogo"), 100, 10, 10, DARKGRAY);
 
            }
            if(iniciou==-2){
                DrawText(TextFormat("THIS IS THE END, MY ONLY FRIEND, THE END, ALL THE DREAMS WE HAD, THE END"), 100, 10, 10, DARKGRAY);
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
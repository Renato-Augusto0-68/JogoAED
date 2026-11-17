# JogoAED
# JogoAED

Jogo desenvolvido em C usando a biblioteca raylib.

## Requisitos

- GCC
- raylib
- Make
- Linux ou MSYS2 no Windows

## Executando no Linux

Clone o projeto:

```bash
git clone https://github.com/Renato-Augusto0-68/JogoAED.git
cd JogoAED

gcc main.c functions/movement.c functions/fases.c functions/falas.c \
-Iraylib/raylib/src \
-Lraylib/raylib/src \
-o game \
raylib/raylib/src/libraylib.a \
-lGL -lm -lpthread -ldl -lrt -lX11
./game

gcc main.c functions/movement.c functions/fases.c functions/falas.c \
-I/ucrt64/include \
-L/ucrt64/lib \
-o game.exe \
-lraylib -lopengl32 -lgdi32 -lwinmm
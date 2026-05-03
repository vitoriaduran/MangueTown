#include "raylib.h"

int main(void){
    const int larguraTela = 850;
    const int alturaTela = 450;

    InitWindow(larguraTela, alturaTela, "MangueTown");

    //aqui fica as texturas

    SetTargetFPS(60); //o jogo roda 60 quadrados por segundos

    //loop principal

    while(!WindowShouldClose()){
        //espaço para a logica (update)

        //espaço para o desenho(render)
        BeginDrawing();
            ClearBackground(RAYWHITE); //fundo fica branco por enquanto
            DrawText("MangueTown", 250, 150, 40, DARKGREEN);
            DrawText("Zezinho e Mané Galinha em: AED", 240, 200, 20, DARKGRAY);
            
            DrawText("Pressione ESC para sair", 10, 420, 15, GRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
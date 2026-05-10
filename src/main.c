#include "raylib.h"
#include "cenarios.h"
#include "personagens.h"
#include "mapa.h"
#include <stdlib.h>

int main(void) {
    const int larguraTela = 1280;
    const int alturaTela = 720;
    
    // 1. Inicialização
    InitWindow(larguraTela, alturaTela, "MangueTown - Zezinho no Mangue");

    GameState gs = { 0 };
    gs.tempo = 0.0f;
    gs.saudeManguezal = 100;

    Personagem zezinho = {0};
    
    zezinho.posicao = (Vector2){ (float)larguraTela / 2, (float)alturaTela - 120 };
    zezinho.velocidade = 5.0f;
    zezinho.movendo = false;
    zezinho.esquerda = false;   

    Fase *faseAtual = criar_mapa(); 

    SetTargetFPS(60);

    // 4. Loop Principal
    while (!WindowShouldClose()) {
        gs.tempo += GetFrameTime();
        zezinho.movendo = false;
        
        if (IsKeyDown(KEY_RIGHT)) { zezinho.posicao.x += zezinho.velocidade; zezinho.esquerda = false; zezinho.movendo = true; }
        if (IsKeyDown(KEY_LEFT))  { zezinho.posicao.x -= zezinho.velocidade; zezinho.esquerda = true;  zezinho.movendo = true; }
        if (IsKeyDown(KEY_UP))    { zezinho.posicao.y -= zezinho.velocidade; zezinho.movendo = true; }
        if (IsKeyDown(KEY_DOWN))  { zezinho.posicao.y += zezinho.velocidade; zezinho.movendo = true; }

        // Troca de Fase
        if (IsKeyPressed(KEY_D) && faseAtual->next != NULL) {
            faseAtual = faseAtual->next;
            zezinho.posicao.x = 50; 
        }
        if (IsKeyPressed(KEY_A) && faseAtual->anterior != NULL) {
            faseAtual = faseAtual->anterior;
            zezinho.posicao.x = larguraTela - 50;
        }

        // 5. Renderização
        BeginDrawing();
            ClearBackground(BLACK);

            switch(faseAtual->id) {
                case FASE_MANGUEZAL: 
                    renderizar_manguezal(&gs); 
                    break;
                case FASE_PONTE:
                     renderizar_ponte(&gs);
                     break;
                case FASE_MARCO_ZERO:
                     renderizar_marco_zero(&gs);
                     break;
                default:
                    break;
            }

            
            desenhar_mane_galinha(400, 650, gs.tempo);
            desenhar_zezinho(zezinho, gs.tempo);

            // Camada 4: Interface (HUD) - Sempre por último
            DrawRectangle(10, 10, 420, 35, (Color){0, 0, 0, 100});
            DrawText(faseAtual -> nome, 20, 10, 20, RAYWHITE);
            
        EndDrawing();
    }

    CloseWindow();    
    return 0;
}
#include "raylib.h"
#include "cenarios.h"
#include <stdlib.h>

// Definição da estrutura da Lista Dupla para o Mapa
typedef struct Fase {
    void (*renderizar)(GameState*); // Ponteiro para a função de desenho
    struct Fase *proximo;
    struct Fase *anterior;
} Fase;

int main(void) {
    // 1. Inicialização (Use a resolução que você definiu nos cenários)
    const int larguraTela = 1280;
    const int alturaTela = 720;
    InitWindow(larguraTela, alturaTela, "Teste de Cenarios - MangueAED");

    // 2. Estado do Jogo (Necessário para as funções de renderização)
    GameState gs = { 0 };
    gs.tempo = 0.0f;
    gs.saudeManguezal = 80; // Para aparecer um pouco de lixo no teste
    gs.plateia.tamanho = 8; // Para aparecer bonequinhos no Marco Zero

    // 3. Criando os nós da Lista Dupla (AED)
    Fase *f1 = (Fase*)malloc(sizeof(Fase));
    Fase *f2 = (Fase*)malloc(sizeof(Fase));
    Fase *f3 = (Fase*)malloc(sizeof(Fase));

    // Configurando as conexões
    f1->renderizar = renderizar_manguezal;
    f1->anterior   = NULL;
    f1->proximo    = f2;

    f2->renderizar = renderizar_ponte;
    f2->anterior   = f1;
    f2->proximo    = f3;

    f3->renderizar = renderizar_marco_zero;
    f3->anterior   = f2;
    f3->proximo    = NULL;

    Fase *faseAtual = f1; // Início do jogo

    SetTargetFPS(60);

    // 4. Loop Principal
    while (!WindowShouldClose()) {
        // Update: atualiza o tempo para as animações (ondas, nuvens, etc)
        gs.tempo += GetFrameTime();

        // Comandos de teste: Teclas Direita/Esquerda para trocar de fase
        if (IsKeyPressed(KEY_RIGHT) && faseAtual->proximo != NULL) {
            faseAtual = faseAtual->proximo;
        }
        if (IsKeyPressed(KEY_LEFT) && faseAtual->anterior != NULL) {
            faseAtual = faseAtual->anterior;
        }

        // Render
        BeginDrawing();
            ClearBackground(BLACK);

            // Chama a função de desenho do nó atual da lista
            faseAtual->renderizar(&gs);

            // Texto de ajuda
            DrawRectangle(10, 10, 350, 30, (Color){0, 0, 0, 150});
            DrawText("Setas DIREITA/ESQUERDA para trocar de fase", 20, 15, 15, RAYWHITE);

        EndDrawing();
    }

    // 5. Limpeza de memória
    free(f1);
    free(f2);
    free(f3);
    CloseWindow();

    return 0;
}
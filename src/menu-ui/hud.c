#include "raylib.h"
#include "menu_iu.h"
#include "cenarios.h"
#include "plateia.h"

void desenhar_hud(GameState* gs) {
    // barra superior
    DrawRectangle(0, 0, SCREEN_W, 52, COR_HUD_BG);
    DrawLine(0, 52, SCREEN_W, 52, (Color){255, 220, 80, 60});
 
    //nome da fase atual
    DrawText(gs->faseAtual->nome, 18, 16, 22, COR_AMARELO_MANGUE);
 
    // Reputação 
    DrawText("Reputacao", SCREEN_W - 310, 8, 16, (Color){200, 200, 200, 255});

    barra_progresso(SCREEN_W - 205, 10, 190, 16, gs->reputacao, 100,
                    (Color){255, 185, 50, 255});

    DrawText(TextFormat("%d%%", gs->reputacao), SCREEN_W - 205 + 192, 11, 14,
             (Color){220, 190, 80, 255});
 
    // Barra inferior 
    DrawRectangle(0, SCREEN_H - 50, SCREEN_W, 50, COR_HUD_BG);
    DrawLine(0, SCREEN_H - 50, SCREEN_W, SCREEN_H - 50, (Color){80, 220, 100, 60});
 
    // Saúde do manguezal
    DrawText("Mangue:", 14, SCREEN_H - 38, 17, COR_VERDE_MANGUE);
    Color corM = gs->saudeManguezal > 50
        ? (Color){50, 200, 80, 255}
        : (Color){210, 80, 50, 255};
    barra_progresso(105, SCREEN_H - 36, 130, 15, gs->saudeManguezal, 100, corM);
 
    // Banda
    DrawText(TextFormat("Banda: %d/4", gs->numMusicos), 268, SCREEN_H - 38, 17,
             COR_ROXO_MANGUE);
 
    //topo da mochila
    const char* itemTopo = peek_mochila(&gs->mochila);
    if (itemTopo) {
        DrawRectangle(SCREEN_W / 2 - 130, SCREEN_H - 46, 260, 36, (Color){35, 25, 55, 185});
        DrawRectangleLines(SCREEN_W / 2 - 130, SCREEN_H - 46, 260, 36, (Color){180, 140, 255, 120});
        DrawText("Mochila:", SCREEN_W / 2 - 120, SCREEN_H - 40, 15, (Color){190, 165, 255, 255});
        DrawText(itemTopo,   SCREEN_W / 2 - 45,  SCREEN_H - 40, 15, COR_AMARELO_MANGUE);
    }
 
    //teclas p/ guiar o jogador
    DrawText("[A/D] Mover  [SPACE] Coletar  [U] Usar  [I] Mochila  [B] Banda  [S] Setlist  [H] Historia  [ESC] Sair",
             SCREEN_W / 2 - 370, SCREEN_H - 18, 13, (Color){155, 155, 155, 255});
 
    //Plateia do marco zero
    if (gs->faseAtual->id == FASE_MARCO_ZERO) {
        DrawText(TextFormat("Plateia: %d/%d", gs->plateia.tamanho, MAX_PLATEIA),
                 SCREEN_W - 160, SCREEN_H - 38, 16, (Color){255, 160, 80, 255});
        if (gs->plateia.tamanho >= MAX_PLATEIA - 3) {
            DrawText("! FILA CHEIA", SCREEN_W - 155, SCREEN_H - 55, 15, (Color){255, 80, 80, 255});
        }
    }
 
    // Mensagem de feedback 
    if (gs->msgTimer > 0) {
        float alpha = gs->msgTimer > 1.0f ? 255 : gs->msgTimer * 255;
        int   tw    = MeasureText(gs->msgTela, 22);

        DrawRectangle(SCREEN_W / 2 - tw / 2 - 15, SCREEN_H / 2 - 55, tw + 30, 38,
                      (Color){20, 15, 38, (unsigned char)alpha});

        DrawText(gs->msgTela, SCREEN_W / 2 - tw / 2, SCREEN_H / 2 - 48, 22,
                 (Color){255, 220, 80, (unsigned char)alpha});
    }
}
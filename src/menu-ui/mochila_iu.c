#include "raylib.h"
#include <stdio.h>
#include "menu_iu.h"

void desenhar_ui_mochila(GameState* gs) {
    if (!gs->uiMochila){
        return;
    }
    int px = SCREEN_W / 2 - 215, py = SCREEN_H / 2 - 215;
    painel_rounded(px, py, 430, 420, (Color){18, 14, 40, 248}, (Color){180, 140, 255, 255});
 
    DrawText("=== MOCHILA ===", px + 100, py + 15, 22, COR_ROXO_MANGUE);
    DrawText("(Pilha: ultimo entra, primeiro sai)", px + 38, py + 42, 14, (Color){130, 110, 185, 255});
    DrawLine(px + 15, py + 62, px + 415, py + 62, (Color){180, 140, 255, 80});
 
    if (gs->mochila.topo < 0) {
        DrawText("Mochila vazia!", px + 130, py + 180, 20, (Color){140, 130, 165, 255});
    } 
    else {
        for (int i = gs->mochila.topo; i >= 0; i--) {
            int idx  = gs->mochila.topo - i;
            bool isTopo = (i == gs->mochila.topo);
            Color bg = isTopo ? (Color){45, 32, 80, 220} : (Color){28, 22, 55, 200};
            Color bd = isTopo ? (Color){255, 205, 55, 255} : (Color){100, 80, 160, 180};
            DrawRectangle(px + 20, py + 75 + idx * 52, 390, 44, bg);
            DrawRectangleLines(px + 20, py + 75 + idx * 52, 390, 44, bd);

            // ícone e texto
            DrawText(isTopo ? ">" : " ", px + 28, py + 88 + idx * 52, 20, bd);
            DrawText(TextFormat("[%d] %s", i + 1, gs->mochila.itens[i]),
                     px + 48, py + 88 + idx * 52, 18,
                     isTopo ? COR_AMARELO_MANGUE : (Color){170, 150, 210, 255});
            if (isTopo) DrawText("<- TOPO", px + 290, py + 88, 16, (Color){255, 180, 50, 200});
        }
    }
 
    DrawLine(px + 15, py + 370, px + 415, py + 370, (Color){180, 140, 255, 60});
    DrawText("[I] Fechar   [U] Usar item do topo", px + 68, py + 380, 16,
             (Color){145, 125, 195, 255});
}
#include "raylib.h"
#include <stdio.h>
#include "menu_iu.h"

void desenhar_ui_banda(GameState* gs) {
    if (!gs->uiBanda) return;
 
    int px = 40, py = SCREEN_H / 2 - 200;
    painel_rounded(px, py, 480, 395, (Color){14, 28, 18, 248}, (Color){80, 220, 100, 255});
 
    DrawText("=== A BANDA ===", px + 130, py + 15, 22, COR_VERDE_MANGUE);
    DrawText("(Lista Encadeada)", px + 158, py + 42, 14, (Color){70, 160, 80, 255});
    DrawLine(px + 15, py + 62, px + 465, py + 62, (Color){80, 220, 100, 80});
 
    if (!gs->banda) {
        DrawText("Nenhum musico ainda...", px + 110, py + 165, 18, (Color){130, 150, 130, 255});
        DrawText("Explore o mapa!", px + 155, py + 195, 16, (Color){80, 180, 90, 255});
    }
    else {
        Musico* cur = gs->banda;
        int     i   = 0;

        while (cur && i < 4) {
            DrawRectangle(px + 18, py + 70 + i * 72, 444, 65, (Color){22, 42, 26, 210});
            DrawRectangleLines(px + 18, py + 70 + i * 72, 444, 65, (Color){55, 160, 65, 200});
            DrawText(TextFormat("%d.  %s", i + 1, cur->nome),
                     px + 32, py + 80 + i * 72, 20, (Color){195, 255, 200, 255});
            DrawText(TextFormat("    %s", cur->instrumento),
                     px + 32, py + 102 + i * 72, 16, (Color){135, 215, 140, 255});
                     
            //barra de energia 
            DrawText("Energia:", px + 270, py + 82 + i * 72, 14, (Color){100, 200, 100, 255});
            barra_progresso(px + 340, py + 84 + i * 72, 100, 12, cur->energia, 10,
                            (Color){90, 220, 75, 255});

            //seta de lista 
            if (cur->next)
                DrawText("->", px + 425, py + 105 + i * 72, 16, (Color){55, 160, 65, 180});
            cur = cur->next;
            i++;
        }
    }
 
    DrawText(TextFormat("[B] Fechar   Musicos: %d/4", gs->numMusicos),
             px + 120, py + 365, 15, (Color){80, 175, 90, 255});
}
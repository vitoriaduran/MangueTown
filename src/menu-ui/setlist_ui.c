#include "raylib.h"
#include <stdio.h>
#include "menu_iu.h"

void desenhar_ui_setlist(GameState* gs) {
    if (!gs->uiSetlist) return;
 
    int px = SCREEN_W - 510, py = 70;
    painel_rounded(px, py, 460, 400, (Color){30, 18, 14, 248}, (Color){255, 185, 50, 255});
 
    DrawText("=== SETLIST ===", px + 125, py + 15, 22, COR_AMARELO_MANGUE);
    DrawText("(Insertion Sort - energia crescente)", px + 32, py + 42, 14,
             (Color){185, 155, 60, 255});
    DrawLine(px + 15, py + 62, px + 445, py + 62, (Color){255, 185, 50, 80});
 
    for (int i = 0; i < gs->setlist.count; i++) {
        int   e   = gs->setlist.energia[i];
        Color bg  = (Color){48, 32, 22, 215};
        Color bd  = (Color){180, 130, 40, 180};
        DrawRectangle(px + 18, py + 70 + i * 58, 424, 50, bg);
        DrawRectangleLines(px + 18, py + 70 + i * 58, 424, 50, bd);
        DrawText(TextFormat("%d.", i + 1),     px + 28, py + 83 + i * 58, 18, (Color){180, 150, 60, 255});
        DrawText(gs->setlist.titulo[i],         px + 55, py + 83 + i * 58, 18, (Color){255, 225, 130, 255});
        DrawText(TextFormat("E:%d", e),         px + 350, py + 83 + i * 58, 16, COR_AMARELO_MANGUE);
        barra_progresso(px + 370, py + 85 + i * 58, 60, 10, e, 10, (Color){255, 185, 50, 255});
    }
 
    DrawLine(px + 15, py + 355, px + 445, py + 355, (Color){255, 185, 50, 60});
    DrawText("[S] Fechar   [ENTER] Ordenar Setlist", px + 50, py + 365, 15,
             (Color){185, 155, 60, 255});
}
 
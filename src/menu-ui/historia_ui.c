#include "raylib.h"
#include <stdio.h>
#include "menu_iu.h"


void desenhar_ui_historia(GameState* gs) {
    if (!gs->uiHistoria) return;
 
    //Busca anos de exemplo 
    int anos[] = {1850, 1907, 1991, 1993, 1996};
    int px = SCREEN_W / 2 - 340, py = 60;
    painel_rounded(px, py, 680, 480, (Color){12, 20, 38, 248}, (Color){80, 155, 255, 255});
 
    DrawText("=== ALMANAQUE CULTURAL ===", px + 150, py + 15, 22, (Color){120, 185, 255, 255});
    DrawText("(Arvore Binaria - busca por ano)", px + 188, py + 42, 14, (Color){80, 130, 205, 255});
    DrawLine(px + 15, py + 62, px + 665, py + 62, (Color){80, 155, 255, 80});
 
    for (int i = 0; i < 5; i++) {
        Historia* h = buscar_historia(gs->arvoreHistorias, anos[i]);
        if (!h){
            continue;
        }
        int ry = py + 72 + i * 78;

        DrawRectangle(px + 18, ry, 644, 70, (Color){20, 35, 62, 210});
        DrawRectangleLines(px + 18, ry, 644, 70, (Color){60, 120, 210, 180});
        DrawText(TextFormat("%d  -  %s", h->ano, h->titulo),
                 px + 30, ry + 10, 18, (Color){160, 210, 255, 255});
        DrawText(h->descricao, px + 30, ry + 34, 14, (Color){120, 170, 220, 255});
    }
 
    DrawLine(px + 15, py + 462, px + 665, py + 462, (Color){80, 155, 255, 60});
    DrawText("[H] Fechar", px + 290, py + 468, 16, (Color){80, 130, 205, 255});
}
 
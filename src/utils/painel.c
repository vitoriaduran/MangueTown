#include "cenarios.h"
#include "raylib.h"
void painel_rounded(int x, int y, int w, int h, Color bg, Color borda) {
    DrawRectangle(x + 2, y + 2, w, h, (Color){0, 0, 0, 80});   /* sombra */
    DrawRectangle(x, y, w, h, bg);
    DrawRectangleLines(x, y, w, h, borda);
    DrawRectangleLines(x + 1, y + 1, w - 2, h - 2, (Color){borda.r, borda.g, borda.b, 60});
}
#include "cenarios.h"
#include "raylib.h"
 
void barra_progresso(int x, int y, int w, int h, float valor, float maximo, Color cor) {
    DrawRectangle(x, y, w, h, (Color){40, 40, 40, 200});
    int preench = (int)(w * (valor / maximo));
    if (preench > 0) DrawRectangle(x, y, preench, h, cor);
    DrawRectangleLines(x, y, w, h, (Color){cor.r, cor.g, cor.b, 150});
}
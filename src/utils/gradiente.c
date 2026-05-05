#include "cenarios.h"
#include "raylib.h"

void gradiente_vertical(Color topo, Color base) {
    for (int y = 0; y < SCREEN_H; y++) {
        float t = (float)y / SCREEN_H;
        Color c = {
            (unsigned char)(topo.r + (base.r - topo.r) * t),
            (unsigned char)(topo.g + (base.g - topo.g) * t),
            (unsigned char)(topo.b + (base.b - topo.b) * t),
            255
        };
        DrawLine(0, y, SCREEN_W, y, c);
    }
}
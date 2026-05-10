#include <stdio.h>
#include "raylib.h"
#include <math.h>

void desenhar_mane_galinha(float x, float y, float tempo) {
    float bx  = x + sinf(tempo * 1.6f) * 10.0f;
    float bob = sinf(tempo * 3.2f) * 3.0f;
 
    // Corpo
    DrawEllipse((int)bx, (int)(y + bob), 20, 13, (Color){225, 105, 32, 255});
    DrawEllipse((int)bx, (int)(y + bob), 15, 9, (Color){250, 140, 58, 170});
    // Padrão do casco 
    DrawLine((int)bx - 8, (int)(y + bob), (int)bx + 8, (int)(y + bob), (Color){190, 80, 22, 120});
    DrawLine((int)bx, (int)(y + bob) - 6, (int)bx, (int)(y + bob) + 6, (Color){190, 80, 22, 120});
 
    // Patas 
    for (int p = 0; p < 3; p++) {
        float sw = sinf(tempo * 4.5f + p * 1.1f) * 7;
        DrawLine((int)bx - 8, (int)(y + bob) + p * 3,
                 (int)bx - 25, (int)(y + bob) + 14 + (int)sw, (Color){200, 82, 22, 255});
        DrawLine((int)bx + 8, (int)(y + bob) + p * 3,
                 (int)bx + 25, (int)(y + bob) + 14 - (int)sw, (Color){200, 82, 22, 255});
    }
 
    // pinças animadas 
    float clAng = sinf(tempo * 2.2f) * 0.35f;
    DrawLine((int)bx - 20, (int)(y + bob) - 6, (int)bx - 33, (int)(y + bob) - 17, (Color){200, 82, 22, 255});
    DrawLine((int)bx + 20, (int)(y + bob) - 6, (int)bx + 33, (int)(y + bob) - 17, (Color){200, 82, 22, 255});
    DrawCircle((int)(bx - 33 + sinf(clAng) * 6), (int)(y + bob) - 17, 6, (Color){245, 125, 42, 255});
    DrawCircle((int)(bx + 33 - sinf(clAng) * 6), (int)(y + bob) - 17, 6, (Color){245, 125, 42, 255});
 
    // Olhos nos palitos 
    DrawLine((int)bx - 6, (int)(y + bob) - 13, (int)bx - 6, (int)(y + bob) - 23, (Color){65, 42, 20, 255});
    DrawLine((int)bx + 6, (int)(y + bob) - 13, (int)bx + 6, (int)(y + bob) - 23, (Color){65, 42, 20, 255});
    DrawCircle((int)bx - 6, (int)(y + bob) - 25, 5, (Color){22, 15, 8, 255});
    DrawCircle((int)bx + 6, (int)(y + bob) - 25, 5, (Color){22, 15, 8, 255});
    DrawPixel((int)bx - 5, (int)(y + bob) - 26, WHITE);
    DrawPixel((int)bx + 7, (int)(y + bob) - 26, WHITE);
 
    // Nome flutuante 
    float nameAlpha = 140 + sinf(tempo * 1.5f) * 60;
    DrawText("Mane Galinha", (int)bx - 50, (int)(y + bob) - 45, 12,
             (Color){255, 200, 80, (unsigned char)nameAlpha});
}

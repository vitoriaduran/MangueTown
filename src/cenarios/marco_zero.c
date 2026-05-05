#include "raylib.h"
#include "cenarios.h"
#include <math.h>
#include <stdlib.h>

void renderizar_marco_zero(GameState* gs) {
    float t = gs->tempo;
 
    // Noite de festa 
    gradiente_vertical((Color){12, 8, 45, 255}, (Color){45, 18, 95, 255});
 
    // Estrelas 
    for (int s = 0; s < 90; s++) {
        int   sx  = (s * 173 + 17) % SCREEN_W;
        int   sy  = (s * 89  + 11) % (SCREEN_H / 2 - 30);
        float bl  = 0.4f + 0.6f * sinf(t * 2.2f + s * 0.65f);
        Color sc  = {255, 255, 215, (unsigned char)(120 + bl * 110)};
        DrawPixel(sx, sy, sc);
        if (s % 4 == 0) DrawCircle(sx, sy, 1, sc);
    }
 
    //lua 
    DrawCircle(1090, 78, 48, (Color){255, 248, 205, 255});
    DrawCircle(1090, 78, 44, (Color){255, 252, 225, 255});
    DrawCircle(1090, 78, 68, (Color){255, 248, 205, 28});
 
    // Fogos
    for (int f = 0; f < 5; f++) {
        int   fx    = 160 + f * 240;
        float fase  = fmodf(t * 0.6f + f * 1.25f, 5.0f);
        if (fase < 2.5f) {
            float r = fase * 55;
            Color cores[5] = {
                {255, 80,  80,  255}, {80,  255, 120, 255},
                {80, 120,  255, 255}, {255, 210, 60,  255}, {210, 80, 255, 255}
            };
            Color fc = cores[f % 5];
            fc.a = (unsigned char)(255 - fase * 80);
            for (int p = 0; p < 10; p++) {
                float ang = p * 0.628f;
                DrawCircle(fx + (int)(cosf(ang) * r), 95 + f * 28 + (int)(sinf(ang) * r), 3, fc);
                /* rastro */
                DrawCircle(fx + (int)(cosf(ang) * r * 0.6f),
                           95 + f * 28 + (int)(sinf(ang) * r * 0.6f), 2,
                           (Color){fc.r, fc.g, fc.b, fc.a / 2});
            }
        }
    }
 
    // Calçamento
    DrawRectangle(0, SCREEN_H - 140, SCREEN_W, 140, (Color){55, 50, 68, 255});
    for (int cx = 0; cx < SCREEN_W; cx += 22) {
        for (int cy = SCREEN_H - 140; cy < SCREEN_H; cy += 13) {
            bool par = ((cx / 22) + (cy / 13)) % 2 == 0;
            Color pc  = par ? (Color){195, 190, 208, 255} : (Color){70, 65, 82, 255};
            DrawRectangle(cx + 1, cy + 1, 20, 11, pc);
        }
    }
 
    // Igreja São Pedro (no fundo tem o centro) 
    // Corpo 
    DrawRectangle(478, SCREEN_H - 530, 324, 402, COR_PAREDE);
    // Moldura topo 
    DrawRectangle(475, SCREEN_H - 535, 330, 14, COR_TELHADO);
    // Frontão
    DrawTriangle(
        (Vector2){475,  (float)(SCREEN_H - 535)},
        (Vector2){640,  (float)(SCREEN_H - 618)},
        (Vector2){805,  (float)(SCREEN_H - 535)},
        COR_PAREDE
    );
    DrawTriangle(
        (Vector2){475,  (float)(SCREEN_H - 535)},
        (Vector2){640,  (float)(SCREEN_H - 618)},
        (Vector2){805,  (float)(SCREEN_H - 535)},
        (Color){0, 0, 0, 0}
    );
    // Torres 
    DrawRectangle(478,  SCREEN_H - 635, 84, 115, COR_PAREDE);
    DrawRectangle(718,  SCREEN_H - 635, 84, 115, COR_PAREDE);
    // Pináculo das torres 
    DrawTriangle(
        (Vector2){478,  (float)(SCREEN_H - 635)},
        (Vector2){520,  (float)(SCREEN_H - 690)},
        (Vector2){562,  (float)(SCREEN_H - 635)},
        COR_TELHADO
    );
    DrawTriangle(
        (Vector2){718,  (float)(SCREEN_H - 635)},
        (Vector2){760,  (float)(SCREEN_H - 690)},
        (Vector2){802,  (float)(SCREEN_H - 635)},
        COR_TELHADO
    );
    // Janelas 
    DrawRectangle(524,  SCREEN_H - 495, 45, 65, (Color){40, 35, 75, 255});
    DrawRectangle(711,  SCREEN_H - 495, 45, 65, (Color){40, 35, 75, 255});
    // Vitral central 
    float vAlpha = 170 + sinf(t * 1.4f) * 55;
    DrawRectangle(596, SCREEN_H - 515, 88, 85, (Color){90, 70, 195, (unsigned char)vAlpha});
    DrawEllipse(640, SCREEN_H - 430, 44, 10, (Color){90, 70, 195, (unsigned char)vAlpha});
    // Portal 
    DrawRectangle(603, SCREEN_H - 400, 74, 88, (Color){35, 28, 58, 255});
    DrawEllipse(640,   SCREEN_H - 315, 37, 10, (Color){35, 28, 58, 255});
    // Cruz no topo 
    DrawRectangle(637, SCREEN_H - 710, 6, 25, (Color){210, 195, 165, 255});
    DrawRectangle(630, SCREEN_H - 704, 20, 6,  (Color){210, 195, 165, 255});
 
    // Casarões coloniais
    // Esquerdo 
    DrawRectangle(0, SCREEN_H - 435, 478, 308, (Color){205, 180, 148, 255});
    DrawRectangle(0, SCREEN_H - 440, 480, 14, COR_TELHADO);
    for (int j = 0; j < 4; j++) {
        DrawRectangle(30 + j * 112, SCREEN_H - 408, 58, 75, (Color){42, 35, 72, 255});
        float la = 90 + sinf(t * 0.8f + j) * 45;
        DrawRectangle(33 + j * 112, SCREEN_H - 405, 52, 69, (Color){255, 195, 75, (unsigned char)la});
    }
    DrawRectangle(185, SCREEN_H - 320, 85, 105, (Color){42, 35, 72, 255});
    // Direito 
    DrawRectangle(802, SCREEN_H - 418, 478, 292, (Color){228, 198, 160, 255});
    DrawRectangle(800, SCREEN_H - 423, 482, 14, COR_TELHADO);
    for (int j = 0; j < 4; j++) {
        DrawRectangle(818 + j * 112, SCREEN_H - 390, 58, 72, (Color){42, 35, 72, 255});
        float la = 90 + sinf(t * 0.9f + j * 1.1f) * 45;
        DrawRectangle(821 + j * 112, SCREEN_H - 387, 52, 66, (Color){255, 195, 75, (unsigned char)la});
    }
    DrawRectangle(1005, SCREEN_H - 308, 85, 100, (Color){42, 35, 72, 255});
 
    // Palco do show 
    DrawRectangle(340, SCREEN_H - 188, 600, 55, (Color){115, 75, 48, 255});
    DrawRectangle(340, SCREEN_H - 192, 600, 10, (Color){145, 95, 58, 255});
    // bordas/pernas do palco 
    for (int p = 0; p < 6; p++) {
        DrawRectangle(352 + p * 100, SCREEN_H - 140, 22, 28, (Color){95, 60, 38, 255});
    }
    // Luzes do palco (spots coloridos) 
    Color spotCores[] = {
        {255, 50, 60, 220}, {60, 255, 110, 220}, {55, 105, 255, 220},
        {255, 205, 50, 220}, {205, 55, 255, 220}, {255, 120, 40, 220}
    };
    for (int l = 0; l < 6; l++) {
        int   lx = 360 + l * 100;
        float ph = fmodf(t * 2.2f + l * 0.85f, 6.28f);
        Color lc  = spotCores[l];
        lc.a = (unsigned char)(140 + sinf(ph) * 75);
        // spot 
        DrawCircle(lx, SCREEN_H - 200, 17, lc);
        // cone de luz 
        DrawTriangle(
            (Vector2){(float)(lx - 17), (float)(SCREEN_H - 185)},
            (Vector2){(float)(lx + 17), (float)(SCREEN_H - 185)},
            (Vector2){(float)(lx + 45), (float)(SCREEN_H - 140)},
            (Color){lc.r, lc.g, lc.b, 38}
        );
    }
    // Caixa de som 
    DrawRectangle(345, SCREEN_H - 245, 55, 60, (Color){30, 25, 40, 255});
    DrawCircle(373, SCREEN_H - 220, 20, (Color){55, 50, 65, 255});
    DrawCircle(373, SCREEN_H - 220, 14, (Color){40, 35, 50, 255});
    DrawRectangle(880, SCREEN_H - 245, 55, 60, (Color){30, 25, 40, 255});
    DrawCircle(908, SCREEN_H - 220, 20, (Color){55, 50, 65, 255});
    DrawCircle(908, SCREEN_H - 220, 14, (Color){40, 35, 50, 255});
 
    // Bandeirinhas de festa 
    for (int b = 0; b < 18; b++) {
        float bx1 = 80.0f + b * 68.0f;
        float by1 = 248.0f + sinf((float)b * 0.55f + t * 0.4f) * 28.0f;
        float bx2 = bx1 + 68;
        float by2 = 248.0f + sinf((float)(b + 1) * 0.55f + t * 0.4f) * 28.0f;
        DrawLine((int)bx1, (int)by1, (int)bx2, (int)by2, (Color){170, 170, 170, 185});
        Color cbands[] = {
            {255, 55, 60, 225}, {255, 205, 55, 225}, {55, 205, 100, 225},
            {55, 105, 255, 225}, {205, 55, 255, 225}
        };
        Color cb = cbands[b % 5];
        DrawTriangle(
            (Vector2){bx1, by1},
            (Vector2){bx1 + 16, by1 + 22},
            (Vector2){bx1 + 32, by1},
            cb
        );
    }
 
    // Plateia: bonecos animados
    for (int p = 0; p < gs->plateia.tamanho && p < 11; p++) {
        int  px = 40 + p * 112;
        int  py = SCREEN_H - 158;
        Color cp = {
            (unsigned char)(90 + (p * 23) % 130),
            (unsigned char)(70 + (p * 17) % 110),
            (unsigned char)(175 + (p * 8) % 70),
            255
        };
        // cabeça
        DrawCircle(px, py - 32, 13, cp);
        // corpo 
        DrawRectangle(px - 8, py - 19, 16, 24, cp);
        // braços levantados com animação 
        float sw = sinf(t * 3.5f + p * 0.6f) * 18;
        DrawLine(px - 8,  py - 12, px - 22, py - 22 + (int)sw,  cp);
        DrawLine(px + 8,  py - 12, px + 22, py - 22 - (int)sw,  cp);
        // pernas 
        DrawLine(px - 4, py + 5, px - 8,  py + 18, cp);
        DrawLine(px + 4, py + 5, px + 8,  py + 18, cp);
    }
 
    // Contorno do calçamento 
    DrawRectangle(0, SCREEN_H - 18, SCREEN_W, 18, (Color){38, 34, 50, 255});
}
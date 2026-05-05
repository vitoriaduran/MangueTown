#include "raylib.h"
#include "cenarios.h"
#include <math.h>
#include <stdlib.h>

void renderizar_ponte(GameState* gs) {
    float t = gs->tempo;
 
    /* Céu azul de meio-dia */
    gradiente_vertical((Color){25, 110, 215, 255}, (Color){90, 175, 255, 255});
 
    /* Nuvens tropicais */
    for (int n = 0; n < 5; n++) {
        float nx = fmodf(60.0f + n * 248.0f + t * 11.0f, (float)SCREEN_W + 260) - 130;
        int   ny = 75 + (n % 3) * 45;
        Color nc = {255, 255, 255, 230};
        DrawEllipse((int)nx, ny, 100, 32, nc);
        DrawEllipse((int)nx - 45,  ny + 10,  65,  22, nc);
        DrawEllipse((int)nx + 45,  ny + 8,   60,  20, nc);
        DrawEllipse((int)nx - 15,  ny - 20,  50,  20, nc);
    }
 
    /* Silhueta do Recife ao fundo */
    int bx[] = {0,  90, 175, 265, 365, 450, 545, 640, 740, 845, 945, 1050, 1150, 1220};
    int bh[] = {200,290,185, 330, 260, 310, 228, 360, 275, 315, 248, 300,  205,  270};
    int bw[] = {85, 70, 80,  90,  75,  85,  70,  95,  80,  85,  90,  75,   85,   90};
    Color cidadeBg = {55, 95, 155, 115};
    for (int i = 0; i < 14; i++) {
        DrawRectangle(bx[i], SCREEN_H - 195 - bh[i], bw[i], bh[i] + 55, cidadeBg);
        /* janelas */
        for (int j = 0; j < bh[i] / 30; j++) {
            for (int k = 0; k < 2; k++) {
                DrawRectangle(bx[i] + 10 + k * 28, SCREEN_H - 190 - bh[i] + j * 30, 14, 18,
                              (Color){80, 130, 200, 80});
            }
        }
    }
 
    /* Rio Capibaribe */
    DrawRectangle(0, SCREEN_H - 130, SCREEN_W, 130, COR_RIO);
    /* Reflexo do céu */
    for (int i = 0; i < 5; i++) {
        float wx = fmodf((float)i * 290 + t * 38, (float)SCREEN_W + 120);
        DrawEllipse((int)wx, SCREEN_H - 72, 108, 14, (Color){110, 158, 225, 90});
    }
 
    /* Barcos */
    for (int b = 0; b < 3; b++) {
        float bxb = fmodf(150.0f + b * 420.0f + t * 18.0f, (float)SCREEN_W + 100);
        int   byb  = SCREEN_H - 125;
        float bob  = sinf(t * 1.2f + b * 2.0f) * 3;
        /* casco */
        DrawRectangle((int)bxb - 32, byb + (int)bob, 64, 22, (Color){155, 95, 55, 255});
        /* vela */
        DrawTriangle(
            (Vector2){bxb,          (float)(byb - 42 + (int)bob)},
            (Vector2){bxb,          (float)(byb      + (int)bob)},
            (Vector2){bxb + 34,     (float)(byb + 18 + (int)bob)},
            (Color){245, 245, 235, 235}
        );
        DrawLine((int)bxb, byb - 42 + (int)bob, (int)bxb, byb + (int)bob, (Color){100, 65, 40, 255});
    }
 
    /* PONTE — pilares */
    int numPilares = 6;
    for (int p = 0; p < numPilares; p++) {
        int px = 80 + p * 210;
        /* pilar */
        DrawRectangle(px - 16, SCREEN_H - 310, 32, 190, COR_PEDRA);
        DrawRectangle(px - 19, SCREEN_H - 318, 38, 22, COR_PEDRA_ESC);
        /* base na água */
        DrawRectangle(px - 22, SCREEN_H - 130, 44, 42, COR_PEDRA_ESC);
        /* capitel decorativo */
        DrawRectangle(px - 22, SCREEN_H - 322, 44, 10, (Color){160, 140, 120, 255});
        /* arco entre pilares */
        if (p < numPilares - 1) {
            int   px2  = 80 + (p + 1) * 210;
            int   midX = (px + px2) / 2;
            int   span = (px2 - px) / 2 - 12;
            DrawEllipse(midX, SCREEN_H - 298, span, 42, COR_PEDRA);
            /* sombra do arco */
            DrawEllipse(midX, SCREEN_H - 288, span - 10, 28, (Color){110, 95, 78, 110});
            /* detalhes de alvenaria */
            for (int k = -1; k <= 1; k++) {
                DrawLine(midX + k * span / 2, SCREEN_H - 298,
                         midX,                SCREEN_H - 340,
                         (Color){140, 120, 100, 80});
            }
        }
    }
 
    /* Tabuleiro da ponte */
    DrawRectangle(60, SCREEN_H - 175, SCREEN_W - 120, 28, COR_PEDRA);
    DrawRectangle(60, SCREEN_H - 178, SCREEN_W - 120, 8, COR_PEDRA_ESC);
 
    /* Parapeitos */
    DrawRectangle(60, SCREEN_H - 222, SCREEN_W - 120, 10, COR_PEDRA);
    for (int i = 0; i < 22; i++) {
        int rx = 70 + i * 52;
        DrawRectangle(rx, SCREEN_H - 218, 9, 48, COR_PEDRA_ESC);
        DrawRectangle(rx - 2, SCREEN_H - 225, 13, 10, COR_PEDRA);
    }
 
    /* Calçamento da ponte */
    DrawRectangle(0, SCREEN_H - 155, SCREEN_W, 18, COR_CALCADA);
    for (int i = 0; i < 22; i++) {
        DrawLine(i * 60, SCREEN_H - 155, i * 60, SCREEN_H - 137, (Color){175, 155, 125, 120});
    }
    for (int j = 0; j < 3; j++) {
        DrawLine(0, SCREEN_H - 155 + j * 6, SCREEN_W, SCREEN_H - 155 + j * 6,
                 (Color){175, 155, 125, 70});
    }
 
    /* Lanternas históricas */
    for (int l = 0; l < 7; l++) {
        int  lx  = 90 + l * 190;
        float brilho = 0.5f + 0.5f * sinf(t * 1.8f + l * 0.9f);
        Color luzC = {255, 215, 90, (unsigned char)(160 + brilho * 60)};
        /* poste */
        DrawRectangle(lx - 3, SCREEN_H - 265, 6, 95, (Color){75, 65, 55, 255});
        /* braço */
        DrawRectangle(lx - 3, SCREEN_H - 268, 22, 5, (Color){75, 65, 55, 255});
        /* cúpula */
        DrawRectangle(lx + 6, SCREEN_H - 278, 24, 14, (Color){70, 60, 50, 255});
        DrawEllipse(lx + 18, SCREEN_H - 280, 13, 5, (Color){80, 70, 60, 255});
        /* luz */
        DrawCircle(lx + 18, SCREEN_H - 271, 8, luzC);
        DrawCircle(lx + 18, SCREEN_H - 271, 20, (Color){255, 215, 90, (unsigned char)(40 * brilho)});
    }
 
    /* Faixa do rio em baixo */
    DrawRectangle(0, SCREEN_H - 25, SCREEN_W, 25, (Color){40, 70, 120, 255});
}
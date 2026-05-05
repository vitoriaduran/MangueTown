#include "raylib.h"
#include "cenarios.h"
#include <math.h>
#include <stdlib.h>

void desenhar_arvore_mangue(int x, int altura, float tempo) {
    /* Raízes aéreas */
    for (int i = 0; i < 6; i++) {
        int rx = x - 35 + i * 14;
        DrawLine(x, SCREEN_H - 135 - altura / 2, rx, SCREEN_H - 135, COR_MANGUE_RAIZ);
    }
    /* Tronco */
    DrawRectangle(x - 9, SCREEN_H - 135 - altura, 18, altura, COR_MANGUE_RAIZ);
 
    /* Copa com balanço animado */
    float sw = sinf(tempo * 0.7f + x * 0.009f) * 6.0f;
    int   cx  = x + (int)sw;
    int   cy  = SCREEN_H - 135 - altura;
 
    DrawCircle(cx, cy, 58, COR_MANGUE_FOLHA);
    DrawCircle(cx - 28, cy + 22, 38, COR_MANGUE_FOLHA);
    DrawCircle(cx + 28, cy + 22, 38, COR_MANGUE_FOLHA);
    DrawCircle(cx, cy - 18, 42, COR_MANGUE_FOLHA2);
    DrawCircle(cx - 18,  cy + 8,  30, COR_MANGUE_FOLHA2);
    DrawCircle(cx + 18,  cy + 8,  30, COR_MANGUE_FOLHA2);
}
 
void desenhar_caranguejo_deco(int cx, float tempo, int idx) {
    float bx = (float)cx + sinf(tempo * 1.8f + idx * 2.1f) * 22.0f;
    int   by = SCREEN_H - 148;
 
    /* Corpo */
    DrawEllipse((int)bx, by, 15, 9, (Color){210, 90, 30, 255});
    DrawEllipse((int)bx, by, 10, 6, (Color){240, 130, 60, 160});
    /* Patas */
    for (int p = 0; p < 3; p++) {
        float sw = sinf(tempo * 5 + p * 1.2f) * 6;
        DrawLine((int)bx - 6, by + 2, (int)bx - 20 + p * 4, by + 14 + (int)sw, (Color){190, 70, 20, 255});
        DrawLine((int)bx + 6, by + 2, (int)bx + 20 - p * 4, by + 14 - (int)sw, (Color){190, 70, 20, 255});
    }
    /* Pinças */
    DrawLine((int)bx - 15, by - 4, (int)bx - 26, by - 14, (Color){190, 70, 20, 255});
    DrawLine((int)bx + 15, by - 4, (int)bx + 26, by - 14, (Color){190, 70, 20, 255});
    DrawCircle((int)bx - 26, by - 14, 5, (Color){230, 110, 40, 255});
    DrawCircle((int)bx + 26, by - 14, 5, (Color){230, 110, 40, 255});
    /* Olhos em palito */
    DrawLine((int)bx - 5, by - 9, (int)bx - 5, by - 18, (Color){60, 40, 20, 255});
    DrawLine((int)bx + 5, by - 9, (int)bx + 5, by - 18, (Color){60, 40, 20, 255});
    DrawCircle((int)bx - 5, by - 20, 4, (Color){20, 15, 10, 255});
    DrawCircle((int)bx + 5, by - 20, 4, (Color){20, 15, 10, 255});
    DrawPixel((int)bx - 4, by - 21, WHITE);
    DrawPixel((int)bx + 6, by - 21, WHITE);
}
 
void renderizar_manguezal(GameState* gs) {
    float t = gs->tempo;
 
    /* Céu laranja */
    gradiente_vertical((Color){255, 150, 70, 255}, (Color){220, 80, 40, 255});
 
    /* Sol se pondo */
    float sunX = 880.0f + sinf(t * 0.04f) * 30.0f;
    int   sunY = 115;
    DrawCircle((int)sunX, sunY, 58, (Color){255, 210, 90, 255});
    DrawCircle((int)sunX, sunY, 52, (Color){255, 240, 160, 255});
    for (int i = 0; i < 10; i++) {
        float ang = (float)i * 0.628f;
        DrawCircle((int)(sunX + cosf(ang) * 75), sunY + (int)(sinf(ang) * 75), 12,
                   (Color){255, 200, 80, 70});
    }
 
    /* Nuvens cor-de-rosa */
    for (int n = 0; n < 4; n++) {
        float nx  = fmodf(150.0f + n * 320.0f + t * 14.0f, (float)SCREEN_W + 200) - 100;
        int   ny  = 70 + n * 38;
        Color nc  = {255, 160, 90, 160};
        DrawEllipse((int)nx, ny, 110, 28, nc);
        DrawEllipse((int)nx - 55, ny + 8, 75, 20, nc);
        DrawEllipse((int)nx + 55, ny + 6, 70, 18, nc);
    }
 
    /* Árvores de fundo */
    for (int i = 0; i < 5; i++) {
        int ax = 50 + i * 255;
        Color sfol = {15, 75, 35, 190};
        DrawCircle(ax, SCREEN_H - 215 - (i % 2) * 25, 48, sfol);
        DrawRectangle(ax - 7, SCREEN_H - 215 - (i % 2) * 25, 14, 110, (Color){60, 40, 25, 190});
    }
 
    /* Água */
    DrawRectangle(0, SCREEN_H - 130, SCREEN_W, 130, COR_MANGUE_AGUA);
    /* Reflexo do sol na água */
    for (int i = 0; i < 6; i++) {
        float rx = sunX - 25 + i * 12 + sinf(t * 2.5f + i) * 18;
        DrawEllipse((int)rx, SCREEN_H - 80, 45 - i * 5, 7, (Color){255, 200, 80, 90});
    }
    /* Ondas */
    for (int i = 0; i < 7; i++) {
        float wx = fmodf((float)i * 200 + t * 45, (float)SCREEN_W + 120);
        DrawEllipse((int)wx, SCREEN_H - 95, 85, 9, (Color){80, 150, 120, 70});
    }
 
    /* Lama */
    DrawRectangle(0, SCREEN_H - 140, SCREEN_W, 18, COR_MANGUE_LAMA);
 
    /* Árvores de frente */
    desenhar_arvore_mangue(120,  190, t);
    desenhar_arvore_mangue(420,  165, t);
    desenhar_arvore_mangue(760,  180, t);
    desenhar_arvore_mangue(1050, 175, t);
    desenhar_arvore_mangue(1200, 145, t);
 
    /* Reflexos das árvores na água */
    for (int i = 0; i < 5; i++) {
        int ax = 120 + i * 270;
        for (int j = 0; j < 3; j++) {
            float ox = sinf(t * 1.3f + j * 1.8f + i) * 9;
            DrawEllipse(ax + (int)ox, SCREEN_H - 90 + j * 10, 55 - j * 10, 5,
                        (Color){40, 110, 55, 50});
        }
    }
 
    /* Chão caminhável */
    DrawRectangle(0, SCREEN_H - 148, SCREEN_W, 20, (Color){95, 72, 48, 255});
    for (int i = 0; i < 10; i++) {
        int px = 60 + i * 125;
        DrawEllipse(px, SCREEN_H - 143, 22, 8, (Color){75, 55, 32, 255});
    }
 
    /* Caranguejos decorativos */
    desenhar_caranguejo_deco(280, t, 0);
    desenhar_caranguejo_deco(640, t, 1);
    desenhar_caranguejo_deco(1000, t, 2);
 
    /* Lixo proporcional à saúde do manguezal */
    int numLixo = (100 - gs->saudeManguezal) / 12;
    for (int i = 0; i < numLixo; i++) {
        int lx = 180 + i * 160;
        /* garrafa */
        DrawRectangle(lx, SCREEN_H - 125, 10, 22, (Color){180, 220, 255, 210});
        DrawRectangle(lx + 2, SCREEN_H - 128, 6, 6, (Color){140, 180, 220, 210});
        /* lata */
        DrawRectangle(lx + 35, SCREEN_H - 122, 17, 19, (Color){230, 190, 55, 210});
        DrawEllipse(lx + 43, SCREEN_H - 122, 9, 3, (Color){255, 220, 80, 210});
    }
 
    /* Névoa de mangue */
    for (int i = 0; i < 4; i++) {
        float fx = fmodf((float)i * 380 + t * 18, (float)SCREEN_W + 300);
        DrawEllipse((int)fx, SCREEN_H - 165, 220, 32, (Color){160, 210, 180, 35});
    }
}
 
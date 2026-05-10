#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "personagens.h"


void desenhar_zezinho(Personagem p, float tempo) {

    float x = p.posicao.x;
    float y = p.posicao.y;
    bool movendo = p.movendo;
    bool esquerda = p.esquerda;

    float legSw = movendo ? sinf(tempo * 8.5f) * 13.0f : 0;
    int   dir   = esquerda ? -1 : 1;
 
    // Sombra 
    DrawEllipse((int)x, (int)y + 6, 20, 7, (Color){0, 0, 0, 75});
 
    // Pernas 
    DrawLine((int)x - 7, (int)y - 5,  (int)x - 12 * dir, (int)y + (int)legSw,        (Color){35, 85, 165, 255});
    DrawLine((int)x + 7, (int)y - 5,  (int)x + 12 * dir, (int)y - (int)legSw,        (Color){35, 85, 165, 255});
    // Pés 
    DrawEllipse((int)x - 12 * dir,  (int)y + (int)legSw + 2,  8, 4, (Color){80, 55, 30, 255});
    DrawEllipse((int)x + 12 * dir,  (int)y - (int)legSw + 2,  8, 4, (Color){80, 55, 30, 255});
 
    // Corpo (camiseta mangue — verde escuro) 
    DrawRectangle((int)x - 13, (int)y - 38, 26, 33, (Color){45, 135, 75, 255});
    DrawRectangle((int)x - 13, (int)y - 38, 26, 6,  (Color){35, 110, 60, 255});
    // Bolso 
    DrawRectangle((int)x + 2, (int)y - 25, 8, 7, (Color){35, 110, 60, 255});
 
    // Braços 
    float armSw = movendo ? sinf(tempo * 8.5f) * 0.5f : 0;
    DrawLine((int)x - 13, (int)y - 30, (int)x - 22, (int)y - 14 + (int)(armSw * 10), (Color){205, 165, 120, 255});
    DrawLine((int)x + 13, (int)y - 30, (int)x + 22, (int)y - 14 - (int)(armSw * 10), (Color){205, 165, 120, 255});
 
    // Pescoço 
    DrawRectangle((int)x - 5, (int)y - 42, 10, 8, (Color){205, 165, 120, 255});
 
    // Cabeça 
    DrawCircle((int)x, (int)y - 52, 20, (Color){205, 165, 120, 255});
 
    // Chapéu de palha 
    DrawEllipse((int)x, (int)y - 68, 25, 7, (Color){185, 145, 58, 255});
    DrawRectangle((int)x - 14, (int)y - 78, 28, 16, (Color){165, 125, 48, 255});
    DrawEllipse((int)x, (int)y - 78, 15, 4, (Color){145, 105, 38, 255});
    // Fita do chapéu 
    DrawRectangle((int)x - 14, (int)y - 70, 28, 4, (Color){200, 50, 50, 255});
 
    // Olhos 
    DrawCircle((int)x - 7, (int)y - 54, 4, (Color){35, 25, 15, 255});
    DrawCircle((int)x + 7, (int)y - 54, 4, (Color){35, 25, 15, 255});
    DrawPixel((int)x - 6, (int)y - 55, WHITE);
    DrawPixel((int)x + 8, (int)y - 55, WHITE);
 
    // Sorriso 
    DrawLine((int)x - 6, (int)y - 46, (int)x - 2, (int)y - 43, (Color){90, 45, 22, 255});
    DrawLine((int)x - 2, (int)y - 43, (int)x + 6, (int)y - 46, (Color){90, 45, 22, 255});
}
#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include "raylib.h"
#include <stdbool.h>

typedef struct {
   Vector2 posicao;
   float velocidade;
   bool movendo;
   bool esquerda;
}Personagem;

void desenhar_zezinho(Personagem p, float tempo);

void desenhar_mane_galinha(float x, float y, float tempo);

#endif
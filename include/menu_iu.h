#ifndef MENU_IU_H
#define MENU_iU_h

#include "raylib.h"
#include "cenarios.h" // Necessário porque o HUD usa GameState e Fase
#include "banda.h"


void desenhar_hud(GameState* gs);

//funçoes da interface grafica

void desenhar_ui_mochila(GameState* gs);
void desenhar_ui_banda(GameState* gs);

#endif
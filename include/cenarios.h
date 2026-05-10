#ifndef CENARIOS_H
#define CENARIOS_H

#include "raylib.h"
#include "mapa.h"
#include "mochila.h"   
#include "banda.h"
#include "plateia.h"


// definições de Cores Temáticas 

#define COR_MANGUE_RAIZ  (Color){ 75, 55, 35, 255 }
#define COR_MANGUE_FOLHA (Color){ 30, 95, 45, 255 }
#define COR_MANGUE_FOLHA2 (Color){ 45, 115, 65, 255 }
#define COR_MANGUE_AGUA  (Color){ 40, 85, 105, 200 }
#define COR_MANGUE_LAMA  (Color){ 55, 42, 30, 255 }
#define COR_RIO          (Color){ 55, 105, 185, 255 }
#define COR_PEDRA        (Color){ 185, 175, 160, 255 }
#define COR_PEDRA_ESC    (Color){ 140, 130, 115, 255 }
#define COR_CALCADA      (Color){ 210, 195, 175, 255 }
#define COR_PAREDE       (Color){ 235, 215, 185, 255 }
#define COR_TELHADO      (Color){ 165, 75, 55, 255 }
#define COR_HUD_BG            (Color){0,   0,   0,   150}
#define COR_AMARELO_MANGUE    (Color){255, 220, 80,  255}
#define COR_VERDE_MANGUE      (Color){80,  220, 100, 255}
#define COR_ROXO_MANGUE       (Color){180, 120, 255, 255}

#ifndef SCREEN_W
#define SCREEN_W 850
#define SCREEN_H 450
#endif


typedef struct{
    float tempo;
    int saudeManguezal;
    int reputacao;
    int numMusicos;
    char msgTela[80];
    float msgTimer;

    FilaPlateia plateia;
    Musico *banda;
    mochila mochila;
    Fase *faseAtual;
    
    bool uiMochila;
    bool uiBanda;
 
}GameState;

//funcoes

void gradiente_vertical(Color topo, Color base);
void  painel_rounded(int x, int y, int w, int h, Color bg, Color borda);
void barra_progresso(int x, int y, int w, int h, float valor, float maximo, Color cor);
//funçoes do manguezal
void desenhar_arvore_mangue(int x, int altura, float tempo);
void desenhar_caranguejo_deco(int cx, float tempo, int idx);
void renderizar_manguezal(GameState* gs);

//funçoes da ponte 
void renderizar_ponte(GameState* gs);

//funçoes marco zero/ patio de sao pedro
void renderizar_marco_zero(GameState* gs);

#endif
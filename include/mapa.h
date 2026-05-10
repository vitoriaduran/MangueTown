#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"

typedef enum  {FASE_MANGUEZAL = 0, FASE_PONTE, FASE_MARCO_ZERO, FASE_COUNT} FaseID;

typedef struct Fase{
    FaseID id;
    char nome[60];
    struct Fase *anterior;
    struct Fase *next;

}Fase;

Fase *criar_mapa(void);

#endif
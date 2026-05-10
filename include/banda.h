#ifndef BANDA_H
#define BANDA_H

#include "raylib.h"

typedef struct Musico {
    char nome[50];
    char instrumento[50];
    int  energia;           
    struct Musico* next;
} Musico;

void inserir_musico(Musico **banda, int *count, const char *nome, const char *instr, int energia);

#endif
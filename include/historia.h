#ifndef HISTORIAS_H
#define HISTORIAS_H

#include <stdlib.h>
#include <string.h>

typedef struct Historia {
    int ano;
    char titulo[100];
    char descricao[220];
    struct Historia *esquerda;
    struct Historia *direita;
} Historia;

Historia* inserir_historia(Historia* raiz, int ano, const char* titulo, const char* desc);
Historia* buscar_historia(Historia* raiz, int ano);

#endif
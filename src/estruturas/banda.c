//lista encadeada

#include "raylib.h"
#include "banda.h"
#include <stdio.h>
#include <string.h>

void inserir_musico(Musico **banda, int *count, const char *nome, const char *instr, int energia){
    Musico *novo = (Musico*)malloc(sizeof(Musico));
    strncpy(novo->nome, nome, 49);
    strncpy(novo->instrumento, instr, 49);
    novo -> energia = energia;
    novo -> next = *banda;
    *banda = novo;
    (*count )++;
}
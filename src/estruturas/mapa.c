#include "raylib.h"
#include "mapa.h"
#include <stdlib.h>
#include <string.h>

Fase * criar_mapa(void){
    Fase *manguezal = (Fase*)malloc(sizeof(Fase));
    Fase *ponte = (Fase*)malloc(sizeof(Fase));
    Fase *marco_zero = (Fase*)malloc(sizeof(Fase));

    manguezal->id = FASE_MANGUEZAL;
    strncpy(manguezal -> nome, "Manguezal de Recife", 59);
    manguezal -> anterior = NULL;
    manguezal -> next =  ponte;

    ponte -> id =  FASE_PONTE;
    strncpy(ponte -> nome, "Ponte Mauricio de Nassau", 59);
    ponte -> anterior = manguezal;
    ponte -> next = marco_zero;

    marco_zero -> id = FASE_MARCO_ZERO;
    strncpy(marco_zero -> nome, "Marco zero - Pátio de São Pedro", 59);
    marco_zero -> anterior = ponte;
    marco_zero -> next = NULL;

    return manguezal;
}


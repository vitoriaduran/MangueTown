#include "raylib.h"
#include "setlist.h"
#include <stdlib.h>
// Insertion Sort no Setlist 
void ordenar_setlist(Setlist* s) {
    for (int i = 1; i < s->count; i++) {
        int   keyE = s->energia[i];
        char  keyT[50];
        strncpy(keyT, s->titulo[i], 49);
        int j = i - 1;
        while (j >= 0 && s->energia[j] > keyE) {
            s->energia[j + 1] = s->energia[j];
            strncpy(s->titulo[j + 1], s->titulo[j], 49);
            j--;
        }
        s->energia[j + 1] = keyE;
        strncpy(s->titulo[j + 1], keyT, 49);
    }
}
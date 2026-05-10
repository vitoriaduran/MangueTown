#include <stdlib.h>
#include "raylib.h"
#include "mochila.h"
#include <string.h>

//pilha

bool push_mochila(mochila *m, const char *item){

    if (m ->topo >= MAX_ITENS_MOCHILA - 1){ //verifica se atingiu o maximo de itens, se atingiu retorna false p/ evitar stack overflow
        return false;
    }
    m->topo ++;
    strncpy(m->itens[m->topo], item, 49);
    return true;

}

const char* remover_mochila(mochila *m){
    if (m ->topo < 0){
        return NULL; //se estiver vazia nao há o que remover
    }
    return m->itens[m->topo--];
}
const char *mostrar_topo(mochila *m){
    if (m->topo < 0 ){
        return NULL; //se estiver vazia nao há o que olhar
    }
    return m->itens[m->topo];
}
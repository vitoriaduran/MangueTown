//fila
#include "raylib.h"
#include "plateia.h"
#include "string.h"
bool inserir_fila(FilaPlateia *f, const char*nome){
    if (f->tamanho >= MAX_PLATEIA){ //se a plateia estiver cheia retorne false
        return false;
    }
    strncpy(f->nomes[f->fim], nome, 49);
    f ->fim = (f->fim + 1) % MAX_PLATEIA; //o resto da divisao% faz com que se chega ao fim, ele volte pra pos 0
    f->tamanho ++;
    return true;

}

bool remover_fila(FilaPlateia *f){
    if (f->tamanho <= 0){ //se nao tiver ninguem, retorna false
        return false;
    }
    f->inicio = (f->inicio + 1) % MAX_PLATEIA;
    f->tamanho --;
    return true;
}
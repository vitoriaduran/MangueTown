#include "historia.h"
#include "raylib.h"
#include "string.h"

Historia *inserir_historia(Historia *raiz, int ano, const char*titulo, const char*desc){
    if (!raiz){
        Historia *h = (Historia*)malloc(sizeof(Historia));
        h->ano = ano;
        strncpy(h->titulo, titulo, 99);
        strncpy(h->descricao, desc, 219);
        h->esquerda = NULL;
        h->direita = NULL;
        return h;
    }
     
    if (ano < raiz->ano){
        raiz->esquerda = inserir_historia(raiz->esquerda, ano,titulo, desc);
    }
    else if(ano > raiz->ano){
        raiz->direita = inserir_historia(raiz->direita, ano, titulo, desc);
    }
    
    return raiz;
}



Historia* buscar_historia(Historia* raiz, int ano) {
    if (!raiz || raiz->ano == ano){
     return raiz;
    }
    if (ano < raiz->ano){
        return buscar_historia(raiz->esquerda, ano);
    }
    else{
        return buscar_historia(raiz->direita, ano);
    }
}
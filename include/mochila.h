#ifndef MOCHILA_H
#define MOCHILA_H
#define MAX_ITENS_MOCHILA 10

typedef struct mochila{
    char itens[MAX_ITENS_MOCHILA][50];
    int topo; //mochila vazia

}mochila;

bool push_mochila(mochila *m, const char *item);
const char *remover_mochila(mochila *m);
const char *mostrar_topo(mochila *m);

#endif
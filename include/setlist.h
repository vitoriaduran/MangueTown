#ifndef SETLIST_H
#define SETLIST_H

#define MAX_SETLIST 10

typedef struct {
    char titulo[MAX_SETLIST][50]; 
    int energia[MAX_SETLIST];     
    int count;                    
}Setlist;

void ordenar_setlist(Setlist* s);

#endif
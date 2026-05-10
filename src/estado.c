#include "raylib.h"
#include <string.h>
#include "cenarios.h"  // Puxa o GameState
#include "mochila.h"   // Puxa push_mochila
#include "banda.h"     // Puxa inserir_musico
#include "plateia.h"   // Puxa inserir_fila (ou enqueue)
#include "historia.h" // Puxa inserir_historia
#include "mapa.h"

GameState inicializar_jogo(void){
    GameState gs;

     memset(&gs, 0, sizeof(GameState));
 
    gs.faseAtual        = criar_mapa();
    gs.reputacao        = 50;
    gs.saudeManguezal   = 70;
    gs.zezX             = 300.0f;
    gs.zezY             = (float)(SCREEN_H - 170);
    gs.jogoRodando      = true;
    gs.mochila.topo     = -1;

     // Historias culturais na arvore 
    gs.arvoreHistorias = inserir_historia(NULL, 1907, "Nascimento do Frevo",
        "O frevo nasceu em Recife como fusao de polca e maxixe.\nMusica agitada que acompanha o passo do frevo.");

    gs.arvoreHistorias = inserir_historia(gs.arvoreHistorias, 1850, "Maracatu",
        "Cortejo afro-brasileiro com origem em Pernambuco.\nRaizes na coroacao dos reis africanos escravizados.");

    gs.arvoreHistorias = inserir_historia(gs.arvoreHistorias, 1991, "Manguebeat",
        "Movimento cultural que misturou mangue com rock,\nbaixa frequencia e eletronico. Surgiu em Recife.");

    gs.arvoreHistorias = inserir_historia(gs.arvoreHistorias, 1993, "Chico Science",
        "Chico Science e Nacao Zumbi lancam Da Lama ao Caos.\nAlbum fundador do Manguebeat.");

    gs.arvoreHistorias = inserir_historia(gs.arvoreHistorias, 1996, "Afogados da Ingazeira",
        "Cena musical do interior de Pernambuco cresce.\nFusion de forro com ritmos modernos.");
    
     // Setlist inicial 
    gs.setlist.count = 5;
    int    energias[] = {7, 2, 9, 4, 6};
    char*  titulos[] = {"Monólogo ao Pé do Ouvido", "A Cidade", "Da Lama ao Caos", "Sangue de Bairro", "Etnia"};

    for (int i = 0; i < 5; i++) {
        gs.setlist.energia[i] = energias[i];
        strncpy(gs.setlist.titulo[i], titulos[i], 49);
    }
 
    //Plateia inicial 
    enqueue_plateia(&gs.plateia, "Ze das Couves");
    enqueue_plateia(&gs.plateia, "Dona Toinha");
    enqueue_plateia(&gs.plateia, "Menino do Mangue");
 
    //Itens iniciais na mochila 
    push_mochila(&gs.mochila, "Concha do Mangue");
    push_mochila(&gs.mochila, "Partitura Velha");
 
    return gs;

}

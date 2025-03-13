#include "musica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica {

    char *titulo;
    char *artista;
    int num;
    char **participantes;
    char *album;
    char *genero;
};

// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica* musica_construct(){

    Musica *m = (Musica *) calloc (1, sizeof(Musica));

    m->titulo = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    m->artista = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    m->album = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    m->genero = (char *) calloc (MAXTAM_STRINGS, sizeof(char));

    scanf("%s ", m->titulo);
    scanf("%s ", m->artista);
    scanf("%d ", &m->num);

    m->participantes = (char **) calloc (m->num, sizeof(char *));

    for (int i = 0; i < m->num; i++){

        m->participantes[i] = (char *)calloc(MAXTAM_STRINGS, sizeof(char));

        scanf("%s ", m->participantes[i]);
    }

    scanf("%s ", m->album);
    scanf("%s\n", m->genero);

    return m;
}

// Imprime os dados da música. Recebe um ponteiro genérico para a música
// e exibe suas informações relevantes, como título, artistas, etc.
// Parâmetros:
//  m - Ponteiro para a Musica a ser impressa.
void musica_print(void* m){

    Musica *mus = (Musica *) m;

    printf("MUSICA\n");
    printf("%s - %s (feat.", mus->artista, mus->titulo);


    for (int i = 0; i < mus->num; i++){

        printf(" %s", mus->participantes[i]);

        if (i < mus->num - 1){
            
            printf(",");
        }
    }

    printf(")\n");
    printf("Album: %s\n", mus->album);
    printf("Genero: %s\n", mus->genero);
}

// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void* m){

    Musica *mus = (Musica *) m;

    free(mus->genero);
    free(mus->album);

    for (int i = 0; i < mus->num; i++){

        free(mus->participantes[i]);
    }

    free(mus->participantes);
    free(mus->artista);
    free(mus->titulo);
    free(mus);
}
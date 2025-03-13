#include "pintura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pintura {

    char *titulo;
    char *artista;
    char *movimento;
    char *material;
    int ano;
};

// Aloca dinamicamente uma nova estrutura Pintura e realiza a leitura dos dados
// de entrada associados à pintura. Retorna o ponteiro para o objeto Pintura.
// Retorna: Ponteiro para a Pintura recém-criada, com dados carregados.
Pintura* pintura_construct(){

    Pintura *p = (Pintura *) calloc (1, sizeof(Pintura));

    p->titulo = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    p->artista = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    p->movimento = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    p->material = (char *) calloc (MAXTAM_STRINGS, sizeof(char));

    scanf("%s ", p->titulo);
    scanf("%s ", p->artista);
    scanf("%s ", p->movimento);
    scanf("%s ", p->material);
    scanf("%d\n", &p->ano);

    return p;
}

// Imprime os dados de uma pintura. Recebe um ponteiro genérico para a pintura,
// e utiliza a função de impressão para exibir as informações relevantes.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser impressa.
void pintura_print(void* p){

    Pintura *pin = (Pintura *) p;

    printf("PINTURA\n");
    printf("Titulo: %s\n", pin->titulo);
    printf("Artista: %s\n", pin->artista);
    printf("Movimento: %s\n", pin->movimento);
    printf("Material: %s\n", pin->material);
    printf("Ano: %d\n", pin->ano);
}

// Libera a memória alocada para a pintura, chamando a função de desalocação
// apropriada para os dados da estrutura Pintura.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser destruída.
void pintura_destroy(void* p){

    Pintura *pin = (Pintura *) p;

    free(pin->material);
    free(pin->movimento);
    free(pin->artista);
    free(pin->titulo);
    free(pin);
}
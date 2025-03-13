#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {

    char *titulo;
    char *autor;
    char *genero;
    char *editora;
    int ano;
};

// Aloca dinamicamente uma nova estrutura Livro e realiza a leitura dos dados
// de entrada associados ao livro. Retorna o ponteiro para o objeto Livro.
// Retorna: Ponteiro para o Livro recém-criado, com os dados carregados.
Livro* livro_construct(){

    Livro *l = (Livro *) calloc (1, sizeof(Livro));

    l->titulo = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    l->autor = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    l->genero = (char *) calloc (MAXTAM_STRINGS, sizeof(char));
    l->editora = (char *) calloc (MAXTAM_STRINGS, sizeof(char));

    scanf("%s ", l->titulo);
    scanf("%s ", l->autor);
    scanf("%s ", l->genero);
    scanf("%s ", l->editora);
    scanf("%d\n", &l->ano);

    return l;
}

// Imprime os dados do livro. Recebe um ponteiro genérico para o livro
// e exibe suas informações relevantes, como título, autor, etc.
// Parâmetros:
//  l - Ponteiro para o Livro a ser impresso.
void livro_print(void* l){

    Livro *liv = (Livro *) l;

    printf("LIVRO\n");
    printf("Titulo: %s\n", liv->titulo);
    printf("Autor: %s\n", liv->autor);
    printf("Genero: %s\n", liv->genero);
    printf("Editora: %s\n", liv->editora);
    printf("Ano: %d\n", liv->ano);
}

// Libera a memória alocada para o livro, desalocando a estrutura Livro
// e seus dados associados de forma adequada.
// Parâmetros:
//  l - Ponteiro para o Livro a ser destruído.
void livro_destroy(void* l){

    Livro *liv = (Livro *) l;

    free(liv->editora);
    free(liv->genero);
    free(liv->autor);
    free(liv->titulo);
    free(liv);
}
#include "roteiro.h"
#include "midia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Roteiro {

    Midia **m;;
    int qtd;
    int qtdAlocados;
};

// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct(){

    Roteiro *r = (Roteiro *) calloc (1, sizeof(Roteiro));

    r->m = (Midia **) calloc (2, sizeof(Midia *));

    r->qtd = 0;
    r->qtdAlocados = 2;

    return r;
}

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro* r, void *dado, PrintFunction print_fn, FreeFunction free_fn){

    if (r->qtd == r->qtdAlocados){

        r->m = (Midia **) realloc (r->m, (r->qtd + 2) * sizeof(Midia *));

        r->qtdAlocados = r->qtd + 2;
    }

    r->m[r->qtd++] = midia_construct(dado, print_fn, free_fn);
}

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r){

    if (r->qtd > 0){

        printf("IMPRIMINDO MIDIAS\n");

        for (int i = 0; i < r->qtd; i++){

            printf("MIDIA %d: ", i + 1);
            midia_print(r->m[i]);
            printf("\n");
        }
    }

    else {

        printf("SEM MIDIAS PARA IMPRIMIR\n");
    }
}

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r){

    for (int i = 0; i < r->qtd; i++){

        midia_destroy(r->m[i]);
    }

    free(r->m);
    free(r);
}
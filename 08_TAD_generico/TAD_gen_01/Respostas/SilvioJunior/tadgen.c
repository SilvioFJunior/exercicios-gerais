#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic{

    Type tipo;
    int numElementos;
    void* vetor;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){

    tGeneric* novo = (tGeneric*) calloc (1, sizeof(tGeneric));
    novo->tipo = type;
    novo->numElementos = numElem;
    novo->vetor = (void*) calloc (novo->numElementos, type == INT ? sizeof(int) : sizeof(float));

    return novo;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){

    if (gen != NULL){

        free(gen->vetor);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){

    printf("\nDigite o vetor:\n");

    for (int j = 0; j < gen->numElementos; j++){

        if (gen->tipo == INT){

            scanf("%d", &((int*)gen->vetor)[j]);
        }

        else {

            scanf("%f", &((float*)gen->vetor)[j]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){

    for (int i = 0; i < gen->numElementos; i++){

        if (gen->tipo == INT){

            printf("%d ", ((int*)gen->vetor)[i]);
        }

        else {

            printf("%.2f ", ((float*)gen->vetor)[i]);
        }
    }

    printf("\n");
}
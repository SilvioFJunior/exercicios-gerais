#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacote{

    Type tipo;
    int numElem;
    void* vetor;
    int soma;
    int id;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){

    tPacote *p = (tPacote*) calloc (1, sizeof(tPacote));
    p->numElem = numElem;
    p->tipo = type;
    p->soma = 0;
    p->vetor = (void*) calloc (p->numElem, type == INT ? sizeof(int) : sizeof(char));

    printf("\n");
    printf("Digite o conteúdo do vetor/mensagem: ");

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){

    if (pac != NULL){

        free(pac->vetor);
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){

    if (pac->tipo == INT){

        for (int i = 0; i < pac->numElem; i++){

            scanf("%d", &((int*)pac->vetor)[i]);
        }
    }

    else {

        scanf("%[^\n]\n", (char*)pac->vetor);
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){

    CalculaSomaVerificacaoPacote(pac);

    printf("%d ", pac->soma);

    if (pac->tipo == INT){

        for (int i = 0; i < pac->numElem; i++){

            printf(" %d", ((int*)pac->vetor)[i]);
        }
    }

    else {

       printf("%s", (char*)pac->vetor);
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){

    pac->soma = 0;

    for (int i = 0; i < pac->numElem; i++){

        if (pac->tipo == INT){

            pac->soma += ((int*)pac->vetor)[i];
        }

        else {

            pac->soma += ((char*)pac->vetor)[i];
        }
    }
}
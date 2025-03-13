#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos {

    tAluno **a;
    int qtdAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){

    tBaseAlunos *b = (tBaseAlunos *) calloc (1, sizeof(tBaseAlunos));
    
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){

    if (baseAlunos != NULL){

        for (int i = 0; i < baseAlunos->qtdAlunos; i++){

            DestruirAluno(baseAlunos->a[i]);
        }

        free(baseAlunos->a);
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){

    int qtd;

    FILE *arquivo = fopen(nomeArquivo, "rb");

    fread(&qtd, sizeof(int), 1, arquivo);

    baseAlunos->qtdAlunos = qtd;

    baseAlunos->a = (tAluno **) realloc (baseAlunos->a, qtd * sizeof(tAluno *));

    for (int i = 0; i < baseAlunos->qtdAlunos; i++){

        baseAlunos->a[i] = LeAluno(arquivo);
    }

    fclose(arquivo);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){

    float total = 0;

    for (int i = 0; i < baseAlunos->qtdAlunos; i++){

        total += GetCoeficienteRendimentoAluno(baseAlunos->a[i]);
    }

    return total/baseAlunos->qtdAlunos;
}
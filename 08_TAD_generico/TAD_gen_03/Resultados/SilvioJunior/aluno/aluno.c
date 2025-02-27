#include "aluno.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

struct Aluno {

    char *nome;
    float nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno(){

    tAluno *a = (tAluno*) calloc (1, sizeof(tAluno));

    a->nome = (char*) calloc (MAX_NOME, sizeof(char));

    return a;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno){

    if (aluno != NULL){

        tAluno *a = (tAluno *)aluno;

        free(a->nome);
        free(aluno);
    }
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno){

    scanf("%[^;];", aluno->nome);
    scanf("%c;", &aluno->genero);
    scanf("%f\n", &aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno){

    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno){

    return aluno->nota;
}
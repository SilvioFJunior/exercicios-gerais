#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno {

    char *nome;
    char *dtNasc;
    char *curso;
    int periodo;
    float coeficiente;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){

    tAluno *a = (tAluno *) calloc (1, sizeof(tAluno));

    a->nome = (char *) calloc (100, sizeof(char));
    a->dtNasc = (char *) calloc (11, sizeof(char));
    a->curso = (char *) calloc (50, sizeof(char));

    strcpy(a->nome, nome);
    strcpy(a->dtNasc, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->coeficiente = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){

    if (aluno != NULL){

        free(aluno->curso);
        free(aluno->dtNasc);
        free(aluno->nome);
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){

    char nome[100];
    char dt[11];
    char curso[50];
    int periodo;
    float coeficiente;

    fread(nome, sizeof(char), 100, arquivo_binario);
    fread(dt, sizeof(char), 11, arquivo_binario);
    fread(curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&coeficiente, sizeof(float), 1, arquivo_binario);

    tAluno *a = CriarAluno(nome, dt, curso, periodo, coeficiente);

    return a;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){

    return aluno->coeficiente;
}
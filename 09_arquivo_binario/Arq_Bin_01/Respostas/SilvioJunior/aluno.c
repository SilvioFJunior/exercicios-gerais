#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {

    char *nome;
    char *dataNasc;
    char *curso;
    char *periodo;
    int conclusao;
    float cr;
    int qtdAlunos;
};

Aluno** CriaVetorAlunos(int numeroAlunos){

    Aluno *a = (Aluno *) calloc (numeroAlunos, sizeof(Aluno));

    a->nome = (char *) calloc (100, sizeof(char));
    a->dataNasc = (char *) calloc (100, sizeof(char));
    a->curso = (char *) calloc (100, sizeof(char));
    a->periodo = (char *) calloc (100, sizeof(char));

    a->qtdAlunos = numeroAlunos;

    a->cr = 0;

    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){

    Aluno *a = (Aluno *) calloc (1, sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->conclusao = percConclusao;
    a->cr = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos);

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos);

void CarregaAlunosBinario(Aluno **alunos, char *fileName);

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){

}
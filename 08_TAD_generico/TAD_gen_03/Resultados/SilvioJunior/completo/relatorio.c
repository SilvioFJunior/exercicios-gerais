#include "aluno.h"
#include "vector.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){

    int qtdAluno = VectorSize(alunos);

    int aprovados = 0;
    int masc = 0;
    int fem = 0;
    int outro = 0;
    float somaNotas = 0;

    for (int i = 0; i < qtdAluno; i++){

        tAluno *a = (tAluno*) VectorGet (alunos, i);

        somaNotas += GetNotaAluno(a);

        if (GetNotaAluno(a) >= 6){

            aprovados++;
        }

        char genero = GetGeneroAluno(a);

        if (genero == 'M'){
            masc++;
        }
        else if (genero == 'F'){
            fem++;
        }
        else {
            outro++;
        }
    }

    float mediaNotas = somaNotas / qtdAluno;
    float percAprovados = (100.0 * aprovados) / qtdAluno;
    float percMasc = (100.0 * masc) / qtdAluno;
    float percFem = (100.0 * fem) / qtdAluno;
    float percOutro = (100.0 * outro) / qtdAluno;

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", percAprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", percMasc);
    printf("Feminino: %.2f%%\n", percFem);
    printf("Outro: %.2f%%\n", percOutro);
}
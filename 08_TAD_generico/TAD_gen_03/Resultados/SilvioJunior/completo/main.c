#include "aluno.h"
#include "vector.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    int qtd;

    scanf("%d\n", &qtd);

    Vector *alunos = VectorConstruct();

    for (int i = 0; i < qtd; i++){

        tAluno *a = CriaAluno();

        LeAluno(a);

        VectorPushBack(alunos, a);
    }

    ImprimeRelatorio(alunos);

    for (int j = 0; j < VectorSize(alunos); j++){

        DestroiAluno(VectorGet(alunos, j));
    }

    VectorDestroy(alunos, NULL);

    return 0;
}
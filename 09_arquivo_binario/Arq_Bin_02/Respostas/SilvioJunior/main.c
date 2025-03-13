#include <stdio.h>
#include "base_alunos.h"

int main()
{
    tBaseAlunos *baseAlunos = CriarBaseAlunos();

    char diretorio[50];
    scanf("%s\n", diretorio);

    LerBaseAlunos(baseAlunos, diretorio);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(baseAlunos));

    DestruirBaseAlunos(baseAlunos);

    return 0;
}
#include <stdio.h>
#include "utils.h"

int main(){

    int qnt;

    scanf("%d", &qnt);

    int *vetor = CriaVetor(qnt);

    LeVetor(vetor, qnt);

    float media = CalculaMedia(vetor, qnt);

    printf("%.2f\n", media);

    LiberaVetor(vetor);

    return 0;
}
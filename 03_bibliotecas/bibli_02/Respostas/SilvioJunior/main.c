#include "matrix_utils.h"
#include <stdio.h>

void PrintarInformacoes(){

    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

int main (){

    int rows1, cols1, rows2, cols2, i;
    int scalar, matrizEscalar;
    
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];

    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);

    int matrix2[rows2][cols2];

    matrix_read(rows2, cols2, matrix2);

    int result1[rows1][cols1];
    int result2[rows1][cols2];
    int result3[rows2][cols2];

    do {

        scanf("%d", &i);

        if (i == 1 && possible_matrix_sum(rows1, cols1, rows2, cols2)){
            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result1);
            PrintarInformacoes();
            matrix_print(rows1, cols1, result1);
        }
        else if (i == 2 && possible_matrix_sub(rows1, cols1, rows2, cols2)){
            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result1);
            PrintarInformacoes();
            matrix_print(rows1, cols1, result1);
        }
        else if (i == 3 && possible_matrix_multiply(cols1, rows2)){
            matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result2);
            PrintarInformacoes();
            matrix_print(rows1, cols2, result2);
        }
        else if (i == 4){
            scanf("%d %d", &scalar, &matrizEscalar);
            if (matrizEscalar == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
                PrintarInformacoes();
                matrix_print(rows1, cols1, matrix1);
            }
            else if (matrizEscalar == 2){
                scalar_multiply(rows2, cols2, matrix2, scalar);
                PrintarInformacoes();
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if (i == 5){
            transpose_matrix(rows1, cols1, matrix1, result1);
            PrintarInformacoes();
            matrix_print(cols1, rows1, result1);
            transpose_matrix(rows2, cols2, matrix2, result3);
            matrix_print(cols2, rows2, result3);
        }
        else if (i == 6){
            PrintarInformacoes();
            return 0;
        }
        else if(!possible_matrix_multiply(cols1, rows2)){
            PrintarInformacoes();
            printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
        }
        else {
            PrintarInformacoes();
            printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }
        
    } while(1);

    return 0;
}
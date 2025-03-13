#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {

    int qtdLin;
    int qtdCol;
    Tipo tipo;
    void **dados;
    int qtdBytesLidos;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){

    FILE *arquivo = fopen(caminho, "rb");

    Imagem *m = (Imagem *) calloc (1, sizeof(Imagem));

    fread(&m->qtdLin, sizeof(int), 1, arquivo);
    fread(&m->qtdCol, sizeof(int), 1, arquivo);
    fread(&m->tipo, sizeof(Tipo), 1, arquivo);

    if (m->tipo == INT){

        m->dados = (void **) calloc (m->qtdLin, sizeof(int *));

        for (int i = 0; i < m->qtdLin; i++){

            m->dados[i] = (int *) calloc (m->qtdCol, sizeof(int));
            fread(&m->dados[i], sizeof(int), m->qtdCol, arquivo);
        }
    }

    else {

        m->dados = (void **) calloc (m->qtdLin, sizeof(float *));

        for (int i = 0; i < m->qtdLin; i++){

            m->dados[i] = (float *) calloc (m->qtdCol, sizeof(float));
            fread(&m->dados[i], sizeof(float), m->qtdCol, arquivo);
        }
    }

    m->qtdBytesLidos = sizeof(int) * 2 + sizeof(Tipo);
    m->qtdBytesLidos += m->qtdLin * m->qtdCol * (m->tipo == INT ? sizeof(int) : sizeof(float));

    fclose(arquivo);

    return m;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){

    for (int i = 0; i < img->qtdLin; i++){

        free(img->dados[i]);
    }

    free(img->dados);
    free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img){
   
    return img->qtdBytesLidos;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img){

    for (int i = 0; i < img->qtdLin; i++){
        
        for (int j = 0; j < img->qtdCol; j++){

            if (img->tipo == INT){

                printf("%d ", ((int **) img->dados)[i][j]);
            }

            else {

                printf("%.2f ", ((float **) img->dados)[i][j]);
            }
        }

        printf("\n");
    }
}
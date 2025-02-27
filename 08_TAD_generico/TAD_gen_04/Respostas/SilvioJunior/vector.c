#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector {

    DataType *d;
    int qtdAlocados;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){

    Vector *v = (Vector*) calloc (1, sizeof(Vector));

    v->qtd = 0;

    v->d = (DataType*) calloc (v->qtd + 2, sizeof(DataType));

    v->qtdAlocados = 2;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){

    if (v->qtdAlocados == v->qtd){

        v->d = (DataType*) realloc (v->d, (v->qtd + 2) * sizeof(DataType));
        v->qtdAlocados = v->qtd + 2;
    }

    v->d[v->qtd++] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){

    return v->d[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){

    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){

    if (v != NULL){

        for (int i = 0; i < v->qtd; i++){

            free(v->d[i]);
        }

        free(v->d);
        free(v);
    }
}
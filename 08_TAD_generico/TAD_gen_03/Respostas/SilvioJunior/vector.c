#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {

    data_type *data;
    int alocados;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){

    Vector *v = (Vector*) calloc (20, sizeof(Vector));  

    v->qtd = 0;

    v->data = (data_type*) calloc (v->qtd + 2, sizeof(data_type));

    v->alocados = 2;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val){

    if (v->alocados == v->qtd){

        v->data = (data_type*) realloc (v->data, (v->qtd + 2) * sizeof(data_type));
        v->alocados = v->qtd + 2;
    }

    v->data[v->qtd++] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){

    return v->data[i];
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
void VectorDestroy(Vector *v, void (*destroy)(data_type)){

    if (v != NULL){

        for (int i = 0; i < v->qtd; i++){

            free(v->data[i]);
        }

        free(v->data);
        free(v);
    }
}
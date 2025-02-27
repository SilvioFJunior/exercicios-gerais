#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia {

    int num;
    char *nome;
    Vector *v;
    int numA;
    int alocados;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){

    tAgencia *a = (tAgencia*) calloc (1, sizeof(tAgencia));

    a->v = VectorConstruct();

    a->alocados = 2;
    a->numA = 0;

    a->nome = (char*) calloc (50, sizeof(char));

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){

    VectorDestroy(agencia, NULL);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){

    scanf("%d;", &agencia->num);
    scanf("%[^\n]\n", agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){

    if (agencia->numA == agencia->alocados){

        agencia->v = (Vector*) realloc (agencia->v, (agencia->numA + 2) * sizeof((Vector)));
        agencia->alocados = agencia->numA + 2;
    }

    agencia->v[agencia->numA++] = conta;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2);

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia);

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia);

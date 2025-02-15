#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    Usuario* usuario;
    int nConta;
    float saldo;
    float* movimentacoes;
    int qtdMovimentacoes;
}Conta;

/**
 * @brief Cria uma nova conta.
 * @param usuario usuario da conta.
 * @param nConta numero da conta.
 * @return Conta criada.
 */
Conta* CriaConta(Usuario* usuario, int nConta){

    Conta *c = (Conta*) calloc (1, sizeof(Conta));
    c->usuario = (Usuario*) calloc (1, sizeof(Usuario));
    c->nConta = nConta;
    c->saldo = 0;

    return c;
}

/**
 * @brief Busca uma conta.
 * @param contas lista de contas.
 * @param qtdContas numero de contas na lista.
 * @param nConta numero da conta a ser procurada.
 * @return Conta buscada, NULL se nao existir.
 */
Conta* BuscaConta(Conta** contas, int qtdContas, int nConta){

    for (int i = 0; i < qtdContas; i++){

        if (RecuperaNConta(contas[i]) == nConta){

            return contas[i];
        }
    }

    return NULL;
}

/**
 * @brief Retorna o usuario de uma conta.
 * @param conta uma conta.
 * @return Usuario da conta.
 */
Usuario* RecuperaUsuario(Conta* conta){

    return conta->usuario;
}

/**
 * @brief Retorna o numero de uma conta.
 * @param conta uma conta.
 * @return Numero da conta.
 */
int RecuperaNConta(Conta* conta){

    return conta->nConta;
}

/**
 * @brief Retorna a quantidade de movimentacoes de uma conta de uma conta.
 * @param conta uma conta.
 * @return Quantidade de movimentacoes da conta.
 */
int RecuperaQtdMovimentacoes(Conta* conta){

    return conta->qtdMovimentacoes;
}

/**
 * @brief Retorna o saldo de uma conta.
 * @param conta uma conta.
 * @return saldo da conta.
 */
float RecuperaSaldo(Conta* conta){

    return conta->saldo;
}

/**
 * @brief Realiza o saque em uma conta.
 * @param conta conta que ocorre a operacao.
 * @param valor valor do saque realizado.
 * @return valor do saque realizado, 0 se nao foi possivel realizar.
 */
float Saque(Conta* conta, float valor){

    if (conta == NULL){

        return 0;
    }

    else {

        conta->saldo -= valor;

        return valor;
    }
}

/**
 * @brief Tranfere um valor deuma conta para outra.
 * @param contaOri conta origem da transferencia.
 * @param contaDes conta destino da transferencia.
 * @param valor valor da tranferencia realizada.
 * @return valor da tranferencia realizada, 0 se nao for possivel.
 */
float Transferencia(Conta* contaOri, Conta* contaDes, float valor){

    if (contaOri == NULL || contaDes == NULL){

        return 0;
    }

    else {

        contaOri->saldo -= valor;
        contaDes->saldo += valor;

        return valor;
    }
} 

/**
 * @brief Retorna o historico de movimentacos da conta.
 * @param conta uma conta.
 * @return as movimentacoes da conta.
 */
float* RecuperaMovimentacoes(Conta* conta){

    return conta.
}

/**
 * @brief Realiza o deposito em uma conta.
 * @param conta conta que ocorre a operacao.
 * @param valor valor do deposito realizado.
 * @return valor do saque realizado, 0 se nao foi possivel realizar.
 */
void Deposito(Conta* conta, float valor);

/**
 * @brief Destroi uma conta.
 * @param conta uma conta.
 */
void DestroiConta(Conta* conta);
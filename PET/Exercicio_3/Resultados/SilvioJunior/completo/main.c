#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

#define MAX_CONTAS 100

int main() {

    int qtdContas = 0;
    int contasAlocadas = 0;

    Conta **contas = calloc (MAX_CONTAS, sizeof(Conta*));

    while (1) {

        int opcao;

        scanf("%d\n", &opcao);

        if (opcao == 0) break;

        if (opcao == 4) { 

            char nome[100];
            int cpf = 0;
            int nConta = 0;

            scanf("%s %d %d\n", nome, &cpf, &nConta);

            Usuario *usuario = CriaUsuario(nome, cpf);

            Conta *conta = CriaConta(usuario, nConta);

            if (qtdContas + 1 == contasAlocadas) {
                contasAlocadas = 2;
                contas = realloc(contas, contasAlocadas * sizeof(Conta*));
            }
        
            contas[qtdContas] = conta;
            qtdContas++;

        } else if (opcao == 1) { 

            int nConta = 0;
            float valor = 0;

            scanf("%d %f\n", &nConta, &valor);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            if (conta) {

                Saque(conta, valor);
            }

        } else if (opcao == 2) { 

            int nConta;
            float valor;

            scanf("%d %f\n", &nConta, &valor);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            if (conta) {

                Deposito(conta, valor);
            }

        } else if (opcao == 3) { 

            int nContaOrigem = 0; 
            int nContaDestino = 0;
            float valor = 0;

            scanf("%d %d %f\n", &nContaOrigem, &nContaDestino, &valor);

            Conta *origem = BuscaConta(contas, qtdContas, nContaOrigem);
            Conta *destino = BuscaConta(contas, qtdContas, nContaDestino);

            if (origem && destino) {

                Transferencia(origem, destino, valor);
            }
        } else if (opcao == 5) { 

            printf("===| Imprimindo Relatorio |===\n");

            for (int i = 0; i < qtdContas; i++) {

                Conta *conta = contas[i];

                printf("Conta: %d\n", conta->nConta);
                printf("Saldo: R$ %.2f\n", conta->saldo);
                printf("Nome: %s\n", conta->usuario->nome);
                printf("CPF: %d\n\n", conta->usuario->cpf);
            }
        } else if (opcao == 6) { 

            int nConta, nTransacoes;

            scanf("%d %d", &nConta, &nTransacoes);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            if (nTransacoes > conta->qtdMovimentacoes){

                nTransacoes == conta->qtdMovimentacoes;
            }

            if (conta) {

                printf("===| Imprimindo Extrato |===\n");
                printf("Conta: %d\n", conta->nConta);
                printf("Saldo: R$ %.2f\n", conta->saldo);
                printf("Nome: %s\n", conta->usuario->nome);
                printf("CPF: %d\n\n", conta->usuario->cpf);

                if (nTransacoes > conta->qtdMovimentacoes){

                    printf("Ultimas %d transações\n", conta->qtdMovimentacoes);
                }

                else {

                    printf("Ultimas %d transações\n", nTransacoes);
                }

                int inicio = conta->qtdMovimentacoes - nTransacoes;

                if (inicio < 0) inicio = 0;

                for (int i = conta->qtdMovimentacoes - 1; i >= inicio; i--) {

                    printf("%.2f\n", conta->movimentacoes[i]);
                }

                printf("\n");
            }
        }
    }

    for (int i = 0; i < qtdContas; i++) {

        DestroiUsuario(RecuperaUsuario(contas[i]));
        DestroiConta(contas[i]);
    }

    free(contas);

    return 0;
}

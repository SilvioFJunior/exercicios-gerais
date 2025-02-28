#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "tabela.h"

struct _Tabela {

    tTime **times;
    int qtdTimes;
    int alocados;
};

int qsort_ComparaTimes(const void *t1, const void *t2)
{
    tTime *time1 = *(tTime **)t1;
    tTime *time2 = *(tTime **)t2;

    return DesempataTimes(time1, time2);
}

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
*/
tTabela* CriaTabela(int numTimes){

    tTabela *tabela = (tTabela*) calloc (1, sizeof(tTabela));

    tabela->qtdTimes = numTimes;

    tabela->times = (tTime**) calloc (numTimes, sizeof(tTime*));

    tabela->alocados = numTimes;

    for (int i = 0; i < numTimes; i++){

        tabela->times[i] = LeTime();
    }

    return tabela;
}

/**
 * @brief Libera a memoria alocada para a tabela e seus times.
*/
void DesalocaTabela(tTabela* tabela){

    for (int i = 0; i < tabela->qtdTimes; i++){

        DesalocaTime(tabela->times[i]);
    }

    free(tabela->times);
    free(tabela);
}

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
*/
void OrdenaTabela(tTabela* tabela){

    qsort(tabela->times, tabela->qtdTimes, sizeof(tTime *), qsort_ComparaTimes);
}

/**
 * @brief Dado um nome, retorna o time correspondente.
*/
tTime* ObtemTimeTabela(tTabela* tabela, char* time){

    for (int i = 0; i < tabela->qtdTimes; i++){

        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0){

            return tabela->times[i];
        }
    }

    return NULL;
}

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
*/
void RemoveTimeTabela(tTabela* tabela, char* time){

    tTime *timeEncontrado;

    timeEncontrado = ObtemTimeTabela(tabela, time);

    for (int i = 0; i < tabela->qtdTimes; i++){

        if (tabela->times[i] == timeEncontrado){

            for (int j = i; j < tabela->qtdTimes - 1; j++){

                tabela->times[j] = tabela->times[j + 1];
            }
        }
    }

    DesalocaTime(timeEncontrado);

    tabela->qtdTimes--;
}

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
*/
void ImprimePremiacao(tTabela* tabela, float valorPremio){

    tTime *t1 = tabela->times[0];
    tTime *t2 = tabela->times[1];
    tTime *t3 = tabela->times[2];

    if (tabela->qtdTimes == 0){

        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
    }

    else if (tabela->qtdTimes == 2){

        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(t1), 0.6 * valorPremio);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(t2), 0.4 * valorPremio);
    }

    else if (tabela->qtdTimes >= 3){

        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(t1), 0.5 * valorPremio);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(t2), 0.3 * valorPremio);
        printf("3º lugar - %s: R$%.2f\n", ObtemNomeTime(t3), 0.2 * valorPremio);
    }
}

/**
 * @brief Imprime todos os times da tabela.
*/
void ImprimeTabela(tTabela* tabela){

    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");

    for (int i = 0; i < tabela->qtdTimes; i++){
        
        ImprimeTime(tabela->times[i]);
    }

    printf("\n");
}
#include "time.h"
#include "tabela.h"
#include "brasileirao.h"
#define MAX_TIMES 20

struct _BRA {

    tTabela *tabela;
    int qtdTimes;
    int qtdRodadas;
    int rodada;
    float premio;
};

/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
*/
BRA *CriaCamp(){

    BRA *b = (BRA*) calloc (1, sizeof(BRA));

    printf("Insira o num de times, rodadas e premio total:\n");

    scanf("%d %d %f\n", &b->qtdTimes, &b->qtdRodadas, &b->premio);

    b->tabela = CriaTabela(b->qtdTimes);

    b->rodada = 0;

    return b;
}

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
*/
void RealizaRodada(BRA *br){

    for (int i = 0; i < br->qtdTimes/2; i++)
    {
        char nomeT1[MAX_TIME_NOME];
        char nomeT2[MAX_TIME_NOME];

        int golsT1 = 0;
        int golsT2 = 0;

        scanf("%s %d x %d %s\n", nomeT1, &golsT1, &golsT2, nomeT2);

        tTime *t1 = ObtemTimeTabela(br->tabela, nomeT1);
        tTime *t2 = ObtemTimeTabela(br->tabela, nomeT2);

        AtualizaGolsMarcados(t1, golsT1);
        AtualizaGolsMarcados(t2, golsT2);

        AtualizaGolsSofridos(t1, golsT2);
        AtualizaGolsSofridos(t2, golsT1);

        if (golsT1 > golsT2){

            AtualizaVitorias(t1);

            AtualizaDerrotas(t2);
        }

        else if (golsT1 < golsT2){

            AtualizaDerrotas(t1);

            AtualizaVitorias(t2);
        }

        else {

            AtualizaEmpates(t1);

            AtualizaEmpates(t2);
        }
    }
    
    OrdenaTabela(br->tabela);
    
    ImprimeTabela(br->tabela);

    br->rodada++;
}

/**
 * @brief Imprime o menu e trata cada opcao.
*/
void RealizaCamp(BRA *br){

    char opcao = 0;

    while (br->rodada < br->qtdRodadas){

        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");

        scanf("%c\n", &opcao);

        if (opcao == 'F'){

            break;
        }

        else if (opcao == 'C'){

            RealizaRodada(br);
        }

        else if (opcao == 'R'){

            RemoveTimesCamp(br);

            if (br->qtdTimes < 2){

                break;
            }

            RealizaRodada(br);
        }
    }
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
*/
void RemoveTimesCamp(BRA *br){

    char nomeT1[MAX_TIME_NOME];
    char nomeT2[MAX_TIME_NOME];

    scanf("%s %s\n", nomeT1, nomeT2);

    RemoveTimeTabela(br->tabela, nomeT1);
    RemoveTimeTabela(br->tabela, nomeT2);

    printf("Times a serem retirados:\n");
    printf("Os times %s e %s se retiraram do campeonato\n", nomeT1, nomeT2);

    br->qtdTimes = br->qtdTimes - 2;
}

/**
 * @brief Libera a memoria do campeonato.
*/
void DesalocaCamp(BRA *br){

    DesalocaTabela(br->tabela);
    free(br);
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
*/
void FinalizaCamp(BRA *br){

    if (br->qtdTimes >= 2){

        printf("Esta foi a tabela final:\n");
        ImprimeTabela(br->tabela);
    }

    ImprimePremiacao(br->tabela, br->premio);

    DesalocaCamp(br);

    printf("Fim do campeonato\n");
}
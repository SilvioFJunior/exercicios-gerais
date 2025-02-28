#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

struct _Time {

    char* nome;
    int qtdVitorias;
    int qtdDerrotas;
    int qtdEmpates;
    int qtdGolMarcado;
    int qtdGolSofrido;
};

/** 
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
*/
tTime* LeTime(){

    tTime *t = (tTime*) calloc (1, sizeof(tTime));
    t->nome = (char*) calloc (MAX_TIME_NOME, sizeof(char));

    scanf("%[^\n]\n", t->nome);

    t->qtdVitorias = 0;
    t->qtdDerrotas = 0;
    t->qtdEmpates = 0;
    t->qtdGolMarcado = 0;
    t->qtdGolSofrido = 0;

    return t;
}

/**
 * @brief Retona o numero de vitorias do time.
*/
int ObtemVitorias(tTime *t){

    return t->qtdVitorias;
}

/**
 * @brief Retona o numero de partidas.
*/
int ObtemPartidas(tTime *t){

    return t->qtdVitorias + t->qtdDerrotas + t->qtdEmpates;
}

/**
 * @brief Retona o numero de derrotas do time.
*/
int ObtemDerrotas(tTime *t){

    return t->qtdDerrotas;
}

/**
 * @brief Retona a string do nome do time.
*/
char* ObtemNomeTime(tTime *t){

    return t->nome;
}

/**
 * @brief Retona o saldo de gols da equipe.
*/
int ObtemSaldo(tTime *t){

    return t->qtdGolMarcado - t->qtdGolSofrido;
}

/**
 * @brief Aumenta o numero de vitorias em 1.
*/
void AtualizaVitorias(tTime *t){

    t->qtdVitorias++;
}

/**
 * @brief Aumenta o numero de empates em 1.
*/
void AtualizaEmpates(tTime *t){

    t->qtdEmpates++;
}

/**
 * @brief Aumenta o numero de derrotas em 1.
*/
void AtualizaDerrotas(tTime *t){

    t->qtdDerrotas++;
}

/**
 * @brief Aumenta a quantidade de gols marcados.
*/
void AtualizaGolsMarcados(tTime *t, int gols){

    t->qtdGolMarcado += gols;
}

/**
 * @brief Aumenta a quantidade de gols sofridos.
*/
void AtualizaGolsSofridos(tTime *t, int gols){

    t->qtdGolSofrido += gols;
}

/**
 * @brief Retorna a pontuacao do time.
*/
int ObtemPontos(tTime* t){

    return 3 * t->qtdVitorias + t->qtdEmpates;
}

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
*/
int DesempataTimes(tTime *t1, tTime *t2){

    int pT1 = ObtemPontos(t1);
    int pT2 = ObtemPontos(t2);

    int sT1 = ObtemSaldo(t1);
    int sT2 = ObtemSaldo(t2);

    if (pT2 > pT1){

        return 1;
    }

    else if (pT1 > pT2){

        return -1;
    }

    else if (t2->qtdVitorias > t1->qtdVitorias){

        return 1;
    }

    else if (t1->qtdVitorias > t2->qtdVitorias){

        return -1;
    }

    if (sT2 > sT1){

        return 1;
    }

    else if (sT1 > sT2){

        return -1;
    }

    return 0;
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime *t){

    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, ObtemPontos(t), t->qtdVitorias, t->qtdDerrotas, t->qtdEmpates, ObtemSaldo(t));
}

/**
 * @brief Libera a memoria alocada para time.
*/
void DesalocaTime(tTime *t){

    free(t->nome);
    free(t);
}
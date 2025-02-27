#include <stdio.h>
#include <stdlib.h>
#include "tSensorPresenca.h"

/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
struct _tSensorPresenca
{
    int id;
    int tempoMin;
    int tempoUltimaNotificacao;
};

tSensorPresenca *leSensorPresenca(int id)
{
    tSensorPresenca *sp = (tSensorPresenca *)calloc(1, sizeof(tSensorPresenca));
    sp->id = id;
    sp->tempoUltimaNotificacao = -9999;
    scanf("%d\n", &sp->tempoMin);
    return sp;
}

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorPresenca(void *s)
{
    free(s);
}

/***
Dado um sensor de temperatura valido, faz a leitura da temperatura ambiente do sensor fisico e
controla o estado do ar condicionado
A leitura do sensor de temperatura sera simulada aqui por uma leitura de um inteiro da entrada padrao
O controle do estado do ar condicionado sera simulado aqui com uma impressao em uma linha da saida padrao sendo
    "SENSOR(#ID)[#MIN-#MAX] processando TEMP:#T\n" em que #ID eh o id do sensor,
    #MIN e #MAX sao conforme definidos acima e #T eh a temperatura lida do sensor fisico, seguida de
    "(DESLIGANDO AR)" para representar que o ar deve desligar ao ficar abaixo da temperatura minima e estava ligado
    "(LIGANDO AR)" para representar que o ar deve ligar ao ficar acima da temperatura maxima e estiver desligado
    "(MANTEM AR)" caso contrario
*/
void processaSensorPresenca(void *s) {
    int presenca, tempo;
    tSensorPresenca * sl = (tSensorPresenca*) s;
    
    scanf("%d %d", &presenca, &tempo);
    printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d", sl->id, sl->tempoMin, presenca, tempo);
    if (presenca && (tempo - sl->tempoUltimaNotificacao) > sl->tempoMin){
        printf("(NOTIFICA)\n");
        sl->tempoUltimaNotificacao = tempo;
    } else {
        printf("(AGUARDA)\n");
    }
}


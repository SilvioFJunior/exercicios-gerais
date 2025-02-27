

#include <stdio.h>
#include <stdlib.h>
#include "tMonitorador.h"

/***
O monitorador eh um TAD generico uniforme que tem o objetivo de
varrer os sensores registrados processando cada um deles continuamente.
*/
typedef struct _tMonitorador
{
    int qtdElementos;
    int qtdElementosAloc;
    void **elementos;
    FptrProcessaElemento funcProcessaElemento;
    FptrLiberaElemento funcLiberaElemento;
};

/***
Cria um monitorador valido definindo, de acordo com o tipo de elemento, suas funcoes de
Processar elemento e Liberar elemento
*/
tMonitorador *criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE)
{
    tMonitorador *m = (tMonitorador *)calloc(1, sizeof(tMonitorador));

    m->qtdElementos = 0;
    m->qtdElementosAloc = 4;
    m->elementos = (void **)calloc(m->qtdElementosAloc, sizeof(void *));
    m->funcProcessaElemento = funcPE;
    m->funcLiberaElemento = funcLE;

    return m;
}

/***
Dado um monitorador valido, libera sua memoria incluindo a de cada um de seus elementos adicionados
*/
void liberaMonitorador(tMonitorador *m)
{
    if (m != NULL)
    {
        for (int i = 0; i < m->qtdElementos; i++)
        {
            m->funcLiberaElemento(m->elementos[i]);
        }
        free(m->elementos);
    }
    free(m);
}

/***
Dado um monitorador valido e um elemento, adiciona o elemento ao cojunto a ser monitorado
*/
void adicionaElementoMonitorador(tMonitorador *m, void *e)
{
    if (m->qtdElementos == m->qtdElementosAloc)
    {
        m->qtdElementosAloc *= 2;
        m->elementos = (void **)realloc(m->elementos, m->qtdElementosAloc * sizeof(void *));
    }
    m->elementos[m->qtdElementos++] = e;
}

/***
Dado um monitorador valido, inicia o monitoramento que durara pelo numero de ciclos informado em numeroDeCiclos
Se numeroDeCiclos for negativo, o monitoramento sera infinito.
O monitoramento consiste em, a cada ciclo, processar cada elemento registrado para monitoramento
*/
int iniciaMonitoramentotMonitorador(tMonitorador *m, int numeroDeCiclos)
{
    while (numeroDeCiclos)
    {
        for (int i = 0; i < m->qtdElementos; i++)
        {
            m->funcProcessaElemento(m->elementos[i]);
        }
        if (numeroDeCiclos > 0)
        {
            numeroDeCiclos--;
        }
    }
}
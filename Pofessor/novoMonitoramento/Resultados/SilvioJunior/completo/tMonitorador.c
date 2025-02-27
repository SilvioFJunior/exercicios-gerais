#include "tMonitorador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
O monitorador eh um TAD generico uniforme que tem o objetivo de
varrer os sensores registrados processando cada um deles continuamente.
*/
struct _tMonitorador {

    FptrProcessaElemento processaElemento;
    FptrLiberaElemento liberaElemento;
    int alocados;
    int qtd;
    void **elementos;
};

/***
Cria um monitorador valido definindo, de acordo com o tipo de elemento, suas funcoes de
Processar elemento e Liberar elemento
*/
tMonitorador *criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE){

    tMonitorador *m = (tMonitorador*) calloc (1, sizeof(tMonitorador));

    m->processaElemento = funcPE;
    m->liberaElemento = funcLE;

    m->qtd = 0;

    m->elementos = (void**) calloc (m->qtd + 2, sizeof(void*));

    m->alocados = 2;

    return m;
}

/***
Dado um monitorador valido, libera sua memoria incluindo a de cada um de seus elementos adicionados
*/
void liberaMonitorador(tMonitorador *m){

    if (m != NULL){

        for (int i = 0; i < m->qtd; i++){

            m->liberaElemento(m->elementos[i]);
        }

        free(m->elementos);
        free(m);
    }
}

/***
Dado um monitorador valido e um elemento, adiciona o elemento ao cojunto a ser monitorado
*/
void adicionaElementoMonitorador(tMonitorador *m, void *e){

    if (m->alocados == m->qtd){

        m->elementos = (void**) realloc (m->elementos, (m->qtd + 2) * sizeof(void*));
        m->alocados = m->qtd + 2;
    }

    m->elementos[m->qtd++] = e;
}

/***
Dado um monitorador valido, inicia o monitoramento que durara pelo numero de ciclos informado em numeroDeCiclos
Se numeroDeCiclos for negativo, o monitoramento sera infinito.
O monitoramento consiste em, a cada ciclo, processar cada elemento registrado para monitoramento
*/
int iniciaMonitoramentotMonitorador(tMonitorador *m, int numeroDeCiclos){

    while (numeroDeCiclos){

        for (int i = 0; i < m->qtd; i++){

            m->processaElemento(m->elementos[i]);
        }

        if (numeroDeCiclos > 0){

            numeroDeCiclos--;
        }
    }
}
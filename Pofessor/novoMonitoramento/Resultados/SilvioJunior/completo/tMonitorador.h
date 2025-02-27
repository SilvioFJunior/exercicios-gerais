#ifndef _TMONITORADOR
#define _TMONITORADOR

typedef void (*FptrProcessaElemento)(void *e);
typedef void (*FptrLiberaElemento)(void *e);

/***
O monitorador eh um TAD generico uniforme que tem o objetivo de
varrer os sensores registrados processando cada um deles continuamente.
*/
typedef struct _tMonitorador tMonitorador;

/***
Cria um monitorador valido definindo, de acordo com o tipo de elemento, suas funcoes de
Processar elemento e Liberar elemento
*/
tMonitorador *criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE);

/***
Dado um monitorador valido, libera sua memoria incluindo a de cada um de seus elementos adicionados
*/
void liberaMonitorador(tMonitorador *m);

/***
Dado um monitorador valido e um elemento, adiciona o elemento ao cojunto a ser monitorado
*/
void adicionaElementoMonitorador(tMonitorador *m, void *e);

/***
Dado um monitorador valido, inicia o monitoramento que durara pelo numero de ciclos informado em numeroDeCiclos
Se numeroDeCiclos for negativo, o monitoramento sera infinito.
O monitoramento consiste em, a cada ciclo, processar cada elemento registrado para monitoramento
*/
int iniciaMonitoramentotMonitorador(tMonitorador *m, int numeroDeCiclos);

#endif
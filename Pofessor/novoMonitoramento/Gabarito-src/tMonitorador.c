#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tMonitorador.h"

struct _tMonitorador{
	int qtdElementos;
	void ** elementos;
	
	FptrProcessaElemento funcProcessaElemento;
    FptrLiberaElemento funcLiberaElemento;
};

tMonitorador * criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE){
	tMonitorador *monitorador = (tMonitorador*) malloc (sizeof(tMonitorador));
    if (!monitorador){
        printf("Nao foi possivel alocar memoria para o monitorador!\n");
        exit(1);  
    }

	monitorador->qtdElementos = 0;
	monitorador->elementos = NULL;
    monitorador->funcProcessaElemento = funcPE;
    monitorador->funcLiberaElemento = funcLE;
    
	return monitorador;
}

void liberaMonitorador(tMonitorador* m){
    if (!m){
        printf("Tentando liberar monitorador invalido!\n");
        exit(1);  
    } 
    
	for(int i = 0; i<m->qtdElementos; i++){
		m->funcLiberaElemento(m->elementos[i]);
	}
	if (m->qtdElementos) free(m->elementos);
	
	free(m);
}

void adicionaElementoMonitorador(tMonitorador * m, void * e){
	m->qtdElementos++;
    //printf("m->qtdElementos %d\n", m->qtdElementos);
    m->elementos = realloc(m->elementos, sizeof(void*)*m->qtdElementos);
    m->elementos[m->qtdElementos-1] = e;
}

int iniciaMonitoramentotMonitorador(tMonitorador* m, int numeroDeCiclos){
    while(numeroDeCiclos){
        //printf("ciclos %d\n", numeroDeCiclos);
        for(int i = 0; i<m->qtdElementos; i++){
            m->funcProcessaElemento(m->elementos[i]);
        }
        if (numeroDeCiclos > 0){
            numeroDeCiclos--;
        }
    }
}

#include <stdio.h>
#include "tMonitorador.h"
#include "tSensorTemperatura.h"
#include "tSensorPresenca.h"

int main(){
    tMonitorador *m;
    char tipo;
    scanf("%c", &tipo);
    int qtdSensores;
    scanf("%d", &qtdSensores);
    //printf("qtdSensores %d\n", qtdSensores);
    if (tipo == 'T'){
        m = criaMonitorador(processaSensorTemperatura, liberaSensorTemperatura);
    } else if (tipo == 'P'){
        m = criaMonitorador(processaSensorPresenca, liberaSensorPresenca);
    }
    for(int i = 0; i < qtdSensores; i++){
        void * e;
        if (tipo == 'T'){
            tSensorTemperatura * s = leSensorTemperatura(i+1);
            e = s;
        } else if (tipo == 'P'){
            tSensorPresenca * s = leSensorPresenca(i+1);
            e = s;
        } else {
            return 1;
        }
        

        adicionaElementoMonitorador(m, e);
    }

    int qtdCiclos;
    scanf("%d", &qtdCiclos);
    //printf("qtdCiclos %d\n", qtdCiclos);
    iniciaMonitoramentotMonitorador(m, qtdCiclos/qtdSensores);

	liberaMonitorador(m);
    
	return 0;
}
#include "tSensorPresenca.h"
#include <stdlib.h>
#include <stdio.h>

struct _tSensorPresenca{
    int id;
	int tempoMin;
    int tempoUltimaNotificacao;
};

tSensorPresenca * leSensorPresenca(int id){
	tSensorPresenca* sensor = (tSensorPresenca*) malloc (sizeof(tSensorPresenca));

    sensor->id = id;
    sensor->tempoUltimaNotificacao = -9999;
	scanf("%d", &sensor->tempoMin);
    scanf("\n");

	return sensor;
}

void liberaSensorPresenca(void* s){
    tSensorPresenca * sl = (tSensorPresenca*) s;
	free(sl);
}

void processaSensorPresenca(void * s){
    int presenca, tempo;
    tSensorPresenca * sl = (tSensorPresenca*) s;
    
    scanf("%d%d", &presenca, &tempo);
    printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d", sl->id, sl->tempoMin, presenca, tempo);
    if (presenca && (tempo - sl->tempoUltimaNotificacao) > sl->tempoMin){
        printf("(NOTIFICA)\n");
        sl->tempoUltimaNotificacao = tempo;
    } else {
        printf("(AGUARDA)\n");
    }
}

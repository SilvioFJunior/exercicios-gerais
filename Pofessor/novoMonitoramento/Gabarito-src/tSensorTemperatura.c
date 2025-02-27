#include "tSensorTemperatura.h"
#include <stdlib.h>
#include <stdio.h>

struct _tSensorTemperatura{
    int id;
	int tempMin, tempMax;
    int estadoAr;
};

tSensorTemperatura * leSensorTemperatura(int id){
	tSensorTemperatura* sensor = (tSensorTemperatura*) malloc (sizeof(tSensorTemperatura));

    sensor->id = id;
    sensor->estadoAr = 0;
	scanf("%d %d", &sensor->tempMin, &sensor->tempMax);
    scanf("\n");

	return sensor;
}

void liberaSensorTemperatura(void* s){
    tSensorTemperatura * sl = (tSensorTemperatura*) s;
	free(sl);
}

void processaSensorTemperatura(void * s){
    int temp;
    tSensorTemperatura * sl = (tSensorTemperatura*) s;
    
    scanf("%d", &temp);
    printf("SENSOR(%d)[%d-%d] processando TEMP:%d", sl->id, sl->tempMin, sl->tempMax, temp);
    if (temp < sl->tempMin && sl->estadoAr){
        printf("(DESLIGANDO AR)\n");
        sl->estadoAr = 0;
    }else if (temp > sl->tempMax && !sl->estadoAr){
        printf("(LIGANDO AR)\n");
        sl->estadoAr = 1;
    } else {
        printf("(MANTEM AR)\n");
    }
}

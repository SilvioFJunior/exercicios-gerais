
#include <stdio.h>
#include <stdlib.h>
#include "tSensorTemperatura.h"

/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
struct _tSensorTemperatura
{
    int id;
    int tempMin;
    int tempMax;
    int estadoAr;
};

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorTemperatura *leSensorTemperatura(int id)
{
    tSensorTemperatura *sensor = (tSensorTemperatura *)calloc(1, sizeof(tSensorTemperatura));
    sensor->id = id;
    scanf("%d %d\n", &sensor->tempMin, &sensor->tempMax);
    sensor->estadoAr = 0;
    return sensor;
}

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorTemperatura(void *s)
{
    tSensorTemperatura *sensor = (tSensorTemperatura *)s;
    free(sensor);
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
void processaSensorTemperatura(void *s)
{

    tSensorTemperatura *sensor = (tSensorTemperatura *)s;
    int temp;
    scanf("%d\n", &temp);
    printf("SENSOR(%d)[%d-%d] processando TEMP:%d", sensor->id, sensor->tempMin, sensor->tempMax, temp);

    if (temp < sensor->tempMin && sensor->estadoAr == 1)
    {
        printf("(DESLIGANDO AR)\n");
        sensor->estadoAr = 0;
    }
    else if (temp > sensor->tempMax && sensor->estadoAr == 0)
    {
        printf("(LIGANDO AR)\n");
        sensor->estadoAr = 1;
    }
    else
    {
        printf("(MANTEM AR)\n");
    }

    // SENSOR(1)[20-23] processando TEMP:19(MANTEM AR)
}

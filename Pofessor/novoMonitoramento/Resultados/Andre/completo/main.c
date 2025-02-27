

#include <stdio.h>
#include "tMonitorador.h"
#include "tSensorTemperatura.h"
#include "tSensorPresenca.h"

int main()
{

    char op;
    int qtdSensores;
    tMonitorador *monitor;

    scanf("%c\n", &op);
    if (op == 'T')
    {
        monitor = criaMonitorador(processaSensorTemperatura, liberaSensorTemperatura);
        scanf("%d\n", &qtdSensores);
        for (int i = 0; i < qtdSensores; i++)
        {
            tSensorTemperatura *sensor = leSensorTemperatura(i + 1);
            adicionaElementoMonitorador(monitor, (void *)sensor);
        }
    }
    else if (op == 'P')
    {
        monitor = criaMonitorador(processaSensorPresenca, liberaSensorPresenca);
        scanf("%d\n", &qtdSensores);
        for (int i = 0; i < qtdSensores; i++)
        {
            tSensorPresenca *sp = leSensorPresenca(i + 1);
            adicionaElementoMonitorador(monitor, (void *)sp);
        }
    }

    int qtdCiclos;
    scanf("%d\n", &qtdCiclos);
    iniciaMonitoramentotMonitorador(monitor, qtdCiclos / qtdSensores);

    liberaMonitorador(monitor);

    return 0;
}
#ifndef _TSENSORTEMPERATURA
#define _TSENSORTEMPERATURA

/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
typedef struct _tSensorTemperatura tSensorTemperatura;

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorTemperatura *leSensorTemperatura(int id);

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorTemperatura(void *s);

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
void processaSensorTemperatura(void *s);

#endif
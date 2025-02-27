#ifndef _TSENSORPRESENCA
#define _TSENSORPRESENCA

/***
O sensor servira para detectar a presenca e notificar alguem sobre uma invasao. 
As notificacoes soh devem ser feitas uma vez por intervalo de tempo, ou seja,
uma vez notificado, soh deve ser notificado novamente apos um tempo limite minimo.
*/
typedef struct _tSensorPresenca tSensorPresenca;

/***
Le as configuracoes de um sensor de presenca da entrada padrao e retorna um sensor valido com 
o id recebido como parametro.  
Configuracoes serao dadas em uma linha seguindo "#TEMPO"
#TEMPO intervalo de tempo que devera decorrer antes de enviar uma nova notificacao
*/
tSensorPresenca * leSensorPresenca(int id);

/***
Dado um sensor de presenca valido, libera sua memoria
*/
void liberaSensorPresenca(void*);

/***
Dado um sensor de presenca valido, faz a leitura do sensor de presenca fisico e 
envia uma notificacao de presenca
A leitura do sensor de presenca sera simulada aqui por uma leitura de dois inteiros da entrada padrao
    O primeiro sendo 0 ou 1 para indicar respectivamente a ausencia e presenca de algum na regiao do sensor.
    O segundo sera o tempo atual em minutos desde o inicio do monitoramento.
A notificacao sera simulada aqui com uma impressao em uma linha da saida padrao sendo
    "SENSOR(#ID)[#TEMPO] processando PRESENCA:#P e #TDECOR\n" em que #ID eh o id do sensor, 
    #TEMPO eh conforme definido acima e #P eh a presenca ou nao (1 ou 0) lida do sensor fisico e 
    #TDECOR eh o tempo decorrido desde o inicio tambem lido do sensor fisico, seguida de
    "(NOTIFICA)" para representar que alguem deve ser notificado da presenca quando ocorreu um nova presenca e 
    o tempo decorrido entre a ultima notificacao eh maior que #TEMPO
    "(AGUARDA)" caso contrario
*/
void processaSensorPresenca(void * s);



#endif
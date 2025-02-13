#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

#define TAM_NOME 100 /**< Tamanho máximo do nome do paciente. */
#define TAM_CSUS 19 /**< Tamanho máximo do número do cartão SUS do paciente. */
#define QTD_LESAO 10 /**< Quantidade de lesões que o paciente pode ter. */


struct paciente{

    tData* d;
    tLesao** l;
    char* cartaoSUS;
    char* nome;
    char genero;
    int qtdLesoes;
    int qtdCirurgias;
    int qtdLesoes;
};


/**
 * @brief Retorna o número do cartão SUS do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna uma string contendo o número do cartão SUS do paciente.
 */
char* GetCartaoSusPaciente(tPaciente* p){

    return p->cartaoSUS;
}

/**
 * @brief Retorna a quantidade de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de lesões do paciente.
 */
int GetQtdLesoesPaciente(tPaciente* p){

    return p->qtdLesoes;
}

/**
 * @brief Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 */
int GetQtdCirurgiasPaciente(tPaciente* p){

    return p->qtdCirurgias;
}

/**
 * @brief Retorna a data de nascimento do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a data de nascimento do paciente.
 */
tData* GetNascimentoPaciente(tPaciente* p){

    return p->d;
}

/**
 * @brief Cria uma estrutura do tipo tPaciente
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente
 */
tPaciente* CriaPaciente(){

    tPaciente *p = (tPaciente*) calloc (1, sizeof(tPaciente));
    p->cartaoSUS = (char*) calloc (TAM_CSUS, sizeof(char));
    p->nome = (char*) calloc (TAM_NOME, sizeof(char));
    p->d = (tData**) calloc (1, sizeof(tData*));
    p->l = (tLesao**) calloc (QTD_LESAO, sizeof(tLesao*))
    p->qtdCirurgias = 0;
    p->qtdLesoes = 0;

    return p;
}

/**
 * @brief Lê informações sobre um paciente do usuário.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente contendo as informações lidas.
 */
tPaciente* LePaciente(){

    tPaciente *p = CriaPaciente();

    scanf("%[ˆ\n]", p->nome);
    p->d = LeData();
    scanf("%[ˆ\n]", p->cartaoSUS);
    scanf("%c", &p->genero);

    return p;
}

/**
 * @brief Imprime as informações de um paciente na saída padrão.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 */
void ImprimePaciente(tPaciente* p)[

    printf()
]

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPaciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente a ser liberada.
 */
void LiberaPaciente(tPaciente* p);


/**
 * @brief Adiciona uma lesão à lista de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
*/
void AdicionaLesaoPaciente(tPaciente* p, tLesao* l);
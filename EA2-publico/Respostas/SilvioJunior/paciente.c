#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

#define TAM_NOME 100
#define TAM_SUS 19

struct tPaciente{

    char* nome;
    char* cartaoSUS;
    char genero;
    Lesao** l;
    Data* d;
    int qtdLesoes;
    int qtdLesoesAlocadas;
};

/*
Função que cria uma estrutura Paciente (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Paciente *lePaciente(){

    Paciente *p = (Paciente*) calloc (1, sizeof(Paciente));
    p->nome = (char*) calloc (TAM_NOME,sizeof(char));
    p->cartaoSUS = (char*) calloc (TAM_SUS, sizeof(char));

    scanf("%[ˆ\n]\n", p->nome);
    p->d = leData();
    scanf("%[ˆ\n]\n", p->cartaoSUS);
    scanf("%c\n", p->genero);

    return p;
}

/*
Função que libera toda a memória alocada para a estrutura Paciente.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaPaciente(Paciente *p){

    if (p != NULL){

        liberaData(p->d);
        free(p->cartaoSUS);
        free(p->nome);
        free(p);
    }
}

/*
Função que recebe um paciente e uma lesão e adiciona a lesão ao paciente no grupo de lesões que ele possui.
Se for necessário mais memória para alocar uma nova lesão, essa função deve realocar a memória necessária.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l){

    if (p->qtdLesoes == p->qtdLesoesAlocadas){

        p->qtdLesoesAlocadas += 2;

        p->l = (Lesao**) realloc (p->l, p->qtdLesoesAlocadas * sizeof(Lesao*));

        p->l[p->qtdLesoes] = l;

        p->qtdLesoes++;
    }
}

/*
Função que calcula a idade do paciente em relação a uma data de referência informada.
*/
int calculaIdadePaciente(Paciente *p, Data *ref){

    return calculaDiffAnosData(p->d, ref);
}

/*
Função que retorna a quantidade de cirurgias associadas a este paciente de acordo com as regras
descritas na descrição.
*/
int getQtdCirurgiasPaciente(Paciente *p){

    int total = 0;

    for (int i = 0; i < p->qtdLesoes; i++){

        if (precisaCirurgiaLesao(p->l[i])){
            total++;
        }
    }

    return total;
}

/*
Função que retorna o cartão do sus do paciente.
*/
char *getCartaoSusPaciente(Paciente *p){

    return p->cartaoSUS;
}

/*
Função que retorna a data de nascimento do paciente.
*/
Data *getDataNascPaciente(Paciente *p){

    return p->d;
}

/*
Função que retorna a quantidade de lesões do paciente
*/
int getQtdLesoesPaciente(Paciente *p){

    return p->qtdLesoes;
}

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.
*/
void imprimeIdLesoesPaciente(Paciente *p){

    if (p->qtdLesoes > 0){

        printf("- %s - ", p->nome);

        for (int i = 0; i < p->qtdLesoes; i++){
            printf("%s ", p->l[i]);
        }

        printf("\n");
    }
}
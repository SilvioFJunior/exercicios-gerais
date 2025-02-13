#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

struct lesao{

    char* id;
    char* diag;
    char* reg; 
    int malig;   
};


/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao(){

    tLesao *l = (tLesao*) calloc (1, sizeof(tLesao));
    l->id = (char*) calloc (TAM_ID, sizeof(char));
    l->diag = (char*) calloc (TAM_DIAG, sizeof(char));

    return l;
}

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l){

    l = CriaLesao();

    scanf("%[ˆ\n]\n", l->id);
    scanf("%[ˆ\n]\n", l->diag);
    scanf("%[ˆ\n]\n", l->reg);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l){

    if (l != NULL){

        free(l->id);
        free(l->diag);
        free(l->reg);
        free(l);
    }
}

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l){

    return l->id;
}

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l){

    if (l->malig > 50){

        return 1;
    }

    return 0;
}
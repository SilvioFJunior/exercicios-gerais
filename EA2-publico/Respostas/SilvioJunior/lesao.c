#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

struct tLesao{
    
    char* id;
    char* diag;
    char* reg;
    int malig;
};

/*
Função que cria uma estrutura Lesao (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Lesao *leLesao(){

    Lesao *l = (Lesao*) calloc (1, sizeof(Lesao));
    l->id = (char*) calloc (TAM_ID, sizeof(char));
    l->diag = (char*) calloc (TAM_DIAG, sizeof(char));
    l->reg = (char*) calloc (TAM_REG, sizeof(char));

    scanf("%[ˆ\n]\n", l->id);
    scanf("%[ˆ\n]\n", l->diag);
    scanf("%[ˆ\n]\n", l->reg);
    scanf("%d", &l->malig);

    return l;
}

/*
Função que libera a memória alocada para a estrutura Lesao.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaLesao(Lesao *l){

    if (l != NULL){
        free(l->reg);
        free(l->diag);
        free(l->id);
        free(l);
    }
}

/*
Função que retorna o Id da lesão passada como parâmetro.
*/
char *getIdLesao(Lesao *l){

    return l->id;
}

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(Lesao *l){

    if (l->malig > 50){
        return 1;
    }

    return 0;
}
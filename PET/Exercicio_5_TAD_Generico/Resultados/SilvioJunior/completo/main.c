#include "roteiro.h"
#include "midia.h"
#include "livro.h"
#include "musica.h"
#include "pintura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int num;

    scanf("%d\n", &num);

    char opcao;

    Roteiro *r = roteiro_construct();

    for (int i = 0; i < num; i++){

        void *dado;
        PrintFunction print = NULL;
        FreeFunction free = NULL;

        scanf("%c ", &opcao);

        if (opcao == 'L'){

            dado = livro_construct();
            print = livro_print;
            free = livro_destroy;
        }

        else if (opcao == 'M'){

            dado = musica_construct();
            print = musica_print;
            free = musica_destroy;
        }

        else if (opcao == 'P'){

            dado = pintura_construct();
            print = pintura_print;
            free = pintura_destroy;
        }

        roteiro_inserir_midia(r, dado, print, free);
    }

    roteiro_imprimir_midias(r);
    roteiro_destroy(r);

    return 0;
}
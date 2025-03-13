#include "roteiro.h"
#include "livro.h"
#include "pintura.h"
#include "musica.h"
#include <stdio.h>

int main()
{
    int n = 0;
    Roteiro *roteiro = roteiro_construct();

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        char tipoMidia = 0;
        void *dado = NULL;
        PrintFunction print_fn = NULL;
        FreeFunction free_fn = NULL;

        scanf("%c ", &tipoMidia);

        if (tipoMidia == 'P')
        {
            dado = pintura_construct();
            print_fn = pintura_print;
            free_fn = pintura_destroy;
        }

        else if (tipoMidia == 'L')
        {
            dado = livro_construct();
            print_fn = livro_print;
            free_fn = livro_destroy;
        }

        else if (tipoMidia == 'M')
        {
            dado = musica_construct();
            print_fn = musica_print;
            free_fn = musica_destroy;
        }

        roteiro_inserir_midia(roteiro, dado, print_fn, free_fn);
    }

    roteiro_imprimir_midias(roteiro);
    roteiro_destroy(roteiro);

    return 0;
}
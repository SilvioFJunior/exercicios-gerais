#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

int main (){

    int alocado = 10;
    int tamanho = 0;

    Produto** vetorP = (Produto**) calloc (alocado, sizeof(Produto*));
    
    int op;
    
    while (1){

        printf("===== Sistema de Registro de Produtos =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir lista de produtos cadastrados\n");
        printf("3 - Salvar lista de produtos em arquivo\n");
        printf("4 - Ler lista de produtos de arquivo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        
        if (op == 1){

            cadastrarProduto(vetorP, &tamanho, &alocado);
        } 
        
        else if (op == 2){

            ordenarLista(vetorP, tamanho);
            exibirLista(vetorP, tamanho);
        } 
        
        else if (op == 3){

            salvarLista(vetorP, tamanho);
            printf("Lista de produtos salva no arquivo 'produtos.bin'.\n");
        } 

        else if (op == 4){

            desalocaLista(vetorP, tamanho);
            vetorP = lerLista(&tamanho, &alocado);
        } 
        
        else if (op == 5){

            printf("Encerrando o programa.\n");

            break;
        } 
        
        else {

            printf("Opcao invalida.\n");
        }
        
        printf("\n");
    }
    
    for (int i = 0; i < tamanho; i++){
        free(vetorP[i]);
    }

    free(vetorP);
    
    return 0;
}

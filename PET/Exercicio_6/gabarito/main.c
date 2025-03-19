#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int alocado = 10;
    int tamanho = 0;
    Produto** vetorProdutos = (Produto**) malloc(alocado * sizeof(Produto*));
    
    int opcao;
    do {
        printf("===== Sistema de Registro de Produtos =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir lista de produtos cadastrados\n");
        printf("3 - Salvar lista de produtos em arquivo\n");
        printf("4 - Ler lista de produtos de arquivo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarProduto(vetorProdutos, &tamanho, &alocado);
                break;
            case 2:
                ordenarLista(vetorProdutos, tamanho);
                exibirLista(vetorProdutos, tamanho);
                break;
            case 3:
                salvarLista(vetorProdutos, tamanho);
                printf("Lista de produtos salva no arquivo 'produtos.bin'.\n");
                break;
            case 4:
                desalocaLista(vetorProdutos, tamanho);
                vetorProdutos = lerLista(&tamanho, &alocado);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        
        printf("\n");
    } while (opcao != 5);
    
    for(int i = 0; i < tamanho; i++) {
        free(vetorProdutos[i]);
    }
    free(vetorProdutos);
    
    return 0;
}
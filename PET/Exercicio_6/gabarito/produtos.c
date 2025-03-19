#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void cadastrarProduto(Produto** vetorProdutos, int* tamanho, int* alocado) {
    if(*tamanho == *alocado) {
        *alocado *= 2;
        vetorProdutos = (Produto**) realloc(vetorProdutos, *alocado * sizeof(Produto*));
    }

    Produto* produto = (Produto*) malloc(sizeof(Produto));

    scanf("%s %f %d", produto->nome, &produto->preco, &produto->quantidade);

    for(int i = 0; i < *tamanho; i++) {
        if(strcmp(produto->nome, vetorProdutos[i]->nome) == 0) {
            vetorProdutos[i]->preco = produto->preco;
            vetorProdutos[i]->quantidade += produto->quantidade;
            free(produto);
            return;
        }
    }

    (vetorProdutos)[*tamanho] = produto;
    (*tamanho)++;
}

void exibirLista(Produto** vetorProdutos, int tamanho) {
    printf("\nLista de produtos cadastrados:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetorProdutos[i]->nome);
        printf("Preco: %.2f\n", vetorProdutos[i]->preco);
        printf("Quantidade em estoque: %d\n\n", vetorProdutos[i]->quantidade);
    }
}

int compararProduto(const void* a, const void* b) {
    Produto* produtoA = *(Produto**)a;
    Produto* produtoB = *(Produto**)b;
    
    if (produtoA->preco * produtoA->quantidade > produtoB->preco * produtoB->quantidade)
        return -1;
    else if (produtoA->preco * produtoA->quantidade < produtoB->preco * produtoB->quantidade)
        return 1;
    else
        return strcmp(produtoA->nome, produtoB->nome);
}

void ordenarLista(Produto** vetorProdutos, int tamanho) {
    qsort(vetorProdutos, tamanho, sizeof(Produto*), compararProduto);
}

void desalocaLista(Produto** vetorProdutos, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        free(vetorProdutos[i]);
    }
    free(vetorProdutos);
}

void salvarLista(Produto** vetorProdutos, int tamanho) {
    FILE* arquivo = fopen("produtos.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if(tamanho == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    fwrite(&tamanho, sizeof(int), 1, arquivo);
    
    for(int i = 0; i < tamanho; i++) {
        fwrite(vetorProdutos[i], sizeof(Produto), 1, arquivo);
    }
    
    fclose(arquivo);
}

Produto** lerLista(int* tamanho, int* alocado) {
    FILE* arquivo = fopen("produtos.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo 'produtos.bin'.\n");
        return NULL;
    }
    
    fread(tamanho, sizeof(int), 1, arquivo);
    *alocado = *tamanho * 2;
    Produto** novoVetorProdutos = (Produto**) malloc(*alocado * sizeof(Produto*));
    
    for(int i = 0; i < *tamanho; i++) {
        Produto* produto = (Produto*) malloc(sizeof(Produto));
        fread(produto, sizeof(Produto), 1, arquivo);
        novoVetorProdutos[i] = produto;
    }
    
    fclose(arquivo);

    return novoVetorProdutos;
}
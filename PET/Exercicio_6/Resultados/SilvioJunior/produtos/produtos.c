#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * @brief Cadastra um novo produto no vetor de produtos.
*/
void cadastrarProduto(Produto** vetorProdutos, int* tamanho, int* alocado){

    if (*tamanho == *alocado){

        *alocado = *alocado * 2;
        vetorProdutos = (Produto **) realloc (vetorProdutos, *alocado * sizeof(Produto *));
    }

    Produto *p = (Produto *) calloc (1, sizeof(Produto));

    scanf("%s %f %d", p->nome, &p->preco, &p->quantidade);

    for (int i = 0; i < *tamanho; i++){

        if (strcmp(p->nome, vetorProdutos[i]->nome) == 0){

            vetorProdutos[i]->preco = p->preco;
            vetorProdutos[i]->quantidade += p->quantidade;

            free(p);
            return;
        }
    }

    (vetorProdutos)[(*tamanho)++] = p;
}

/** 
 * @brief Exibe a lista de produtos ordenada.
*/
void exibirLista(Produto** vetorProdutos, int tamanho){

    printf("\nLista de produtos cadastrados:\n");

    for (int i = 0; i < tamanho; i++){

        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetorProdutos[i]->nome);
        printf("Preco: %.2f\n", vetorProdutos[i]->preco);
        printf("Quantidade em estoque: %d\n\n", vetorProdutos[i]->quantidade);
    }
}

/** 
 * @brief Compara dois produtos.
*/
int compararProduto(const void* a, const void* b){

    Produto* produtoA = *(Produto**)a;
    Produto* produtoB = *(Produto**)b;
    
    if (produtoA->preco * produtoA->quantidade > produtoB->preco * produtoB->quantidade){
        
        return -1;
    }

    else if (produtoA->preco * produtoA->quantidade < produtoB->preco * produtoB->quantidade){
        
        return 1;
    }

    else {

        return strcmp(produtoA->nome, produtoB->nome);
    }
}

/** 
 * @brief Ordena a lista de produtos.
*/
void ordenarLista(Produto** vetorProdutos, int tamanho){

    qsort(vetorProdutos, tamanho, sizeof(Produto*), compararProduto);
}

/** 
 * @brief Desaloca a lista de produtos e todos os seus produtos.
*/
void desalocaLista(Produto** vetorProdutos, int tamanho){

    for (int i = 0; i < tamanho; i++){

        free(vetorProdutos[i]);
    }

    free(vetorProdutos);
}

/** 
 * @brief Escreve a lista em um arquivo binário.
*/
void salvarLista(Produto** vetorProdutos, int tamanho){

    FILE* arquivo = fopen("produtos.bin", "wb");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");

        return;
    }

    if (tamanho == 0){

        printf("Nenhum produto cadastrado.\n");

        return;
    }

    fwrite(&tamanho, sizeof(int), 1, arquivo);
    
    for (int i = 0; i < tamanho; i++){

        fwrite(vetorProdutos[i], sizeof(Produto), 1, arquivo);
    }
    
    fclose(arquivo);
}

/** 
 * @brief Le uma lista de produtos salva em formato binário e a retorna.
*/
Produto** lerLista(int* tamanho, int* alocado){

    FILE* arquivo = fopen("produtos.bin", "rb");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo 'produtos.bin'.\n");

        return NULL;
    }
    
    fread(tamanho, sizeof(int), 1, arquivo);

    *alocado = *tamanho * 2;

    Produto** vetorP = (Produto**) malloc(*alocado * sizeof(Produto*));
    
    for(int i = 0; i < *tamanho; i++) {

        Produto* p = (Produto*) malloc(sizeof(Produto));

        fread(p, sizeof(Produto), 1, arquivo);

        vetorP[i] = p;
    }
    
    fclose(arquivo);

    return vetorP;
}
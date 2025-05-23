#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um usuario.
 * @param nome nome do usuario.
 * @param cpf cpf do usuario.
 * @return Usuario criado.
 */
Usuario* CriaUsuario(char* nome, int cpf){

    Usuario *u =(Usuario*) calloc (1, sizeof(Usuario));
    
    strcpy(u->nome, nome);
    u->cpf = cpf;

    return u;
}

/**
 * @brief Retorna o nome de um usuario.
 * @param usuario  um usuario.
 * @return nome do usuario.
 */
char* RecuperaNomeUsuario(Usuario* usuario){

    return usuario->nome;
}

/**
 * @brief Retorna o cpf de um usuario.
 * @param usuario  um usuario.
 * @return cpf do usuario.
 */
int RecuperaCpfUsuario(Usuario* usuario){

    return usuario->cpf;
}

/**
 * @brief Destroi um usuario.
 * @param usuario  um usuario.
 */
void DestroiUsuario(Usuario* usuario){

    if (usuario != NULL){

        free(usuario->nome);
        free(usuario);
    }
}
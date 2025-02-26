#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario *CriaUsuario(char *nome, int cpf)
{
    Usuario *usuario = (Usuario *)calloc(1, sizeof(Usuario));
    usuario->nome = (char *)calloc(sizeof(nome), sizeof(char));
    strcpy(usuario->nome, nome);
    usuario->cpf = cpf;
    return usuario;
}

char *RecuperaNomeUsuario(Usuario *usuario)
{
    return usuario->nome;
}

int RecuperaCpfUsuario(Usuario *usuario)
{
    return usuario->cpf;
}

void DestroiUsuario(Usuario *usuario)
{
    if (usuario != NULL)
    {
        free(usuario->nome);
        free(usuario);
    }
}
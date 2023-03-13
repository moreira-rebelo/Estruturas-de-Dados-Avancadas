/**
*@file utilizadores.c
*@author Francisco Rebêlo (a16443@alunos.ipca.pt)
*@brief Local onde estão definidas todas as funções relativas aos utilizadores
*@version 1
*@date 2023/03/09
*
*@copyright Copyright (c) 2023
*/

#include <stdlib.h>
#include "funcoes.h"

/*listaUtilizadores* lerUtilizadores()
{
    FILE *ficheiroUtilizadores;
    ficheiroUtilizadores = fopen("C:/Users/morei/Desktop/EDA/a16443_Fase1/Codigo/utilizadores.txt", "r");

    if (ficheiroUtilizadores == NULL){
        perror("Erro ao abrir ficheiro!");
        exit(1);
    }

    Utilizador* inicio = NULL;
    char line[100];
    char *sp = NULL;
    int idUtilizador = -1;
    int permissao;
    char nome[50];
    int nif;
    int saldo;
    while (fgets(line, 100, ficheiroUtilizadores) != NULL) {
        sp = strtok(line, ",");
        idUtilizador = atoi(sp);
        sp = strtok(NULL, ",");
        permissao = atoi(sp);
        sp = strtok(NULL, ",");
        strncpy(nome, sp, sizeof(nome));
        sp = strtok(NULL, ",");
        nif = atoi(sp);
        sp = strtok(NULL, ",");
        saldo = atoi(sp);
        inicio = inserirUtilizadorFim(inicio, idUtilizador, permissao, nome, nif);
    }
    fclose(ficheiroUtilizadores);
    return inicio;
}*/

//----- INSERIR NO FIM -----
listaUtilizadores* inserirUtilizadorFim(listaUtilizadores* inicio, int idUtilizador, int permissao, char nome, int nif, int saldo)
{
    listaUtilizadores* novo = (listaUtilizadores*)malloc(sizeof(listaUtilizadores));
    listaUtilizadores* aux;

    if (novo != NULL) {
        novo->idUtilizador = idUtilizador;
        novo->permissao = permissao;
        strncpy(novo->nome, nome, sizeof(novo->nome));
        novo->nif = nif;
        novo->saldo = saldo;
        novo->seguinte = NULL;

        if (inicio == NULL) {
            return(novo);
        }
        else {
            aux = inicio;
            while (aux->seguinte) {
                aux = aux->seguinte;
            }
            aux->seguinte = novo;
        }
    }
    return(inicio);
}

//Imprimir utilizadores
void printListaUtilizadores(listaUtilizadores* inicio) {

    listaUtilizadores* atual = inicio;

    while (atual != NULL) {

        printf("ID Utilizador: %d\n", atual->idUtilizador);
        printf("Permissao: %d\n", atual->permissao);
        printf("NIF: %d\n", atual->nif);
        printf("Saldo: %d\n", atual->saldo);
        printf("------------------------\n");

        atual = atual->seguinte;
    }
}



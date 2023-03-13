#/**
*@file funcoes.h
*@author Francisco Rebêlo (a16443@alunos.ipca.pt)
*@brief Ficheiro header
*@version 1
*@date 2023/03/09
*
*@copyright Copyright (c) 2023
*/

#include <stdio.h>
#ifndef X
#define X

/**
*@brief Struct de utilizadores
*
*/
typedef struct listaUtilizadores
{
    int idUtilizador, permissao, nif, saldo;
        struct listaUtilizadores* seguinte;
} listaUtilizadores;


/**
*@brief Struct de veiculos
*
*/
typedef struct listaVeiculos
{
    int tipo, cargaBateria, custo, geoCodigo;
    struct listaVeiculos* seguinte;

} listaVeiculos;


//listaUtilizadores* lerUtilizadores();

// ----- FUNÇÕES PARA INSERIR ITEMS NA LISTA
listaUtilizadores* inserirUtilizadorFim(listaUtilizadores* inicio, int idUtilizador, int permissao, char nome, int nif, int saldo);
listaVeiculos* iserirVeiculoFim(listaVeiculos* inicio, int idVeiculo, int tipo, int cargaBateria, int custo, char geoCodigo);

// ----- FUNÇÕES PARA LER ITEMS NA LISTA E REALIZAR OPERAÇÕES COM OS DADOS
/*
void lerListaTMin(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista);
void lerListaTMin(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista);
void lerListaTMedio(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista);
*/

void printListaUtilizadores(listaUtilizadores* inicio);

#endif
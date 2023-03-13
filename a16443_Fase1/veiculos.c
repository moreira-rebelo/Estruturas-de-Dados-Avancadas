/**
*@file veiculos.c
*@author Francisco Rebêlo (a16443@alunos.ipca.pt)
*@brief Local onde estão definidas todas as funções relativas aos veiculos
*@version 1
*@date 2023/03/09
*
*@copyright Copyright (c) 2023
*/

#include <stdlib.h>
#include "funcoes.h"

//----- INSERIR NO FIM -----
listaVeiculos* inserirVeiculoFim(listaVeiculos* inicio, int idVeiculo, int tipo, int cargaBateria, int custo, char geoCodigo)
{
    listaVeiculos* novo = (listaVeiculos*)malloc(sizeof(listaVeiculos));
    listaVeiculos* aux;

    if (novo != NULL) {
        novo->idVeiculo = idVeiculo;
        novo->tipo = tipo;
        novo->cargaBateria = cargaBateria;
        novo->custo = custo;
        novo->geoCodigo = geoCodigo;
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
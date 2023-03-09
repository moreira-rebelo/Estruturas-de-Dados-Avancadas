/**
@file main.c
@author Francisco Rebêlo (a16443@alunos.ipca.pt)
@brief 
@version 
@date 2023/03/09

@copyright Copyright (c) 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

int main() {
//----- DECLARAÇÃO DE VARIÁVEIS ------
    int aux, i = 0,;
    char line[100], c = '|', *sp;
    listaJob *inicio = NULL;

//----- LÊ A TABELA A PARTIR DE UM FICHEIRO TXT -----
    FILE *ficheiroUtilizadores;
    ficheiroUtilizadores = fopen("C:/Users/FR/Desktop/EDA1FINAL/tabela.txt", "r");

    if (ficheiroTabela == NULL){
        perror("Erro ao abrir ficheiro!");
        exit(1);
    }

    while (fgets(line, 100, ficheiroTabela) != NULL) {

        while (sp != NULL) { //Enquanto não chega ao fim da linha mantém no ciclo
            if (nOp == -1){ //Se nOp = -1, quer dizer que ainda não foram importadas máquinas, portanto lê desde o inicio da linha
                sp = strtok(line, ","); //Começa a ler desde o início da linha até encontrar a vírgula e guarda no apontador sp
                nOp = atoi(sp); //Converte o caracter num inteiro e guarda na variável nOp
            }
            else { //Caso contrário continua a lêr de onde parou
                sp = strtok(NULL, ",");
                nOp = atoi(sp);
            }

            sp = strtok(NULL, ",");
            machineId = atoi(sp);

            sp = strtok(NULL, ",");
            machineT = atoi(sp);

            inicio = inserirJobFim(inicio, nOp, machineId, machineT);
        }
    }
    fclose(ficheiroTabela);


    lerListaTMin(inicio, &nOpLista, &machineIdLista, &machineTLista);
    lerListaTMax(inicio, &nOpLista, &machineIdLista, &machineTLista);
    lerListaTMedio(inicio, &nOpLista, &machineIdLista, &machineTLista);

    return 0;
}

/**
*@file main.c
*@author Francisco Reb�lo (a16443@alunos.ipca.pt)
*@brief
*@version 1
*@date 2023/03/09
*
*@copyright Copyright (c) 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
//#include "lista.c"
#include "utilizadores.c"
//#include "veiculos.c"


int main() {
    //----- DECLARA��O DE VARI�VEIS ------
    int aux, i = 0;
    int idUtilizador = -1, nif, saldo, permissao; //Utilizador
    int idVeiculo, tipo, cargaBateria, custo; //Veiculo
    char line[100], c = '|', * sp, nome[20], geoCodigo[20];

    listaUtilizadores* inicio = NULL;
    listaVeiculos* inicio = NULL;

    //----- L� A TABELA  DE UTILIZADORES A PARTIR DE UM FICHEIRO TXT -----
    FILE* ficheiroUtilizadores;
    ficheiroUtilizadores = fopen("C:/Users/morei/Desktop/EDA/a16443_Fase1/Codigo/utilizadores.txt", "r");

    if (ficheiroUtilizadores == NULL) {
        perror("Erro ao abrir ficheiro!");
        exit(1);
    }

    while (fgets(line, 100, ficheiroUtilizadores) != NULL) {

        ;        while (sp != NULL) { //Enquanto n�o chega ao fim do ficheiro mant�m no ciclo



            if (idUtilizador == -1) { //Se idUtilizador = -1, quer dizer que ainda n�o foram importados utilizadores, portanto l� desde o inicio da linha
                sp = strtok(line, ","); //Come�a a ler desde o in�cio da linha at� encontrar a v�rgula e guarda no apontador sp
                idUtilizador = atoi(sp); //Converte o caracter num inteiro e guarda na vari�vel idUtilizador
            }
            else { //Caso contr�rio continua a l�r de onde parou
                sp = strtok(NULL, ",");
                idUtilizador = atoi(sp);
            }

            sp = strtok(NULL, ",");
            permissao = atoi(sp);

            sp = strtok(NULL, ",");
            strncpy(nome, sp, sizeof(nome)); //Le o nome e guarda na vari�vel nome

            sp = strtok(NULL, ",");
            nif = atoi(sp);

            sp = strtok(NULL, ",");
            saldo = atoi(sp);

            sp = strtok(NULL, ";");
            inicio = inserirUtilizadorFim(inicio, idUtilizador, permissao, nome, nif);
        }
    }
    fclose(ficheiroUtilizadores);


    printListaUtilizadores(inicio);

   // lerListaTMin(inicio, &nOpLista, &machineIdLista, &machineTLista);
   // lerListaTMax(inicio, &nOpLista, &machineIdLista, &machineTLista);
   // lerListaTMedio(inicio, &nOpLista, &machineIdLista, &machineTLista);

    return 0;
}

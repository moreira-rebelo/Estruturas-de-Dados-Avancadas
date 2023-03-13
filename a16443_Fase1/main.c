/**
*@file main.c
*@author Francisco Rebêlo (a16443@alunos.ipca.pt)
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
    //----- DECLARAÇÃO DE VARIÁVEIS ------
    int aux, i = 0;
    int idUtilizador = -1, nif, saldo, permissao; //Utilizador
    int idVeiculo, tipo, cargaBateria, custo; //Veiculo
    char line[100], c = '|', * sp, nome[20], geoCodigo[20];

    listaUtilizadores* inicio = NULL;
    listaVeiculos* inicio = NULL;

    //----- LÊ A TABELA  DE UTILIZADORES A PARTIR DE UM FICHEIRO TXT -----
    FILE* ficheiroUtilizadores;
    ficheiroUtilizadores = fopen("C:/Users/morei/Desktop/EDA/a16443_Fase1/Codigo/utilizadores.txt", "r");

    if (ficheiroUtilizadores == NULL) {
        perror("Erro ao abrir ficheiro!");
        exit(1);
    }

    while (fgets(line, 100, ficheiroUtilizadores) != NULL) {

        ;        while (sp != NULL) { //Enquanto não chega ao fim do ficheiro mantém no ciclo



            if (idUtilizador == -1) { //Se idUtilizador = -1, quer dizer que ainda não foram importados utilizadores, portanto lê desde o inicio da linha
                sp = strtok(line, ","); //Começa a ler desde o início da linha até encontrar a vírgula e guarda no apontador sp
                idUtilizador = atoi(sp); //Converte o caracter num inteiro e guarda na variável idUtilizador
            }
            else { //Caso contrário continua a lêr de onde parou
                sp = strtok(NULL, ",");
                idUtilizador = atoi(sp);
            }

            sp = strtok(NULL, ",");
            permissao = atoi(sp);

            sp = strtok(NULL, ",");
            strncpy(nome, sp, sizeof(nome)); //Le o nome e guarda na variável nome

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

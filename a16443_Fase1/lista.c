#include <stdlib.h>
#include "funcoes.h"

//----- INSERIR NO INICIO -----
listaJob* inserirJobInicio(listaJob* inicio, int nOp, int machineId, int machineT) {
    listaJob* novo = (listaJob*)malloc(sizeof(listaJob));

    if (novo != NULL) {
        novo->nOp = nOp;
        novo->seguinte = inicio;
        novo->machineId;
        novo->machineId = machineId;
        novo->machineT;
        novo->machineT = machineT;
        return(novo);
    }
}



// ----- CORRE A LISTA E ESCOLHE OS VALORES DE TEMPO MENORES -----
void lerListaTMin(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista) {
    listaJob* aux = inicio;
    int i = 1, nOpAux, machineIdAux, machineTAux, somaT = 0;

    printf("\n=== TEMPO MINIMO PARA CONLCUSAO DO JOB =====\n\n");

    while (aux != NULL) {
        while (aux->nOp == i) {

            nOpAux = aux->nOp;
            machineIdAux = aux->machineId;
            machineTAux = aux->machineT;

            aux = aux->seguinte;

            if (machineTAux > aux->machineT) {
                nOpAux = aux->nOp;
                machineIdAux = aux->machineId;
                machineTAux = aux->machineT;
            }
            else {
                somaT = somaT + machineTAux;
                printf("Utilizada a maquina %d na operacao %d com duracao total de: %d\n", machineIdAux, nOpAux, somaT);
                aux = aux->seguinte;
            }
            i++;
        }
        aux = aux->seguinte;
    }
    printf("\n--------------------------------------------------------------\n");
    printf("| A quantidade minima de tempo para completar o job e de: %d |\n", somaT);
    printf("--------------------------------------------------------------\n");
}

// ----- CORRE A LISTA E ESCOLHE OS VALORES DE TEMPO MAIORES -----
void lerListaTMax(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista) {
    listaJob* aux = inicio;
    int i = 1, nOpAux, machineIdAux, machineTAux, somaT = 0;

    printf("\n=== TEMPO MAXIMO PARA CONLCUSAO DO JOB =====\n\n");

    while (aux != NULL) {
        while (aux->nOp == i) {

            nOpAux = aux->nOp;
            machineIdAux = aux->machineId;
            machineTAux = aux->machineT;

            aux = aux->seguinte;

            if (machineTAux > aux->machineT) {
                somaT = somaT + machineTAux;
                printf("Utilizada a maquina %d na operacao %d com duracao total de: %d\n", machineIdAux, nOpAux, somaT);
                aux = aux->seguinte;
            }
            else {
                nOpAux = aux->nOp;
                machineIdAux = aux->machineId;
                machineTAux = aux->machineT;
                somaT = somaT + machineTAux;
                printf("Utilizada a maquina %d na operacao %d com duracao total de: %d\n", machineIdAux, nOpAux, somaT);
                aux = aux->seguinte;
            }
            i++;
        }
        aux = aux->seguinte;
    }
    printf("\n--------------------------------------------------------------\n");
    printf("| A quantidade maxima de tempo para completar o job e de: %d |\n", somaT);
    printf("--------------------------------------------------------------\n");
}

// ----- CORRE A LISTA E DETERMINA A M?DIA -----
void lerListaTMedio(listaJob* inicio, int* nOpLista, int* machineIdLista, int* machineTLista) {
    listaJob* aux = inicio;
    int tot = 0, media, soma = 0;

    printf("\n=== TEMPO MEDIO PARA CONCLUSAO DO JOB =====\n");

    while (aux != NULL) {

        soma = soma + aux->machineT;
        tot++;
        aux = aux->seguinte;
    }

    media = soma / tot;

    printf("--------------------------------------------------------------\n");
    printf("| A quantidade media de tempo para completar o job e de: %d |\n", media);
    printf("--------------------------------------------------------------\n");
}
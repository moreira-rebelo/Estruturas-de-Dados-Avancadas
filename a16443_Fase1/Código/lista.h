#include <stdio.h>
#ifndef X
#define X

typedef struct listaJob {
    int nOp;
    int machineId;
    int machineT;

    struct listaJob *seguinte;
    struct listaJob *anterior;
} listaJob;

// ----- FUNÇÕES PARA INSERIR ITEMS NA LISTA
listaJob* inserirJobInicio(listaJob *inicio, int nOp, int machineId, int machineT);
listaJob* inserirJobFim(listaJob *inicio, int nOp, int machineId, int machineT);

// ----- FUNÇÕES PARA LER ITEMS NA LISTA E REALIZAR OPERAÇÕES COM OS DADOS
void lerListaTMin(listaJob *inicio, int *nOpLista, int *machineIdLista, int *machineTLista);
void lerListaTMin(listaJob *inicio, int *nOpLista, int *machineIdLista, int *machineTLista);
void lerListaTMedio(listaJob *inicio, int *nOpLista, int *machineIdLista, int *machineTLista);

#endif
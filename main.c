#include <stdio.h>
#include <stdlib.h>
#include "FuncAux/embaralhaVet.h"
#include "FuncAux/baseDeDados.h"
#include "Employee/employee.h"
#include "MetodosBusca/buscaBinaria.h"
#include "SelectionMethod/s.h"
#include "SelectionMethod/selecSubs.h"

int main() {
    printf("Starting...\n");

    int pick;

    printf("\nEscolha: \n 1 - Criar um arquivo .dat randomico; \n 2 - Ler um arquivo .dat existente.\n   ---> ");
    scanf("%i", &pick);

    if (pick == 1) {
        procedimento_File_If_Not_Null();
    } else {
        encontraArquivo();
    }

    return 0;
}


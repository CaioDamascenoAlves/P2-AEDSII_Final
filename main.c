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
        FILE *arq = fopen("registro.dat", "wb+");

        if (arq != NULL) {

            int numFunc = 0, idEmployee = 0, sortingMethod = 0;
            int *vet;
            printf("Insira o numero de Funcionarios: ");
            scanf("%i", &numFunc);

            printf("Insira o Id do Funcionario que deseja buscar: ");
            scanf("%i", &idEmployee);

            vet = (int *)malloc(numFunc * sizeof(int));

            embaralhaVet(vet, numFunc);

            criaBD(arq, numFunc, vet);

            TEmp *emp = sequentialFetch(idEmployee, arq);

            if (emp == NULL) {
                printf("\nRegistro nao encontrado.\n");
            } else {
                printf("\nRegistro achado pela busca sequencial: \n");
                printEmployee(emp);
            }

            printf("\n3 - Substitution Selection;\n 4 - Natural Selection.\n --->  ");
            scanf("%i", &sortingMethod);


            if (sortingMethod == 3){

                int numberOfPartition = 0;
                numberOfPartition = substitutionSelection(arq, "substitutionSelectionPartition");

                fclose(arq);

                exit(0);
            } else {
                int numberOfPartition = 0;
                numberOfPartition = naturalSelection(arq, "naturalSelectionPartition");

                fclose(arq);

                exit(0);
            }

            free(emp);
            free(vet);
            fclose(arq);

        } else {
            printf("Err file.\n");
            return 1;
        }
    } else {

        char nameFile[50];

        printf("\nEnter the file name: ");
        scanf("%s", &nameFile);

        FILE *arq = fopen(nameFile, "rb+");

        if (arq != NULL) {

            int idEmployee, totalComparisonsSequential = 0, sortingMethod = 0;

            printf("\nOk!\n");

            printf("Input the id of Employee you want to find: ");
            scanf("%i", &idEmployee);

            TEmp *emp = sequentialFetch(idEmployee, arq);

            if (emp == NULL) {
                printf("\nRegistro nao encontrado.\n");
            } else {
                printf("\nRegistro encontrado pela busca sequencial: \n");
                printEmployee(emp);
            }

            printf("3 - Substitution Selection\n 4 - Natural Selection.\n --->  ");
            scanf("%i", &sortingMethod);

           if (sortingMethod == 3){
                int numberOfPartition = 0;
                numberOfPartition = substitutionSelection(arq, "substitutionSelectionPartition");

                fclose(arq);

                exit(0);
            } else {
                int numberOfPartition = 0;
                numberOfPartition = naturalSelection(arq, "naturalSelectionPartition");

                fclose(arq);

                exit(0);
            }

            free(emp);
            fclose(arq);

        } else {
            printf("Err file.\n");
            return 1;
        }
    }

    return 0;
}



#include "../Employee/employee.h"

void procedimento_File_If_Not_Null(void){
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
        }
}

#include "../Employee/employee.h"
void encontraArquivo(){
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
        }
}

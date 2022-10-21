
#include "../Employee/employee.h"
#include "../Hash/CreateDataBase.h"
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

            printf("\n3 - Substitution Selection;\n 4 - Natural Selection.\n 5 - Hash Table\n --->  ");
            scanf("%i", &sortingMethod);


            if (sortingMethod == 3){

                int numberOfPartition = 0;
                numberOfPartition = substitutionSelection(arq, "substitutionSelectionPartition");

                fclose(arq);

                exit(0);
            } else if(sortingMethod == 4) {
                int numberOfPartition = 0;
                numberOfPartition = naturalSelection(arq, "naturalSelectionPartition");

                fclose(arq);

                exit(0);
            }else if (sortingMethod == 5){
                int numberOfPartition;
                char partitionName[100];
                char str1[100];
                char str2[100] = ".dat";

                printf("\nInsert number of partition for Hash Table (Hash Function): ");
                scanf("%i", &numberOfPartition);

                makePartitionHashTable(numberOfPartition);
                hashTable(arq, numberOfPartition, numFunc);

                printf("Hash Table Successfully Created");

                int pickAux = 0;

                 while (pickAux != 5) {

                    printf("\n\nInput an option: \n 1 - Insert Employee; \n 2 - Search Employee; \n 3 - Delete Employee; \n 4 - Print Employee IDs; \n 5 - Close program. \n ----> ");
                    scanf("%i", &pickAux);


                    if (pickAux == 1) {
                        int employeeID;
                        int partitionID;

                        printf("\nInput employee ID: ");
                        scanf("%i", &employeeID);

                        TEmp funcHashIsert;

                        if (employeeID < 0)
                        {
                            printf("\nErr: ID < 0");
                            break;
                        }

                        funcHashIsert.id = employeeID;

                        char auxName[15];
                        for (int j = 0; j < 15; j++)
                        {
                            auxName[j] = 'a' + (char)(rand() % 26);
                        }

                        sprintf(funcHashIsert.name, "%s", auxName);
                        sprintf(funcHashIsert.cpf, "111.111.111-11");
                        sprintf(funcHashIsert.birthDate, "01/08/2021");
                        funcHashIsert.pay = 1000 + rand() % 10000;

                        partitionID = employeeID % numberOfPartition;

                        insertHashTable(&funcHashIsert, employeeID, partitionID);


                    } else if (pickAux == 2) {

                        int employeeID;
                        int partitionID;

                        printf("\nInput employee id: ");
                        scanf("%i", &employeeID);

                        partitionID = employeeID % numberOfPartition;

                        TEmp *funcSearchHashTable = searchHashTable(employeeID, partitionID);

                        if (funcSearchHashTable != NULL) {
                            printEmployee(funcSearchHashTable);
                        } else {
                            printf("\nEmployee id not found");
                        }

                    } else if (pickAux == 3) {

                        int employeeID;
                        int partitionID;

                        printf("\nInput employee id: ");
                        scanf("%i", &employeeID);

                        partitionID = employeeID % numberOfPartition;

                        deleteHashTable(employeeID, partitionID);

                    } else if (pickAux == 4) {

                        for (int i = 0; i < numberOfPartition; ++i) {

                            itoa(i, str1, 10);
                            strcat(strcpy(partitionName, "hashTablePartition"), str1);
                            strcat(strcpy(partitionName, partitionName), str2);

                            FILE *filePartition = fopen(partitionName,"rb+");

                            printPartitionEmployeeID(filePartition, partitionName);

                            fclose(filePartition);
                        }

                    } else {
                        printf("Closing...");
                    }


                }
                fclose(arq);
                return 0;
            }

            free(emp);
            free(vet);
            fclose(arq);

        }
        else {
            printf("Err file.\n");
        }
}

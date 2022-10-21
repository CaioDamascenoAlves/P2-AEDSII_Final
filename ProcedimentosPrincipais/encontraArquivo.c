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

            printf("3 - Substitution Selection\n 4 - Natural Selection.\n 5 - Hash Table.\n --->  ");
            scanf("%i", &sortingMethod);

           if (sortingMethod == 3){
                int numberOfPartition = 0;
                numberOfPartition = substitutionSelection(arq, "substitutionSelectionPartition");

                fclose(arq);

                exit(0);
            } else if(sortingMethod == 4){
                int numberOfPartition = 0;
                numberOfPartition = naturalSelection(arq, "naturalSelectionPartition");

                fclose(arq);

                exit(0);
            }

            free(emp);
            fclose(arq);

        } else {

                int numberOfPartition;
                int contSizeFile = 0;
                contSizeFile = tamArq(arq, contSizeFile);
                char partitionName[100];
                char str1[100];
                char str2[100] = ".dat";

                printf("\nInsert number of partition for Hash Table (Hash Function): ");
                scanf("%i", &numberOfPartition);

                makePartitionHashTable(numberOfPartition);
                hashTable(arq, numberOfPartition, contSizeFile);

                printf("Hash Table Successfully Created");

                int pickAux = 0;



                    printf("\n\nInput an option: \n 1 - Insert Employee; \n 2 - Search Employee; \n 3 - Delete Employee; \n 4 - Print employee IDs; \n 5 - Close program. \n ----> ");
                    fflush(stdin);
                    scanf("%i", &pickAux);
                while (pickAux != 5) {
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

}

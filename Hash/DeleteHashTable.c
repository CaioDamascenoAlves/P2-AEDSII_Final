#include "../Employee/employee.h"
void deleteHashTable(int employerID, int partitionID) {

    char partitionName[100];
    char str1[100];
    char str2[100] = ".dat";
    int totalCompararisons = 0;

    itoa(partitionID, str1, 10);
    strcat(strcpy(partitionName, "hashTablePartition"), str1);
    strcat(strcpy(partitionName, partitionName), str2);

    FILE *filePartition = fopen(partitionName,"r+b");

    TEmp *auxFunc = sequentialFetch(employerID, filePartition, &totalCompararisons);

    if (auxFunc != NULL) {

        fseek(filePartition, (totalCompararisons - 1) * sizeof(TEmp), SEEK_SET);

        TEmp funcHashDelet;

        funcHashDelet.id = 999999999;
        sprintf(funcHashDelet.name, "%s", auxFunc->name);
        sprintf(funcHashDelet.cpf, "%s", auxFunc->cpf);
        sprintf(funcHashDelet.birthDate, "%s", auxFunc->birthDate);
        funcHashDelet.pay = auxFunc->pay;

        salvaRegistro(&funcHashDelet, filePartition);

        printf("\nEmployee deleted successfully.");
    } else {
        printf("\nEmployee id not exist in the Hash Table.");
    }

    fclose(filePartition);
}

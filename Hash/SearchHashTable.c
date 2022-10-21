#include "../Employee/employee.h"

TEmp *searchHashTable(int employerID, int partitionID) {

    char partitionName[100];
    char str1[100];
    char str2[100] = ".dat";
    int totalCompararisons;

    itoa(partitionID, str1, 10);
    strcat(strcpy(partitionName, "hashTablePartition"), str1);
    strcat(strcpy(partitionName, partitionName), str2);

    printf("\nSearching in %s...", partitionName);

    FILE *filePartition = fopen(partitionName,"rb+");

    TEmp *auxFunc = sequentialFetch(employerID, filePartition, &totalCompararisons);

    fclose(filePartition);

    return auxFunc;
}

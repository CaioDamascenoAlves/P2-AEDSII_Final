#include "../Employee/employee.h"

void insertHashTable(TEmp *funcHashTableInsert,int employerID, int partitionID) {

    char partitionName[100];
    char str1[100];
    char str2[100] = ".dat";
    int totalCompararisons = 0;
    int totalCompararisonsDeleted = 0;
    int sizefilePartition = 0;

    itoa(partitionID, str1, 10);
    strcat(strcpy(partitionName, "hashTablePartition"), str1);
    strcat(strcpy(partitionName, partitionName), str2);

    FILE *filePartition = fopen(partitionName,"r+b");

    sizefilePartition = tamArq(filePartition, 0);
    rewind(filePartition);

    TEmp *auxFunc = sequentialFetch(funcHashTableInsert->id, filePartition, &totalCompararisons);
    rewind(filePartition);

    TEmp *auxFuncDeleted = sequentialFetch(999999999, filePartition, &totalCompararisonsDeleted);
    rewind(filePartition);

    if (auxFunc == NULL && auxFuncDeleted == NULL) {
        fseek(filePartition, (sizefilePartition) * sizeof(TEmp), SEEK_SET);\
        salvaRegistro(funcHashTableInsert, filePartition);
        printf("\nEmployee entered successfully at the end.");
    } else if (auxFunc == NULL && auxFuncDeleted != NULL){
        fseek(filePartition, (totalCompararisonsDeleted - 1) * sizeof(TEmp), SEEK_SET);\
        salvaRegistro(funcHashTableInsert, filePartition);
        printf("\nEmployee entered successfully at employee previous deleted.");
    } else {
        printf("\nEmployee id already exist in the Hash Table.");

    }

    fclose(filePartition);
}

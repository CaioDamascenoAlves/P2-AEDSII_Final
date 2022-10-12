#include "../Employee/employee.h"
#include "leRegEmployee.h"
#include "tamArq.h"
void printPartitionEmployeeID(FILE *file, char partitionName[]) {

    printf("\nIDs employee of partition %s: \n --->  ", partitionName);

    for (int i = 0; i < tamArq(file, 0); ++i) {

        fseek(file, i * sizeof(TEmp), SEEK_SET) ;
        TEmp *aux = leReg(file);

        printf(" %i ", aux->id);
    }

    printf("\n");
}

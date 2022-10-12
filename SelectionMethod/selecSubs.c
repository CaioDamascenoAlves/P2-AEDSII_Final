#include "../Employee/employee.h"
#include "../FuncAux/tamArq.h"
#include "../FuncAux/leRegEmployee.h"
#include "../FuncAux/salvaRegistro.h"
#include "../FuncAux/reservatorio.h"
int substitutionSelection (FILE *file, char nameFilePartition[]) {

    int numberOfPartition = 0, contSizeFile = 0, position = 6, smallElementPosition = 0, smallElement = 999999, sizeFileemp = 0, selectedPosition = 0;
    struct Employee func[6];
    int empVeTEmp [6] = {0, 0, 0, 0, 0, 0};

    rewind(file);

    sizeFileemp = tamArq(file, contSizeFile);


    printf("\nPerforming substitution selection...");

    for (int i = 0; i < 6; ++i) {
        fseek(file, i * sizeof(TEmp), SEEK_SET);

        TEmp *emp = leReg(file);
        func[i] = *emp;

    }

    for (int i = 0; i < 6; ++i) {
        empVeTEmp[i] = func[i].id;
    }

    while (position != sizeFileemp) {

        char partitionName[100];
        char str1[100];
        char str2[100] = ".dat";

        itoa(numberOfPartition, str1, 10);
        strcat(strcpy(partitionName, nameFilePartition), str1);
        strcat(strcpy(partitionName, partitionName), str2);

        FILE *filePartition = fopen(partitionName, "wb+");

        int empVetFrozen[6] = {0, 0, 0, 0, 0, 0,};

        while (position != sizeFileemp) {

            smallElement = 9999999;

            for (int i = 0; i < 6; ++i) {

                if (smallElement > empVeTEmp[i] && empVetFrozen[i] != 1) {
                    smallElement = empVeTEmp[i];
                    smallElementPosition = i;
                }
            }

            salvaRegistro(&func[smallElementPosition], filePartition);

            fseek(file, position * sizeof(TEmp), SEEK_SET);

            TEmp *emp = leReg(file);

            position++;

            empVeTEmp[smallElementPosition] = emp->id;
            func[smallElementPosition] = *emp;

            if (emp->id < smallElement) {
                empVetFrozen[smallElementPosition] = 1;
            }

            if(reservatorioVet(empVetFrozen) == 1) {
                numberOfPartition++;
                break;
            }

        }

        fclose(filePartition);

        if (position >= sizeFileemp) {
            break;
        }

    }

    char partitionName[100];
    char str1[100];
    char str2[100] = ".dat";

    itoa(numberOfPartition, str1, 10);
    strcat(strcpy(partitionName, nameFilePartition), str1);
    strcat(strcpy(partitionName, partitionName), str2);

    FILE *filePartitionFinal = fopen(partitionName, "ab+");

    int k, j;

    struct Employee funcemp;

    for (k = 1; k < 6; k++) {

        for (j = 0; j < 6 - 1; j++) {

            if (func[j].id > func[j + 1].id) {
                funcemp = func[j];
                func[j] = func[j + 1];
                func[j + 1] = funcemp;
            }
        }
    }

    for (int i = 0; i < 6; ++i) {
        salvaRegistro(&func[i], filePartitionFinal);
    }

    fclose(filePartitionFinal);

    for (int i = 0; i <= numberOfPartition; ++i) {


        itoa(i, str1, 10);
        strcat(strcpy(partitionName, nameFilePartition), str1);
        strcat(strcpy(partitionName, partitionName), str2);

        FILE *filePartition = fopen(partitionName, "rb+");

        printPartitionEmployeeID(filePartition, partitionName);

        fclose(filePartition);
    }

    return numberOfPartition;

}

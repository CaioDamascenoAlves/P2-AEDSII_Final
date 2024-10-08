#include "../Employee/employee.h"
#include "../FuncAux/leRegEmployee.h"
#include "../FuncAux/salvaRegistro.h"
#include "../FuncAux/tamArq.h"

int naturalSelection(FILE *file, char nameFilePartition[]) {

    int  sizeFileAux = tamArq(file, 0), position = 0, numberOfPartition = 0, smallElement = 999999999, smallElementPosition = 0, sizeReservoir = 0, flag = 0;

    struct Employee func[6];

    int empVet[6] = {0, 0, 0, 0, 0, 0};

    rewind(file);

    printf("\nPerforming substitution selection...");

    while (!feof(file)) {

        FILE *fileReservoir = fopen("reservoir.dat", "wb+");

        char partitionName[100];
        char str1[100];
        char str2[100] = ".dat";

        itoa(numberOfPartition, str1, 10);
        strcat(strcpy(partitionName, nameFilePartition), str1);
        strcat(strcpy(partitionName, partitionName), str2);

        FILE *filePartition = fopen(partitionName, "wb+");

        if (flag == 0) {
            for (int i = 0; i < 6; ++i) {

                TEmp *emp = leReg(file);
                position++;

                func[i] = *emp;
                empVet[i] = emp->id;
            }
        }

        while (!feof(file)) {

            for (int i = 0; i < 6; ++i) {

                if (empVet[i] < smallElement) {
                    smallElement = empVet[i];
                    smallElementPosition = i;
                }
            }

            TEmp *emp = leReg(file);
            position++;


            if (emp->id < func[smallElementPosition].id) {
                salvaRegistro(emp, fileReservoir);
                sizeReservoir++;

                if (sizeReservoir == 6) {

                    break;
                }

            } else {
                salvaRegistro(&func[smallElementPosition], filePartition);
                empVet[smallElementPosition] = emp->id;
                func[smallElementPosition] = *emp;
            }

            smallElement = 999999999;

            if (position >= sizeFileAux) {
                break;
            }

        }

        struct Employee aux;

        int k, j;

        for (k = 1; k < 6; k++) {

            for (j = 0; j < 6 - 1; j++) {

                if (func[j].id > func[j + 1].id) {
                    aux = func[j];
                    func[j] = func[j + 1];
                    func[j + 1] = aux;
                }
            }
        }

        for (int i = 0; i < 6; ++i) {
            salvaRegistro(&func[i], filePartition);
        }

        rewind(fileReservoir);

        for (int i = 0; i < sizeReservoir; ++i) {
            TEmp *empReservoir = leReg(fileReservoir);
            func[i] = *empReservoir;
            empVet[i] = empReservoir->id;
            flag = 1;
        }


        fclose(fileReservoir);
        fclose(filePartition);

        if (position >= sizeFileAux) {
            break;
        }

        sizeReservoir = 0;
        numberOfPartition++;

    }

    for (int i = 0; i <= numberOfPartition; ++i) {

        char partitionName[100];
        char str1[100];
        char str2[100] = ".dat";

        itoa(i, str1, 10);
        strcat(strcpy(partitionName, nameFilePartition), str1);
        strcat(strcpy(partitionName, partitionName), str2);

        FILE *filePartition = fopen(partitionName, "rb+");

        printPartitionEmployeeID(filePartition, partitionName);

        fclose(filePartition);
    }

    return numberOfPartition;
}

#include <stdio.h>
#include "../Employee/employee.h"
#include "tamArq.h"
void printAllEmployeeFile(FILE *file) {

    rewind(file);

    for (int i = 0; i < tamArq(file, 0); ++i) {

        fseek(file, i * sizeof(TEmp), SEEK_SET);
        TEmp *emp = leReg(file);
        printEmployee(emp);
    }

}

void printEmployee (TEmp *emp) {
    printf("\nRegister found: \n");
    printf("ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("CPF: %s\n", emp->cpf);
    printf("Birth of Date: %s\n", emp->birthDate);
    printf("Payment: %.2f\n", emp->pay);
}

#include <stdio.h>
#include "../Employee/employee.h"

TEmp *leReg(FILE *in) {
    TEmp *emp = (TEmp*) malloc (sizeof(TEmp));

    if ( 0 >= fread(&emp->id, sizeof(int), 1, in)) {
        free(emp);
        return NULL;
    }

    fread(emp->name, sizeof(char), sizeof(emp->name), in);
    fread(emp->cpf, sizeof(char), sizeof(emp->cpf), in);
    fread(emp->birthDate, sizeof(char), sizeof(emp->birthDate), in);
    fread(&emp->pay, sizeof(double), 1, in);

    return emp;
}

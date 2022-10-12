#include <stdio.h>
#include "../Employee/employee.h"
void salvaRegistro(TEmp *emp, FILE *out) {
    fwrite(&emp->id, sizeof(int), 1, out);
    fwrite(emp->name, sizeof(char), sizeof(emp->name), out);
    fwrite(emp->cpf, sizeof(char), sizeof(emp->cpf), out);
    fwrite(emp->birthDate, sizeof(char), sizeof(emp->birthDate), out);
    fwrite(&emp->pay, sizeof(double), 1, out);
}

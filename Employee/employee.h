#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <stdio.h>

typedef struct Employee {
    int id;
    char name[50];
    char cpf[15];
    char birthDate[11];
    double pay;
} TEmp;



#endif // EMPLOYEE_H_INCLUDED

#include "../Employee/employee.h"
void createDataBase(FILE *arq, int nemp, int *vet) {
    for(int i = 1; i <= nemp; i++) {

        printf("Creating random employee %i..\n", i);
        TEmp emp;

        emp.id = vet[i - 1];

        char auxName[15];
        for(int j = 0; j < 15; j++) {
            auxName[j]= 'a' + (char)(rand()%26);
        }

        sprintf(emp.name, "%s", auxName);
        sprintf(emp.cpf, "111.111.111-11");
        sprintf(emp.birthDate, "01/08/2021");
        emp.pay = 1000 + rand() % 10000;
        fseek(arq, (i-1)* sizeof(TEmp), SEEK_SET);
        salvaRegistro(&emp, arq);
    }
}

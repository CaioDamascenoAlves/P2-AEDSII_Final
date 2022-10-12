#include "../Employee/employee.h"
#include "../FuncAux/leRegEmployee.h"
TEmp *sequentialFetch(int id, FILE *arq) {
    int position = 0;

    while (!feof(arq)) {

        fseek(arq, position * sizeof(TEmp), SEEK_SET) ;
        TEmp *emp = leReg(arq);

        position++;

        if (emp == NULL) {
            return NULL;
        } else if(id == emp->id) {
            return emp;
        }
    }

    return NULL;
}

#include "../Employee/employee.h"
#include "../FuncAux/leRegEmployee.h"
TEmp *buscaBinaria(int id, FILE *file, int sizeFile) {

    int left = 0, right = sizeFile - 1;

    rewind(file);

    while (left <= right) {
        int middle = (left+right) / 2;
        fseek(file, middle * sizeof(TEmp), SEEK_SET);
        TEmp *func = leReg(file);

        if (id == func -> id) {

            return func;
        } else if (func->id < id) {
            left = middle+1;
        } else {
            right = middle-1;
        }
    }
    return NULL;
}

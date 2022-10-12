#include "../Employee/employee.h"

int tamArq (FILE *file, int contSizeFile) {

    int bytesAUX = 0;

    while(!feof(file)) {

        fseek(file, bytesAUX * sizeof(TEmp), SEEK_SET);

        TEmp *aux = leReg(file);
        if(aux != NULL) {
            contSizeFile++;
        }

        bytesAUX++;
    }

    return contSizeFile;
}

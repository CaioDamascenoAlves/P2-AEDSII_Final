#include "reservatorio.h"

int reservatorioVet (int vet[6]) {

    int cont = 0;

    for (int i = 0; i < 6; ++i) {
        if (vet[i] == 1) {
            cont++;
        }
    }

    if (cont == 6) {
        return 1;
    } else {
        return 0;
    }
}

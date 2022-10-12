void embaralhaVet(int *vet, int vetSize)
{

    for (int i = 0; i < vetSize; i++) {
        vet[i] = i + 1;
    }

    for (int i = 0; i < vetSize; i++)
    {
        int r = rand() % vetSize;

        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }

}

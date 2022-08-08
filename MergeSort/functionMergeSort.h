// Funções do mergeSort
#include <stdio.h>
#include <stdlib.h>
void mergesort(int *vetor, int tamanho)
{
    int *aux = (int *)malloc(sizeof(int) * tamanho);
    sort(vetor, aux, 0, tamanho - 1);

    free(aux);
}

void sort(int *vetor, int *aux, int inicio, int fim)
{
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;
    // entradas separadas até inicio >=fim
    sort(vetor, aux, inicio, meio);
    sort(vetor, aux, meio + 1, fim);

    if (vetor[meio] <= vetor[meio + 1])
        return;

    interloca(vetor, aux, inicio, meio, fim);
}

void interloca(int *vetor, int *aux, int inicio, int meio, int fim)
{
    int i,
        iv = inicio,
        im = meio + 1;
    // printando movimento do sort
    printf("|");
    for (i = 0; i < 8; i++)
        printf("%d ", vetor[i]);

    printf("|\n");
    for (i = inicio; i <= fim; i++)
        aux[i] = vetor[i];

    i = inicio;

    while (iv <= meio && im <= fim)
    {

        if (aux[iv] <= aux[im])
            vetor[i++] = aux[iv++];
        else
            vetor[i++] = aux[im++];
    }

    while (iv <= meio)
        vetor[i++] = aux[iv++];

    while (im <= fim)
        vetor[i++] = aux[im++];
}

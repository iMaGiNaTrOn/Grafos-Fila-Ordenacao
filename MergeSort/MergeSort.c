// executar: make run
#include <stdio.h>
#include <stdlib.h>
#include "functionMergeSort.h"

int main()
{
  int i;
  int vetor[8];

  for (i = 0; i < 8; i++)
  {
    printf("[%d]: ", i);
    scanf("%d", &vetor[i]);
  }

  printf("\n");
  mergesort(vetor, 8);

  printf("Vetor Ordenado: [");
  for (i = 0; i < 8; i++)
    if (i == 7)
    {
      printf("%d", vetor[i]);
    }
    else
    {
      printf("%d, ", vetor[i]);
    }
  printf("]\n");
  return 0;
}

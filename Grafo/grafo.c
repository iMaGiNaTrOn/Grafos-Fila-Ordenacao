// Executar: make run
#include <stdio.h>
#include <stdlib.h>
#include "funcoes-grafo.h"

// Função principal
int main()
{
    // Cria um grafo
    int V = 5;
    Grafo *grafo = createGrafo(V);
    addEdge(grafo, 0, 1);
    addEdge(grafo, 0, 4);
    addEdge(grafo, 1, 2);
    addEdge(grafo, 1, 3);
    addEdge(grafo, 1, 4);
    addEdge(grafo, 2, 3);
    addEdge(grafo, 3, 4);

    printf("Grafo\n");
    // printa o grafo
    printGrafo(grafo);

    printf("\nChecagem de existência de arestas\n");
    checkEdge(0, 1, grafo);
    checkEdge(0, 3, grafo);
    checkEdge(5, 1, grafo);

    printf("\nRemovendo aresta de um grafo\n");
    printf("No nodo 1, valor 3 deve ser removido");
    removeEdge(1, 3, grafo);

    printf("\nGrafo atualizado\n");
    printGrafo(grafo);

    printf("\nRemovendo todo o grafo\n");
    removeGraph(grafo);

    printGrafo(grafo);

    return 0;
}

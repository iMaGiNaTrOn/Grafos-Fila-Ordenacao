#include <stdio.h>
#include <stdlib.h>

// Nodo de uma lista de adjacência
typedef struct Node
{
    int dest;
    struct Node *next;
} Node;

// Estrutura de uma lista de adjacência
typedef struct AdjList
{
    Node *head;
} AdjList;

// Grafo como uma lista
typedef struct Grafo
{
    int V;
    AdjList *array;
} Grafo;

// Função para criar uma nova lista de adjacência
Node *newAdjListNode(int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função que cria grafo com V vertices
Grafo *createGrafo(int V)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->V = V;

    // Cria um array de listas de adjacência
    grafo->array = (AdjList *)malloc(V * sizeof(AdjList));

    // Inicializa cada lista com a head nula
    int i;
    for (i = 0; i < V; ++i)
        grafo->array[i].head = NULL;

    return grafo;
}

// Adiciona uma aresta
void addEdge(Grafo *grafo, int src, int dest)
{
    // Adiciona um vertice na lista
    Node *check = NULL;
    Node *newNode = newAdjListNode(dest);

    if (grafo->array[src].head == NULL)
    {
        newNode->next = grafo->array[src].head;
        grafo->array[src].head = newNode;
    }
    else
    {

        check = grafo->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }

        check->next = newNode;
    }

    // Como o grafo é não-direcionado, adiciona o nodo de src em dest tbm
    newNode = newAdjListNode(src);
    if (grafo->array[dest].head == NULL)
    {
        newNode->next = grafo->array[dest].head;
        grafo->array[dest].head = newNode;
    }
    else
    {
        check = grafo->array[dest].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
}

void checkEdge(int v1, int v2, Grafo *graph)
{
    // indice de erro
    int erro = 0;
    Node *check;
    // verifica se o nodo requisitado existe dentro do grafo
    if (v1 >= graph->V)
    {
        printf("valor esta fora do alcance do grafo\n");
        erro = 1;
        // se ele existir, check recebe o ponteiro do valor q ele referencia
    }
    else
    {
        check = graph->array[v1].head;
    }

    // aqui, se ele nn houve erro, ele vai checar a aresta
    if (erro == 0)
    {
        while (check)
        { // enquanto check for diferente de NULL, procura no nodo seguinte
            if (check->dest != v2)
            {
                check = check->next;
            }
            else
            {
                printf("Aresta esta presente\n");
                break;
            }
        }
        // se chegou aqui, com certeza check == NULL, então aresta nn estava presente
        if (check == NULL)
            printf("Aresta nao esta presente\n");
    }
}

void removeEdge(int v1, int v2, Grafo *grafo)
{
    Node *node;
    Node *aux;

    // checa se v1 está dentro do escopo de tamanho de grafo
    if (v1 >= grafo->V)
    {
        printf("Valor de v1 está fora do alcance do grafo\n");
        // checa se v2 está dentro do escopo do tamanho de grafo
    }
    else if (v2 >= grafo->V)
    {
        printf("Valor de v2 está fora do alcance do grafo\n");
    }
    else
    {
        // ambos v1 e v2 estão dentro do escopo, então começa a checar se tem
        node = grafo->array[v1].head; // node recebe o valor da cabeça
        while (node)
        {
            if (node->dest == v2)
            { // checa se valor de destino de nodo é v2
                // se for, remove ele do nodo
                aux->next = node->next;
                free(node);
                printf("Aresta v1:v2 removida\n");
                break;
            }
            else if (node->next == NULL)
            {                                                // senão, ele checa se o proximo ponteiro é nulo
                printf("Nao existe aresta entre v1 e v2\n"); // se for, o v2 nn estava feito no grafo
                break;
            }
            aux = node;
            node = node->next;
        }
    }
}

// remove todo o grafo
void removeGraph(Grafo *grafo)
{
    // Vtotal é a qtd de vertices total
    int Vtotal = (grafo->V) - 1;
    // enquanto Vtotal é um valor dentro do tamanho, ele faz um laço for
    for (Vtotal; Vtotal > -1; Vtotal--)
    {
        Node *nodo;
        Node *aux;
        // enquanto a cabeça da lista no indice de Vtotal for diferente de nulo
        // ele vai fazendo limpeza de cada vertice do grafo
        while (grafo->array[Vtotal].head != NULL)
        {
            nodo = grafo->array[Vtotal].head;

            // condição de parada pra quando ele atinge o ultimo nodo, na cabeça no indice Vtotal
            if (nodo->next == NULL)
            {
                free(nodo);
                break;
            }

            // varrendo todo o array no indice de Vtotal
            while (nodo)
            {
                // condição de limpeza de aresta
                if (nodo->next == NULL)
                {
                    aux->next = NULL;
                    free(nodo);
                    break;
                }
                aux = nodo;
                nodo = nodo->next;
            }
        }
    }
    // libera espaço do grafo
    free(grafo);
    printf("Grafo removido com sucesso!\n");
}

// Printa grafo
void printGrafo(Grafo *graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        Node *pCrawl = graph->array[v].head;
        printf("\n Lista de Adjacência do Nodo %d\n Inicio ", v);
        while (pCrawl)
        {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
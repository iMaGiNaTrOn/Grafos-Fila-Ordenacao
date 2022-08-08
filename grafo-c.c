#include <stdio.h>
#include <stdlib.h>
 
// Nodo de uma lista de adjacência
typedef struct Node {
    int dest;
    struct Node* next;
}Node;
 
// Estrutura de uma lista de adjacência
typedef struct AdjList {
    Node* head;
}AdjList;
 
// Grafo como uma lista
typedef struct Grafo {
    int V;
    AdjList* array;
}Grafo;
 
// Função para criar uma nova lista de adjacência
Node* newAdjListNode(int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// Função que cria grafo com V vertices
Grafo* createGrafo(int V)
{
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;
 
    // Cria um array de listas de adjacência
    grafo->array = (AdjList*)malloc(V * sizeof(AdjList));
 
    // Inicializa cada lista com a head nula
    int i;
    for (i = 0; i < V; ++i)
        grafo->array[i].head = NULL;
 
    return grafo;
}
 
// Adiciona uma aresta
void addEdge(Grafo* grafo, int src, int dest)
{
    // Adiciona um vertice na lista 
    Node* check = NULL;
    Node* newNode = newAdjListNode(dest);
 
    if (grafo->array[src].head == NULL) {
        newNode->next = grafo->array[src].head;
        grafo->array[src].head = newNode;
    }
    else {
 
        check = grafo->array[src].head;
        while (check->next != NULL) {
            check = check->next;
        }

        check->next = newNode;
    }
 
    // Como o grafo é não-direcionado, adiciona o nodo de src em dest tbm
    newNode = newAdjListNode(src);
    if (grafo->array[dest].head == NULL) {
        newNode->next = grafo->array[dest].head;
        grafo->array[dest].head = newNode;
    }
    else {
        check = grafo->array[dest].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }
}

void checkEdge(int v1, int v2, Grafo* graph)
{
    //indice de erro
    int erro = 0;
    Node* check;
    //verifica se o nodo requisitado existe dentro do grafo
    if(v1 >= graph->V){
        printf("valor esta fora do alcance do grafo\n");
        erro = 1;
    //se ele existir, check recebe o ponteiro do valor q ele referencia
    } else {
        check = graph->array[v1].head;
    }

    if(erro == 0) {
        while (check) {
            if(check->dest != v2) {
                check = check->next;
            } else {
                printf("Aresta esta presente\n");
                break;
            }
        }
        if (check == NULL)
            printf("Aresta nao esta presente\n");
    }
}

void removeEdge(int v1, int v2, Grafo* grafo)
{
    Node* node;
    Node* aux;
    
    //checa se v1 está dentro do escopo de tamanho de grafo
    if(v1 >= grafo->V) {
        printf("Valor de v1 está fora do alcance do grafo\n");
    //checa se v2 está dentro do escopo do tamanho de grafo
    } else if (v2 >= grafo->V) {
        printf("Valor de v2 está fora do alcance do grafo\n");
    } else {
        //ambos v1 e v2 estão dentro do escopo, então começa a checar se tem 
        int i = 0;
        node = grafo->array[v1].head;
        while(node) {
            if (node->dest == v2) {
                aux->next = node->next;
                free(node);
                printf("Aresta v1:v2 removida\n");
                break;
            } else if (node->next == NULL) {
                printf("Nao existe aresta entre v1 e v2\n");
                break;
            }
            i++;
            aux = node;
            node = node->next;
        }
    }
}

void removeGraph(Grafo* grafo) {
    int Vtotal = (grafo->V) - 1;
    for(Vtotal; Vtotal > -1; Vtotal--) {
        Node* nodo;
        Node* aux;
        nodo = grafo->array[Vtotal].head;
        printf("%d\n", nodo->dest);
        while (nodo) {
            printf("%d ", nodo->dest);
            if (nodo->next == NULL){
                printf("NÃO CONSIGO IR PRA FRENTE!!\n");
                aux->next = NULL;
                free(nodo);
                break;
            }
            aux = nodo;
            nodo = nodo->next;
        }
        
    }
}
 
// Printa grafo
void printGrafo(Grafo* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v) {
        Node* pCrawl = graph->array[v].head;
        printf("\n Lista de Adjacência do Nodo %d\n Inicio ", v);
        while (pCrawl) {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
// Função principal
int main()
{
    // Cria um grafo
    int V = 5;
    Grafo* grafo = createGrafo(V);
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

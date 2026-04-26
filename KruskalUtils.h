#include "Nodo.h"

void sort_edges(Graph* graph);

void kruskal(Graph* graph, Graph* resultado, int* costoTotal, List* sin_visitar, List* visitados);

Node* encontrar_padre(Node* nodo);

void destroyGraph(Graph* graph);

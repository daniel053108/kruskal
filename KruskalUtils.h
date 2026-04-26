#include "Nodo.h"



void initNodeList(NodeList* nodeList, char* name);
void pushNodeList(NodeList* nodeList, Node* node);
int isDuplicated(NodeList _nodeList, Node* _node);
void printNodeList(NodeList _nodeList);
void sort_edges(Graph* graph);

void kruskal(Graph* graph,Graph* resultado,int* costoTotal,int cantidaNodos);
Node* encontrar_padre(Node* nodo);
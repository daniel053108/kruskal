#include "Nodo.h"

typedef struct _nodeList{
    Node** nodes;
    char* name;
    int cant_nodes;
    int max_nodes;
}NodeList;

NodeList sin_visitar;

NodeList visitados;

void initNodeList(NodeList* nodeList, char* name);
void pushNodeList(NodeList* nodeList, Node* node);
int isDuplicated(NodeList _nodeList, Node* _node);
void printNodeList(NodeList _nodeList);


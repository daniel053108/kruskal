#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    char* name;
    
    /// referencia al anterior
    struct _node* padre;

}Node;

typedef struct _path{
    int weigth;
    Node* origin;
    Node* destination;
}Path;

typedef struct _graph{
    Path** path_list;
    int cant_edges;
    int max_edges;
    

}Graph;

typedef struct _nodeList{
    Node** nodes;
    char* name;
    int cant_nodes;
    int max_nodes;
}NodeList;








void init_graph(Graph* graph);

void addEdge(char* name_origin, int weigth, char* name_destination, Graph* graph, NodeList* sin_visitar);

void pushEdge(Graph* graph, Path* path);

void printGraph(Graph graph);

void printAEM(Graph graph, int costo);

Node* existeNodo(char* nombre, NodeList* lista);
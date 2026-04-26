#include "List.h"

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
    List path_list;
}Graph;


void sort_edges(Graph* graph);

void init_graph(Graph* graph);

void addEdge(char* name_origin, int weigth, char* name_destination, Graph* graph, List* sin_visitar);

void pushEdge(Graph* graph, Path* path);

void printGraph(Graph graph);

void printPath(Path path);

void printNodeList(List list);

void printNodo(Node node);

Node* existeNodo(char* nombre, List* lista);

void printAEM(Graph graph, int costo);

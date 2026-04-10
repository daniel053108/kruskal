#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char* name;
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

void init_graph(Graph* graph);

void addEdge(char* name_origin, int weigth, char* name_destination, Graph* graph);

void pushEdge(Graph* graph, Path* path);

void printGraph(Graph graph);
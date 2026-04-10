#include <stdlib.h>

typedef struct _node{
    char* name;
}Node;

typedef struct _path{
    int weigth;
    Node* origin;
    Node* destination;
}path;

typedef struct _graph{
    path** path_list;
    int cant_edges;
}graph;

void init_graph(graph* graph);

void addEdge(char* name_origin, int weigth, char* name_destination, graph* graph);

void pushEdge(graph* graph, path* path);

void printGraph(graph graph);
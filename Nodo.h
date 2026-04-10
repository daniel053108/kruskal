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
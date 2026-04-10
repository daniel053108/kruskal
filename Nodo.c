#include "Nodo.h"

void init_graph(graph* graph){
    graph->path_list = (path*)malloc(sizeof(path));
    graph->cant_edges = -1;
}

void pushEdge(graph* graph, path* path){
    graph->cant_edges++;
    graph->path_list[graph->cant_edges] = path; 
}

void addEdge(char* name_origin, int weigth, char* name_destination, graph* graph){
    Node* origin = (Node*)malloc(sizeof(Node));
    origin->name = name_origin;

    Node* destination = (Node*)malloc(sizeof(Node));
    destination->name = name_destination;

    path* newPath = (path*)malloc(sizeof(path));

    newPath->origin = origin;
    newPath->destination = destination;
    newPath->weigth = weigth;

}
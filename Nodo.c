#include "KruskalUtils.h"

void init_graph(Graph* graph){
    graph->cant_edges = 0;
    graph->max_edges = 10;
    graph->path_list = (Path**)malloc(graph->max_edges*sizeof(Path*));
}

void pushEdge(Graph* graph, Path* path){
    if((graph->cant_edges + 1) == graph->max_edges){
        graph->max_edges += 10;
        graph->path_list = (Path**)realloc(graph->path_list, graph->max_edges * sizeof(Path*));
    }
    graph->path_list[graph->cant_edges] = path; 
    graph->cant_edges++;
}

void addEdge(char* name_origin, int weigth, char* name_destination, Graph* graph){
    Node* origin = (Node*)malloc(sizeof(Node));
    origin->name = name_origin;

    Node* destination = (Node*)malloc(sizeof(Node));
    destination->name = name_destination;

    Path* newPath = (Path*)malloc(sizeof(Path));

    if(!isDuplicated(sin_visitar, origin)){
        pushNodeList(&sin_visitar, origin);
    }

    if(!isDuplicated(sin_visitar, destination)){
        pushNodeList(&sin_visitar, destination);
    }

    
    newPath->origin = origin;
    newPath->destination = destination;
    newPath->weigth = weigth;

    pushEdge(graph, newPath);
}

void printGraph(Graph graph){
    printf("cantidad de caminos: %d\n", graph.cant_edges);

    printf("|CAMINOS|\n");
    printf("|ORIGEN|PESO|DESTINO\n");
    for(int i = 0; i <= graph.cant_edges - 1; i++){
        Path* path = graph.path_list[i];
        printf("|%s|%d|%s|\n",path->origin->name, path->weigth, path->destination->name);  
    }
}
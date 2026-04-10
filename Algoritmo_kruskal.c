#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

int main(void){
    
    graph graph;

    init_graph(&graph);

    addEdge("1", 100, "2", &graph);
    addEdge("1", 200, "3", &graph);
    addEdge("2", 400, "3", &graph);

    printGraph(graph);
    
    return 0;
}


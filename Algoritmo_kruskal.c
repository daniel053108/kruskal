#include <stdio.h>
#include <stdlib.h>
#include "KruskalUtils.h"

int main(void){
    
    Graph graph;
    initNodeList(&sin_visitar, "Nodos Sin Visitar");
    initNodeList(&visitados, "Nodos Visitados");

    init_graph(&graph);

    addEdge("1", 100, "2", &graph);
    addEdge("1", 200, "3", &graph);
    addEdge("2", 400, "3", &graph);

    printGraph(graph);

    printNodeList(sin_visitar);
    printNodeList(visitados);
    
    return 0;
}


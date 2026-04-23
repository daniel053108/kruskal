#include <stdio.h>
#include <stdlib.h>
#include "KruskalUtils.h"

int main(void){
    
    Graph graph;
    initNodeList(&sin_visitar, "Nodos Sin Visitar");
    initNodeList(&visitados, "Nodos Visitados");

    init_graph(&graph);

    addEdge("1", 400, "2", &graph);
    addEdge("1", 100, "3", &graph);
    addEdge("2", 200, "3", &graph);

    printGraph(graph);

    sort_edges(&graph);

    printGraph(graph);

    printNodeList(sin_visitar);
    printNodeList(visitados);
    
    return 0;
}


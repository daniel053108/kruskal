#include <stdio.h>
#include <stdlib.h>
#include "KruskalUtils.h"

int main(void){
    Graph graph;
    initNodeList(&sin_visitar, "Nodos Sin Visitar");
    initNodeList(&visitados, "Nodos Visitados");

    init_graph(&graph);

    addEdge("A", 28, "B", &graph);
    addEdge("B", 16, "C", &graph);
    addEdge("C", 12, "D", &graph);
    addEdge("D", 22, "E", &graph);
    addEdge("E", 25, "F", &graph);
    addEdge("E", 24, "G", &graph);
    addEdge("G", 18, "D", &graph);
    addEdge("G", 14, "B", &graph);
    addEdge("F", 10, "A", &graph);

    printGraph(graph);

    sort_edges(&graph);

    printGraph(graph);

    printNodeList(sin_visitar);
    printNodeList(visitados);
    
    return 0;
}


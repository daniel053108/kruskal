#include "KruskalUtils.h"
#include <stdio.h>

int main(void){    
    List sin_visitar;
    Graph graph;
    Graph resultado;
    int costo = 0;
    initList(&sin_visitar, "Nodos Sin Visitar");

    init_graph(&graph);
    init_graph(&resultado);

    addEdge("A", 28, "B", &graph, &sin_visitar);
    addEdge("B", 16, "C", &graph, &sin_visitar);
    addEdge("C", 12, "D", &graph, &sin_visitar);
    addEdge("D", 22, "E", &graph, &sin_visitar);
    addEdge("E", 25, "F", &graph, &sin_visitar);
    addEdge("E", 24, "G", &graph, &sin_visitar);
    addEdge("G", 18, "D", &graph, &sin_visitar);
    addEdge("G", 14, "B", &graph, &sin_visitar);
    addEdge("F", 10, "A", &graph, &sin_visitar);


    printGraph(graph);

    sort_edges(&graph);

    printGraph(graph);
    printNodeList(sin_visitar);

    kruskal(&graph,&resultado,&costo,sin_visitar.cant_items);

    printAEM(resultado, costo);

    destroyGraph(&graph);
    destroyGraph(&resultado);

    destroyList(&sin_visitar);

    return 0;
}


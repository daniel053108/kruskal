#include "KruskalUtils.h"
#include <stdio.h>

int main(void){    
    List sin_visitar;
    List visitados;
    Graph graph;
    Graph resultado;
    int costo = 0;
    
    initList(&sin_visitar, "Nodos");
    initList(&visitados, "Nodos Agregados");

    init_graph(&graph);
    init_graph(&resultado);

    printf("----------------Agregando caminos al grafo...----------------\n");

    addEdge("A", 100, "B", &graph, &sin_visitar);
    addEdge("A", 30, "D", &graph, &sin_visitar);
    addEdge("A", 85, "D", &graph, &sin_visitar);
    
    addEdge("B", 100, "C", &graph, &sin_visitar);
    addEdge("B", 40, "E", &graph, &sin_visitar);
    addEdge("B", 45, "F", &graph, &sin_visitar);
    addEdge("B", 70, "G", &graph, &sin_visitar);
    
    addEdge("C", 55, "G", &graph, &sin_visitar);
    addEdge("C", 60, "H", &graph, &sin_visitar);
    
    addEdge("D", 50, "P", &graph, &sin_visitar);
    
    addEdge("E", 10, "I", &graph, &sin_visitar);
    
    addEdge("F", 55, "J", &graph, &sin_visitar);
    
    addEdge("G", 15, "K", &graph, &sin_visitar);
    addEdge("G", 20, "L", &graph, &sin_visitar);
    
    addEdge("H", 40, "L", &graph, &sin_visitar);
    addEdge("H", 85, "N", &graph, &sin_visitar);
    addEdge("H", 70, "O", &graph, &sin_visitar);
    
    addEdge("I", 60, "J", &graph, &sin_visitar);
    addEdge("I", 90, "P", &graph, &sin_visitar);
    
    addEdge("J", 80, "K", &graph, &sin_visitar);
    addEdge("J", 45, "Q", &graph, &sin_visitar);
    
    addEdge("K", 60, "M", &graph, &sin_visitar);
    
    addEdge("L", 50, "M", &graph, &sin_visitar);
    
    addEdge("M", 2, "S", &graph, &sin_visitar);
    
    addEdge("N", 120, "O", &graph, &sin_visitar);
    addEdge("N", 105, "O", &graph, &sin_visitar);
    addEdge("N", 55, "S", &graph, &sin_visitar);
    addEdge("N", 60, "T", &graph, &sin_visitar);
    
    addEdge("O", 195, "T", &graph, &sin_visitar);
    
    addEdge("P", 205, "R", &graph, &sin_visitar);
    
    addEdge("Q", 5, "R", &graph, &sin_visitar);
    
    addEdge("R", 230, "T", &graph, &sin_visitar);
    
    addEdge("S", 25, "T", &graph, &sin_visitar);


    printGraph(graph);


    printf("\n----------------Ordenando caminos por tamaño...----------------\n");
    sort_edges(&graph);

    printGraph(graph);
    printNodeList(sin_visitar);

    printf("\n----------------Aplicando algoritmo de Kruskal...----------------\n");
    kruskal(&graph,&resultado,&costo,&sin_visitar, &visitados);

    printf("\n");
    printAEM(resultado, costo);

    destroyGraph(&graph);
    destroyGraph(&resultado);

    destroyList(&sin_visitar);
    destroyList(&visitados);

    return 0;
}


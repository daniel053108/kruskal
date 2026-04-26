#include <stdio.h>
#include <stdlib.h>
#include "KruskalUtils.h"

int main(void){
    
    Graph graph;
    Graph resultado;
    int costo = 0;
    //nodelist de referencia para evitar variables globales


    ///visitados no es necesario
    ////NodeList visitados;
    NodeList sin_visitar;

    initNodeList(&sin_visitar, "Nodos Sin Visitar");
    ////initNodeList(&visitados, "Nodos Visitados");

    init_graph(&graph);
    init_graph(&resultado);

    addEdge("A", 10, "F", &graph,&sin_visitar);
    addEdge("A", 28, "B", &graph,&sin_visitar);
    addEdge("F", 25, "E", &graph,&sin_visitar);
    addEdge("E", 22, "D", &graph,&sin_visitar);
    addEdge("D", 12, "C", &graph,&sin_visitar);
    addEdge("C", 16, "B", &graph,&sin_visitar);
    addEdge("G", 14, "B", &graph,&sin_visitar);
    addEdge("E", 24, "G", &graph,&sin_visitar);
    addEdge("G", 18, "D", &graph,&sin_visitar);
    
    printGraph(graph);

    sort_edges(&graph);

    printGraph(graph);

    printNodeList(sin_visitar);
    ////printNodeList(visitados);

    kruskal(&graph,&resultado,&costo,sin_visitar.cant_nodes);
    printAEM(resultado, costo);
    
    return 0;
}


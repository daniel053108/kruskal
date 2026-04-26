#include <stdio.h>
#include "KruskalUtils.h"

void sort_edges(Graph* graph){
    int cantidad = graph->path_list.cant_items;
    int i ,k = cantidad/2;
    Path* actual;
    int anterior;

    while(k>0){
        for(i = k; i < cantidad; i++){
            actual = (Path*)itemOf(graph->path_list, i);
            anterior = i;
            while(anterior >= k && ((Path*)itemOf(graph->path_list,(anterior - k)))->weigth > actual->weigth){
                pushItemIn(&graph->path_list, itemOf(graph->path_list, (anterior-k)), anterior, 0); 
                anterior-=k;
            }
            pushItemIn(&graph->path_list, actual, anterior, 0);
        }
        k = k/2;
    }  
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Algoritmo Kruskal

void kruskal(Graph* graph,Graph* resultado,int* costoTotal,int cantidadNodos){
    //recorrer la lista de los paths
    int cantidad = graph->path_list.cant_items;
    int contador = 0;

    for(int i =0; i< cantidad;i++){
        Node* raizOrigen = encontrar_padre(((Path*)itemOf(graph->path_list, i))->origin);
        Node* raizDestino = encontrar_padre(((Path*)itemOf(graph->path_list, i))->destination);

        if(raizDestino != raizOrigen && contador <= cantidadNodos-1){
            raizOrigen->padre = raizDestino;
            Path* path = (Path*)itemOf(graph->path_list, i);
            
            pushEdge(resultado, path);
            *costoTotal+= path->weigth;
            contador++;
        }
    }

}  

Node* encontrar_padre(Node* nodo){
    //cuando el nodo = padre paramos
    if(nodo->padre == nodo){
        return nodo;
    }
    ///recorremos hasta encontrar el padre
    return encontrar_padre(nodo->padre);
}

void destroyGraph(Graph* graph){
    destroyList(&graph->path_list);
}

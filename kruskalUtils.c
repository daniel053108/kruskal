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

void kruskal(Graph* graph,Graph* resultado,int* costoTotal,List* sin_visitar, List* visitados){
    //recorrer la lista de los paths
    List sin_visitar_aux = *sin_visitar;
    int cantidad = graph->path_list.cant_items;
    int contador = 0;
    for(int i =0; i< cantidad;i++){
        Path* current_path = (Path*)itemOf(graph->path_list, i);
        printf("\nRevisando Camino: %s - %s, peso: %d\n", current_path->origin->name, current_path->destination->name, current_path->weigth);
        
        Node* raizOrigen = encontrar_padre(current_path->origin);
        Node* raizDestino = encontrar_padre(current_path->destination);

        if(raizDestino != raizOrigen && contador < sin_visitar->cant_items ){
            printf("Camino agregado!!\n");
            raizOrigen->padre = raizDestino;
            if(!inList(*visitados, raizOrigen)){
                pushList(visitados, raizOrigen);
               popIn(&sin_visitar_aux,indexOf(sin_visitar_aux, raizOrigen));
            }
            if(!inList(*visitados, raizDestino)){
                pushList(visitados, raizDestino);
                popIn(&sin_visitar_aux,indexOf(sin_visitar_aux, raizDestino));
            }
            Path* path = (Path*)itemOf(graph->path_list, i);
            pushEdge(resultado, path);
            *costoTotal+= path->weigth;
            contador++;
        }

        printNodeList(sin_visitar_aux);
        printNodeList(*visitados);
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

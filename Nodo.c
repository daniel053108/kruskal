#include "Nodo.h"
#include <stdio.h>
#include "utils.h"

void init_graph(Graph* graph){
    initList(&graph->path_list, "Lista de Caminos");
}

void pushEdge(Graph* graph, Path* path){
    pushList(&graph->path_list, path);
}

void addEdge(char* name_origin, int weigth, char* name_destination, Graph* graph, List* sin_visitar){
    Node* origin = existeNodo(name_origin,sin_visitar);
    Node* destination = existeNodo(name_destination,sin_visitar);


    if(!origin){
        origin = (Node*)malloc(sizeof(Node));
        origin->name = name_origin;
        origin->padre = origin;
        pushList(sin_visitar,origin);
    }
    
    
    if(!destination){
        destination = (Node*)malloc(sizeof(Node));
        destination->name = name_destination;
        destination->padre = destination;
        pushList(sin_visitar,destination);
    }

    Path* newPath = (Path*)malloc(sizeof(Path));
    
    newPath->origin = origin;
    newPath->destination = destination;
    newPath->weigth = weigth;

    pushEdge(graph, newPath);
}

void printGraph(Graph graph){
    printf("cantidad de caminos: %d\n", graph.path_list.cant_items);

    printf("|CAMINOS|\n");
    printf("|ORIGEN|PESO|DESTINO\n");
    NodoItem* current = graph.path_list.head;
    while(current != NULL){
        Path path = *((Path*) (current->item));
        printPath(path);
        current = current->next;
    }
}

void printPath(Path path){
    printf("|%s|%d|%s|\n",path.origin->name, path.weigth, path.destination->name);  
}

void printNodeList(List list){
    printf("%s: [", list.name);
    NodoItem* current = list.head;
    while(current != NULL){
        Node node = *((Node*) (current->item));
        printf("%s, ", node.name);
        current = current->next;
    }
    printf("]\n");
}

void printNodo(Node node){
    printf("Nodo: %s\n", node.name);
}
    
Node* existeNodo(char* nombre, List* lista){
    for(int i = 0; i < lista->cant_items; i++){
        if(!string_cmp(nombre, ((Node*)itemOf(*lista, i))->name) == 0){
            return ((Node*)itemOf(*lista, i));
        }
    }
    return NULL;
}

void printAEM(Graph graph, int costo){
    printf("----RESULTADO----\n");
    printf("cantidad de caminos: %d\n", graph.path_list.cant_items);
    printf("COSTO CAMINO: %d\n",costo);
    printf("|CAMINOS|\n");
    printf("|ORIGEN|PESO|DESTINO\n");
    NodoItem* current = graph.path_list.head;
    while(current != NULL){
        printPath(*((Path*)current->item));
        current = current->next;
    }
}
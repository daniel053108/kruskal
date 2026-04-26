#include "KruskalUtils.h"

void initNodeList(NodeList* nodeList, char* name){
    nodeList->name = name;
    nodeList->max_nodes = 10;
    nodeList->cant_nodes = 0;
    nodeList->nodes = (Node**)malloc(nodeList->max_nodes * sizeof(Node*));
}

void pushNodeList(NodeList* nodeList, Node* node){
    ///compare con la cantidad de nodos que hay no el maximo
    if(nodeList->cant_nodes == nodeList->max_nodes){
        nodeList->max_nodes += 10;
        nodeList->nodes = (Node**)realloc(nodeList->nodes, nodeList->max_nodes * sizeof(Node*));
    }
    nodeList->nodes[nodeList->cant_nodes] = node;
    nodeList->cant_nodes++;
}

int isDuplicated(NodeList _nodeList, Node* _node){
    for(int i = 0; i < _nodeList.cant_nodes ; i++){
        Node* node = _nodeList.nodes[i];
        if(node->name[0] == _node->name[0]){
            return 1;
        }
    }
    return 0;
}



void printNodeList(NodeList _nodeList){
    printf("%s:", _nodeList.name);
    printf("[");
    for(int i = 0; i < _nodeList.cant_nodes ; i++){
        printf("%s,", _nodeList.nodes[i]->name);
    }  
    printf("]\n");
}

void sort_edges(Graph* graph){
    int cantidad = graph->cant_edges;
    int i ,k = cantidad/2;
    Path* actual;
    int anterior;

    while(k>0){
        for(i=k;i<cantidad;i++){
            actual = graph->path_list[i];
            anterior = i;
            while(anterior >= k && graph->path_list[anterior - k]->weigth > actual->weigth){
                graph->path_list[anterior] = graph->path_list[anterior- k];
                anterior-=k;
            }
            graph->path_list[anterior] = actual;
        }
        k = k/2;
    }   
}
/**/
void kruskal(Graph* graph,Graph* resultado,int* costoTotal,int cantidaNodos){
    //recorrer la lista de los paths
    int cantidad = graph->cant_edges;
    int contador =0;

    for(int i =0; i< cantidad;i++){
        Node* raizOrigen = encontrar_padre(graph->path_list[i]->origin);
        Node* raizDestino = encontrar_padre(graph->path_list[i]->destination);

        if(raizDestino != raizOrigen && contador <= cantidaNodos-1){
            raizOrigen->padre = raizDestino;
            pushEdge(resultado,graph->path_list[i]);
            *costoTotal+= graph->path_list[i]->weigth;
            contador++;
            
        }

    }

}

Node* encontrar_padre(Node* nodo){
    //cuando el nodod = padre paramos
    if(nodo->padre == nodo){
        return nodo;
    }
    ///recorremos hasta encontrar el padre
    return encontrar_padre(nodo->padre);


}





/*
int isLoop(Path* Path){

    for(int i =0;i< sin_visitar.cant_nodes+1;i++){
        for(int j =0; j < visitados.cant_nodes+1;j++ ){
            if(&sin_visitar.nodes[i]->name == &visitados.nodes[i]->name ){
                return 1;
            }else{
                &visitados.nodes[i+1] = &sin_visitar.nodes[i];
            }
        }
    }

}

*/

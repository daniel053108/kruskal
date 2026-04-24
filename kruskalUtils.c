#include "KruskalUtils.h"

void initNodeList(NodeList* nodeList, char* name){
    nodeList->name = name;
    nodeList->max_nodes = 10;
    nodeList->cant_nodes = 0;
    nodeList->nodes = (Node**)malloc(nodeList->max_nodes * sizeof(Node*));
}

void pushNodeList(NodeList* nodeList, Node* node){
    if(nodeList->cant_nodes + 1 == nodeList->max_nodes){
        nodeList->max_nodes += 10;
        nodeList->nodes = (Node**)realloc(nodeList->nodes, nodeList->max_nodes * sizeof(Node*));
    }
    nodeList->nodes[nodeList->cant_nodes] = node;
    nodeList->cant_nodes++;
}

int isDuplicated(NodeList _nodeList, Node* _node){
    printf("Entrada: %s\n", _node->name);
    for(int i = 0; i < _nodeList.cant_nodes; i++){
        Node* node = _nodeList.nodes[i];
        printf("%s == %s\n", node->name, _node->name);
        if(string_cmp(node->name, _node->name)){
            printf("Repetido\n");
            return 1;
        }
    }
    return 0;
}

void printNodeList(NodeList _nodeList){
    printf("%s:\n", _nodeList.name);
    printf("Cantidad de nodos dentro: %d\n", _nodeList.cant_nodes);
    printf("Max de nodos: %d\n", _nodeList.max_nodes);
    printf("[");
    for(int i = 0; i < _nodeList.cant_nodes; i++){
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

int isVisited(Node* node){
    return isDuplicated(visitados, node);
}

int string_cmp(const char* str1,const char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2)return 0;
    
    for(int i = 0; i < len1; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

size_t strlen(const char* str){
    size_t len = 0;
    while(str[len] != '\0'){
        len++;
    }

    return len;
}

int nodeListIsEmpty(NodeList nodeList){
    return nodeList.cant_nodes == 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//Algoritmo Kruskal

void kruskal(){
    while(nodeListIsEmpty(sin_visitar)){
        
    }
}
#include "KruskalUtils.h"

void initNodeList(NodeList* nodeList, char* name){
    nodeList->name = name;
    nodeList->max_nodes = 10;
    nodeList->cant_nodes = 0;
    nodeList->nodes = (Node**)malloc(nodeList->max_nodes * sizeof(Node*));
}

void pushNodeList(NodeList* nodeList, Node* node){
    if(nodeList->max_nodes + 1 == nodeList->max_nodes){
        nodeList->max_nodes += 10;
        nodeList->nodes = (Node**)realloc(nodeList->nodes, nodeList->max_nodes * sizeof(Node*));
    }
    nodeList->nodes[nodeList->cant_nodes] = node;
    nodeList->cant_nodes++;
}

int isDuplicated(NodeList _nodeList, Node* _node){
    for(int i = 0; i < _nodeList.cant_nodes - 1; i++){
        Node* node = _nodeList.nodes[i];
        if(node->name == _node->name){
            return 1;
        }
    }
    return 0;
}

void printNodeList(NodeList _nodeList){
    printf("%s:", _nodeList.name);
    printf("[");
    for(int i = 0; i < _nodeList.cant_nodes - 1; i++){
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
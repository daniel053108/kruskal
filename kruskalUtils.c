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

void orderNodesList(NodeList* _nodeList){
    
}

void printNodeList(NodeList _nodeList){
    printf("%s:", _nodeList.name);
    printf("[");
    for(int i = 0; i < _nodeList.cant_nodes - 1; i++){
        printf("%s,", _nodeList.nodes[i]->name);
    }  
    printf("]\n");
}
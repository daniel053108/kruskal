#include "Nodo.h"
#include <stdio.h>

void initList(List* list, char* listName){
    list->head = NULL;
    list->tail = NULL;
    list->cant_items = 0;
    list->name = listName;
}

void pushList(List* list, void* item){
    NodoItem* newNodo = (NodoItem*)malloc(sizeof(NodoItem));
    newNodo->item = item;
    newNodo->next = NULL;
    newNodo->prev = list->tail;
    if(newNodo->prev != NULL)
        newNodo->prev->next = newNodo;
    list->tail = newNodo;   
    if(list->head == NULL){
        list->head = newNodo;    
    }
    list->cant_items++;
}

void* popList(List* list){
    void* returnItem = list->tail->item;
    NodoItem* newTail = list->tail->prev;
    free(list->tail);
    newTail->next = NULL;
    list->tail = newTail;
    list->cant_items--;
    return returnItem;
}

void* dequeue(List* list){
    void* returnItem = list->head->item;
    NodoItem* newHead = list->head->next;
    free(list->head);
    newHead->prev = NULL;
    list->head = newHead;
    list->cant_items--;
    return returnItem;
}

void* popIn(List* list, int idx){
    if(idx >= list->cant_items || idx < 0){
        return NULL;
    }

    NodoItem* current = list->head;
    for(int i = 0; i < idx; i++){
        current = current->next;
    }

    void* returnItem = current->item;

    if(current == list->head){
        list->head = current->next;
    }

    if(current == list->tail){
        list->tail = current->prev;
    }

    if(current->prev != NULL){
        current->prev->next = current->next;
    }

    if(current->next != NULL){
        current->next->prev = current->prev;
    }

}

int isEmpty(List list){
    return list.cant_items == 0;
}

int inList(List list, void* item){
    NodoItem* current = list.head;
    while(current != NULL){
        if(current->item == item){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void* itemOf(List list, int idx){
    if(idx >= list.cant_items || idx < 0){
        return NULL;
    }
    NodoItem* current = list.head;
    for(int i = 0; i < idx; i++){
        current = current->next;
    }
    return current->item;
}

int indexOf(List list, void* item){
    int idx = 0;
    NodoItem* current = list.head;
    while(current != NULL){
        if(current->item == item){
            return idx;
        }
        current = current->next;
        idx++;
    }
    return -1;
}

int pushItemIn(List* list, void* item, int idx, int freeMemory){
    NodoItem* current = list->head;

    if(idx >= list->cant_items || idx < 0){
        return -1;
    }
    for(int i = 0; i < idx; i++){
        current = current->next;
    }

    if(current == NULL)return -1;

    if(freeMemory)
        free(current->item);
    current->item = item;
}

void destroyList(List* list){
    NodoItem* current = list->head;
    while(current != NULL){
        NodoItem* next = current->next;
        free(current);
        current = next;
    }
}

#include <stdlib.h>

typedef struct _NodoItem{
    void* item;
    struct _NodoItem* next;
    struct _NodoItem* prev;
}NodoItem;

typedef struct _List{
    NodoItem* head;
    NodoItem* tail;
    int cant_items;
    char* name;
}List;

void initList(List* list, char* listName);
void pushList(List* list, void* item);
void* popList(List* list);
void* dequeue(List* list);
void* popIn(List* list, int idx);
int isEmpty(List list);
int inList(List list, void* item);
void* itemOf(List list, int idx);
int indexOf(List list, void* item);
int pushItemIn(List* list, void* item, int idx, int freeMemory);
void destroyList(List* list);


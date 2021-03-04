#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _SNode
{
    Data _data;
    struct _SNode* _next;
} Node;

typedef struct _SLinkedList
{
    Node* _head;
    Node* _tail;
    Node* _cur;

    int _num_of_data;
} LinkedList;

int is_empty(LinkedList* list);
void init_linkedList(LinkedList* list);
void add_node_to_linkedList(LinkedList* list, Data data);
Data search_data_from_linkedList(LinkedList* list, Data data);
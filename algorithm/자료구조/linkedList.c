#include "linkedList.h"

void init_linkedList(LinkedList* list)
{
    list->_head = NULL;
    list->_tail = NULL;
    list->_cur = NULL;
    list->_num_of_data = 0;
}

int is_empty(LinkedList* list)
{
    if(list->_tail == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

void add_node_to_linkedList(LinkedList* list, Data data)
{
    if(list->_tail == NULL)
    {
        list->_tail = list->_head = (Node*)malloc(sizeof(Node));
        list->_head->_data = data;
        list->_head->_next = NULL;
    }
    else
    {
        list->_head->_next = (Node*)malloc(sizeof(Node));
        list->_head = list->_head->_next;
        list->_head->_data = data;
        list->_head->_next = NULL;
    }
}

Data search_data_from_linkedList(LinkedList* list, Data data)
{
    if(is_empty(list))
    {
        printf("linkedList is empty \n");
        return -1;
    }

    list->_cur = list->_tail;
    while(list->_cur != NULL)
    {
        if(list->_cur->_data == data)
        {
            return list->_cur->_data;
        }
        list->_cur = list->_cur;
    }

    printf("Data: %d is not exist \n", data);
    return -1;
}
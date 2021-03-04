#include "stackLinkedList.h"

int main(void)
{
    Stack stack = { 0, };

    stack_init(&stack);

    if(is_empty(&stack))
    {
        printf("stack is empty \n");
    }

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printf("peek : %d \n", peek(&stack));
    printf("pop : %d \n", pop(&stack));
    printf("peek : %d \n", peek(&stack));
    printf("pop : %d \n", pop(&stack));
    printf("peek : %d \n", peek(&stack));
    printf("pop : %d \n", pop(&stack));
    printf("peek : %d \n", peek(&stack));
    printf("pop : %d \n", pop(&stack));
    printf("peek : %d \n", peek(&stack));
    printf("pop : %d \n", pop(&stack));

    return 0;
}

void stack_init(Stack* _pStack)
{
    if(is_empty(_pStack))
    {
        _pStack->_top = NULL;
        _pStack->_bottom = NULL;
    }
    else
    {
        while(_pStack->_top != _pStack->_bottom)
        {
            _pStack->_top = _pStack->_top->_back;
            free(_pStack->_top->_front);
        }
        free(_pStack->_top);
        _pStack->_top = NULL;
        _pStack->_bottom = NULL;
    }
}

int is_empty(Stack* _pStack)
{
    if(_pStack->_top == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

void push(Stack* _pStack, int data)
{
    if(_pStack->_bottom == NULL)
    {
        _pStack->_bottom = (Data*)malloc(sizeof(Data));
        _pStack->_top = _pStack->_bottom;
        _pStack->_top->_data = data;
        _pStack->_top->_front = NULL;
        _pStack->_top->_back = NULL;
    }
    else
    {
        _pStack->_top->_front = (Data*)malloc(sizeof(Data));
        _pStack->_top->_front->_front = NULL;
        _pStack->_top->_front->_back = _pStack->_top;
        _pStack->_top->_front->_data = data;
        _pStack->_top = _pStack->_top->_front;
    }
}

int pop(Stack* _pStack)
{
    int ret = 0;
    if(is_empty(_pStack))
    {
        printf("Stack is empty \n");
        return -1;
    }

    ret = _pStack->_top->_data;

    if(_pStack->_top == _pStack->_bottom)
    {
        free(_pStack->_bottom);
        _pStack->_bottom = NULL;
        _pStack->_top = NULL;
    }
    else
    {
        _pStack->_top = _pStack->_top->_back;
        free(_pStack->_top->_front);
    }

    return ret;
}

int peek(Stack* _pStack)
{
    if(is_empty(_pStack))
    {
        printf("Stkac is empty \n");
        return -1;
    }
    return _pStack->_top->_data;
}
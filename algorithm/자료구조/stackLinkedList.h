#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

typedef struct _SData
{
    int _data;
    struct _SData* _front;
    struct _SData* _back;
} Data;

typedef struct _SStack
{
    Data* _top;
    Data* _bottom;
} Stack;

void stack_init(Stack* _pStack);
int is_empty(Stack* _pStack);
void push(Stack* _pStack, int data);
int pop(Stack* _pStack);
int peek(Stack* _pStack);
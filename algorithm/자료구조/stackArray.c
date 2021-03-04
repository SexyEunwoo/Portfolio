#include "stackArray.h"

int is_digit(char);
int operator_to_priority(char);
void push_operator(char);
int conv_to_rpn_exp(char[]);
int calc_rpn_exp(void);

Stack stack;
int idx = 0;
char arr[100];

int main(void)
{
    conv_to_rpn_exp("((3-1)+3)*(5-2)");
    printf("calc : %d \n", calc_rpn_exp());
    return 0;
}

int calc_rpn_exp(void)
{
    int ret = 0;
    Stack calc_stack;

    stack_init(&calc_stack);

    for(int i = 0; i < strlen(arr); i++)
    {
        if(is_digit(arr[i]))
        {
            push(&calc_stack, arr[i]);
        }
        else
        {
            int num2 = pop(&calc_stack) - 48;
            int num1 = pop(&calc_stack) - 48;
            switch (arr[i])
            {
                case '+':
                    ret = num1 + num2;
                    break;
                case '-':
                    ret = num1 - num2;
                    break;
                case '*':
                    ret = num1 * num2;
                    break;
                case '/':
                    ret = num1 / num2;
                    break;
            }
            ret += 48;
            push(&calc_stack, ret);
        }
    }

    return pop(&calc_stack) - 48;
}

int conv_to_rpn_exp(char calc[])
{
    char ch;

    stack_init(&stack);

    for(int i = 0; i < strlen(calc); i++)
    {
        ch = calc[i];
        if(is_digit(ch))
        {
            arr[idx++] = ch;
        }
        else
        {
            push_operator(ch);
        }
    }

    while (!is_empty(&stack))
    {
        arr[idx++] = pop(&stack);
    }

    printf("%s \n", arr);
    return 0;
}

int is_digit(char ch)
{
    if(ch >= 48 && ch <= 57)
    {
        return TRUE;
    }
    return FALSE;
}

void push_operator(char ch)
{
    if(is_empty(&stack))
    {
        push(&stack, ch);
    }
    else if(ch == ')')
    {
        while(peek(&stack) != '(')
        {
            arr[idx++] = pop(&stack);
        }
        pop(&stack);
    }
    else
    {
        while(1)
        {
            if((is_empty(&stack)) || (peek(&stack) == '(') || (operator_to_priority(ch) < operator_to_priority(stack._data[stack._idx_top])))
            {
                push(&stack, ch);
                break;
            }
            else
            {
                arr[idx++] = pop(&stack);
            }
        }
    }
}

int operator_to_priority(char ch)
{
    int ret = 0;
    switch (ch)
    {
        case '+':
        case '-':
            ret = 4;
            break;
        case '*':
        case '/':
            ret = 2;
            break;
        case '(':
            ret = 1;
    }

    return ret;
}

void stack_init(Stack* _pStack)
{
    _pStack->_idx_bottom = -1;
    _pStack->_idx_top = -1;
}

int is_empty(Stack* _pStack)
{
    if(_pStack->_idx_top == -1)
    {
        return TRUE;
    }
    return FALSE;
}

int is_full(Stack* _pStack)
{
    if(_pStack->_idx_top == (STACK_SIZE - 1))
    {
        return TRUE;
    }
    return FALSE;
}

void push(Stack* _pStack, Data data)
{
    if(is_full(_pStack))
    {
        printf("Stack is full \n");
    }
    _pStack->_data[++(_pStack->_idx_top)] = data;
}

Data pop(Stack* _pStack)
{
    if(is_empty(_pStack))
    {
        printf("Stack is empty \n");
        return -1;
    }
    return _pStack->_data[_pStack->_idx_top--];
}

Data peek(Stack* _pStack)
{
    if(is_empty(_pStack))
    {
        printf("Stack is empty \n");
        return -1;
    }
    return _pStack->_data[_pStack->_idx_top];
}
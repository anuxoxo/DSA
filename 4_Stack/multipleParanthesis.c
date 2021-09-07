#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    else
    {
        printf("\nStack Overflown!");
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else
        return 0;
}
int paranthesisMatch(char *exp)
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 10;
    stk->top = -1;
    stk->arr = (char *)malloc(stk->size * sizeof(int));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(stk, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(stk))
            {
                return 0;
            }
            char poppedChar = pop(stk);
            if (!match(poppedChar, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(stk))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char exp[] = "[4-6]((8){(9-8)})";

    if (paranthesisMatch(exp))
    {
        printf("\nBalanced Paranthesis!");
    }
    else
    {
        printf("\nUnbalanced Paranthesis!\n");
    }
    return 0;
}

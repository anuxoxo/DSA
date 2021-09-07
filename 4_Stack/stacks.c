#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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
        printf("\nStack Full!");
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Enter a valid position!!!");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

void display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack empty!");
    }
    else
    {
        printf("\nStack elements are: ");
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("\n%d", ptr->arr[i]);
        }
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 10;
    stk->top = -1;
    stk->arr = (int *)malloc(stk->size * sizeof(int));

    push(stk, 11);
    push(stk, 27);
    push(stk, 31);
    push(stk, 89);
    push(stk, 37);
    display(stk);

    for (int j = 1; j <= stk->top + 1; j++)
    {
        printf("\nThe value at position %d is : %d", j, peek(stk, j));
    }

    return 0;
}
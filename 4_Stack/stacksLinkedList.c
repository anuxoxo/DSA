#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL)
    {
        return 1;
    }

    free(ptr);
    return 0;
}

struct Node *push(struct Node *top, int data)
{
    if (!isFull())
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->next = top;

        top = ptr;
        return top;
    }
    else
    {
        printf("\nStack overflown!");
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("\nStack underflown!");
        return -1;
    }

    int x = (*top)->data;
    (*top) = (*top)->next;
    return x;
}

void display(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nNo elements to display!");
    }
    else
    {

        printf("\nStack Elements are: \n");
        while (ptr != NULL)
        {
            printf("\nElement : %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int peek(struct Node *ptr, int pos)
{
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct Node *top)
{
    return top->data;
}
int stackBottom(struct Node *ptr)
{

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    display(top);
    printf("\nPopped element is: %d", pop(&top));
    printf("\nPopped element is: %d", pop(&top));
    display(top);

    printf("\nPeeked element is: %d", peek(top, 1));
    printf("\nStack top: %d", stackTop(top));
    printf("\nStack bottom: %d", stackBottom(top));


    return 0;
}

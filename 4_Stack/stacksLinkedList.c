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

void push(struct Node *top, int data)
{
    if (!isFull())
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->next = top;

        top = ptr;
    }
    else
    {
        printf("\nStack overflown!");
    }
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("\nElement : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *top = NULL;

    push(top, 1);
    display(top);
}

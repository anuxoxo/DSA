#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *node)
{
    while (node != NULL)
    {
        printf("\n%d", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 90;
    second->next = third;

    third->data = 71;
    third->next = fourth;

    fourth->data = 121;
    fourth->next = NULL;

    traverse(head);
    return 0;
}
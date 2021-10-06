#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

void insertAtEnd(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        temp->prev = head;
    }
}

void traversal()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->prev = NULL;

    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 7;
    first->prev = head;
    first->next = NULL;

    head->next = first;

    traversal();

    return 0;
}
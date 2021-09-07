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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    return temp;
}

void insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
}

void insertAtEnd(struct Node *head, int data)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
}

void insertAfterANode(struct Node *prevNode, struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    // ----------- insertAtFirst --------
    // head = insertAtFirst(head, 10);
    // traverse(head);

    // ------- insertAtIndex ----------
    // insertAtIndex(head, 22, 2);
    // traverse(head);

    // insertAtEnd(head, 900);
    // traverse(head);

    insertAfterANode(second, head, 5);
    traverse(head);

    return 0;
}
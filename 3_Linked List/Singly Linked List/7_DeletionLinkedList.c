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

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

void deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *temp = ptr->next;

    ptr->next = temp->next;
    free(temp);
}

void deleteAtEnd(struct Node *head)
{
    struct Node *temp1 = head;
    struct Node *temp2 = head->next;

    while (temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    free(temp2);
    temp1->next = NULL;
}

void deleteAValue(struct Node *head, int value)
{
    struct Node *temp1 = head;
    struct Node *temp2 = head->next;

    while (temp2->data != value && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp2->data == value)
    {
        temp1->next = temp2->next;
        free(temp2);
    }
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

    // head = deleteAtFirst(head);
    // deleteAtIndex(head, 2);
    // deleteAtEnd(head);
    // deleteAValue(head, 4);

    traverse(head);

    return 0;
}
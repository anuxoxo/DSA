#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertAtEnd(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
}

void traverse()
{
    struct Node *ptr = head;
    int i = 1;

    if (head == NULL)
    {
        printf("\n--------------------------------");
        printf("\nNo elements to display!");
        printf("\n--------------------------------");
    }
    else
    {
        printf("\nLinked list traversal");
        printf("\n--------------------------------");

        while (ptr != NULL)
        {
            printf("\nElement %d: %d", i++, ptr->data);
            ptr = ptr->next;
        }
    }
}

void reverse()
{
    struct Node *curr = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;
    traverse();
}

void evenPrint()
{
    struct Node *ptr = head;
    int i = 1;

    while (ptr != NULL)
    {
        if (i++ % 2 == 0)
        {
            printf("%d ", ptr->data);
        }
        ptr = ptr->next;
    }
}

int main()
{
    head = NULL;
    int data, n = 10;

    for (int i = 0; i < n; i++)
    {
        printf("Enter data %d :", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }

    // reverse();
    evenPrint();

    return 0;
}
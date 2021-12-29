#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * front, *rear;

void enqueue(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("\nQueue Full!");
    }
    else
    {
        temp->data = val;
        temp->next = NULL;

        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }

        printf("\nElement inserted: %d", val);
    }
}

int dequeue()
{
    int val = -1;
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("\nQueue Empty!");
    }
    else
    {
        front = front->next;
        val = temp->data;
        free(temp);
    }
    return val;
}

void traverse()
{
    struct Node *temp = front;
    printf("\n\nElements: ");
    while (temp != rear->next)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    front = rear = NULL;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("\n\nDequed element: %d", dequeue());
    printf("\nDequed element: %d", dequeue());
    printf("\nDequed element: %d", dequeue());
    traverse();
    return 0;
}
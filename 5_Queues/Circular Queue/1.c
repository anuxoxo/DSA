#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int counter, size, front, rear, *arr;
} q;

void enqueue(struct Queue *q, int val)
{
    if (q->counter == q->size)
    {
        printf("\nQueue full!");
    }
    else
    {
        if (q->front == -1)
            q->front++;

        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        q->counter++;
        printf("\nEnqued element: %d\n", val);
    }
}

int dequeue(struct Queue *q)
{
    if (q->counter == 0)
    {
        printf("\nQueue Empty!");
    }
    else
    {
        int a = q->arr[q->front];
        q->front = (q->front + 1) % q->size;

        q->counter--;
        return a;
    }
}

void display(struct Queue *q)
{
    for (int i = q->front, j = 0; j < q->counter; i = (i + 1) % q->size, j++)
    {
        printf("\n%d", q->arr[i]);
    }
}

int main()
{
    struct Queue q;
    q.size = 3;
    q.front = q.rear = -1;
    q.counter = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 5);
    enqueue(&q, 50);

    printf("\nDequeing element is %d", dequeue(&q));
    printf("\nDequeing element is %d", dequeue(&q));

    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size, front, rear, *arr;
};

int isFull(struct Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->front > q->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nQueue Full!");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;

        q->rear++;
        q->arr[q->rear] = val;
        printf("\nEnqued element: %d", val);
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue Empty!");
    }
    else
    {
        int a = q->arr[q->front];
        q->front++;
        return a;
    }
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);

    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 5);

    printf("\nDequeing element is %d", dequeue(&q));
    printf("\nDequeing element is %d", dequeue(&q));

    return 0;
}
#include <iostream>
using namespace std;

#define n 10

class Queue
{
    int *arr;
    int front, rear;

public:
    Queue()
    {
        arr = new int[n];
        front = rear = -1;
    }
    bool empty()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue empty";
            return true;
        }
        return false;
    }
    void push(int val)
    {
        if (rear != n - 1)
        {
            if (front == -1)
                front++;

            arr[++rear] = val;
        }
    }

    void pop()
    {
        if (!empty())
        {
            front++;
        }
    }
    int peek()
    {
        if (!empty())
        {
            return arr[front];
        }
        return -1;
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i + 1);
    }
    q.pop();
    for (int i = 0; i < 5; i++)
    {
        cout << q.peek() << endl;
        q.pop();
    }

    return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void push(int val)
    {
        Node *n = new Node(val);

        if (front == NULL)
        {
            front = n;
            rear = n;
            return;
        }

        rear->next = n;
        rear = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflown" << endl;
            return;
        }
        Node *todel = front;
        front = front->next;
        delete todel;
    }
    int peek()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            cout << "Queue underflown" << endl;
            return true;
        }
        return false;
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
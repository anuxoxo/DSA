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

void insertAtHead(Node *&rear, int val)
{
    Node *n = new Node(val);
    if (rear == NULL)
    {
        n->next = n;
        rear = n;
        return;
    }
    n->next = rear->next;
    rear->next = n;
    rear = n;
}

void insertAtTail(Node *&rear, int val)
{
    if (rear == NULL)
    {
        insertAtHead(rear, val);
        return;
    }
    Node *temp = rear;
    Node *n = new Node(val);
    n->next = rear->next;
    rear->next = n;
    rear = n;
}

void display(Node *rear)
{
    Node *temp = rear->next;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != rear->next);
    cout << "NULL" << endl;
}
void delAtHead(Node *&rear)
{
    Node *todel = rear->next;
    rear->next = todel->next;
    delete todel;
}
void deletion(Node *&rear, int pos)
{
    if (pos == 1)
    {
        delAtHead(rear);
        return;
    }
    Node *temp = rear->next;
    int i = 1;
    do
    {
        temp = temp->next;
    } while (temp != rear->next && ++i != pos - 1);
    Node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}

int main()
{
    Node *rear = NULL;
    insertAtTail(rear, 1);
    insertAtTail(rear, 2);
    insertAtTail(rear, 3);
    insertAtTail(rear, 4);
    insertAtTail(rear, 5);
    insertAtTail(rear, 6);
    display(rear);
    deletion(rear, 1);
    display(rear);

    return 0;
}
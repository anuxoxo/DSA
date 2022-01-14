#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val, Node *n = NULL)
    {
        data = val;
        next = n;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

Node *kAppend(Node *head, int k)
{
    Node *tail = head, *newHead, *newTail;
    int n = length(head), i = 0;

    k = k % n;

    while (tail->next != NULL)
    {
        if (i == n - k - 1)
            newTail = tail;
        if (i == n - k)
            newHead = tail;

        tail = tail->next;
        i++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    Node *head = NULL, *revH;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    Node *newHead = kAppend(head, 2);
    display(newHead);
    return 0;
}

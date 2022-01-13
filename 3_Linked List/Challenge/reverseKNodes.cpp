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

Node *reversek(Node *&head, int k)
{
    Node *curr = head, *prev = NULL, *next;
    int i = 0;
    while (curr != NULL && i < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        i++;
    }
    if (next != NULL)
        head->next = reversek(next, k);

    return prev;
}

int main()
{
    Node *head = NULL, *revH;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    revH = reversek(head, 2);
    display(revH);
    return 0;
}

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

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val, head);
    head = n;
}

void delHead(Node *&head)
{
    Node *delNode = head;
    head = head->next;
    delete delNode;
}
void deletion(Node *&head, int key)
{
    if (head == NULL)
        return;
    else if (head->next == NULL || head->data == key)
    {
        Node *delNode = head;
        head = head->next;
        delete delNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next->data != key)
        {
            temp = temp->next;
        }
        Node *delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;
    }
}

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node *reverse(Node *head)
{
    Node *prev = NULL, *curr = head, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node *recReverse(Node *head)
{
    if (head->next == NULL || head == NULL)
        return head;

    Node *newHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    // deletion(head, 3);
    // display(head);
    // deletion(head, 1);
    // display(head);

    Node *rev = recReverse(head);
    display(rev);

    return 0;
}

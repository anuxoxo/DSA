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

int intersectionPoint(Node *&head1, Node *&head2)
{
    int m = length(head1), n = length(head2), d = 0;
    Node *ptr1, *ptr2;

    if (m > n)
    {
        d = m - n;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = n - m;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
            return -1;
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void makeIntersect(Node *head1, Node *head2, int pos)
{
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && --pos)
        temp1 = temp1->next;

    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;
}

int main()
{
    Node *head1 = NULL, *head2;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    makeIntersect(head1, head2, 3);
    display(head1);
    display(head2);
    cout << intersectionPoint(head1, head2);

    return 0;
}

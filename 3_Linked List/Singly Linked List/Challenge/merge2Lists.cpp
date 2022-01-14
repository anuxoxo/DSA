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

Node *mergeLists(Node *head1, Node *head2)
{
    Node *newHead = new Node(-1), *ptr = newHead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ptr->next = head1;
            head1 = head1->next;
        }
        else
        {
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }

    while (head1 != NULL)
    {
        ptr->next = head1;
        ptr = ptr->next;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        ptr->next = head2;
        ptr = ptr->next;
        head2 = head2->next;
    }
    ptr = newHead;
    newHead = newHead->next;
    free(ptr);

    return newHead;
}

Node *mergeRecursive(Node *head1, Node *head2)
{
    if (head1 = NULL)
        return head2;
    if (head2 = NULL)
        return head1;

    Node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL, *mergedHead = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    mergedHead = mergeRecursive(head1, head2);
    display(mergedHead);

    return 0;
}

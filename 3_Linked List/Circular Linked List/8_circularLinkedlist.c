#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayNodes(struct Node *head)
{
    struct Node *temp = head;
    do
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// struct Node * insertAtFirst(struct Node *head, int data){
//     struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node * p = head->next;
//     while(p->next != head){
//         p = p->next;
//     }
//     // At this point p points to the last node of this circular linked list

//     p->next = ptr;
//     ptr->next = head;
//     head = ptr;
//     return head;

// }

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    temp->data = data;

    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);

    ptr->next = temp;
    temp->next = head;
    head = temp;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    struct Node *b = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = a;

    a->data = 2;
    a->next = b;

    b->data = 3;
    b->next = head;

    // displayNodes(head);
    head = insertAtFirst(head, 10);
    displayNodes(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void create_list(int data)
{
    struct Node *temp, *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void display(struct Node *head)
{
    struct Node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void add_beg(struct Node *head, int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void add_end(struct Node *head, int data)
{
    struct Node *temp, *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

void list_length(struct Node *head)
{
    struct Node *p;
    p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    printf("No of Nodes Present are %d", c);
}

int main()
{
    int data, c, n;
    head = NULL;

    printf("Enter The No. Of Nodes To Be Created :\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The data For Node %d :", i + 1);
        scanf("%d", &data);
        create_list(data);
    }
    printf("\n\n");

    while (1)
    {
        printf("Enter Your Choice :\n");
        printf("1:Display The Node\n");
        printf("2:Insert Node At The Beginning\n");
        printf("3-Insert Node At The End\n");
        printf("4:No. Of Nodes\n");
        printf("5:Exit\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("The Elements In The Nodes Are :\n");
            display(head);
            break;
        case 2:
            printf("Enter The Data To be Inserted At The Beginning :\n");
            scanf("%d", &data);
            add_beg(head, data);
            break;
        case 3:
            printf("Enter The Data To Be Inserted At The End :\n");
            scanf("%d", &data);
            add_end(head, data);
            break;
        case 4:
            list_length(head);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
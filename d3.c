#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *start = NULL;

void create()
{
    struct Node *newnode, *temp;
    int data;
    printf("Enter The Data :");
    scanf("%d", &data);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    if (start == NULL)
    {
        start = temp = newnode;
    }
    else
    {
        temp->link = newnode;
        temp = newnode;
    }
}
void search()
{
    int item;
    printf("\nEnter The Data To Be Searched :");
    scanf("%d", &item);
    struct Node *temp, *prev, *temp2;
    temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp = start;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == item)
        {
            temp2->data = temp->data;
            prev->link = temp->link;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->link;
    }

    temp2->link = start;
    start = temp2;
}

void display()
{
    struct Node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int n;
    printf("Enter The No. Of Data To Be Inserted :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        create();
    display();
    search();
    display();
    return 0;
}
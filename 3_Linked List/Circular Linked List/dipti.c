#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *last;

struct Node *create_list(struct Node *last)
{
    struct Node *temp;
    int n, data;
    printf("ENTER THE NO. OF NODES\t\t:");
    scanf("%d", &n);
    last = NULL;
    if (n == 0)
        return last;

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE DATA AT NODE 1\t:");
    scanf("%d", &data);
    temp->info = data;
    last = temp;
    last->link = last;

    for (int i = 2; i <= n; i++)
    {
        printf("ENTER THE DATA AT NODE %d\t:", i);
        scanf("%d", &data);
        struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
        temp1->info = data;
        temp1->link = last->link;
        last->link = temp1;
        // last = temp1;
    }
    return last;
}

void display(struct Node *last)
{
    struct Node *temp = last;
    do
    {
        printf("ELEMENTS ARE\t%d\n", temp->info);
        temp = temp->link;
    } while (temp != last);
}

int main()
{
    last = create_list(last);
    int c;
    while (1)
    {
        printf("\nENTER YOUR CHOICE\n");
        printf("1:Display All The Nodes\n");
        printf("2:Insert Node At Given Location\n");
        printf("3:Delete Node At Given Location\n");
        printf("4:EXIT\n");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            display(last);
            break;
        case 4:
            exit(1);
        }
    }

    return 0;
}
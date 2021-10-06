#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *multiply;
    struct Node *next;
};

struct Node *head;

void insertAtEnd(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->multiply = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
}

void pointMultiply()
{
    struct Node *ptr = head;
    struct Node *temp = head->next;

    if (head == NULL)
    {
        printf("\n--------------------------------");
        printf("\nNo elements to point!");
        printf("\n--------------------------------");
    }
    else
    {
        while (ptr != NULL)
        {
            while (temp != NULL)
            {
                if (temp->data % ptr->data == 0)
                {
                    if (ptr->multiply != NULL && temp->data < ptr->multiply->data)
                    {
                        ptr->multiply = temp;
                    }
                    else if (ptr->multiply == NULL)
                    {
                        ptr->multiply = temp;
                    }
                }
                temp = temp->next;
            }
            ptr = ptr->next;
        }
    }
}

void traverse()
{
    struct Node *ptr = head;
    int i = 1;

    if (head == NULL)
    {
        printf("\n--------------------------------");
        printf("\nNo elements to display!");
        printf("\n--------------------------------");
    }
    else
    {
        printf("\nLinked list traversal");
        printf("\n--------------------------------");

        while (ptr != NULL)
        {
            printf("\nElement %d: %d", i++, ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    head = NULL;
    int choice, data;
    char ch = 'y';

    do
    {
        printf("\nMENU: \n1. Insert at start\n2. Insert at end\n3. Delete at start\n4. Delete at end\n5. Traverse & display\n6. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            fflush(stdin);

            insertAtEnd(data);
            break;
        case 2:
            traverse();
            break;
        case 3:
            exit(0);
        default:
            printf("\nWrong choice!");
        }

        printf("\n\nDo you want to enter again? (y/n): ");
        scanf("%c", &ch);
        fflush(stdin);

        if (ch != 'y' && ch != 'Y')
        {
            printf("\n********************************************");
            printf("\nTHANK YOU, SEE YOU AGAIN!");
            printf("\n********************************************\n");
        }

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
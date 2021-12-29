#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} * root;

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{

    struct Node *p = createNode(7);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(9);
    struct Node *p3 = createNode(0);
    struct Node *p4 = createNode(3);
    struct Node *p5 = createNode(8);
    struct Node *p7 = createNode(10);
    struct Node *p8 = createNode(2);
    struct Node *p9 = createNode(5);
    struct Node *p10 = createNode(4);
    struct Node *p11 = createNode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p7;
    p4->left = p8;
    p4->right = p9;
    p9->left = p10;
    p9->right = p11;
    printf("\n\n");
    inorderTraversal(p);
    printf("\n\n");

    return 0;
}
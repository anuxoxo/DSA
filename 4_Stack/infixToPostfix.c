#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *stk)
{
    if (stk->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *stk)
{
    if (stk->top == stk->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *stk, char value)
{
    if (!isFull(stk))
    {
        stk->top++;
        stk->arr[stk->top] = value;
    }
    else
    {
        printf("\nStack Full!");
    }
}

char pop(struct stack *stk)
{
    if (isEmpty(stk))
    {
        printf("\nStack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = stk->arr[stk->top];
        (stk->top)--;
        return val;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 20;
    stk->top = -1;
    stk->arr = (char *)malloc(stk->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(stk, '(');
            i++;
        }
        else if (infix[i] == ')')
        {
            while (stk->top != '(')
            {
                postfix[j++] = pop(stk);
            }
            pop(stk);
            i++;
        }
        else if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stk->arr[stk->top]))
            {
                push(stk, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(stk);
                j++;
            }
        }
    }

    while (!isEmpty(stk))
    {
        postfix[j] = pop(stk);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix, str[100];
    printf("\nEnter infix expression: ");
    gets(str);

    infix = str;

    printf("%s", infixToPostfix(infix));

    return 0;
}
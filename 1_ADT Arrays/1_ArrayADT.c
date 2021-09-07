#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *ptr, int totalSize, int usedSize)
{
    ptr->totalSize = totalSize;
    ptr->usedSize = usedSize;
    ptr->ptr = (int *)malloc(totalSize * sizeof(int));
}

void setVal(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &a->ptr[i]);
    }
}

void display(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\n", a->ptr[i]);
    }
}

int main()
{
    struct myArray array;

    createArray(&array, 10, 2);
    
    setVal(&array);
    display(&array);

    return 0;
}
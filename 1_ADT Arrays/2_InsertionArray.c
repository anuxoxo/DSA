#include <stdio.h>

int display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int capacity, int size, int i, int element)
{
    if (size < capacity && i < capacity)
    {
        for (int j = size; j >= i; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[i] = element;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[10] = {2, 42, 21, 45};
    int size = 4, index = 11;
    display(arr, size);

    int res = insert(arr, 10, size, index, 100);

    if (res)
    {
        size += 1;
        display(arr, size);
    }
    else
    {
        printf("\nArray overflown!");
    }
    return 0;
}
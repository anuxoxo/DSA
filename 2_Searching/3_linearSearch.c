#include <stdio.h>

int linearSearch(int arr[], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {91, 12, 73, 64, 52, 16, 37, 21, 19, 10};
    int search = 371;
    int res = linearSearch(arr, 10, search);

    if (res != -1)
    {
        printf("\nElement found at pos %d", res);
    }
    else
    {
        printf("\nElement not found!");
    }

    return 0;
}
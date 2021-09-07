#include <stdio.h>

int binarySearch(int arr[], int size, int search)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == search)
        {
            return mid;
        }
        else if (search <= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int search = 1;
    int res = binarySearch(arr, 10, search);

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
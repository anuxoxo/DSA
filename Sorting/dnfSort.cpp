#include <iostream>
using namespace std;

void dnfSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 0)
            swap(arr[low++], arr[mid++]);
        else
            swap(arr[mid], arr[high--]);
    }
}

int main()
{
    int arr[] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    dnfSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
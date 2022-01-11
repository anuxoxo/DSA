#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 1; i < n; i++)
        k = max(k, arr[i]);

    int count[k + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    int newArr[n];
    for (int i = n - 1; i >= 0; i--)
        newArr[--count[arr[i]]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = newArr[i];
}

void negCountSort(int arr[], int n)
{
    int k = arr[0], l = arr[0];
    for (int i = 1; i < n; i++)
    {
        k = max(k, arr[i]);
        l = min(l, arr[i]);
    }

    int count[k - l + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i] - l]++;

    for (int i = 1; i <= k - l + 1; i++)
        count[i] += count[i - 1];

    int newArr[n];
    for (int i = n - 1; i >= 0; i--)
        newArr[--count[arr[i] - l]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = newArr[i];
}

int main()
{
    // int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int arr[] = {-1, -1, 2, 0, 1, 1, -2, -2, 2};

    negCountSort(arr, 9);
    // countSort(arr, 9);

    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";

    return 0;
}
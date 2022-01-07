#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int i, int key)
{
    if (arr[i] == key)
        return i;
    else if (i == n)
        return -1;

    return firstOccurrence(arr, n, i + 1, key);
}

int lastOccurrence(int arr[], int i, int key)
{
    if (arr[i] == key)
        return i;
    else if (i < 0)
        return -1;

    return lastOccurrence(arr, i - 1, key);
}

int main()
{
    int n = 7, arr[n] = {2, 4, 1, 4, 5, 4, 6};
    cout << firstOccurrence(arr, n, 0, 4) << endl;
    cout << lastOccurrence(arr, n - 1, 4) << endl;
    return 0;
}
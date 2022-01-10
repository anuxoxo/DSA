#include <iostream>
using namespace std;
void Merge(int arr[], int l, int mid, int r)
{
    int a[r - l + 1];
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++];
    }

    while (i <= mid)
        a[k++] = arr[i++];
    while (j <= r)
        a[k++] = arr[j++];

    for (int i = l; i <= r; i++)
    {
        arr[i] = a[i];
    }
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
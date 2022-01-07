#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 1)
        return true;

    return (arr[0] < arr[1]) && (isSorted(arr + 1, n - 1));
}

int main()
{
    int n = 5, arr[n] = {1, 2, 3, 4, 5};
    cout << isSorted(arr, n);

    return 0;
}
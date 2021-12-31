#include <iostream>
using namespace std;

bool pairSum(int arr[], int n, int k)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] < k)
            low++;
        else if (arr[low] + arr[high] > k)
            high--;
        else if (arr[low] + arr[high] == k)
        {
            cout << low << " : " << arr[low] << ", " << high << " : " << arr[high] << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // sort array, if not-> sort first
    }
    cout << pairSum(arr, n, k);
    return 0;
}
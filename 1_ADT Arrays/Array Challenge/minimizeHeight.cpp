#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    // code here
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    for (int i = 0; i < n - 1; i++)
    {
        int mn = min(smallest, arr[i + 1] - k);
        int mx = max(largest, arr[i] + k);
        if (mn < 0)
            continue;
        ans = min(ans, mx - mn);
    }
    return ans;
}

int main()
{
    int arr[10] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    cout << getMinDiff(arr, 10, 10);
    return 0;
}
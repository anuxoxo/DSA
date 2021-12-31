#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e5;
    int idx[N], minIndex = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == -1)
        {
            idx[arr[i]] = i;
        }
        else
        {
            minIndex = min(minIndex, idx[arr[i]]);
        }
    }

    if (minIndex == INT_MAX)
        cout << -1 << endl;
    else
        cout << minIndex + 1 << endl;

    return 0;
}
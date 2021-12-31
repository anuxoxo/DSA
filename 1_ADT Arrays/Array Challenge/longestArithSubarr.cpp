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

    int maxLen = 2, currLen = 2, prevD = arr[0] - arr[1];

    for (int i = 1; i < n - 1; i++)
    {
        if (prevD == arr[i] - arr[i + 1])
        {
            currLen++;
        }
        else
        {
            prevD = arr[i] - arr[i + 1];
            currLen = 2;
        }

        maxLen = max(maxLen, currLen);
    }

    cout << maxLen << endl;

    return 0;
}
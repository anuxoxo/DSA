#include <iostream>
#include <climits>
using namespace std;

int Kadane(int arr[], int n)
{
    int cs = 0, ms = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
            cs = 0;
        ms = max(cs, ms);
    }
    return ms;
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

    int wrapsum, nonwrapsum, ts = 0;

    nonwrapsum = Kadane(arr, n);

    for (int i = 0; i < n; i++)
    {
        ts += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = ts + Kadane(arr, n);

    cout << max(wrapsum, nonwrapsum) << endl;

    return 0;
}
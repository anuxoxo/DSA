#include <bits/stdc++.h>
using namespace std;

int func(int a[], int n)
{
    if (n == 1)
        return n;

    int mx = 0, gcd = 0, mul = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            gcd = __gcd(mul, a[j]);
            mul *= a[j];

            if (gcd == 1)
                mx = max(mx, j - i + 1);
            else
                break;
        }
    }
    return mx;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << func(arr, n) << endl;
    }

    return 0;
}
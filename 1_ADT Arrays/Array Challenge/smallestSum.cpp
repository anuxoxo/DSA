#include <iostream>
#include <algorithm>
using namespace std;

long long int minValue(int a[], int b[], int n)
{
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] * b[i] << endl;
    }

    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i] + b[i];
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << minValue(a, b, n);
    return 0;
}
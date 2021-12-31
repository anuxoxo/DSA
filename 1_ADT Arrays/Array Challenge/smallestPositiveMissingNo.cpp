#include <iostream>
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
    bool num[N] = {false};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            num[arr[i]] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (!num[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
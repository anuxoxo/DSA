#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = -1;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int maxRec = -1, count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] > maxRec && arr[i] > arr[i + 1]))
        {
            count++;
        }

        maxRec = max(maxRec, arr[i]);
    }

    cout << count;

    return 0;
}
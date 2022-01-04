#include <iostream>
#define N 10
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i = 0, j = n - 1, flag = 0;
    while (i < n && j >= 0)
    {

        if (arr[i][j] == t)
        {
            flag = 1;
            break;
        }
        else if (arr[i][j] > t)
            j--;
        else
            i++;
    }
    if (flag)
        cout << true;
    else
        cout << false;
    return 0;
}
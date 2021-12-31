#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0, i = 0, j = 0;

    while (j < n && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }

    if (sum == s)
    {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
    }

    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }

        j++;
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, s;
//     cin >> n >> s;

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == s)
//             {
//                 cout << i + 1 << " " << j + 1 << endl;
//                 return 0;
//             }
//         }
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter n : ";
    cin >> n;
    cout << "\nPrime numbers are : " << endl;
    for (int num = 2; num <= n; num++)
    {
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                num++;
                i = 2;
            }
            else
            {
                continue;
            }
        }

        cout << ++count << " : " << num << endl;
    }

    return 0;
}
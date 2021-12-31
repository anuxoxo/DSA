#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}
int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << factorial(i) / (factorial(i - j) * factorial(j)) << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int reverse(int n)
{
    int res = 0;
    while (n > 0)
    {
        int rem = n % 10;
        res = res * 10 + rem;
        n /= 10;
    }
    return res;
}

void maxF()
{
    int a = 2, b = 3;
    int maxN = INT_MAX, min = INT_MIN;
    cout << max(a, b);
}

int binAdd(int a, int b)
{
    int c = 0, res = 0;

    while (a > 0 && b > 0)
    {
        if (a % 10 == 0 && b % 10 == 0)
        {
            res = res * 10 + c;
            c = 0;
        }
        else if ((a % 10 == 0 && b % 10 == 1) || (a % 10 == 1 && b % 10 == 0))
        {
            if (c)
            {
                c = 1;
            }
            else
            {
                res = res * 10 + 1;
                c = 0;
            }
        }
        else
        {
            res = res * 10 + c;
            c = 1;
        }

        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {
        if (c)
        {
            if (a % 10 == 1)
            {
                c = 1;
            }
            else
            {
                res = res * 10 + 1;
                c = 0;
            }
        }
        else
        {
            res = res * 10 + a % 10;
        }
        a /= 10;
    }
    while (b > 0)
    {
        res *= 10;
        if (c)
        {
            if (b % 10 == 1)
            {
                c = 1;
            }
            else
            {
                res = res * 10 + 1;
                c = 0;
            }
        }
        else
        {
            res = res * 10 + b % 10;
        }
        b /= 10;
    }

    if (c)
    {
        res = res * 10 + c;
    }

    return reverse(res);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << binAdd(a, b);
    // maxF();
    return 0;
}
// Write your code here
#include <iostream>

using namespace std;

int main()
{
    int a, b, c = 1;
    cin >> a >> b;
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0)
            c++;
    }

    cout << c;
}
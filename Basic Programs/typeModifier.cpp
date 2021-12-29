#include <iostream>
using namespace std;

int main()
{
    int a, sum = 0;
    do
    {
        cout << "Enter a : ";
        cin >> a;

        if (a >= 0)
            sum += a;

    } while (a >= 0);
    cout << "\nSum = " << sum << endl;
    return 0;
}
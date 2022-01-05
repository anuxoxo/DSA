#include <iostream>
using namespace std;

int ispowerof2(int n)
{
    return (n && !(n & n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << ispowerof2(n) << endl;

    return 0;
}
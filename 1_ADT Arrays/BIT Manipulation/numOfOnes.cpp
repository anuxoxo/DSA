#include <iostream>
using namespace std;

int numOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << numOfOnes(n);

    return 0;
}
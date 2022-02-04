#include <bits/stdc++.h>
using namespace std;

int findLargestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}

int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = findLargestPower(n);
    return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
}

int main()
{
    int N = 4;
    cout << countSetBits(N) << endl;
    return 0;
}

// Input:
// N = 3
// M[][] = {{1, 1, 0},        {1, 1, 0},        {1, 1, 0}}
// Output:2
// Explanation:2nd column (0-based indexing) is having 3 zeros which is maximum among all columns.
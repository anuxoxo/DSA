#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return (((1 << pos) & n) != 0);
}

int setBit(int n, int pos)
{
    return ((1 << pos) | n);
}

int clearBit(int n, int pos)
{
    return (~(1 << pos) & n);
}

int updateBit(int n, int pos, int val)
{
    n = clearBit(n, pos);
    return (val << pos) | n;
}

int main()
{
    int n, pos;
    cin >> n >> pos;
    // cout << getBit(n, pos) << endl;
    // cout << setBit(n, pos) << endl;
    // cout << clearBit(n, pos) << endl;
    cout << updateBit(n, pos, 0) << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int c = 1;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c++ << " ";
        }
        cout << endl;
    }

    return 0;
}
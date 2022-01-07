#include <iostream>
using namespace std;

void towerofHanoi(int n, char src, char dest, char aux)
{
    if (n == 0)
        return;
        
    towerofHanoi(n - 1, src, aux, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, aux, dest, src);
}

int main()
{
    towerofHanoi(3, 'A', 'B', 'C');
    return 0;
}
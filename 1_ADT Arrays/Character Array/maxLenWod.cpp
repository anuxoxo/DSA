#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char str[n + 1];
    cin.getline(str, n);
    cin.ignore();

    int len = 0, maxL = 0, s = 0, maxS = 0;
    for (int i = 0;; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (len > maxL)
            {
                maxS = s;
                maxL = len;
            }

            len = 0;
            s = i + 1;
        }
        else
            len++;

        if (str[i] == '\0')
            break;
    }

    cout << maxL << endl;
    for (int i = maxS; i < maxS + maxL; i++)
    {
        cout << str[i];
    }

    return 0;
}
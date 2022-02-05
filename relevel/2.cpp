#include <bits/stdc++.h>
using namespace std;
int count(string s)
{
    int c = 0, mc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
        {
            c++;
            mc = max(mc, c);
        }
        else
            c = 0;
    }
    return mc;
}

int func(string s)
{
    int mc = 0, c = 0, b = 0;
    c = count(s);
    mc = max(mc, c);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
        {
            b = i;
            break;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        string temp = s;
        if (s[i] == 'G')
        {
            char ch = temp[b];
            temp[b] = temp[i];
            temp[i] = ch;

            c = count(temp);
            mc = max(mc, c);
        }
    }
    return mc;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << func(s) << endl;
    return 0;
}
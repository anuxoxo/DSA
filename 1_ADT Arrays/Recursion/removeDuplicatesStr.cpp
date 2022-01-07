#include <iostream>
using namespace std;

string remDup(string s)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string ans = remDup(s.substr(1));

    if (ch == ans[0])
        return ans;

    return ch + ans;
}

int main()
{
    string s = "aaaaabbbbbbeccccdd";
    cout << remDup(s);
    return 0;
}
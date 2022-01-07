#include <iostream>
#include <string>
// #include <algorithm>
using namespace std;

void reverse(string s)
{
    if (s.length() == 0)
        return;

    reverse(s.substr(1));
    cout << s[0];
}

int main()
{
    string s = "binod";
    reverse(s);
    // reverse(s.begin(), s.end());
    // cout << s;
    return 0;
}
#include <iostream>
using namespace std;

void substrWithAscii(string s, string ans = "")
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int ascii = ch;
    substrWithAscii(s.substr(1), ans);
    substrWithAscii(s.substr(1), ans + ch);
    substrWithAscii(s.substr(1), ans + to_string(ascii));
}

int main()
{
    string s = "AB";
    substrWithAscii(s);
    return 0;
}
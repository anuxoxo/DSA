#include <iostream>
using namespace std;

void replaceStr(string s, string target, string replaceSubstr)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'p' && s[i + 1] == 'i')
        {
            s.replace(i, 2, replaceSubstr);
        }
    }

    cout << s << endl;
}

int main()
{
    string str = "pippxxppiixipi";
    // str.replace(0, 3, "Sak");
    // cout<<str;
    replaceStr(str, "pi", "3.14");
    return 0;
}
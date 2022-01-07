#include <iostream>
using namespace std;

string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans = "")
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string word = arr[ch - '0'];

    for (int i = 0; i < word.length(); i++)
    {
        keypad(s.substr(1), ans + word[i]);
    }
}

int main()
{
    keypad("23", "");
    return 0;
}

// #include <iostream>
// using namespace std;

// string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void keypad(int l, int h)
// {
//     for (int i = 0; i < arr[l].length(); i++)
//     {
//         for (int j = 0; j < arr[h].length(); j++)
//         {
//             cout << arr[l][i] << arr[h][j] << endl;
//         }
//     }
// }

// int main()
// {
//     keypad(2, 3);
//     return 0;
// }
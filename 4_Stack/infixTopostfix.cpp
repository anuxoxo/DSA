#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str)
{
    stack<char> st;
    string res = "";

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            st.push('(');
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
string infixToPrefix(string str)
{
    stack<char> st;
    string res = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            res += str[i];
        }
        else if (str[i] == ')')
        {
            st.push(')');
        }
        else if (str[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;
    cout << infixToPrefix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}
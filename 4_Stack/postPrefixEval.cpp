#include <iostream>
#include <stack>
using namespace std;

int prefixEval(string s)
{
    stack<int> stk;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            stk.push(s[i] - '0');
        }
        else
        {
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();

            switch (s[i])
            {
            case '+':
                stk.push(op1 + op2);
                break;
            case '-':
                stk.push(op1 - op2);
                break;
            case '*':
                stk.push(op1 * op2);
                break;
            case '/':
                stk.push(op1 / op2);
                break;
            case '^':
                stk.push(op1 ^ op2);
                break;
            }
        }
    }
    return stk.top();
}

int postEval(string str)
{
    stack<int> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(op1 + op2);
                break;

            case '-':
                s.push(op1 - op2);
                break;

            case '*':
                s.push(op1 * op2);
                break;

            case '/':
                s.push(op1 / op2);
                break;

            case '^':
                s.push(op1 ^ op2);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    cout << prefixEval("-+7*45+20") << endl;
    cout << postEval("46+2/5*7+");

    return 0;
}
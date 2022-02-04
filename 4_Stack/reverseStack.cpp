#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int el)
{
    if (s.empty())
    {
        s.push(el);
        // cout << "TOP " << s.top() << endl;
        return;
    }
    int topel = s.top();
    s.pop();
    insertAtBottom(s, el);
    s.push(topel);
    // cout << "TOP last " << s.top() << endl;
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int el = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, el);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
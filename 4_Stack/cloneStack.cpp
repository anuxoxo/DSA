#include <iostream>
#include <stack>
using namespace std;

// clone stack without using extra space

void cloneStk(stack<int> &st, stack<int> &clone)
{
    if (st.empty())
        return;

    int x = st.top();
    st.pop();

    cloneStk(st, clone);

    clone.push(x);
}

int main()
{
    stack<int> st, clone;
    st.push(1);
    st.push(2);
    st.push(3);

    cloneStk(st, clone);

    while (!clone.empty())
    {
        cout << clone.top() << endl;
        clone.pop();
    }
    return 0;
}
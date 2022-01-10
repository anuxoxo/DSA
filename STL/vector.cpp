#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(18);
    v.push_back(14);
    v.push_back(7);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto element : v)
        cout << element << " ";
    cout << endl;

    v.pop_back();

    vector<int> v2(3, 22); // 22 22 22

    swap(v, v2);

    for (auto element : v)
        cout << element << " ";
    cout << endl;
    for (auto element : v2)
        cout << element << " ";
    cout << endl;

    v2.push_back(38);

    sort(v2.begin(), v2.end());
    for (auto element : v2)
        cout << element << " ";
    cout << endl;
    sort(v2.begin(), v2.end(), greater<int>());
    for (auto element : v2)
        cout << element << " ";
    cout << endl;
    return 0;
}
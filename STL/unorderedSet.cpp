#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int nums1[] = {4, 9, 5},
        nums2[] = {9, 4, 9, 8, 4};

    unordered_map<int, int> u;
    vector<int> v;


    for (int i = 0; i < 5; i++)
    {
        u[nums2[i]]++;
    }

    for (auto x : u)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}

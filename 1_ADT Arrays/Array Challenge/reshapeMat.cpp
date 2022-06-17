#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    if (mat.size() == 0)
        return mat;

    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c)
        return mat;

    vector<vector<int>> newM(r);
    for (int i = 0; i < r; i++)
    {
        newM[i] = vector<int>(c);
    }

    int row = 0, col = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newM[row][col++] = mat[i][j];
            if (col >= c)
            {
                row++;
                col = 0;
            }
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> v(2);
    vector<vector<int>> v1(2);

    for (int i = 0; i < 2; i++)
    {
        v[i] = vector<int>(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < 1; i++)
    {
        v1[i] = vector<int>(4);
    }

    v1 = matrixReshape(v, 1, 4);

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
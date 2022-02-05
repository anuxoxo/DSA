#include <iostream>
using namespace std;

int main()
{
    vector<

        vector>

    performOps(vector<vector> & A)
    {

        vector<

            vector>

            B;

        B.resize(A.size());

        for (int i = 0; i < A.size(); i++)
        {

            B[i].resize(A[i].size());

            for (int j = 0; j < A[i].size(); j++)
            {

                B[i][A[i].size() - 1 - j] = A[i][j];
            }
        }

        return B;
    }

    // Lets say performOps was called with A : [ [ 1, 2, 3, 4 ], [ 5, 6, 7, 8 ], [ 9, 10, 11, 12 ] ].

    //                                         What would be the output of the following call :

    //     vector <

    // vector >

    B = performOps(A);

    for (int i = 0; i < B.size(); i++)
    {

        for (int j = 0; j < B[i].size(); j++)
            cout < <

                B[i][j] < <

                " ";
    }
    return 0;
}
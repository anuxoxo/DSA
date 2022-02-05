int Solution::solve(vector<int> &A, int B)
{
    int count = 0, i = 0, n = A.size();

    while (i < n)
    {
        int pos = -1;
        for (int j = max(0, i - B + 1); j <= min(n, i + B - 1); j++)
        {
            if (A[j] == 1)
                pos = j;
        }

        if (pos == -1)
            return -1;

        count++;
        i = pos + B;
    }
    return count;
}

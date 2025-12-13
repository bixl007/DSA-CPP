#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix.size();

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX;
                int right = INT_MAX;
                int down = INT_MAX;
                if (j > 0)
                {
                    left = matrix[i + 1][j - 1];
                }
                if (j < n - 1)
                {
                    right = matrix[i + 1][j + 1];
                }
                down = matrix[i + 1][j];

                matrix[i][j] += min(left, min(right, down));
            }
        }
        int mini = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            mini = min(mini, matrix[0][i]);
        }
        return mini;
    }
};
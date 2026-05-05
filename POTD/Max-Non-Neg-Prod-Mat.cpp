#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid.size();
        int MOD = 1e9 + 7;

        vector<vector<long long>> maxi;
        vector<vector<long long>> mini;

        maxi[0][0] = mini[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
        {
            maxi[0][i] = mini[0][i] = maxi[0][i - 1] * grid[0][i];
        }

        for (int i = 1; i < m; i++)
        {
            maxi[i][0] = mini[i][0] = maxi[i - 1][0] * grid[0][i];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                long long a = grid[i][j] * mini[i - 1][j];
                long long b = grid[i][j] * mini[i][j - 1];
                long long c = grid[i][j] * maxi[i - 1][j];
                long long d = grid[i][j] * maxi[i][j - 1];

                maxi[i][j] = max({a, b, c, d});
                mini[i][j] = min({a, b, c, d});
            }
        }

        if (maxi[m - 1][n - 1] < 0)
            return -1;
        return maxi[m - 1][n - 1] % MOD;
    }
};

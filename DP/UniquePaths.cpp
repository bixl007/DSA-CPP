#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m && j == n)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = 0, right = 0;
        if (i < m)
            down = solve(i + 1, j, m, n, dp);

        if (j < n)
            right = solve(i, j + 1, m, n, dp);

        return dp[i][j] = (down + right);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m - 1, n - 1, dp);
    }
};

// Tabulation

class Solution
{
private:
    int solve(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            dp[i][n - 1] = 1;
        }

        for(int i = 0; i < n; i++) {
            dp[m - 1][i] = 1;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m, n);
    }
};


// SO
class Solution
{
private:
    int solve(int m, int n)
    {
        vector<int> row(n, 1);

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                row[j] = row[j] + row[j + 1];
            }
        }
        return row[0];
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m, n);
    }
};

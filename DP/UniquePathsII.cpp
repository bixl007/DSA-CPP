#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == m && j == n && grid[i][j] != 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = 0, right = 0;
        if (i < m && grid[i + 1][j] != 1)
            down = solve(i + 1, j, m, n, grid, dp);

        if (j < n && grid[i][j + 1] != 1)
            right = solve(i, j + 1, m, n, grid, dp);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m - 1, n - 1, obstacleGrid, dp);
    }
};

// Tablulation

class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        return solve(0, 0, m, n, obstacleGrid);
    }
};

// SO

class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        vector<int> row(n, 0);
        row[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    row[j] = 0;
                    continue;
                }
                if (j > 0)
                    row[j] += row[j - 1];
            }
        }
        return row[n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        return solve(0, 0, m, n, obstacleGrid);
    }
};

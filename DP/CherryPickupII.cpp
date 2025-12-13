#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 > n - 1 || j2 < 0 || j2 > n - 1)
            return -1e8;
        if (i == m - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;
        for (int r1 = -1; r1 <= 1; r1++)
        {
            for (int r2 = -1; r2 <= 1; r2++)
            {
                if (j1 == j2)
                {
                    maxi = max(maxi, grid[i][j2] + solve(i + 1, j1 + r1,
                                                         j2 + r2, m, n, grid, dp));
                }
                else
                    maxi = max(maxi,
                               grid[i][j1] + grid[i][j2] +
                                   solve(i + 1, r1 + j1, r2 + j2, m, n, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(0, 0, n - 1, m, n, grid, dp);
    }
};

// Tablulation

class Solution
{
private:
    int solve(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int r1 = 0; r1 < n; r1++)
        {
            for (int r2 = 0; r2 < n; r2++)
            {
                if (r1 == r2)
                {
                    dp[m - 1][r1][r2] = grid[m - 1][r1];
                }
                else
                    dp[m - 1][r1][r2] = grid[m - 1][r1] + grid[m - 1][r2];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {
                    int maxi = -1e8;
                    for (int r1 = -1; r1 <= 1; r1++)
                    {
                        for (int r2 = -1; r2 <= 1; r2++)
                        {
                            if (j1 + r1 >= 0 && j1 + r1 < n && j2 + r2 >= 0 && j2 + r2 < n)
                            {

                                if (j1 == j2)
                                {
                                    maxi = max(maxi, grid[i][j2] + dp[i + 1][j1 + r1][j2 + r2]);
                                }
                                else
                                    maxi = max(maxi,
                                               grid[i][j1] + grid[i][j2] +
                                                   dp[i + 1][r1 + j1][r2 + j2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n - 1];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        return solve(grid);
    }
};

// SO


class Solution
{
private:
    int solve(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> curr(n, vector<int>(n, 0));
        vector<vector<int>> next(n, vector<int>(n, 0));

        for (int r1 = 0; r1 < n; r1++)
        {
            for (int r2 = 0; r2 < n; r2++)
            {
                if (r1 == r2)
                {
                    next[r1][r2] = grid[m - 1][r1];
                }
                else
                    next[r1][r2] = grid[m - 1][r1] + grid[m - 1][r2];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {
                    int maxi = -1e8;
                    for (int r1 = -1; r1 <= 1; r1++)
                    {
                        for (int r2 = -1; r2 <= 1; r2++)
                        {
                            if (j1 + r1 >= 0 && j1 + r1 < n && j2 + r2 >= 0 && j2 + r2 < n)
                            {

                                if (j1 == j2)
                                {
                                    maxi = max(maxi, grid[i][j2] + next[j1 + r1][j2 + r2]);
                                }
                                else
                                    maxi = max(maxi,
                                               grid[i][j1] + grid[i][j2] +
                                                   next[r1 + j1][r2 + j2]);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            next = curr;
        }
        return next[0][n - 1];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        return solve(grid);
    }
};
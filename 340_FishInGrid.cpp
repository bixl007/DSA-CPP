#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
        {
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        temp += solve(i + 1, j, grid);
        temp += solve(i - 1, j, grid);
        temp += solve(i, j + 1, grid);
        temp += solve(i, j - 1, grid);
        return temp;
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }
        return ans;
    }
};

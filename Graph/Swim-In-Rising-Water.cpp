#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto itr = pq.top();
            int val = itr[0];
            int i = itr[1];
            int j = itr[2];
            pq.pop();

            if (i == n - 1 && j == n - 1)
                return val;

            for (int it = 0; it < 4; it++)
            {
                int nr = i + dr[it];
                int nc = j + dc[it];

                if (nr >= 0 && nr <= n - 1 && nc >= 0 && nc <= n - 1 && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    pq.push({max(val, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};

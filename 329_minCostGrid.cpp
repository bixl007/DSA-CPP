#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int bfs(vector<vector<pair<int, int>>> &adj)
    {
        int n = adj.size();
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        vector<int> dis(n, 1e9);
        dis[0] = 0;
        while (!q.empty())
        {
            auto [currNode, currCost] = q.front();
            q.pop_front();
            for (auto it : adj[currNode])
            {
                auto [nbr, nbrCost] = it;
                if (currCost + nbrCost < dis[nbr])
                {
                    dis[nbr] = currCost + nbrCost;
                    if (nbrCost == 0)
                    {
                        q.push_front({nbr, dis[nbr]});
                    }
                    else
                    {
                        q.push_back({nbr, dis[nbr]});
                    }
                }
            }
        }
        return dis[n - 1];
    }

public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> adj(n * m);
        int nodeCnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == n - 1 && j == m - 1)
                    continue;
                if (j + 1 < m)
                {
                    if (grid[i][j] == 1)
                        adj[nodeCnt].push_back({nodeCnt + 1, 0});
                    else
                        adj[nodeCnt].push_back({nodeCnt + 1, 1});
                }
                if (j - 1 >= 0)
                {
                    if (grid[i][j] == 2)
                        adj[nodeCnt].push_back({nodeCnt - 1, 0});
                    else
                        adj[nodeCnt].push_back({nodeCnt - 1, 1});
                }
                if (i + 1 < n)
                {
                    if (grid[i][j] == 3)
                        adj[nodeCnt].push_back({nodeCnt + m, 0});
                    else
                        adj[nodeCnt].push_back({nodeCnt + m, 1});
                }
                if (i - 1 >= 0)
                {
                    if (grid[i][j] == 4)
                        adj[nodeCnt].push_back({nodeCnt - m, 0});
                    else
                        adj[nodeCnt].push_back({nodeCnt - m, 1});
                }
                nodeCnt++;
            }
        }

        int ans = bfs(adj);
        return ans;
    }
};
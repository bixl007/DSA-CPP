#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Disjoint
{
public:
    vector<int> parent, size;
    Disjoint(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionSize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    bool isValid(int r, int c, int n, int m)
    {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        Disjoint ds(n * m);

        vector<int> res;
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;

        for (auto itr : operators)
        {
            int row = itr[0], col = itr[1];
            if (vis[row][col])
            {
                res.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;

            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (isValid(nr, nc, n, m))
                {
                    if (vis[nr][nc])
                    {
                        int nkey = row * m + col;
                        int adjKey = nr * m + nc;

                        if (ds.findUPar(nkey) != ds.findUPar(adjKey))
                        {
                            cnt--;
                            ds.unionSize(nkey, adjKey);
                        }
                    }
                }
            }
            res.push_back(cnt);
        }

        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;

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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        Disjoint ds(n);
        int extra = 0;

        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v))
            {
                extra++;
            }
            else
            {
                ds.unionSize(u, v);
            }
        }

        int comp = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                comp++;
        }
        int needed = comp - 1;

        if (needed <= extra)
            return needed;
        return -1;
    }
};
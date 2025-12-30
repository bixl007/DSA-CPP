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

// User function Template for C++
class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[2] < b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // code here
        sort(edges.begin(), edges.end(), comp);

        Disjoint d(V);

        int mxWt = 0;

        for (auto it : edges)
        {
            int node1 = it[0];
            int node2 = it[1];
            int wt = it[2];

            if (d.findUPar(node1) != d.findUPar(node2))
            {
                mxWt += wt;
                d.unionSize(node1, node2);
            }
        }

        return mxWt;
    }
};
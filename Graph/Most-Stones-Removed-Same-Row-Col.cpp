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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxR = -1;
        int maxC = -1;
        
        for(auto it : stones) {
            maxR = max(it[0], maxR);
            maxC = max(it[1], maxC);
        }

        int n = stones.size();
        Disjoint ds(maxR + maxC + 1);
        unordered_set<int> stoneNodes;

        for(auto it : stones) {
            int u = it[0];
            int v = it[1] + maxR + 1;
            ds.unionSize(u, v);
        }

        for(auto it : stones) {
            stoneNodes.insert(ds.findUPar(it[0]));
        }

        return n - stoneNodes.size();
        
    }
};
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> parent, rank, size;
    Disjoint(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
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

    void unionRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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

int main()
{
    Disjoint ds(7);

    ds.unionSize(1, 2);
    ds.unionSize(2, 3);
    ds.unionSize(4, 5);
    ds.unionSize(6, 7);
    ds.unionSize(5, 6);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same component!" << endl;
    }
    else
    {
        cout << "Different components" << endl;
    }

    ds.unionSize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same component!" << endl;
    }
    else
    {
        cout << "Different components" << endl;
    }
    return 0;
}
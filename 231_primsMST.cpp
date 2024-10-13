#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX); // n + 1 because the starting value is 1 not 0.
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;
    parent[1] = -1;

    // Find minimum node from key vector
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u = -1;

        for (int j = 0; j <= n; j++)
        {
            if (mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }

        // Mark mst as true for minimum node
        mst[u] = true;

        // Check adjacent nodes of minimum node
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) // Since we need to exclude the first element and the value starts from 1
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // run loop for n - 1 times
    for (int i = 0; i < n - 1; i++)
    {

        // Traverse on edges List
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if ((dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for -ve cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if ((dist[u] + w < dist[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return dist;
    }
    return dist;
}
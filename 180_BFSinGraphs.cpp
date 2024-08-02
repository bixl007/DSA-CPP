#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;

    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    unordered_map<int, bool> visited;
    vector<int> ans;

    bfs(adj, ans, visited, 0);

    return ans;
}
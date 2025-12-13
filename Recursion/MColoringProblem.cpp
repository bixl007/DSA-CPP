#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int node, vector<int> &col, vector<vector<int>> &adj, int v, int i) {
        for(int k = 0; k < v; k++) {
            if(k != node && adj[k][node] == 1 && col[k] == i)
                return false;
        }
        return true;
    }

    bool solve(int node, vector<int> &col, vector<vector<int>> &adj, int m, int v) {
        if(node == v)
            return true;
        
        for (int i = 0; i <= m; i++)
        {
            if(isSafe(node, col, adj, v, i)) {
                col[node] = i;
                solve(node + 1, col, adj, m, v);
                col[node] = 0;
            }
        }
        
    }
public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<int> col(v, 0);
        vector<vector<int>> adj(v, vector<int>(v, 0));
        for (auto i : edges)
        {
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
        }
        

        return solve(0, col, adj, m, v);
    
    }
};
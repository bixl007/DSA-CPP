#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int &i, int &j, int &n)
    {

        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= n)
            return false;

        return true;
    }

    void addInitialIslands(vector<vector<int>> grid,
                           DisjointSet &ds, int n)
    {

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++)
                {

                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1)
                    {

                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {

        int n = grid.size();

        DisjointSet ds(n * n);

        addInitialIslands(grid, ds, n);

        int ans = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                if (grid[row][col] == 1)
                    continue;

                set<int> components;

                for (int ind = 0; ind < 4; ind++)
                {

                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1)
                    {

                        int nodeNumber = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNumber));
                    }
                }

                int sizeTotal = 0;

                for (auto it : components)
                {

                    sizeTotal += ds.size[it];
                }

                ans = max(ans, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {

            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }

        return ans;
    }
};

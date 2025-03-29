#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> v(r, vector<int>(c));
        queue<int> q;
        if (m * n == r * c)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    q.push(mat[i][j]);
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    v[i][j] = q.front();
                    q.pop();
                }
            }
            return v;
        }
        return mat;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> first, second;
            for (int j = 0; j < n; j++)
            {
                first.insert(matrix[i][j]);
                second.insert(matrix[j][i]);
            }
            if (n != first.size() || n != second.size())
                return false;
        }
        return true;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> rows(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                rows[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(rows);
        }
        return res;
    }
};
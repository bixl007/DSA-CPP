#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res;
        vector<int> ans;
        int counter = 0;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> rows(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                rows[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            if (counter == rowIndex)
                return rows;
            counter++;
            res.push_back(rows);
            ans = rows;
        }
        return ans;
    }
};
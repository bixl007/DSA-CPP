#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ans = {-1, -1};
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    cnt++;
            }

            if (ans[1] < cnt)
            {
                ans[0] = i;
                ans[1] = cnt;
            }
        }
        return ans;
    }
};
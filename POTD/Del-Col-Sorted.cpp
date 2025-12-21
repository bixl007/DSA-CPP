#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> sorted(n - 1, false);
        int cnt = 0;

        for (int col = 0; col < m; col++)
        {
            bool checker = false;
            for (int i = 0; i < n; i++)
            {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col])
                {
                    checker = true;
                    break;
                }
            }

            if (checker)
                cnt++;
            else
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (strs[i][col] < strs[i + 1][col])
                        sorted[i] = true;
                }
            }
        }
        return cnt;
    }
};
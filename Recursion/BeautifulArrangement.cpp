#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, vector<bool> &arr, int n)
    {
        if (idx == n + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (!arr[i])
                    return 0;
            }

            return 1;
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i])
            {
                continue;
            }

            if (i % idx == 0 || idx % i == 0)
            {
                arr[i] = 1;
                cnt += solve(idx + 1, arr, n);
                arr[i] = 0;
            }
        }
        return cnt;
    }
    int countArrangement(int n)
    {
        vector<bool> arr(n + 1, false);
        return solve(1, arr, n);
    }
};
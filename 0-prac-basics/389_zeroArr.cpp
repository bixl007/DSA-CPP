#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), sum = 0, cnt = 0;
        vector<int> diff(n + 1);

        for (int i = 0; i < n; i++)
        {
            while (sum + diff[i] < nums[i])
            {
                cnt++;
                if (cnt > queries.size())
                    return -1;

                int left = queries[cnt - 1][0],
                    right = queries[cnt - 1][1],
                    value = queries[cnt - 1][2];
                if (right >= i)
                {
                    diff[max(left, i)] += value;
                    if (right + 1 < diff.size())
                    {
                        diff[right + 1] -= value;
                    }
                }
            }
            sum += diff[i];
        }
        return cnt;
    }
};

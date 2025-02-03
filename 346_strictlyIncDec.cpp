#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int stInc = 1, stDec = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                stInc++;
                stDec = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                stDec++;
                stInc = 1;
            }
            else
            {
                stDec = 1;
                stInc = 1;
            }
            ans = max(ans, max(stInc, stDec));
        }

        return ans;
    }
};
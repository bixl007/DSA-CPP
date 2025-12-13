#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int left = -1, right = -1;
        int maxi = nums[0], mini = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < maxi)
                right = i;
            maxi = max(maxi, nums[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > mini)
                left = i;
            mini = min(mini, nums[i]);
        }

        return (left == -1) ? 0 : (right - left + 1);
    }
};
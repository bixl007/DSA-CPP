#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        sort(nums.begin(), nums.end());

        int l = 0, r = 0, mini = n - 1;

        while (r < n)
        {
            while (nums[r] > k * nums[l] && l < r)
                l++;
            int len = r - l + 1;
            mini = min(mini, n - len);
            r++;
        }

        return mini;
    }
};
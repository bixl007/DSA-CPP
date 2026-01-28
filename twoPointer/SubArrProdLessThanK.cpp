#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        if (k <= 1)
            return 0;

        int l = 0, r = 0, n = nums.size();
        long long mul = 1, ways = 0;

        for (int r = 0; r < n; r++)
        {
            mul *= nums[r];

            while (mul >= k)
            {
                mul /= nums[l];
                l++;
            }

            ways += (r - l + 1);
        }
        return ways;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size() - 1;
        if (nums.size() == 1)
            return 0;

        int diff = nums[n] - k - (nums[0] + k);

        if (diff < 0)
            return 0;

        return diff;
    }
};
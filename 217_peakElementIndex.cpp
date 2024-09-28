#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int maxi = INT_MIN;

        if (nums.size() == 1)
            return 0;

        for (auto i : nums)
        {
            if (i > maxi)
                maxi = max(maxi, i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxi)
            {
                return i;
            }
        }
        return -1;
    }
};
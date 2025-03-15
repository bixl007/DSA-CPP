#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(vector<int> &nums, int k, int mid)
    {
        int cnt = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= mid)
            {
                cnt++;
                i += 2;
            }
            else
                i++;
        }
        return cnt >= k;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (solve(nums, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
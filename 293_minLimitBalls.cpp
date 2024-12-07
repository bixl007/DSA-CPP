#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int ops = 0;
            for (int i : nums)
            {
                if ((ops += (i - 1) / mid) > maxOperations)
                    break;
            }
            ops <= maxOperations ? high = mid : low = mid + 1;
        }
        return high;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
                cnt++;
            if (cnt > 1)
                return false;
        }
        return true;
    }
};
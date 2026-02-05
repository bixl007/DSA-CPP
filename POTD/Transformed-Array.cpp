#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res = nums;

        for (int i = 0; i < n; i++)
        {
            int idx = (((i + nums[i]) % n) + n) % n;
            res[i] = nums[idx];
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> even, odd;
        for (auto i : nums)
        {
            if (i % 2 == 0)
            {
                even.push_back(i);
            }
            else
            {
                odd.push_back(i);
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (c1 < even.size())
            {
                nums[i] = even[c1++];
            }
            else
            {
                nums[i] = odd[c2++];
            }
        }
        return nums;
    }
};
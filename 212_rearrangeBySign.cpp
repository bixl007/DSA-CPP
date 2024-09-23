#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;

        for (auto i : nums)
        {
            if (i < 0)
            {
                neg.push_back(i);
            }
            else
            {
                pos.push_back(i);
            }
        }

        int x = 0, y = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                nums[i] = pos[x++];
            else
                nums[i] = neg[y++];
        }

        return nums;
    }
};
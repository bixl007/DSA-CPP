#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bits(int value) { return bitset<10>(value).count(); }
    bool canSortArray(vector<int> &nums)
    {
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    if (bits(nums[i]) == bits(nums[i + 1]))
                    {
                        swap(nums[i], nums[i + 1]);
                        flag = true;
                    }
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};
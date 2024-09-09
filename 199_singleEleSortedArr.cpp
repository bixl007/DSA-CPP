#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int count = 0;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0 && nums[i] != nums[i + 1])
                return nums[i];
            if (nums[i] == nums[i + 1])
                count++;
            else
                count = 0;
        }
        return -1;
    }
};
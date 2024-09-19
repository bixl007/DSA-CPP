#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int size = nums.size();

        int counter = 1;

        if (size == 1 && nums[0] != 1)
            return 1;
        if (size == 1 && nums[0] == 1)
            return 2;

        if (nums[0] == 1)
            counter++;

        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] > 0)
                {
                    if (nums[i] != counter)
                    {
                        return counter;
                    }
                    counter++;
                }
            }
        }

        if (counter == 1)
            return 1;

        return nums[size - 1] + 1;
    }
};
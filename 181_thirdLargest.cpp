#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> arr;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                arr.push_back(nums[i]);
            }
        }
        arr.push_back(nums[nums.size() - 1]);

        if (arr.size() >= 3)
        {
            return arr[arr.size() - 3];
        }
        return arr[arr.size() - 1];
    }
};
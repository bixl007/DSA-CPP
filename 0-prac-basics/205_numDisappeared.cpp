#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int counter = 1;
        vector<bool> checker(n, true);

        for (int i = 0; i < n; i++)
        {
            checker[nums[i] - 1] = false;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (checker[i] == true)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
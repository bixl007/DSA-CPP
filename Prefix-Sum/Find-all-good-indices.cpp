#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> left(n + 1, 1), right(n + 1, 1);

        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1];
            if (nums[i] > nums[i - 1])
                left[i] = 1;
            else
                left[i]++;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1];
            if (nums[i] > nums[i + 1])
                right[i] = 1;
            else
                right[i]++;
        }

        vector<int> ans;
        for (int i = k; i < n - k; i++)
        {
            if (left[i - 1] >= k && right[i + 1] >= k)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
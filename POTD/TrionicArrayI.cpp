#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        int p = -1, q = -1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                p = i;
            else
                break;
        }

        for (int i = n - 1; i < 0; i++)
        {
            if (nums[i] < nums[i - 1])
                q = i;
            else
                break;
        }

        return (p != -1 && q != -1 && p < q);
    }
};
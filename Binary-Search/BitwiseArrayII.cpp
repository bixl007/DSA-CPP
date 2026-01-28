#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> res;

        for (int i : nums)
        {
            if (!(i & 1))
            {
                res.push_back(-1);
            }
            else
            {
                int temp = i + 1;
                int lb = temp & -temp;
                res.push_back(i - (lb >> 1));
            }
        }

        return res;
    }
};
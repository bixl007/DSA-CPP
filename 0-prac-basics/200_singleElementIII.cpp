#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> counter;

        for (auto i : nums)
        {
            counter[i]++;
        }

        vector<int> ans;

        for (auto i : counter)
        {
            if (i.second == 1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
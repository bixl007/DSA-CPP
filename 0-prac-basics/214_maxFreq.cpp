#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        int maxi = INT_MIN;
        for (auto i : nums)
        {
            mpp[i]++;
        }

        for (auto i : mpp)
        {
            if (i.second > maxi)
                maxi = max(i.second, maxi);
        }

        int counter = 0;

        for (auto i : mpp)
        {
            if (i.second == maxi)
                counter += i.second;
        }
        return counter;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> mpp;

        for (auto i : nums)
        {
            mpp[i]++;
        }
        int sum = 0;
        for (auto i : mpp)
        {
            if (i.second == 1)
                sum += i.first;
        }
        return sum;
    }
};
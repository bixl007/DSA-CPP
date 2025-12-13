#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        map<int, int> counter;

        for (auto i : nums)
        {
            if (i % 2 == 0)
            {
                counter[i]++;
            }
        }

        int maxi = INT_MIN;

        for (auto i : counter)
        {
            maxi = max(i.second, maxi);
        }

        for (auto i : counter)
        {
            if (i.second == maxi)
                return i.first;
        }
        return -1;
    }
};
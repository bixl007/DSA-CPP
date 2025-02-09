#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> count;
        long long good = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            good += count[key];
            count[key]++;
        }
        return (n * (n - 1)) / 2 - good;
    }
};
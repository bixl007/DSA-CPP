#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {

        unordered_map<int, int> counter;

        for (auto i : nums)
            counter[i]++;

        vector<int> arr;
        int ans = 0;

        for (auto i : counter)
        {
            if (i.second == 2)
                arr.push_back(i.first);
        }

        for (auto i : arr)
            ans ^= i;
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int val = 0.25 * arr.size();
        unordered_map<int, int> counter;
        for (auto i : arr)
        {
            counter[i]++;
        }

        for (auto i : counter)
        {
            if (i.second > val)
                return i.first;
        }
        return -1;
    }
};
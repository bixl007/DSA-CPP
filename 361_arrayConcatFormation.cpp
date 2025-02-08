#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, vector<int>> mp;
        for (auto &i : pieces)
        {
            mp[i[0]] = i;
        }
        vector<int> res;
        for (auto &i : arr)
        {
            if (mp.find(i) != mp.end())
                res.insert(res.end(), mp[i].begin(), mp[i].end());
        }
        return res == arr;
    }
};
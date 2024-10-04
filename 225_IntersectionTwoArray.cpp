#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        set<int> st1;
        set<int> st2;
        unordered_map<int, int> mapp;

        for (auto i : nums1)
        {
            st1.insert(i);
        }

        for (auto i : nums2)
        {
            st2.insert(i);
        }

        for (auto i : st1)
        {
            mapp[i]++;
        }

        for (auto i : st2)
        {
            mapp[i]++;
        }

        for (auto i : mapp)
        {
            if (i.second == 2)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
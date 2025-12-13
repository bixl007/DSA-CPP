#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mpp;

        for (auto i : strs)
        {
            string word = i;
            sort(word.begin(), word.end());
            mpp[word].push_back(i);
        }
        vector<vector<string>> ans;

        for (auto i : mpp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
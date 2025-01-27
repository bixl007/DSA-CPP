#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> Prefix(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++)
        {
            Prefix[i + 1] = Prefix[i];
            if (vowels.count(words[i].front()) &&
                vowels.count(words[i].back()))
            {
                Prefix[i + 1]++;
            }
        }
        vector<int> ans;
        for (auto &query : queries)
        {
            int L = query[0], r = query[1];
            ans.push_back(Prefix[r + 1] - Prefix[L]);
        }

        return ans;
    }
};
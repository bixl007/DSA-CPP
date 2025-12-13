#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(string &s, unordered_set<string> &st, int start, int end, vector<vector<int>> &dp)
    {
        if (dp[start][end] != -1)
            return dp[start][end];

        if (end == s.size() - 1)
        {
            if (st.count(s.substr(start, end - start + 1)))
            {
                return true;
            }
            return false;
        }

        if (st.count(s.substr(start, end - start + 1)))
        {
            dp[start][end] = 1;
            if (solve(s, st, end + 1, end + 1, dp))
                return true;
        }
        return dp[start][end] = solve(s, st, start, end + 1, dp);
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(s, st, 0, 0, dp);
    }
};
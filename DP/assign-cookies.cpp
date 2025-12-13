#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &g, vector<int> &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s.size() || j >= g.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        if (g[j] <= s[i])
            res = max(res, 1 + solve(g, s, i + 1, j + 1, dp));
        res = max(res, solve(g, s, i + 1, j, dp));

        return dp[i][j] = res;
    }
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<vector<int>> dp(s.size() + 1, vector<int>(g.size() + 1, -1));

        return solve(g, s, 0, 0, dp);
    }
};

// SO

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;
        for (int i : s)
        {
            if (i >= g[j])
            {
                j++;
                if (j >= g.size())
                    break;
            }
        }

        return j;
    }
};
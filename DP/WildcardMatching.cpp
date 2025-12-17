#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (j == 0 && i > 0)
        {
            for (int itr = 1; itr <= i; itr++)
            {
                if (p[itr - 1] != '*')
                    return false;
            }

            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, p, s, dp);
        if (p[i - 1] == '*')
        {
            return dp[i][j] = solve(i - 1, j, p, s, dp) | solve(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, p, s, dp);
    }
};

// Tabulation

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;

        for (int i = 1; i <= n; i++)
        {
        }

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int j = 1; j <= i; j++)
            {
                if (p[j - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {

                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                {
                    curr[j] = prev[j] | curr[j - 1];
                }
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
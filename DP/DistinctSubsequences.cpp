#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, s, t, dp);
    }
};

// Tabulation
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

// SO
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<double> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= 1; j--)
            {

                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j];
                else
                    dp[j] = dp[j];
            }
        }
        return dp[n];
    }
};
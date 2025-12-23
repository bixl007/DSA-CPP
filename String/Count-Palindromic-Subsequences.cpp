#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            dp[i][j] = solve(s, i + 1, j, dp) +
                       solve(s, i, j - 1, dp) + 1;
        else
            dp[i][j] = solve(s, i + 1, j, dp) + solve(s, i, j - 1, dp) -
                       solve(s, i + 1, j - 1, dp);

        return dp[i][j];
    }
    int countPS(string &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(s, 0, n - 1, dp);
    };
};


// Tabulation
class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }

        return dp[0][n - 1];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i - 1] == word2[j - 1])
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = min({1 + solve(i - 1, j - 1, word1, word2, dp), 1 + solve(i - 1, j, word1, word2, dp), 1 + solve(i, j - 1, word1, word2, dp)});
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, word1, word2, dp);
    }
};

// Tabulation
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({1 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
            }
        }

        return dp[n][m];
    }
};

// SO
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 0; i <= m; i++)
        {
            prev[i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = min({1 + prev[j - 1], 1 + prev[j], 1 + curr[j - 1]});
            }
            prev = curr;
        }

        return prev[m];
    }
};
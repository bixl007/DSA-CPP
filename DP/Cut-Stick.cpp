#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution
{
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int idx = i; idx <= j; idx++)
        {
            int cnt = cuts[j + 1] - cuts[i - 1] + solve(i, idx - 1, cuts, dp) + solve(idx + 1, j, cuts, dp);
            mini = min(mini, cnt);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        int size = cuts.size();

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(1, c, cuts, dp);
    }
};

// Tabulation
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    int size = cuts.size();

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            int mini = INT_MAX;

            for (int idx = i; idx <= j; idx++)
            {
                int cnt = cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] + dp[idx + 1][j];
                mini = min(mini, cnt);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}
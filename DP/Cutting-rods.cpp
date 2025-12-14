#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int n, vector<int> &price, vector<vector<int>> &dp)
    {
        if (idx == 0)
            return n * price[0];
        if (dp[idx][n] != -1)
            return dp[idx][n];

        int notTake = solve(idx - 1, n, price, dp);
        int take = INT_MIN;
        int len = idx + 1;
        if (len <= n)
            take = price[idx] + solve(idx, n - len, price, dp);
        return dp[idx][n] = max(take, notTake);
    }
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(n - 1, n, price, dp);
    }
};

// Tabulation

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i * price[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                int len = i + 1;
                if (len <= j)
                    take = price[i] + dp[i][j - len];
                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

// SO

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            dp[i] = i * price[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                int notTake = dp[j];
                int take = INT_MIN;
                int len = i + 1;
                if (len <= j)
                    take = price[i] + dp[j - len];
                dp[j] = max(take, notTake);
            }
        }

        return dp[n];
    }
};
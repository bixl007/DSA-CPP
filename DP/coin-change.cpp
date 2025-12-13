#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];

        int mini = 1e9;
        for (int i = 0; i < coins.size(); i++)
        {
            if (amount >= coins[i])
                mini = min(mini, 1 + solve(coins, amount - coins[i], dp));
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Tabulation

class Solution
{
public:
    int solve(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        int ans = solve(coins, amount);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};
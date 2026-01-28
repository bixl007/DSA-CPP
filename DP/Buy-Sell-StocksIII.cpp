#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &prices, int n, int i, int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || !cap)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        // buy = 0 -> we can buy the stocks
        if (!buy)
        {
            profit = max(solve(prices, n, i + 1, buy, cap, dp), -prices[i] + solve(prices, n, i + 1, !buy, cap, dp));
        }

        if (buy)
        {
            profit = max(solve(prices, n, i + 1, buy, cap, dp), prices[i] + solve(prices, n, i + 1, !buy, cap - 1, dp));
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, n, 0, 0, 2, dp);
    }
};

// Tablulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    int profit = 0;
                    // buy = 0 -> we can buy the stocks
                    if (!buy)
                    {
                        profit = max(dp[i + 1][buy][cap], -prices[i] + dp[i + 1][!buy][cap]);
                    }

                    if (buy)
                    {
                        profit = max(dp[i + 1][buy][cap], prices[i] + dp[i + 1][!buy][cap - 1]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][0][2];
    }
};

// SO

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    int profit = 0;
                    // buy = 0 -> we can buy the stocks
                    if (!buy)
                    {
                        profit = max(next[buy][cap], -prices[i] + next[!buy][cap]);
                    }

                    if (buy)
                    {
                        profit = max(next[buy][cap], prices[i] + next[!buy][cap - 1]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            next = curr;
        }
        return curr[0][2];
    }
};

// Another approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int price : prices)
        {

            buy1 = max(buy1, -price);

            sell1 = max(sell1, buy1 + price);

            buy2 = max(buy2, sell1 - price);

            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};
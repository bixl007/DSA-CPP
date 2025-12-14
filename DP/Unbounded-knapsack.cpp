#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            return (capacity / wt[0]) * val[0];
        }
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];

        int notTake = solve(idx - 1, capacity, val, wt, dp);
        int take = 0;
        if (wt[idx] <= capacity)
            take = val[idx] + solve(idx, capacity - wt[idx], val, wt, dp);
        return dp[idx][capacity] = max(take, notTake);
    }
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, capacity, val, wt, dp);
    }
};

// Tabulation
class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int j = 0; j <= capacity; j++)
        {
            dp[0][j] = (j / wt[0]) * val[0];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + dp[i][j - wt[i]];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][capacity];
    }
};


// SO
class Solution
{
    public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);
        
        for (int j = 0; j <= capacity; j++)
        {
            prev[j] = (j / wt[0]) * val[0];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                int notTake = prev[j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];
                prev[j] = max(take, notTake);
            }
        }
        return prev[capacity];
    }
};
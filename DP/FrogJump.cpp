#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &height, int i, int last, vector<int> &dp)
    {

        if (i == height.size() - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int inc = INT_MAX;
        int exc = INT_MAX;

        if (i + 1 < height.size())
            inc = abs(height[i] - height[i + 1]) + solve(height, i + 1, height[i], dp);

        if (i + 2 < height.size())
            exc = abs(height[i] - height[i + 2]) + solve(height, i + 2, height[i], dp);

        return dp[i] = min(inc, exc);
    }

public:
    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(height, 0, height[0], dp);
    }
};

// Tablulation

class Solution
{
private:
    int solve(vector<int> &height, int i)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {

            int inc = INT_MAX;
            int exc = INT_MAX;

            if (i + 1 < n)
                inc = abs(height[i] - height[i + 1]) + dp[i + 1];

            if (i + 2 < n)
                exc = abs(height[i] - height[i + 2]) + dp[i + 2];
            dp[i] = min(inc, exc);
        }

        return dp[0];
    }

public:
    int minCost(vector<int> &height)
    {
        // Code here
        return solve(height, 0);
    }
};

// SO

class Solution
{
private:
    int solve(vector<int> &height, int i)
    {
        int n = height.size();
        int next = INT_MAX;
        int prev = 0;

        for (int i = n - 2; i >= 0; i--)
        {

            int inc = INT_MAX;
            int exc = INT_MAX;

            if (i + 1 < n)
                inc = abs(height[i] - height[i + 1]) + prev;

            if (i + 2 < n)
                exc = abs(height[i] - height[i + 2]) + next;
            next = prev;
            prev = min(inc, exc);
        }

        return prev;
    }

public:
    int minCost(vector<int> &height)
    {
        // Code here
        return solve(height, 0);
    }
};

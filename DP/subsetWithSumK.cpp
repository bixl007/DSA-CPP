#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int target, int idx, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;

            if (target == 0 || target == arr[0])
                return 1;

            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];

        int res = 0;
        if (arr[idx] <= target)
            res += solve(arr, target - arr[idx], idx - 1, dp);

        res += solve(arr, target, idx - 1, dp);

        return dp[idx][target] = res;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, target, n - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int solve(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
        {
            dp[0][arr[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int res = 0;
                if (arr[i] <= j)
                    res += dp[i - 1][j - arr[i]];

                res += dp[i - 1][j];
                dp[i][j] = res;
            }
        }

        return dp[n - 1][target];
    }
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        return solve(arr, target);
    }
};

// SO

class Solution
{
public:
    int solve(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= arr[i]; j--)
            {
                dp[j] = dp[j] + dp[j - arr[i]];
            }
        }

        return dp[target];
    }
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        return solve(arr, target);
    }
};

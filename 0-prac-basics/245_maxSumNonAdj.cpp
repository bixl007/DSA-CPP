#include <bits/stdc++.h>
using namespace std;

// Recursive approach
int solve(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[n];

    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1);

    int ans = max(include, exclude);

    return ans;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    int ans = solve(nums, n - 1);

    return ans;
}

// Memorization
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[n];

    if (dp[n] != -1)
        return dp[n];

    int include = solve(nums, n - 2, dp) + nums[n];
    int exclude = solve(nums, n - 1, dp);

    dp[n] = max(include, exclude);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    int ans = solve(nums, n - 1, dp);

    return ans;
}

// Tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

// Space optimisation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return nums[0];

    int prev1 = nums[0];
    int prev2 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int current = max(prev2, prev1 + nums[i]);
        prev1 = prev2;
        prev2 = current;
    }

    return prev2;
}
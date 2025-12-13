#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int offset = 1000;
    int solve(vector<int> &nums, int target, int idx, int curr, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
        {
            return (curr == target);
        }

        if (dp[idx][curr + offset] != -1)
            return dp[idx][curr + offset];

        int add = solve(nums, target, idx + 1, curr + nums[idx], dp);
        int sub = solve(nums, target, idx + 1, curr - nums[idx], dp);

        return dp[idx][curr + offset] = add + sub;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }
};

// Tabulation
class Solution
{
public:
    int offset = 1000;
    int solve(vector<int> &nums, int target, int idx, int curr)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        dp[0][offset] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 2000; j++)
            {
                if (dp[i][j] > 0)
                {
                    if (j + nums[i] <= 2000)
                        dp[i + 1][j + nums[i]] += dp[i][j];
                    if (j - nums[i] >= 0)
                        dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        if (target > 1000 || target < -1000)
            return 0;
        return dp[n][target + offset];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solve(nums, target, 0, 0);
    }
};

// SO

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if ((total + target) & 1 || abs(target) > total)
            return 0;

        int sum = (total + target) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int i : nums)
        {
            for (int j = sum; j >= i; j--)
            {
                dp[j] += dp[j - i];
            }
        }
        return dp[sum];
    }
};
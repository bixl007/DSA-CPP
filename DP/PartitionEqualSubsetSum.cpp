#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (sum < 0 || idx == nums.size())
            return false;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool take = solve(nums, idx + 1, sum - nums[idx], dp);
        bool notTake = solve(nums, idx + 1, sum, dp);

        return dp[idx][sum] = take | notTake;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum & 1)
            return false;
        sum /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return solve(nums, 0, sum, dp);
    }
};

// Tabulation

class Solution
{
private:
    bool solve(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        if (nums[0] <= sum) {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool take = 0;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];

                bool notTake = dp[i - 1][j];

                dp[i][j] = take | notTake;
            }
        }

        return dp[n - 1][sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum & 1)
            return false;
        sum /= 2;

        return solve(nums, sum);
    }
};


// SO
class Solution
{
private:
    bool solve(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;


        for (int i = 0; i < n; i++)
        {
            for (int j = sum; j > 0; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum & 1)
            return false;
        sum /= 2;

        return solve(nums, sum);
    }
};

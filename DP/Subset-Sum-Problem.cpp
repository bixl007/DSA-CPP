#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(vector<int> &arr, int sum, int idx, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (idx == arr.size())
            return false;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        bool take = false;
        if (arr[idx] <= sum)
            take = solve(arr, sum - arr[idx], idx + 1, dp);
        bool notTake = solve(arr, sum, idx + 1, dp);

        return dp[idx][sum] = take | notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};

// Tabulation

class Solution
{
private:
    bool solve(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= sum) 
            dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool take = false;
                if (arr[i] <= j)
                {
                    take = dp[i - 1][j - arr[i]];
                }
                bool notTake = dp[i - 1][j];
        
                dp[i][j] = take | notTake;
            }
        }
        return dp[n - 1][sum];
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        return solve(arr, sum);
    }
};

// SO

class Solution
{
private:
    bool solve(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = true;

        if (arr[0] <= sum) 
            prev[arr[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = sum; j >= 1; j--) {
                bool take = false;
                if (arr[i] <= j)
                {
                    take = prev[j - arr[i]];
                }
                bool notTake = prev[j];
        
                prev[j] = take | notTake;
            }
        }
        return prev[sum];
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        return solve(arr, sum);
    }
};

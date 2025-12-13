#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }

        if (dp[n][last] != -1)
            return dp[n][last];

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != last)
            {
                int points = arr[n][i] + solve(n - 1, i, arr, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[n][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        return solve(n - 1, 3, arr, dp);
    }
};

// Tabulation
class Solution
{
private:
    int solve(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][1]));

        for (int days = 1; days < n; days++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[days][last] = 0;

                for (int task = 0; task < 3; task++)
                {

                    if (task != last)
                    {
                        int points = arr[days][task] + dp[days - 1][task];
                        dp[days][last] = max(dp[days][last], points);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        return solve(arr);
    }
};

// SO

class Solution
{
private:
    int solve(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> dp(4, 0);
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

        for (int days = 1; days < n; days++)
        {
            vector<int> curr(4, 0);
            for (int last = 0; last < 4; last++)
            {

                for (int task = 0; task < 3; task++)
                {

                    if (task != last)
                    {
                        int points = arr[days][task] + dp[task];
                        curr[last] = max(curr[last], points);
                    }
                }
            }
            dp = curr;
        }
        return dp[3];
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        return solve(arr);
    }
};
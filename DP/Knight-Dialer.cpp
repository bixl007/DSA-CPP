#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;

    int solve(int n, int i, vector<vector<int>> &jumps, vector<vector<int>> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[n][i] != -1)
            return dp[n][i];

        int cnt = 0;
        for (int i : jumps[i])
        {
            cnt = (cnt + solve(n - 1, i, jumps, dp)) % MOD;
        }

        return dp[n][i] = cnt;
    }

    int knightDialer(int n)
    {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}};

        vector<vector<int>> dp(n + 1, vector<int>(10, -1));

        int total = 0;

        for (int i = 0; i <= 9; i++)
        {
            total = (total + solve(n, i, jumps, dp)) % MOD;
        }

        return total;
    }
};

// Tabulation
class Solution
{
public:
    int MOD = 1e9 + 7;

    int knightDialer(int n)
    {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}};

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));

        for (int i = 0; i < 10; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                for (int itr : jumps[j])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][itr]) % MOD;
                }
            }
        }

        int total = 0;

        for (int i = 0; i <= 9; i++)
        {
            total = (total + dp[n][i]) % MOD;
        }

        return total;
    }
};

// SO
class Solution
{
public:
    int MOD = 1e9 + 7;

    int knightDialer(int n)
    {
        if (n == 1)
            return 10;

        vector<long long> curr(10, 1);

        for (int i = 1; i < n; i++)
        {
            vector<long long> next(10, 0);
            next[0] = (curr[4] + curr[6]) % MOD;
            next[1] = (curr[6] + curr[8]) % MOD;
            next[2] = (curr[7] + curr[9]) % MOD;
            next[3] = (curr[4] + curr[8]) % MOD;
            next[4] = (curr[3] + curr[9] + curr[0]) % MOD;
            next[5] = 0;
            next[6] = (curr[1] + curr[7] + curr[0]) % MOD;
            next[7] = (curr[2] + curr[6]) % MOD;
            next[8] = (curr[1] + curr[3]) % MOD;
            next[9] = (curr[2] + curr[4]) % MOD;

            curr = next;
        }

        int total = 0;

        for (int i = 0; i <= 9; i++)
        {
            total = (total + curr[i]) % MOD;
        }

        return total;
    }
};
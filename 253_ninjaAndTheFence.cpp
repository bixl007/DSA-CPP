#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Recursive
int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

int solve(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    return ans;
}

int numberOfWays(int n, int k)
{
    return solve(n, k);
}

// Memorization
int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));
    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

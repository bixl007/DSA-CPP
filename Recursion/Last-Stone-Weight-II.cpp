#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int idx, int total, vector<int> &stone, vector<vector<int>> &dp)
    {
        if (idx >= stone.size())
            return 0;

        if (dp[idx][total] != -1)
            return dp[idx][total];

        int take = 0;
        if (total - stone[idx] >= 0)
            take = stone[idx] + solve(idx + 1, total - stone[idx], stone, dp);

        int notTake = solve(idx + 1, total, stone, dp);

        return dp[idx][total] = max(take, notTake);
    }

public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return total - 2 * solve(0, target, stones, dp);
    }
};

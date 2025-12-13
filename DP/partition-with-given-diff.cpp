#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
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
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = 0;
        
        for(int i : arr)
            total += i;

        if(total - diff < 0 || (total - diff) % 2 == 0)
            return 0;

        return solve(arr, (total - diff) % 2);

        
    }
};
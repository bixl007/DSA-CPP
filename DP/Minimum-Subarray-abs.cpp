#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, mini = INT_MAX, total = 0;

    void solve(vector<int> &nums, int idx, int count, int curr) {
        if(count == n) {
            int diff = abs(curr - (total - curr));
            mini = min(mini, diff);
            return ;
        }

        if(idx >= n * 2)
            return ;
        
        solve(nums, idx + 1, count + 1, curr + nums[idx]);
        solve(nums, idx + 1, count, curr);
    }

    int minimumDifference(vector<int>& nums) {
        n = nums.size() / 2;
        total = 0;
        for(int i : nums) {
            total += i;
        }

        solve(nums, 0, 0, 0);

        return mini;

    }
};

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
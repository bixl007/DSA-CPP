#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int> &nums)
{
    long long int n = nums.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return nums[0];

    long long int prev1 = nums[0];
    long long int prev2 = max(nums[0], nums[1]);

    for (long long int i = 2; i < n; i++)
    {
        long long int current = max(prev2, prev1 + nums[i]);
        prev1 = prev2;
        prev2 = current;
    }

    return prev2;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    if (valueInHouse.size() == 1)
        return valueInHouse[0];

    vector<int> first, second;
    for (int i = 0; i < valueInHouse.size(); i++)
    {
        if (i != valueInHouse.size() - 1)
            first.push_back(valueInHouse[i]);
        if (i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(second));
}
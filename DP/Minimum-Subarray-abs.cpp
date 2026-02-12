#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, total = 0;
    unordered_map<string, int> dp;

    int solve(vector<int> &nums, int idx, int count, int curr)
    {
        if (count == n)
        {
            int diff = abs(curr - (total - curr));
            return diff;
        }

        if (idx >= n * 2)
            return 1e9;

        string key = to_string(idx) + "-" + to_string(count) + "-" + to_string(curr);

        if (dp.find(key) != dp.end())
            return dp[key];

        int res = solve(nums, idx + 1, count, curr);

        if (count < n)
            res = min(res, solve(nums, idx + 1, count + 1, curr + nums[idx]));

        return dp[key] = res;
    }

    int minimumDifference(vector<int> &nums)
    {
        n = nums.size() / 2;
        total = 0;
        for (int i : nums)
        {
            total += i;
        }

        dp.clear();

        return solve(nums, 0, 0, 0);
    }
};

// Split from middle
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);

        for (int mask = 0; mask < (1 << N); mask++)
        {
            int sz = 0, l = 0, r = 0;
            for (int i = 0; i < N; i++)
            {
                if (mask & (1 << i))
                {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for (int i = 0; i <= N; i++)
        {
            sort(right[i].begin(), right[i].end());
        }

        res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        for (int i = 1; i < N; i++)
        {
            for (auto &a : left[i])
            {
                int b = (sum - 2 * a) / 2;
                int rsz = N - i;
                auto &arr = right[rsz];

                auto itr = lower_bound(arr.begin(), arr.end(), b);

                if (itr != arr.end())
                    res = min(res, abs(sum - 2 * (a + (*itr))));

                if (itr != arr.begin())
                {
                    auto it = itr;
                    it--;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }
            }
        }
        return res;
    }
};
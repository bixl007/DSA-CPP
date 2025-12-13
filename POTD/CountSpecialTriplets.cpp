#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        unordered_map<int, int> pref, suff;
        int MOD = 1e9 + 7;
        for (auto i : nums)
            suff[i]++;

        long long ans = 0;

        for (auto i : nums)
        {
            suff[i] -= 1;
            ans += (long long)pref[i * 2] * suff[i * 2];
            pref[i]++;
        }
        return ans % MOD;
    }
};
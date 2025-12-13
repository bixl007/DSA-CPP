#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long cnt = 0;

            for (int i : candies)
            {
                cnt += i / mid;
            }

            if (cnt >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};
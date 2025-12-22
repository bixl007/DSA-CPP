#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    vector<int> findSubarray(vector<int> &arr)
    {
        // code here
        long long maxi = LLONG_MIN;
        int start = 0;
        long long sum = 0;

        int st = -1, ed = -1, n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                sum = 0;
                start = i + 1;
                continue;
            }

            sum += arr[i];

            if (sum > maxi || (sum == maxi && (i - start > ed - st)))
            {
                maxi = sum;
                st = start;
                ed = i;
            }
        }

        vector<int> res;
        if (st == -1)
            return {-1};
        for (int i = st; i <= ed; i++)
        {
            res.push_back(arr[i]);
        }

        return res;
    }
};
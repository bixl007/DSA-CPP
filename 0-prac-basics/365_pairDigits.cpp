#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        vector<int> arr(82);
        int ans = -1;

        for (int &i : nums)
        {
            int sum = 0, temp = i;
            while (temp != 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (arr[sum] != 0)
                ans = max(ans, i + arr[sum]);
            arr[sum] = max(arr[sum], i);
        }
        return ans;
    }
};
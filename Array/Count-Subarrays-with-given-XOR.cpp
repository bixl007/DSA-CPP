#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int curr = 0, n = arr.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            curr ^= arr[i];
            int target = curr ^ k;

            if (mpp.find(target) != mpp.end())
            {
                cnt += mpp[target];
            }

            mpp[target]++;
        }

        return cnt;
    }
};
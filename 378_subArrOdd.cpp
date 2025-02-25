#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        long long oddCount = 0, prefixSum = 0;
        for (int a : arr)
        {
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};
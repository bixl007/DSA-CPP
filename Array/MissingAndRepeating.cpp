#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        long long n = arr.size();
        long long origSum = (n * (n + 1)) / 2;
        long long origDub = (n * (n + 1) * (2 * n + 1)) / 6;

        long long actualSum = 0, actualDub = 0;

        for (int i = 0; i < n; i++)
        {
            actualSum += arr[i];
            actualDub += (long long)arr[i] * arr[i];
        }

        long long val1 = actualSum - origSum;
        long long val2 = actualDub - origDub;

        long long sum = val2 / val1;

        long long repeating = (sum + val1) / 2;
        long long missing = sum - repeating;

        return {(int)repeating, (int)missing};
    }
};
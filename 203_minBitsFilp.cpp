#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = 0;

        int xorResult = start ^ goal;

        while (xorResult)
        {
            ans += xorResult & 1;
            xorResult >>= 1;
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long res = x;
        long remaining = n - 1;
        long position = 1;

        while (remaining)
        {
            if (!(x & position))
            {
                res |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        return res;
    }
};
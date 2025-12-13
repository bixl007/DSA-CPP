#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int totalZero = 0;

        for (auto i : s)
        {
            if (i == '0')
                totalZero++;
        }

        int ans = -1, zero = 0, size = s.length();

        for (int i = 0; i < size - 1; i++)
        {
            if (s[i] == '0')
            {
                zero++;
                totalZero--;
            }
            ans = max(ans, (zero + (size - totalZero - i - 1)));
        }
        return ans;
    }
};
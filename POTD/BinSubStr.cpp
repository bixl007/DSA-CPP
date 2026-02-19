#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int n = s.length();
        int curr = 1, prev = 0, cnt = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                curr++;
            }
            else
            {
                cnt += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        cnt += min(curr, prev);

        return cnt;
    }
};
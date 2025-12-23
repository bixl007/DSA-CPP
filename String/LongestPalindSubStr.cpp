#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int expand(string &s, int start, int end)
    {
        while (start >= 0 && end < s.size() && s[start] == s[end])
        {
            start--;
            end++;
        }
        return end - start - 1;
    }
    string longestPalindrome(string s)
    {
        int start = -1, end = -1, n = s.size();

        for (int i = 0; i < n; i++)
        {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);

            int maxi = max(odd, even);

            if (maxi > end - start)
            {
                start = i - ((maxi - 1) / 2);
                end = i + ((maxi - 1) / 2);
            }
        }

        return s.substr(start, end - start + 1);
    }
};
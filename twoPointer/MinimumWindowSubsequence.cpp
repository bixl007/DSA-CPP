#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s1, string &s2)
    {
        // Code here
        int n = s1.size();
        int m = s2.size();
        int l = 0, r = 0;
        string st = "";
        int minLen = INT_MAX;

        while (l < n)
        {
            if (s1[l] == s2[r])
            {
                r++;
                if (r == m)
                {
                    int end = l;
                    int k = r - 1;

                    while (k >= 0)
                    {
                        if (s1[end] == s2[k])
                        {
                            k--;
                        }
                        end--;
                    }

                    int start = end + 1;
                    int len = l - start + 1;

                    if (len < minLen)
                    {
                        minLen = len;
                        st = s1.substr(start, len);
                    }
                    r = 0;
                    l = start + 1;
                    continue;
                }
            }
            l++;
        }
        return st;
    }
};

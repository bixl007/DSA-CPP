#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(vector<int> &lps, string s)
    {
        int i = 0;
        int j = i + 1;

        while (j < s.length())
        {
            if (s[i] == s[j])
            {
                i++;
                lps[j] = i;
                j++;
            }
            else
            {
                if (i == 0)
                    j++;
                else
                    i = lps[i - 1];
            }
        }
    }
    string longestPrefix(string s)
    {

        vector<int> lps(s.size(), 0);

        f(lps, s);

        int i = lps[s.length() - 1];
        return s.substr(0, i);
    }
};
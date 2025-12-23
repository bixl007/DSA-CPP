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
    string shortestPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        string merged = s + "#" + t;

        vector<int> lps(merged.size(), 0);

        f(lps, merged);

        int i = lps[merged.length() - 1];
        string temp = s.substr(i);

        reverse(temp.begin(), temp.end());

        return temp + s;
    }
};
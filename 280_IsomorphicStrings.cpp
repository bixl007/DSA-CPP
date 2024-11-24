#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int sCount[256] = {0};
        int tCount[256] = {0};

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (sCount[s[i]] != tCount[t[i]])
                return false;

            sCount[s[i]] = i + 1;
            tCount[t[i]] = i + 1;
        }

        return true;
    }
};
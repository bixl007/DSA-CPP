#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {

        if (s1 == s2)
            return true;

        int n = s1.size(), m = s2.size();
        vector<char> temp;

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                temp.push_back(i);
            }
        }

        if (temp.size() != 2)
            return false;

        swap(s2[temp[0]], s2[temp[1]]);

        return s1 == s2;
    }
};
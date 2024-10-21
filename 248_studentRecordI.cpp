#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int len = s.length(), ab = 0, late = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'A')
                ab++;
            if (s[i] == 'L')
                late++;
            if (s[i] != 'L')
                late = 0;
            if (late >= 3)
                return false;
            if (ab >= 2)
                return false;
        }

        return true;
    }
};
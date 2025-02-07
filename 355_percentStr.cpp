#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == letter)
                cnt++;
        }
        return (cnt * 100) / s.size();
    }
};
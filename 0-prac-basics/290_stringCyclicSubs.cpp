#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int str2Idx = 0;
        int str2Len = str2.length();
        for (char currChar : str1)
        {
            if (str2Idx < str2Len && (str2[str2Idx] - currChar + 26) % 26 <= 1)
            {
                str2Idx++;
            }
        }
        return str2Idx == str2Len;
    }
};
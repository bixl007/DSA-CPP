#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (!isalpha(s[i]))
                ++i;
            else if (!isalpha(s[j]))
                --j;
            else
                swap(s[i++], s[j--]);
        }
        return s;
    }
};
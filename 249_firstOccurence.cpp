#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int a = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[a])
            {
                a++;
            }
            else
            {
                i -= a;
                a = 0;
            }
            cout << a << endl;
            if (a == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};
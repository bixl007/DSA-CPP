#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string res1 = "", res2 = "";

        for (auto i : s)
        {
            if (i == '#')
            {
                if (res1.empty())
                    continue;
                else
                {
                    res1.pop_back();
                }
            }
            else
            {
                res1.push_back(i);
            }
        }
        for (auto i : t)
        {
            if (i == '#')
            {
                if (res2.empty())
                    continue;
                else
                {
                    res2.pop_back();
                }
            }
            else
            {
                res2.push_back(i);
            }
        }
        return res1 == res2;
    }
};
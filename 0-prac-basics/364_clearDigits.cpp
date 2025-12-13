#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        string ans;
        for (char i : s)
        {
            if (isdigit(i))
            {
                if (!ans.empty())
                    ans.pop_back();
            }
            else
                ans.push_back(i);
        }
        return ans;
    }
};
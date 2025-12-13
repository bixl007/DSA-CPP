#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string str = "";
        int k = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (k < spaces.size() && i == spaces[k])
            {
                str.push_back(' ');
                k++;
            }
            str.push_back(s[i]);
        }
        return str;
    }
};
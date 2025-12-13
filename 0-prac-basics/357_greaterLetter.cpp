#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        vector<int> cnt(128);
        for (auto i : s)
        {
            cnt[i]++;
        }
        for (char i = 'Z'; i >= 'A'; i--)
        {
            if (cnt[i] && cnt[i + 'a' - 'A'])
                return string(1, i);
        }
        return "";
    }
};
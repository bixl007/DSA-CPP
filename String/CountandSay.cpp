#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(string str)
    {
        int n = str.size();
        if (!n)
            return "1";
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            int cnt = 1;

            while (i + 1 < n && str[i] == str[i + 1])
            {
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += str[i];
        }
        return ans;
    }
    string countAndSay(int n)
    {
        string ans = "";

        while (n--)
        {
            ans = solve(ans);
        }
        return ans;
    }
};
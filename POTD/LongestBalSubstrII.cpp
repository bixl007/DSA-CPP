#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleFreq(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int cnt = 1, maxi = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                cnt++;
            else
                cnt = 1;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }

    int doubleFreq(string s, char c1, char c2)
    {
        map<int, int> pos;
        pos[0] = -1;

        int res = 0, diff = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != c1 && s[i] != c2)
            {
                pos.clear();
                pos[0] = i;
                diff = 0;
                continue;
            }

            if (s[i] == c1)
                diff++;
            else
                diff--;

            if (pos.find(diff) != pos.end())
            {
                res = max(res, (i - pos[diff]));
            }
            else
            {
                pos[diff] = i;
            }
        }

        return res;
    }

    int tripleFreq(string &s)
    {
        int n = s.size();

        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;

        vector<int> freq(3, 0);
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;

            vector<int> key = {freq[1] - freq[0], freq[2] - freq[0]};

            if (pos.find(key) != pos.end())
            {
                maxi = max(maxi, i - pos[key]);
            }
            else
            {
                pos[key] = i;
            }
        }
        return maxi;
    }

    int longestBalanced(string s)
    {
        return max({singleFreq(s), doubleFreq(s, 'a', 'b'),
                    doubleFreq(s, 'a', 'c'), doubleFreq(s, 'b', 'c'),
                    tripleFreq(s)});
    }
};
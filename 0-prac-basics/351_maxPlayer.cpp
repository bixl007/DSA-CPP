#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &g, vector<int> &s)
    {
        int l = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (auto i : s)
        {
            if (i >= g[l])
            {
                l++;
                if (l == g.size())
                    break;
            }
        }
        return l;
    }
};
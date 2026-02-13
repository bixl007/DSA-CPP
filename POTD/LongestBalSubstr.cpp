#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.length();
        int cnt = 1;

        vector<int> freq(26, 0);

        for (int l = 0; l < n; l++)
        {
            fill(freq.begin(), freq.end(), 0);
            int unique = 0, maxF = 0, cntMax = 0;
            for (int r = l; r < n; r++)
            {
                int curr = ++freq[s[r] - 'a'];
                if (curr == 1)
                    unique++;

                if (curr > maxF) {
                    maxF = curr;
                    cntMax = 1;
                }
                else if (curr == maxF)
                {
                    cntMax++;
                }

                if (unique == cntMax)
                {
                    cnt = max(cnt, r - l + 1);
                }
            }
        }

        return cnt;
    }
};
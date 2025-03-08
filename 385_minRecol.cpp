#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string &blocks, int k)
    {
        const int n = blocks.size();
        int win = count(blocks.begin(), blocks.begin() + k, 'W');
        int recolor = win;
        for (int l = 0, r = k; r < n; r++, l++)
        {
            win += (blocks[r] == 'W') - (blocks[l] == 'W');
            recolor = min(recolor, win);
        }
        return recolor;
    }
};
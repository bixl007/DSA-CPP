#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int backtrack(string &tile, vector<bool> &used)
    {
        int cnt = 0;
        for (int i = 0; i < tile.size(); i++)
        {
            if (used[i] || (i > 0 && tile[i] == tile[i - 1] && !used[i - 1]))
                continue;
            used[i] = true;
            cnt += 1 + backtrack(tile, used);
            used[i] = false;
        }
        return cnt;
    }

public:
    int numTilePossibilities(string tiles)
    {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        return backtrack(tiles, used);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int a, int b, int c, int d, vector<int> &matchsticks, int idx)
    {
        if (idx == matchsticks.size())
        {
            return a == b && b == c && c == d;
        }

        return solve(a + matchsticks[idx], b, c, d, matchsticks, idx + 1) ||
               solve(a, b + matchsticks[idx], c, d, matchsticks, idx + 1) ||
               solve(a, b, c + matchsticks[idx], d, matchsticks, idx + 1) ||
               solve(a, b, c, d + matchsticks[idx], matchsticks, idx + 1);
    }
    bool makesquare(vector<int> &matchsticks)
    {
        int n = matchsticks.size();

        if (n < 4)
            return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0)
            return false;

        return solve(0, 0, 0, 0, matchsticks, 0);
    }
};

class Solution
{
public:
    bool solve(int idx, int target, vector<int> sides, vector<int> &matchsticks)
    {
        if (idx == matchsticks.size())
            return true;

        for (int i = 0; i < 4; i++)
        {
            if (matchsticks[idx] + sides[i] > target)
                continue;

            int j = i - 1;
            for (; j >= 0; j--)
            {
                if (sides[i] == sides[j])
                    break;
            }
            if (j != -1)
                continue;

            sides[i] += matchsticks[idx];
            if (solve(idx + 1, target, sides, matchsticks))
                return true;
            sides[i] -= matchsticks[idx];
        }

        return false;
    }
    
    bool makesquare(vector<int> &matchsticks)
    {
        int n = matchsticks.size();

        if (n < 4)
            return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);

        return solve(0, sum / 4, sides, matchsticks);
    }
};

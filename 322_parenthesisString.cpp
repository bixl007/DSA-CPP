#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool canBeValid(string &input, string &mask)
    {
        const int len = input.size();
        if (len & 1)
            return false;
        int minBalance = 0, maxBalance = 0;
        for (int i = 0; i < len; i++)
        {
            bool openParenthesis = input[i] == '(';
            bool isWildCard = mask[i] == '0';
            minBalance += (!openParenthesis || isWildCard) ? -1 : 1;
            maxBalance += (openParenthesis || isWildCard) ? 1 : -1;
            if (maxBalance < 0)
                return false;
            minBalance = max(minBalance, 0);
        }
        return minBalance == 0;
    }
};
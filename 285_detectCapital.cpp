#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.length();
        bool a = false;
        if (isupper(word[0]))
        {
            if (n > 1 && isupper(word[1]))
            {
                a = true;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (a == false)
            {
                if (isupper(word[i]))
                {
                    return false;
                }
            }
            else
            {
                if (islower(word[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
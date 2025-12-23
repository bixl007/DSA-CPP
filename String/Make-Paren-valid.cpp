#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0, close = 0;

        for (char ch : s)
        {
            if (ch == '(')
                open++;
            else if (ch == ')' && open)
                open--;
            else
                close++;
        }

        return open + close;
    }
};
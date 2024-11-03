#include <iostream>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s == goal)
            {
                return true;
            }
            else
            {
                s = s.substr(1) + (s.substr(0, 1));
            }
        }

        return false;
    }
};
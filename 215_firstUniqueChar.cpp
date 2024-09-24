#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> counter;

        for (int i = 0; i < s.length(); i++)
        {
            counter[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (counter[s[i]] == 1)
            {
                return i;
                break;
            }
        }
        return -1;
    }
};
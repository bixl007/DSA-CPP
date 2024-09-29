#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> mp1, mp2;
        for (auto i : ransomNote)
        {
            mp1[i]++;
        }

        for (auto i : magazine)
        {
            mp2[i]++;
        }
        bool checker = false;

        for (auto i : ransomNote)
        {
            if (mp1[i] <= mp2[i])
            {
                checker = true;
            }
            else
            {
                cout << i << endl;
                cout << mp1[i] << ' ' << mp2[i];
                checker = false;
                break;
            }
        }
        return checker;
    }
};
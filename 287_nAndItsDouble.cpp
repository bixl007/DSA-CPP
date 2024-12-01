#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> seen;
        for (auto i : arr)
        {
            if (seen.count(i * 2) || (i % 2 == 0 && seen.count(i / 2)))
                return true;
            seen.insert(i);
        }
        return false;
    }
};
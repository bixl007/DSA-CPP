#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, vector<char>> transitions;
    unordered_map<string, bool> memo;

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (const string &s : allowed)
        {
            transitions[s.substr(0, 2)].push_back(s[2]);
        }

        return solve(bottom);
    }

private:
    bool solve(string currentLevel)
    {
        if (currentLevel.length() == 1)
            return true;

        if (memo.count(currentLevel))
            return memo[currentLevel];

        return memo[currentLevel] = buildNextLevel(currentLevel, "", 0);
    }

    bool buildNextLevel(const string &currentLevel, string nextLevel, int idx)
    {
        if (idx == currentLevel.length() - 1)
        {
            return solve(nextLevel);
        }

        string basePair = currentLevel.substr(idx, 2);

        if (transitions.find(basePair) == transitions.end())
        {
            return false;
        }

        for (char topBlock : transitions[basePair])
        {
            if (buildNextLevel(currentLevel, nextLevel + topBlock, idx + 1))
            {
                return true;
            }
        }

        return false;
    }
};